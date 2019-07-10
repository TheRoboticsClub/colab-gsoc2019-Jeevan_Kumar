#include "setclass.h"
#include "ui_setclass.h"

SetClass::SetClass(QWidget *parent) : QMainWindow(parent),ui(new Ui::SetClass){
    ui->setupUi(this);
    connect(ui->pushButton_ok    , SIGNAL (clicked()),this, SLOT (HandlePushButton_ok()));
    connect(ui->pushButton_cancel, SIGNAL (clicked()),this, SLOT (HandlePushButton_cancel()));
}

SetClass::~SetClass(){
    delete ui;
}

void SetClass::HandlePushButton_ok(){
    *(this->name_f)= ui->comboBox->currentText().toUtf8().constData();
    delete this;
}

void SetClass::HandlePushButton_cancel(){
    delete this;
}

void SetClass::SetInit(std::string *str , std::vector<std::string>*classNames,std::string *name_f){
    ui->lineEdit->setText(QString::fromStdString(*str));
    for(unsigned int i=0;i<classNames->size();i++){
        ui->comboBox->addItem(QString::fromStdString(classNames->at(i)));
    }
    // *name_f = "hi";
    this->name_f=name_f;
}

void SetClass::wait(){
  QEventLoop loop;
  connect(this, SIGNAL(destroyed()), &loop, SLOT(quit()));
  loop.exec();
}
