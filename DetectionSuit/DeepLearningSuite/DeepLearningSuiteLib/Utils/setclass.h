#ifndef SETCLASS_H
#define SETCLASS_H

#include <iostream>
#include <QMainWindow>

namespace Ui {
class SetClass;
}

class SetClass : public QMainWindow{
    Q_OBJECT

public:
    explicit SetClass(QWidget *parent = 0);
    ~SetClass();
    void SetInit(std::string *name, std::vector<std::string> *classNames,std::string *name_f);

private slots:
    void HandlePushButton_ok();
    void HandlePushButton_cancel();

private:
    Ui::SetClass *ui;
    std::string *name_f;
};

#endif // SETCLASS_H
