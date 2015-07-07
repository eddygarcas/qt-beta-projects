#ifndef QGNUPGP_H
#define QGNUPGP_H

#include <QtGui/QWidget>
#include "ui_qgnupgp.h"

class QGnuPGP : public QWidget
{
    Q_OBJECT

public:
    QGnuPGP(QWidget *parent = 0);
    ~QGnuPGP();

private:
    Ui::QGnuPGPClass ui;
};

#endif // QGNUPGP_H
