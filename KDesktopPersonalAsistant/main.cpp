#include "kdesktoppersonalasistant.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    KDesktopPersonalAsistant w;
    //a.setMainWidget(&w);
    a.connect( &a, SIGNAL( lastWindowClosed() ), &a, SLOT( quit() ) );
    w.show();
    return a.exec();
}
