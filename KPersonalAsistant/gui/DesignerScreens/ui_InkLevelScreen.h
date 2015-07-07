/********************************************************************************
** Form generated from reading ui file 'InkLevelScreen.ui'
**
** Created: Fri 21. Nov 11:31:21 2008
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_INKLEVELSCREEN_H
#define UI_INKLEVELSCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "ScreenTitle.h"

QT_BEGIN_NAMESPACE

class Ui_InkLevelScreen
{
public:
    QVBoxLayout *vboxLayout;
    ScreenTitle *screentitle;
    QHBoxLayout *hboxLayout;

    void setupUi(QWidget *InkLevelScreen)
    {
    if (InkLevelScreen->objectName().isEmpty())
        InkLevelScreen->setObjectName(QString::fromUtf8("InkLevelScreen"));
    InkLevelScreen->resize(388, 316);
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(InkLevelScreen->sizePolicy().hasHeightForWidth());
    InkLevelScreen->setSizePolicy(sizePolicy);
    vboxLayout = new QVBoxLayout(InkLevelScreen);
    vboxLayout->setSpacing(0);
    vboxLayout->setMargin(0);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    screentitle = new ScreenTitle(InkLevelScreen);
    screentitle->setObjectName(QString::fromUtf8("screentitle"));

    vboxLayout->addWidget(screentitle);

    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));

    vboxLayout->addLayout(hboxLayout);


    retranslateUi(InkLevelScreen);

    QMetaObject::connectSlotsByName(InkLevelScreen);
    } // setupUi

    void retranslateUi(QWidget *InkLevelScreen)
    {
    InkLevelScreen->setWindowTitle(QApplication::translate("InkLevelScreen", "NULL", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(InkLevelScreen);
    } // retranslateUi

};

namespace Ui {
    class InkLevelScreen: public Ui_InkLevelScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INKLEVELSCREEN_H
