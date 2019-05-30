#include "Playback.hpp"

Playback::Playback(){
  this->pause = false;
  this->speed = 1;
}

bool Playback::IsPaused(){
  return this->pause;
}

void Playback::GetInput(char keypressed){
  this->keystroke = keypressed;
  Playback::process();
}

void Playback::process(){
  switch (this->keystroke) {
    case ' ' :
    case 'p' :
    case 'k' : this->pause = !this->pause;
               std::cout << "Keystroke : " << this->keystroke << std::endl;
               break;
    case '+' : this->speed += 2;
               std::cout << "Keystroke : " << this->keystroke << std::endl;
               break;
    case '-' : this->speed -= 2;
               std::cout << "Keystroke : " << this->keystroke << std::endl;
               break;
    default  : break;
  }
  Playback::show();
}

void Playback::show(){
  if(this->pause)
    Playback::WaitTillResume();
  usleep(int(this->rate()*10000));
}

double Playback::rate(){
  return this->speed;
}

void Playback::WaitTillResume(){
  while(this->pause)
    Playback::GetInput(cv::waitKey(0));
}
