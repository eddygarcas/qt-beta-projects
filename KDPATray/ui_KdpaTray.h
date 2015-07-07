/********************************************************************************
** Form generated from reading ui file 'KdpaTray.ui'
**
** Created: Fri 21. Nov 11:32:59 2008
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_KDPATRAY_H
#define UI_KDPATRAY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KDPATrayClass
{
public:

    void setupUi(QWidget *KDPATrayClass)
    {
    if (KDPATrayClass->objectName().isEmpty())
        KDPATrayClass->setObjectName(QString::fromUtf8("KDPATrayClass"));
    KDPATrayClass->resize(400, 300);

    retranslateUi(KDPATrayClass);

    QMetaObject::connectSlotsByName(KDPATrayClass);
    } // setupUi

    void retranslateUi(QWidget *KDPATrayClass)
    {
    KDPATrayClass->setWindowTitle(QApplication::translate("KDPATrayClass", "KDPATray", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(KDPATrayClass);
    } // retranslateUi

};

namespace Ui {
    class KDPATrayClass: public Ui_KDPATrayClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KDPATRAY_H
