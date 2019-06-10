#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

//void MainWindow::on_pushButton_clicked(){
//    QString file_name = QFileDialog::getOpenFileName(this,"Open a files","~/");
//}


void MainWindow::on_toolButton_3_clicked(){
    QString file_name = QFileDialog::getExistingDirectory(this,"Open a file","~/");
//    std::cout << file_name << std::endl;
    std::string utf8_text = file_name.toUtf8().constData();
    std::cout << utf8_text << std::endl;
}

void MainWindow::on_toolButton_clicked(){
    QString file_name = QFileDialog::getOpenFileName(this,"Open a file","~/");
}
void MainWindow::on_toolButton_2_clicked(){
    QString file_name = QFileDialog::getOpenFileName(this,"Open a file","~/");
}
void MainWindow::on_toolButton_4_clicked(){
    QString file_name = QFileDialog::getOpenFileName(this,"Open a file","~/");
}

