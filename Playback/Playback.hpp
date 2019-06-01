#ifndef PLAYBACK_RATES
#define PLAYBACK_RATES
#include<iostream>
#include <opencv2/opencv.hpp>
#include <glog/logging.h>
#include <unistd.h>

class Playback {
public:
  Playback(const int framesCount);
  void GetInput(char keypressed , cv::Mat inference);
  void GetInput(char keypressed);
  bool IsPaused();
  void WaitTillResume();
  void process();
  double rate();
  void show();
  void completeShow();
  void updateFrame(int frameId);
  static void onSlide(int currentPos,void *frame);
private:
  bool pause;
  double speed;
  char keystroke;
  std::vector<cv::Mat> inferences;
  int frameId;
  const int framesCount;
};
#endif
