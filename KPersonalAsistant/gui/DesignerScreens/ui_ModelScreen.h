/********************************************************************************
** Form generated from reading ui file 'ModelScreen.ui'
**
** Created: Fri 21. Nov 11:31:21 2008
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MODELSCREEN_H
#define UI_MODELSCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_window
{
public:
    QVBoxLayout *vboxLayout;

    void setupUi(QWidget *window)
    {
    if (window->objectName().isEmpty())
        window->setObjectName(QString::fromUtf8("window"));
    vboxLayout = new QVBoxLayout(window);
    vboxLayout->setSpacing(0);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    vboxLayout->setContentsMargins(0, 0, 0, 0);

    retranslateUi(window);

    QMetaObject::connectSlotsByName(window);
    } // setupUi

    void retranslateUi(QWidget *window)
    {
    window->setWindowTitle(QApplication::translate("window", "NULL", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(window);
    } // retranslateUi

};

namespace Ui {
    class window: public Ui_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODELSCREEN_H
