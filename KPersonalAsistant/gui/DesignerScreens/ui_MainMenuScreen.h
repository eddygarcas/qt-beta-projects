/********************************************************************************
** Form generated from reading ui file 'MainMenuScreen.ui'
**
** Created: Fri 21. Nov 11:31:21 2008
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINMENUSCREEN_H
#define UI_MAINMENUSCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "ScreenTitle.h"
#include "StatusBar.h"

QT_BEGIN_NAMESPACE

class Ui_MainMenuScreen
{
public:
    QVBoxLayout *vboxLayout;
    ScreenTitle *screentitle;
    QGridLayout *gridLayout;
    StatusBar *statusbar;

    void setupUi(QWidget *MainMenuScreen)
    {
    if (MainMenuScreen->objectName().isEmpty())
        MainMenuScreen->setObjectName(QString::fromUtf8("MainMenuScreen"));
    MainMenuScreen->resize(249, 196);
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(MainMenuScreen->sizePolicy().hasHeightForWidth());
    MainMenuScreen->setSizePolicy(sizePolicy);
    vboxLayout = new QVBoxLayout(MainMenuScreen);
    vboxLayout->setSpacing(0);
    vboxLayout->setMargin(0);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    screentitle = new ScreenTitle(MainMenuScreen);
    screentitle->setObjectName(QString::fromUtf8("screentitle"));

    vboxLayout->addWidget(screentitle);

    gridLayout = new QGridLayout();
    gridLayout->setSpacing(6);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

    vboxLayout->addLayout(gridLayout);

    statusbar = new StatusBar(MainMenuScreen);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));

    vboxLayout->addWidget(statusbar);


    retranslateUi(MainMenuScreen);

    QMetaObject::connectSlotsByName(MainMenuScreen);
    } // setupUi

    void retranslateUi(QWidget *MainMenuScreen)
    {
    MainMenuScreen->setWindowTitle(QApplication::translate("MainMenuScreen", "NULL", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(MainMenuScreen);
    } // retranslateUi

};

namespace Ui {
    class MainMenuScreen: public Ui_MainMenuScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENUSCREEN_H
