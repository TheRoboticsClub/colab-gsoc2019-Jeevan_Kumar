//
// Created by frivas on 22/01/17.
//

#include "Sample.h"
#include <glog/logging.h>
#include <iomanip>
#include <boost/filesystem/operations.hpp>


Sample::Sample() {
    this->colorImagePath="";
    this->depthImagePath="";
    this->rectRegions=RectRegionsPtr(new RectRegions());
    this->contourRegions=ContourRegionsPtr(new ContourRegions());
    this->rleRegions=RleRegionsPtr(new RleRegions());
    // this->selected = new std::vector<int>
    // cv::setMouseCallback("Detection", Sample::CallBackFunc ,this);
}

Sample::Sample(const cv::Mat &colorImage) {
    colorImage.copyTo(this->colorImage);
    // cv::setMouseCallback("Detection", Sample::CallBackFunc ,&this->rectRegions);
}

Sample::Sample(const cv::Mat &colorImage, const RectRegionsPtr &rectRegions) {
    this->setColorImage(colorImage);
    this->setRectRegions(rectRegions);
    // cv::setMouseCallback("Detection", Sample::CallBackFunc ,&this->rectRegions);
}

Sample::Sample(const cv::Mat &colorImage, const ContourRegionsPtr &contourRegions) {
    this->setColorImage(colorImage);
    this->setContourRegions(contourRegions);
}

Sample::Sample(const cv::Mat &colorImage, const RectRegionsPtr &rectRegions, const ContourRegionsPtr &contourRegions) {
    this->setColorImage(colorImage);
    this->setRectRegions(rectRegions);
    this->setContourRegions(contourRegions);
}

Sample::Sample(const cv::Mat &colorImage, const cv::Mat &depthImage, const RectRegionsPtr &rectRegions) {
    this->setColorImage(colorImage);
    this->setDepthImage(depthImage);
    this->setRectRegions(rectRegions);
}

Sample::Sample(const cv::Mat &colorImage, const cv::Mat &depthImage, const ContourRegionsPtr &contourRegions) {
    this->setColorImage(colorImage);
    this->setDepthImage(depthImage);
    this->setContourRegions(contourRegions);
}

Sample::Sample(const cv::Mat &colorImage, const cv::Mat &depthImage, const RectRegionsPtr &rectRegions,
               const ContourRegionsPtr &contourRegions) {
    this->setColorImage(colorImage);
    this->setDepthImage(depthImage);
    this->setRectRegions(rectRegions);
    this->setContourRegions(contourRegions);

}

void Sample::setSampleDims(const int width, const int height) {
    this->width = width;
    this->height = height;
}

void Sample::setColorImage(const cv::Mat &image) {
    image.copyTo(this->colorImage);
}

void Sample::clearColorImage() {             // For better memory management
    if (!this->colorImage.empty())
        this->colorImage.release();
}

void Sample::clearDepthImage() {            // For better memory management
    if (!this->depthImage.empty())
        this->depthImage.release();
}

void Sample::setDepthImage(const cv::Mat &image) {
    image.copyTo(this->depthImage);
}

void Sample::setRectRegions(const RectRegionsPtr &regions) {
    this->rectRegions=regions;
}

void Sample::setContourRegions(const ContourRegionsPtr &regions) {
    this->contourRegions=regions;
}

void Sample::setRleRegions(const RleRegionsPtr& regions) {
    this->rleRegions=regions;
}


int Sample::getSampleWidth() const {
    if (this->width != -1)
        return this->width;

    if (!this->getColorImage().empty())
        return this->getColorImage().cols;

    if (!this->getDepthImage().empty())
        return this->getDepthImage().cols;

    return -1;
}

int Sample::getSampleHeight() const {
    if (this->height != -1)
        return this->height;

    if (!this->getColorImage().empty())
        return this->getColorImage().rows;

    if (!this->getDepthImage().empty())
        return this->getDepthImage().rows;

    return -1;
}

RectRegionsPtr Sample::getRectRegions() const{
    return this->rectRegions;
}

ContourRegionsPtr Sample::getContourRegions() const{
    return this->contourRegions;
}

RleRegionsPtr Sample::getRleRegions() const{
    return this->rleRegions;
}

std::string Sample::getColorImagePath() const{
    if (this->colorImagePath.empty())
        throw std::invalid_argument("Color Image Path not set in this Sample");

    return this->colorImagePath;
}

std::string Sample::getDepthImagePath() const{
    if (this->depthImagePath.empty())
        throw std::invalid_argument("Depth Image Path not set in this Sample");

    return this->depthImagePath;
}

cv::Mat Sample::getColorImage() const{
    if (this->colorImage.empty()) {
        cv::Mat image = cv::imread(this->colorImagePath);
        return image;
    }
    else
        return this->colorImage.clone();
}

cv::Mat Sample::getDepthImage() const{
    if (this->depthImage.empty()) {
        cv::Mat image = cv::imread(this->depthImagePath);
        return image;
    }
    else
        return this->depthImage.clone();
}

Sample::Sample(const std::string &path, const std::string &id,bool loadDepth) {
    this->colorImagePath=path + "/"  + id + ".png";

    if (boost::filesystem::exists(boost::filesystem::path(path + "/" + id + ".json")))
        this->rectRegions=RectRegionsPtr(new RectRegions(path + "/" + id + ".json"));
    else{
        LOG(ERROR) << "Error " + id + " sample has not associated detection";
    }

    if (boost::filesystem::exists(boost::filesystem::path(path + "/" + id + "-region.json")))
        this->contourRegions=ContourRegionsPtr(new ContourRegions(path + "/" + id + "-region.json"));

    if (loadDepth) {
        this->depthImagePath=path + "/" + id + "-depth.png";
    }
}

cv::Mat Sample::getSampledColorImage() const{
    cv::Mat image = this->getColorImage();
    if (this->rectRegions)
        this->rectRegions->drawRegions(image);
    if (this->contourRegions)
        this->contourRegions->drawRegions(image);
    if (this->rleRegions)
        this->rleRegions->drawRegions(image);
    return image;
}

cv::Mat Sample::getSampledDepthImage() const{
    cv::Mat image =this->getDepthImage();
    if (this->rectRegions)
        this->rectRegions->drawRegions(image);
    if (this->contourRegions)
        this->contourRegions->drawRegions(image);
    return image;
}

void Sample::save(const std::string &outPath, int id) {
    std::stringstream ss ;
    ss << std::setfill('0') << std::setw(5) << id;
    this->save(outPath,ss.str());

}

void Sample::save(const std::string &outPath, const std::string &filename) {


    if (this->colorImage.empty()){
        if (!this->colorImagePath.empty())
            if (boost::filesystem::exists(boost::filesystem::path(this->colorImagePath))) {
                cv::Mat image = cv::imread(this->colorImagePath);
                cv::imwrite(outPath + "/" + filename + ".png", image);
            }
    }
    else
        cv::imwrite(outPath + "/" + filename + ".png",this->colorImage);

    if (this->depthImage.empty()){
        if (boost::filesystem::exists(boost::filesystem::path(this->depthImagePath))) {
            cv::Mat image = cv::imread(this->depthImagePath);
            cv::imwrite(outPath + "/" + filename + "-depth.png", image);
        }
    }
    else
        cv::imwrite(outPath + "/" + filename + "-depth.png", depthImage);

    bool ifRegions = false;
    if(!rectRegions->getRegions().empty()) {
        rectRegions->saveJson(outPath + "/" + filename + ".json");
        ifRegions = true;
    }
    if (!contourRegions->getRegions().empty()) {
        contourRegions->saveJson(outPath + "/" + filename + "-region.json");
        ifRegions = true;
    }

    if (!ifRegions)
        LOG(WARNING) << "Both ContourRegions and Rect Regions are not present, hence not saving any regions for Sample: " << this->sampleID;
}

void Sample::save(const std::string &outPath) {
    if (this->sampleID.size() != 0 ){
        this->save(outPath,this->sampleID);
    }
    else{
        LOG(ERROR) << "No sample id is defined, this sample will not be saved";
    }

}

void Sample::print() {

    LOG(INFO) << "Printing Regions with Classes" << '\n';

    std::vector<RectRegion> regionsToPrint = this->rectRegions->getRegions();

    for (auto it = regionsToPrint.begin(); it != regionsToPrint.end(); it++) {
        LOG(INFO) << "Class: " << it->classID << '\n';
        LOG(INFO) << "Confidence: " << it->confidence_score << '\n';
        LOG(INFO) << "uniqObjectID" << it->uniqObjectID <<'\n';
        // it->region.x=x;
        // it->region.y=y;
        LOG(INFO) << "BBOX" << it->region.x << it->region.y << it->region.width << it->region.height << '\n';
    }
    // LOG(INFO) << "Fuddu : " << this->rectRegions->regions.size() << std::endl;
}

// void calculator(int x,int y,int height,int width,int newX, int newY,int temp){
//     switch (temp1) {
//       case /* value */:
//     }
// }

int mod(int test){
    if(test<0)
      return -test;
    return test;
}

void Sample::AdjustBox(int x, int y){
      for (auto it = this->rectRegions->regions.begin(); it != this->rectRegions->regions.end(); it++) {
          if(mod(it->region.x-x)<20 && mod(it->region.y-y)<20){
            it->region.width  -= (x-it->region.x);
            it->region.height -= (y-it->region.y);
            it->region.x=x;
            it->region.y=y;
          }
          else if(mod(it->region.x+it->region.width-x)<20 && mod(it->region.y-y)<20){
            it->region.width  += (x-(it->region.x+it->region.width));
            it->region.height -= (y-it->region.y);
            // it->region.x=x;
            it->region.y=y;
          }
          else if(mod(it->region.x-x)<20 && mod(it->region.y+it->region.height-y)<20){
            it->region.width  -= (x-it->region.x);
            it->region.height += (y-(it->region.y+it->region.height));
            it->region.x=x;
            // it->region.y=y;
          }
          else if(mod(it->region.x+it->region.width-x)<20 && mod(it->region.y+it->region.height-y)<20){
            it->region.width  += (x-it->region.x-it->region.width);
            it->region.height += (y-it->region.y-it->region.height);
            // it->region.x=x;
            // it->region.y=y;
          }
      }
}

bool Sample::show(const std::string readerImplementation, const std::string windowName, const int waitKey, const bool showDepth) {
    cv::Mat image = this->getSampledColorImage();
    cv::imshow(windowName, image);

    if (showDepth) {

        if (!(this->isDepthImageValid())) {
            LOG(WARNING)<< "Depth Images not available! Please verify your dataset or uncheck 'Show Depth Images'";
            return false;
        }

        cv::Mat depth_color;

        if (readerImplementation == "spinello")
            depth_color = this->getSampledDepthColorMapImage(-0.9345, 1013.17);
        else
            depth_color = this->getSampledDepthColorMapImage();


        cv::imshow("Depth Color Map", depth_color);
    }

    int key = cv::waitKey(waitKey);
    if (char(key) == 'q' || key == 27) {
        cv::destroyWindow(windowName);
        return false;
    }

    return true;

}

bool Sample::isDepthImageValid() {
    return !this->depthImage.empty();
}

bool Sample::isValid() {
    return !this->colorImage.empty();
}

void Sample::filterSamplesByID(std::vector<std::string> filteredIDS) {
    if (this->rectRegions)
        this->rectRegions->filterSamplesByID(filteredIDS);
    if (contourRegions)
        this->contourRegions->filterSamplesByID(filteredIDS);
}

void Sample::setColorImage(const std::string &imagePath) {
    this->colorImagePath=imagePath;
}

void Sample::setDepthImage(const std::string &imagePath) {
    this->depthImagePath=imagePath;
}

void Sample::setSampleID(const std::string &sampleID) {
    this->sampleID=sampleID;
}

std::string Sample::getSampleID() {
    return this->sampleID;
}

Sample::~Sample() {
    if (!this->colorImage.empty()){
        this->colorImage.release();
    }
    if (this->depthImage.empty()){
        this->depthImage.release();
    }

}

cv::Mat Sample::getDeptImageGrayRGB() const {
    cv::Mat image = this->getDepthImage();
    std::vector<cv::Mat> imageVector;
    cv::split(image,imageVector);

    std::vector<cv::Mat> grayRGB_vector;
    grayRGB_vector.push_back(imageVector[0]);
    grayRGB_vector.push_back(imageVector[0]);
    grayRGB_vector.push_back(imageVector[0]);

    cv::Mat grayRGB;
    cv::merge(grayRGB_vector,grayRGB);
    return grayRGB;

}

cv::Mat Sample::getDepthColorMapImage(double alpha, double beta) const {
    cv::Mat image = getDepthImage();
    double minVal, maxVal;

    minMaxLoc( image, &minVal, &maxVal );

    cv::Mat mask;
    cv::threshold(image, mask, maxVal - 1, 255, cv::THRESH_BINARY_INV);
    mask.convertTo(mask, CV_8UC1);

    image.convertTo(image, CV_8UC1, alpha, beta);

    cv::Mat colorMappedDepth;
    cv::applyColorMap(image, image, cv::COLORMAP_RAINBOW);
    image.copyTo(colorMappedDepth, mask);

    return colorMappedDepth;;
}

cv::Mat Sample::getSampledDepthColorMapImage(double alpha, double beta) const {
    cv::Mat image = getDepthColorMapImage(alpha, beta);
    if (this->rectRegions)
        this->rectRegions->drawRegions(image);
    if (this->contourRegions)
        this->contourRegions->drawRegions(image);
    return image;
}


void Sample::CallBackFunc(int event, int x, int y, int flags, void* userdata){
     if(event == cv::EVENT_LBUTTONUP){
       // check(userdata);
         // std::vector<RectRegion> regionsToPrint = ((Sample *)userdata)->rectRegions->getRegions();
         RectRegions jumma = *(((Sample *)userdata)->rectRegions);
         for (auto it = jumma.getRegions().begin(); it != jumma.getRegions().end(); it++) {
             LOG(INFO) << "Class: " << it->classID << '\n';
             LOG(INFO) << "Confidence: " << it->confidence_score << '\n';
             // LOG(INFO) << "uniqObjectID" << it->uniqObjectID <<'\n';
             LOG(INFO) << "BBOX" << it->region.x++ << " " << it->region.y++ << " " << it->region.width << " "  << it->region.height << '\n';
             LOG(INFO) << " It has been executed\n";
         }
         // const RectRegionsPtr& regions = regionsToPrint;
       // setRectRegions(regionss);

     }
     if  ( event == cv::EVENT_LBUTTONUP ){
     LOG(INFO) << " This sis  : " << (((Sample *)(userdata))->rectRegions->getRegions()).size() << std::endl;
     }
}

void Sample::SetMousy(bool mousy){
  this->mousy = mousy;
}

bool Sample::GetMousy(){
  return this->mousy;
}
