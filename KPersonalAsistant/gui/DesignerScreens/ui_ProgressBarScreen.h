/********************************************************************************
** Form generated from reading ui file 'ProgressBarScreen.ui'
**
** Created: Fri 21. Nov 11:31:21 2008
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_PROGRESSBARSCREEN_H
#define UI_PROGRESSBARSCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "ScreenTitle.h"

QT_BEGIN_NAMESPACE

class Ui_ProgressBarScreen
{
public:
    QVBoxLayout *vboxLayout;
    ScreenTitle *screentitle;
    QVBoxLayout *vboxLayout1;
    QSpacerItem *spacerItem;
    QLabel *progressBarTitle;
    QProgressBar *progressBarElement;
    QSpacerItem *spacerItem1;

    void setupUi(QWidget *ProgressBarScreen)
    {
    if (ProgressBarScreen->objectName().isEmpty())
        ProgressBarScreen->setObjectName(QString::fromUtf8("ProgressBarScreen"));
    ProgressBarScreen->resize(58, 132);
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(ProgressBarScreen->sizePolicy().hasHeightForWidth());
    ProgressBarScreen->setSizePolicy(sizePolicy);
    vboxLayout = new QVBoxLayout(ProgressBarScreen);
    vboxLayout->setSpacing(0);
    vboxLayout->setMargin(0);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    screentitle = new ScreenTitle(ProgressBarScreen);
    screentitle->setObjectName(QString::fromUtf8("screentitle"));

    vboxLayout->addWidget(screentitle);

    vboxLayout1 = new QVBoxLayout();
    vboxLayout1->setSpacing(0);
    vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
    vboxLayout1->setContentsMargins(6, -1, 6, -1);
    spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    vboxLayout1->addItem(spacerItem);

    progressBarTitle = new QLabel(ProgressBarScreen);
    progressBarTitle->setObjectName(QString::fromUtf8("progressBarTitle"));
    progressBarTitle->setAlignment(Qt::AlignCenter);

    vboxLayout1->addWidget(progressBarTitle);

    progressBarElement = new QProgressBar(ProgressBarScreen);
    progressBarElement->setObjectName(QString::fromUtf8("progressBarElement"));
    progressBarElement->setMinimumSize(QSize(0, 16));
    progressBarElement->setMaximumSize(QSize(0, 16));
    progressBarElement->setValue(0);
    progressBarElement->setAlignment(Qt::AlignCenter);
    progressBarElement->setTextVisible(true);
    progressBarElement->setOrientation(Qt::Horizontal);
    progressBarElement->setInvertedAppearance(false);
    progressBarElement->setTextDirection(QProgressBar::TopToBottom);

    vboxLayout1->addWidget(progressBarElement);

    spacerItem1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    vboxLayout1->addItem(spacerItem1);


    vboxLayout->addLayout(vboxLayout1);


    retranslateUi(ProgressBarScreen);

    QMetaObject::connectSlotsByName(ProgressBarScreen);
    } // setupUi

    void retranslateUi(QWidget *ProgressBarScreen)
    {
    ProgressBarScreen->setWindowTitle(QApplication::translate("ProgressBarScreen", "NULL", 0, QApplication::UnicodeUTF8));
    progressBarTitle->setText(QApplication::translate("ProgressBarScreen", "TextLabel", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(ProgressBarScreen);
    } // retranslateUi

};

namespace Ui {
    class ProgressBarScreen: public Ui_ProgressBarScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRESSBARSCREEN_H
