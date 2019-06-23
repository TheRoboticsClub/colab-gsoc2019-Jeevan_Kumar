#include "pop_up.h"
#include "ui_pop_up.h"
#include <QFileDialog>
#include <QMessageBox>

pop_up::pop_up(QWidget *parent) : QMainWindow(parent), ui(new Ui::pop_up){
    ui->setupUi(this);
    connect(ui->toolButton_1, SIGNAL (clicked()),this, SLOT (HandleToolButton_1()));
    connect(ui->pushButton_ok, SIGNAL (clicked()),this, SLOT (HandlePushButton_ok()));
}

pop_up::~pop_up()
{
    delete ui;
}

void pop_up::HandleToolButton_1(){
    QString dir_name = QFileDialog::getExistingDirectory(this,"Select config file","~/");
    ui->lineEdit->setText(dir_name);
    *(this->path) = dir_name.toUtf8().constData();
   // this->node[test]=dir_name.toUtf8().constData();
}

void pop_up::HandlePushButton_ok(){
     if(!ui->lineEdit->text().size()){
        QMessageBox::warning(this,"Warning","Please provide " + this->name +
                                              " parameter to continue");
        return;
     }
    QApplication::quit();
    QCoreApplication::quit();
      // return ;
}


void pop_up::SetName(std::string Name){
    this->name = QString::fromStdString(Name);
    ui->label->setText(this->name);
}

void pop_up::SetPath(std::string *path){
  this->path = path;
}
