#include "addclass.h"
#include "ui_addclass.h"

AddClass::AddClass(QWidget *parent) : QMainWindow(parent),ui(new Ui::AddClass){
    ui->setupUi(this);
    connect(ui->pushButton_ok    , SIGNAL (clicked()),this, SLOT (HandlePushButton_ok()));
    connect(ui->pushButton_cancel, SIGNAL (clicked()),this, SLOT (HandlePushButton_cancel()));
    connect(ui->checkBox, SIGNAL (clicked()),this, SLOT (HandleCheckbox()));
    AddClass::HandleCheckbox();
}

AddClass::~AddClass(){
    delete ui;
}

void AddClass::HandlePushButton_ok(){
    *(this->name_f) =  ui->checkBox->isChecked() ? ui->comboBox->currentText().toUtf8().constData() :
                                                   ui->lineEdit->text().toUtf8().constData() ;
   if(! this->name_f->length())
     return;
    delete this;
}

void AddClass::HandlePushButton_cancel(){
    delete this;
}

void AddClass::SetInit(std::vector<std::string>*classNames,std::string *name_f){
    for(unsigned int i=0;i<classNames->size();i++)
        ui->comboBox->addItem(QString::fromStdString(classNames->at(i)));
    this->name_f=name_f;
}

void AddClass::wait(){
  QEventLoop loop;
  connect(this, SIGNAL(destroyed()), &loop, SLOT(quit()));
  loop.exec();
}

void AddClass::HandleCheckbox(){
    ui->comboBox->setDisabled(!ui->checkBox->isChecked());
    ui->lineEdit->setDisabled(ui->checkBox->isChecked());
}
