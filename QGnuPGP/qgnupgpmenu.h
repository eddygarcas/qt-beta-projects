#ifndef QGNUPGPMENU_H
#define QGNUPGPMENU_H

#include <QtGui/QMainWindow>
#include "ui_qgnupgpmenu.h"

class QGnuPGPMenu : public QMainWindow
{
    Q_OBJECT

public:
    QGnuPGPMenu(QWidget *parent = 0);
    ~QGnuPGPMenu();

private:
    Ui::QGnuPGPMenuClass ui;
};

#endif // QGNUPGPMENU_H
