#ifndef PLAYBACK_RATES
#define PLAYBACK_RATES
#include<iostream>
#include <opencv2/opencv.hpp>
#include <glog/logging.h>
#include <unistd.h>

class Playback {
public:
  Playback();
  void GetInput(char keypressed);
  bool IsPaused();
  void WaitTillResume();
  void show();
  void process();
  double rate();
private:
  bool pause;
  double speed;
  char keystroke;
};
#endif
