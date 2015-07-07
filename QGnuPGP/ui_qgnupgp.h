/********************************************************************************
** Form generated from reading ui file 'qgnupgp.ui'
**
** Created: Tue 30. Jun 16:08:16 2009
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_QGNUPGP_H
#define UI_QGNUPGP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QGnuPGPClass
{
public:

    void setupUi(QWidget *QGnuPGPClass)
    {
    if (QGnuPGPClass->objectName().isEmpty())
        QGnuPGPClass->setObjectName(QString::fromUtf8("QGnuPGPClass"));
    QGnuPGPClass->setWindowModality(Qt::NonModal);
    QGnuPGPClass->resize(546, 439);

    retranslateUi(QGnuPGPClass);

    QMetaObject::connectSlotsByName(QGnuPGPClass);
    } // setupUi

    void retranslateUi(QWidget *QGnuPGPClass)
    {
    QGnuPGPClass->setWindowTitle(QApplication::translate("QGnuPGPClass", "QGnuPGP", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(QGnuPGPClass);
    } // retranslateUi

};

namespace Ui {
    class QGnuPGPClass: public Ui_QGnuPGPClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGNUPGP_H
