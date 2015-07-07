/********************************************************************************
** Form generated from reading ui file 'kdesktoppersonalasistant.ui'
**
** Created: Mon 3. Nov 17:04:53 2008
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_KDESKTOPPERSONALASISTANT_H
#define UI_KDESKTOPPERSONALASISTANT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "GuiController.h"

QT_BEGIN_NAMESPACE

class Ui_KDesktopPersonalAsistantClass
{
public:
    QAction *action_Exit;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QMenuBar *menubar;
    QMenu *menu_Exit;
    QMenu *menuHelp;
    QStatusBar *statusbar;
    GuiController *controller;

    void setupUi(QMainWindow *KDesktopPersonalAsistantClass)
    {
    if (KDesktopPersonalAsistantClass->objectName().isEmpty())
        KDesktopPersonalAsistantClass->setObjectName(QString::fromUtf8("KDesktopPersonalAsistantClass"));
    KDesktopPersonalAsistantClass->resize(321, 260);
    action_Exit = new QAction(KDesktopPersonalAsistantClass);
    action_Exit->setObjectName(QString::fromUtf8("action_Exit"));
    centralwidget = new QWidget(KDesktopPersonalAsistantClass);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    gridLayout = new QGridLayout(centralwidget);
    gridLayout->setSpacing(0);
    gridLayout->setMargin(0);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    verticalLayout = new QVBoxLayout();
    verticalLayout->setSpacing(0);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    verticalLayout->setSizeConstraint(QLayout::SetNoConstraint);

    controller = &GuiController::instance(KDesktopPersonalAsistantClass);
    verticalLayout->addWidget(controller);
    controller->start();
    gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

    KDesktopPersonalAsistantClass->setCentralWidget(centralwidget);
    menubar = new QMenuBar(KDesktopPersonalAsistantClass);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 321, 19));
    menu_Exit = new QMenu(menubar);
    menu_Exit->setObjectName(QString::fromUtf8("menu_Exit"));
    menu_Exit->setTearOffEnabled(true);
    menuHelp = new QMenu(menubar);
    menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
    KDesktopPersonalAsistantClass->setMenuBar(menubar);
    statusbar = new QStatusBar(KDesktopPersonalAsistantClass);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    KDesktopPersonalAsistantClass->setStatusBar(statusbar);

    menubar->addAction(menu_Exit->menuAction());
    menubar->addAction(menuHelp->menuAction());
    menu_Exit->addAction(action_Exit);

    retranslateUi(KDesktopPersonalAsistantClass);

    QMetaObject::connectSlotsByName(KDesktopPersonalAsistantClass);
    } // setupUi

    void retranslateUi(QMainWindow *KDesktopPersonalAsistantClass)
    {
    KDesktopPersonalAsistantClass->setWindowTitle(QApplication::translate("KDesktopPersonalAsistantClass", "MainWindow", 0, QApplication::UnicodeUTF8));
    action_Exit->setText(QApplication::translate("KDesktopPersonalAsistantClass", "&Exit", 0, QApplication::UnicodeUTF8));
    menu_Exit->setTitle(QApplication::translate("KDesktopPersonalAsistantClass", "&Program", "Program exit", QApplication::UnicodeUTF8));
    menuHelp->setTitle(QApplication::translate("KDesktopPersonalAsistantClass", "&Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class KDesktopPersonalAsistantClass: public Ui_KDesktopPersonalAsistantClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KDESKTOPPERSONALASISTANT_H
