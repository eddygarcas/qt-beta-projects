#include <QtGui>
#include <QApplication>
#include <GuiController.h>

int main(int argc, char *argv[])
{
    /*QApplication a(argc, argv);
    KPersonalAsistant w;
    w.show();
    return a.exec();*/

    QApplication a(argc, argv, QApplication::GuiClient);
    //GuiController::instance().setInterface("IPrinterInformation",printerInformation_);
   // GuiController::instance().start();
    a.exec();
}
