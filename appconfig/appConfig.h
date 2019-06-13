#ifndef APPCONFIG_H
#define APPCONFIG_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_toolButton1_clicked();
    void on_toolButton2_clicked();
    void on_toolButton3_clicked();
    void on_toolButton4_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // APPCONFIG_H
