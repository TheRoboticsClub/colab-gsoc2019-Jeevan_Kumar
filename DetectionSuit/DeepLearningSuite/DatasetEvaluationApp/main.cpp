#include "mainwindow.h"
#include <QApplication>
#include <Utils/SampleGenerationApp.h>
#include <QStyleFactory>
#include "gui/Appcfg.hpp"

class MyApp:public SampleGenerationApp{
public:
    void RequiredParameters(){
      this->requiredArguments.push_back("datasetPath");
      this->requiredArguments.push_back("evaluationsPath");
      this->requiredArguments.push_back("weightsPath");
      this->requiredArguments.push_back("netCfgPath");
      this->requiredArguments.push_back("namesPath");
    }
    MyApp(int argc, char* argv[]):SampleGenerationApp(argc,argv){
      RequiredParameters();
    };
    MyApp(YAML::Node node):SampleGenerationApp(node){
        RequiredParameters();
    };
    MyApp(std::string filepath, bool isPath):SampleGenerationApp(filepath,isPath){
      RequiredParameters();
    };
    void operator()(){
        QApplication a(argc, argv);
        MainWindow w(this);
        w.show();


        a.exec();

    };
};




int main(int argc, char *argv[]){
  if(argc<3){
    Appcfg app(argc,argv);
    YAML::Node noder = app.get_node();
    if(noder["appconfig"]){
      MyApp myApp(noder["appconfig"].as<std::string>(),true);
      myApp.process();
    }
    else{
      MyApp myApp(noder);
      myApp.process();
    }
  }
  else{
    MyApp myApp(argc,argv);
    myApp.process();
  }
}
