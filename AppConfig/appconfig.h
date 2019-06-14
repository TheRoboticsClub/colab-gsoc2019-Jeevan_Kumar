#ifndef APPCONFIG_H
#define APPCONFIG_H

#include <QMainWindow>

namespace Ui {
class appconfig;
}

class appconfig : public QMainWindow
{
    Q_OBJECT

public:
    explicit appconfig(QWidget *parent = 0);
    ~appconfig();

private:
    Ui::appconfig *ui;
private slots:
    void handleToolbuttonWeights();
    void handleToolbuttonNames();
    void handleToolbuttonCfg();
    void handleToolbuttonAppconfig();
    void handleToolbuttonEval();
    void handleCheckbox();
    void handlePushbuttonOK();
};

#endif // APPCONFIG_H
