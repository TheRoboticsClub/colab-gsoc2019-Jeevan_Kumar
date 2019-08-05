#include "ros/ros.h"
#include "std_msgs/String.h"
#include "opencv2/highgui/highgui.hpp"
#include "image_converter.hpp"
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <DatasetConverters/liveReaders/GenericLiveReader.h>
#include <FrameworkEvaluator/GenericInferencer.h>
#include <FrameworkEvaluator/MassInferencer.h>
#include <FrameworkEvaluator/labeling.h>

const std::string &netConfigList = "/home/issiki/dl-DetectionSuite/DeepLearningSuite/build/DatasetEvaluationApp/datasets/cfg//foo.cfg",
&weights = "/home/issiki/dl-DetectionSuite/DeepLearningSuite/build/DatasetEvaluationApp/datasets/weights//ssd_mobilenet_v1_coco_2018_01_28/frozen_inference_graph.pb",
&inferencerImp = "tensorflow",
&inferencerNames="/home/issiki/dl-DetectionSuite/DeepLearningSuite/build/DatasetEvaluationApp/datasets/names//coco.names.txt",
&outputFolder="";
std::map<std::string, std::string>* inferencerParamsMap = new std::map<std::string, std::string>();
double* confidence_threshold = new double(0.2);
GenericInferencerPtr inferencer(new GenericInferencer(netConfigList,weights,inferencerNames,inferencerImp, inferencerParamsMap));
MassInferencer massInferencer(inferencer->getInferencer(),outputFolder, confidence_threshold, true);


void chatterCallback(const sensor_msgs::ImageConstPtr& img){

  cv_bridge::CvImagePtr cv_ptr;
  try{
    cv_ptr = cv_bridge::toCvCopy(img, sensor_msgs::image_encodings::BGR8);
  }
  catch (cv_bridge::Exception& e){
    ROS_ERROR("cv_bridge exception: %s", e.what());
    return;
  }

  // cv::imshow("Mat", cv_ptr->image);
  cv::waitKey(3);

  massInferencer.process(false,cv_ptr->image);

}


int main(int argc, char *argv[]){
  ros::init(argc, argv, "detection_node");
  std::string param;
  ros::NodeHandle nh("~");
  std::string check;
  nh.getParam("topic", check);
  std::cout << check << std::endl;
  ROS_INFO("Got parameter : %s", check.c_str());

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe(check, 10, chatterCallback);

  ros::spin();

  return 0;
}
