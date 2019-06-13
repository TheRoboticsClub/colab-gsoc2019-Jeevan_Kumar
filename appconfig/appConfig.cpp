#include "appConfig.h"
#include "ui_Appconfig.h"
#include <QFileDialog>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_toolButton1_clicked(){
    QString dir_name = QFileDialog::getExistingDirectory(this,"Open a dir","~/");
//    std::string utf8_text = dir_name.toUtf8().constData();
    ui->lineEdit1->setText(dir_name);
}

void MainWindow::on_toolButton2_clicked(){
    QString dir_name = QFileDialog::getExistingDirectory(this,"Open a dir","~/");
//    std::string utf8_text = dir_name.toUtf8().constData();
    ui->lineEdit2->setText(dir_name);
}

void MainWindow::on_toolButton3_clicked(){
    QString dir_name = QFileDialog::getExistingDirectory(this,"Open a dir","~/");
//    std::string utf8_text = dir_name.toUtf8().constData();
    ui->lineEdit3->setText(dir_name);
}

void MainWindow::on_toolButton4_clicked(){
    QString dir_name = QFileDialog::getExistingDirectory(this,"Open a dir","~/");
//    std::string utf8_text = dir_name.toUtf8().constData();
    ui->lineEdit4->setText(dir_name);
}

