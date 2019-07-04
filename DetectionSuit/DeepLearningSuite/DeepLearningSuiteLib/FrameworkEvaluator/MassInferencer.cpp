//
// Created by frivas on 1/02/17.
//

#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <glog/logging.h>
#include "MassInferencer.h"

MassInferencer::MassInferencer(DatasetReaderPtr reader, FrameworkInferencerPtr inferencer, const std::string& resultsPath, bool debug)
 : MassInferencer::MassInferencer(reader, inferencer, resultsPath, NULL, debug) {
        this->detections = new std::vector<Sample>();
 }  // Delegating Constructor

MassInferencer::MassInferencer(DatasetReaderPtr reader, FrameworkInferencerPtr inferencer, bool debug)
 : MassInferencer::MassInferencer(reader, inferencer, NULL, debug) {
       this->detections = new std::vector<Sample>();
 }  // Delegating Constructor

MassInferencer::MassInferencer(DatasetReaderPtr reader, FrameworkInferencerPtr inferencer,
                               const std::string &resultsPath,double* confidence_threshold, bool debug): reader(reader), inferencer(inferencer), resultsPath(resultsPath),confidence_threshold(confidence_threshold),debug(debug)
{
    if (resultsPath.empty())
        saveOutput = false;
    else
        saveOutput = true;
    alreadyProcessed=0;
    this->detections = new std::vector<Sample>();
    int time=0;
    time = reader->IsVideo() ? reader->TotalFrames() : 1 ;
    this->playback.AddTrackbar(time);
    if (!resultsPath.empty()) {
        auto boostPath= boost::filesystem::path(this->resultsPath);
        if (!boost::filesystem::exists(boostPath)){
            boost::filesystem::create_directories(boostPath);
        }
        else{
            LOG(WARNING)<<"Output directory already exists";
            LOG(WARNING)<<"Continuing detecting";
            boost::filesystem::directory_iterator end_itr;

            for (boost::filesystem::directory_iterator itr(boostPath); itr!=end_itr; ++itr)
            {
                if ((is_regular_file(itr->status()) && itr->path().extension()==".png") && (itr->path().string().find("-depth") == std::string::npos)) {
                    alreadyProcessed++;
                }

            }
          //exit(-1);
        }
    }
}

MassInferencer::MassInferencer(DatasetReaderPtr reader, FrameworkInferencerPtr inferencer,
                               const std::string &resultsPath, bool* stopDeployer,double* confidence_threshold, bool debug): reader(reader), inferencer(inferencer), resultsPath(resultsPath),debug(debug),stopDeployer(stopDeployer),confidence_threshold(confidence_threshold)
{

    if (resultsPath.empty())
        saveOutput = false;
    else
        saveOutput = true;

    this->detections = new std::vector<Sample>();
    int time=0;
    time = reader->IsVideo() ? reader->TotalFrames() : 1 ;
    this->playback.AddTrackbar(time);
    alreadyProcessed=0;
    if (!resultsPath.empty()) {
        auto boostPath= boost::filesystem::path(this->resultsPath);
        if (!boost::filesystem::exists(boostPath)){
            boost::filesystem::create_directories(boostPath);
        }
        else{
            LOG(WARNING)<<"Output directory already exists";
            LOG(WARNING)<<"Files might be overwritten, if present in the directory";
            boost::filesystem::directory_iterator end_itr;


        }

    }

}

MassInferencer::MassInferencer(DatasetReaderPtr reader, FrameworkInferencerPtr inferencer, double* confidence_threshold, bool debug): reader(reader), inferencer(inferencer), confidence_threshold(confidence_threshold), debug(debug)
{
        //Constructor to avoid writing results to outputPath
        saveOutput = false;
        alreadyProcessed=0;
        this->detections = new std::vector<Sample>();
        int time=0;
        time = reader->IsVideo() ? reader->TotalFrames() : 1 ;
        this->playback.AddTrackbar(time);
}

void MassInferencer::BorderChange(int event, int x, int y, int flags, void* userdata){
    if(event == cv::EVENT_LBUTTONDOWN){
      int currFrame = ((MassInferencer *)(userdata))->playback.currentFrame();
      LOG(INFO) << currFrame << std::endl;
      (((MassInferencer *)(userdata))->detections)->at(currFrame-1).AdjustBox(x,y);
      cv::Mat imager = (((MassInferencer *)(userdata))->detections)->at(currFrame-1).getSampledColorImage();
      ((MassInferencer *)(userdata))->playback.updateFrame(currFrame-1,&imager);
      // // ((Sample *)(userdata))->AdjustBox(x,y);
      // // ((Sample *)(userdata))->SetMousy(true);
      cv::imshow("Detection", imager);
    }
     if(event == cv::EVENT_LBUTTONUP){
       // ((Sample *)(userdata))->AdjustBox(x,y);
       // ((Sample *)(userdata))->SetMousy(true);
       // cv::imshow("Detection", ((Sample *)(userdata))->getSampledColorImage());
     }
}

void MassInferencer::IsProcessed(Sample *sample, int *counter , int *nsamples){
  while (alreadyProcessed>0){
    LOG(INFO) << "Already evaluated: " << sample->getSampleID() << "(" << *counter << "/" << *nsamples << ")" << std::endl;
    this->reader->getNextSample(*sample);
    *counter++;
    alreadyProcessed--;
  }
}

void MassInferencer::Shower(Sample *sample, Sample *detection,cv::Mat *image2detect, bool &useDepthImages){
  if (this->debug) {
      cv::Mat image =sample->getSampledColorImage();
      Sample detectionWithImage=*detection;

      if (useDepthImages)
          detectionWithImage.setColorImage(sample->getDepthColorMapImage());
      else
          detectionWithImage.setColorImage(sample->getColorImage());

      if (useDepthImages){
          cv::imshow("GT on Depth", sample->getSampledDepthColorMapImage());
          cv::imshow("Input", *image2detect);
      }
      char keystroke=cv::waitKey(1);
      if(reader->IsValidFrame() && reader->IsVideo())
        this->playback.GetInput(keystroke,detectionWithImage.getSampledColorImage(),image);
      else{
        cv::imshow("GT on RGB", image);
        cv::imshow("Detection", detectionWithImage.getSampledColorImage());
        cv::waitKey(100);
      }
  }
}

void MassInferencer::finder(Sample *sample , Sample *detection, cv::Mat *image2detect ,bool &useDepthImages, int *counter , int *nsamples){
  *counter+=1;
  if (this->stopDeployer != NULL && *(this->stopDeployer)) {
      LOG(INFO) << "Deployer Process Stopped" << "\n";
      return;
  }

  LOG(INFO) << "Evaluating : " << sample->getSampleID() << "(" << *counter << "/" << *nsamples << ")" << std::endl;

  if (useDepthImages)
      *image2detect = sample->getDepthColorMapImage();
  else {
      *image2detect = sample->getColorImage();
  }

  double thresh = this->confidence_threshold == NULL ? this->default_confidence_threshold
                                                      : *(this->confidence_threshold);

  try {
      *detection=this->inferencer->detect(*image2detect, thresh);
  }
  catch(const std::runtime_error& error) {
    LOG(ERROR) << "Error Occured: " << error.what() << '\n';
    exit(1);
  }

  detection->setSampleID(sample->getSampleID());

  if (saveOutput)
      detection->save(this->resultsPath);

}

void MassInferencer::process(bool useDepthImages, DatasetReaderPtr readerDetection) {

    Sample sample;
    int counter=0;
    int nsamples = this->reader->getNumberOfElements();

    MassInferencer::IsProcessed(&sample,&counter,&nsamples);
    cv::Mat image2detect;
    static Sample detection;
    cv::setMouseCallback("Detection", MassInferencer::BorderChange ,this);
    bool read_succesful = true;
    while (read_succesful){
        if(!detection.GetMousy()){
          read_succesful=this->reader->getNextSample(sample);
          MassInferencer::finder(&sample,&detection,&image2detect,useDepthImages,&counter,&nsamples);
          MassInferencer::Shower(&sample,&detection,&image2detect,useDepthImages);
          this->detections->push_back(detection);
      }
        detection.clearColorImage();
        detection.clearDepthImage();
        detection.SetMousy(false);
        if (readerDetection != NULL)
            readerDetection->addSample(detection);
    }

    if(!reader->IsValidFrame()){
      this->playback.completeShow();
      cv::destroyAllWindows();
      LOG(INFO) << "Mean inference time: " << this->inferencer->getMeanDurationTime() << "(ms)" <<  std::endl;
    }


}



FrameworkInferencerPtr MassInferencer::getInferencer() const {
    return this->inferencer;
}
