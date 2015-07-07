#include "qgnupgpmenu.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGnuPGPMenu w;
    w.show();
    return a.exec();
}
