#include "DeployerNode.hpp"
#include <boost/bind.hpp>

DeployerNode::DeployerNode(int argc, char *argv[]){
  std::string path;
  ros::init(argc, argv, "deployer_node");
  ros::NodeHandle nh("~");
  nh.getParam("topic", this->topic);
  nh.getParam("configfile", path);

  ROS_INFO("Will subscribe to ROS TOPIC : %s", this->topic.c_str());

  YAML::Node config = YAML::LoadFile(path);
  const std::string &netConfigList   = (const std::string) config["netConfigList"].as<std::string>(),
                    &weights         = (const std::string) config["weights"].as<std::string>(),
                    &inferencerImp   = (const std::string) config["inferencerImp"].as<std::string>(),
                    &inferencerNames = (const std::string) config["inferencerNames"].as<std::string>(),
                    &outputFolder = "";
                    // &outputFolder    = (const std::string) config["outputFolder"].as<std::string>();
  // std::map<std::string, std::string> *inferencerParamsMap = config["outputFolder"].as<std::map<std::string, std::string>();
  std::map<std::string, std::string>* inferencerParamsMap = new std::map<std::string, std::string>();
  double* confidence_threshold = new double(0.2);
  this->inferencer = new GenericInferencer(netConfigList,weights,inferencerNames,inferencerImp, inferencerParamsMap);
  this->massInferencer = new MassInferencer(inferencer->getInferencer(),outputFolder, confidence_threshold, true);
  this->node = new ros::NodeHandle();
  this->sub = this->node->subscribe<sensor_msgs::Image>(this->topic, 10,boost::bind(&DeployerNode::ros_to_cv, _1, this->massInferencer));
  ros::spin();
}

void DeployerNode::ros_to_cv(const sensor_msgs::ImageConstPtr& img , MassInferencer *massInferencer){
  cv_bridge::CvImagePtr cv_ptr;
  try{
    cv_ptr = cv_bridge::toCvCopy(img, sensor_msgs::image_encodings::BGR8);
  }
  catch (cv_bridge::Exception& e){
    ROS_ERROR("cv_bridge exception: %s", e.what());
    return;
  }
  massInferencer->process(false,cv_ptr->image);
}




DeployerNode::~DeployerNode(){
  delete inferencer;
  delete massInferencer;
  delete node;
}
