#include "appconfig.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    appconfig w;
    w.show();

    return a.exec();
}
