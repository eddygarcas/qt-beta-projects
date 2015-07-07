/********************************************************************************
** Form generated from reading ui file 'TextListScreen.ui'
**
** Created: Fri 21. Nov 11:31:21 2008
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_TEXTLISTSCREEN_H
#define UI_TEXTLISTSCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "ScreenTitle.h"
#include "WidgetScroll.h"

QT_BEGIN_NAMESPACE

class Ui_TextListScreen
{
public:
    QVBoxLayout *vboxLayout;
    ScreenTitle *screentitle;
    WidgetScroll *widgetscroll;

    void setupUi(QWidget *TextListScreen)
    {
    if (TextListScreen->objectName().isEmpty())
        TextListScreen->setObjectName(QString::fromUtf8("TextListScreen"));
    TextListScreen->resize(240, 150);
    vboxLayout = new QVBoxLayout(TextListScreen);
    vboxLayout->setSpacing(0);
    vboxLayout->setMargin(0);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    screentitle = new ScreenTitle(TextListScreen);
    screentitle->setObjectName(QString::fromUtf8("screentitle"));
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(screentitle->sizePolicy().hasHeightForWidth());
    screentitle->setSizePolicy(sizePolicy);

    vboxLayout->addWidget(screentitle);

    widgetscroll = new WidgetScroll(TextListScreen);
    widgetscroll->setObjectName(QString::fromUtf8("widgetscroll"));
    QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(widgetscroll->sizePolicy().hasHeightForWidth());
    widgetscroll->setSizePolicy(sizePolicy1);
    widgetscroll->setMinimumSize(QSize(240, 140));

    vboxLayout->addWidget(widgetscroll);


    retranslateUi(TextListScreen);

    QMetaObject::connectSlotsByName(TextListScreen);
    } // setupUi

    void retranslateUi(QWidget *TextListScreen)
    {
    TextListScreen->setWindowTitle(QApplication::translate("TextListScreen", "NULL", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(TextListScreen);
    } // retranslateUi

};

namespace Ui {
    class TextListScreen: public Ui_TextListScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTLISTSCREEN_H
