#ifndef KDESKTOPPERSONALASISTANT_H
#define KDESKTOPPERSONALASISTANT_H

#include <QtGui/QMainWindow>
#include "ui_kdesktoppersonalasistant.h"

class KDesktopPersonalAsistant : public QMainWindow
{
    Q_OBJECT

public:
    KDesktopPersonalAsistant(QWidget *parent = 0);
    ~KDesktopPersonalAsistant();
public slots:
    void on_action_Exit_triggered (bool triggered);

private:
    Ui::KDesktopPersonalAsistantClass ui;
};

#endif // KDESKTOPPERSONALASISTANT_H
