//
// Created by frivas on 26/03/17.
//

#include "VideoReader.h"

VideoReader::VideoReader(const std::string &videoPath):DatasetReader(true) {
    this->cap =  new cv::VideoCapture(videoPath);
    this->framesCount = this->cap->get(cv::CAP_PROP_FRAME_COUNT);
    this->isVideo = true;
    if(!cap->isOpened())  // check if we succeeded
			 throw std::invalid_argument( "Couldn't open Video file!" );

    init=false;
}

VideoReader::~VideoReader() {
    LOG(INFO) << "Releasing Video File";
    this->cap->release();

}

bool VideoReader::getNextSample(Sample &sample) {

    cv::Mat image;
    int count = 0;

    try {
        while (!cap->read(image)) {
            this->validFrame = false;
            LOG(ERROR) << "Frame not valid " << std::endl;
			if (count >= 5) {
				LOG(INFO) << "Video Ended" << '\n';
				return false;
			}						// Video Ended
			count++;
        }

        //    init=true;
        this->validFrame = true;
        sample.setSampleID(std::to_string(++this->sample_count));
        sample.setColorImage(image);
        return true;
    }
    catch (const std::exception &exc)
    {
          LOG(ERROR) << "Exception Detected: " << exc.what();
          return false;
    }


}
