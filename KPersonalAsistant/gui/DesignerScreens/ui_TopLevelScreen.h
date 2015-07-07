/********************************************************************************
** Form generated from reading ui file 'TopLevelScreen.ui'
**
** Created: Fri 21. Nov 11:31:21 2008
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_TOPLEVELSCREEN_H
#define UI_TOPLEVELSCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "ScreenTitle.h"

QT_BEGIN_NAMESPACE

class Ui_TopLevelScreen
{
public:
    QVBoxLayout *vboxLayout;
    ScreenTitle *screentitle;
    QVBoxLayout *vboxLayout1;
    QLabel *printerUrl;
    QLabel *printer_IPv4;
    QHBoxLayout *hboxLayout;
    QPushButton *pushButton;
    QLabel *textToMenu;
    QLabel *manufacturerLogo;

    void setupUi(QWidget *TopLevelScreen)
    {
    if (TopLevelScreen->objectName().isEmpty())
        TopLevelScreen->setObjectName(QString::fromUtf8("TopLevelScreen"));
    TopLevelScreen->resize(506, 340);
    vboxLayout = new QVBoxLayout(TopLevelScreen);
    vboxLayout->setSpacing(0);
    vboxLayout->setMargin(0);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    screentitle = new ScreenTitle(TopLevelScreen);
    screentitle->setObjectName(QString::fromUtf8("screentitle"));
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(screentitle->sizePolicy().hasHeightForWidth());
    screentitle->setSizePolicy(sizePolicy);

    vboxLayout->addWidget(screentitle);

    vboxLayout1 = new QVBoxLayout();
    vboxLayout1->setSpacing(0);
    vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
    printerUrl = new QLabel(TopLevelScreen);
    printerUrl->setObjectName(QString::fromUtf8("printerUrl"));
    printerUrl->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

    vboxLayout1->addWidget(printerUrl);

    printer_IPv4 = new QLabel(TopLevelScreen);
    printer_IPv4->setObjectName(QString::fromUtf8("printer_IPv4"));
    printer_IPv4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

    vboxLayout1->addWidget(printer_IPv4);

    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    pushButton = new QPushButton(TopLevelScreen);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));
    pushButton->setMaximumSize(QSize(1, 1));

    hboxLayout->addWidget(pushButton);

    textToMenu = new QLabel(TopLevelScreen);
    textToMenu->setObjectName(QString::fromUtf8("textToMenu"));
    textToMenu->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

    hboxLayout->addWidget(textToMenu);

    manufacturerLogo = new QLabel(TopLevelScreen);
    manufacturerLogo->setObjectName(QString::fromUtf8("manufacturerLogo"));
    manufacturerLogo->setMaximumSize(QSize(62, 75));
    manufacturerLogo->setPixmap(QPixmap(QString::fromUtf8("../../../../../local/CProjects/Samson/resources/hp_logo.bmp")));
    manufacturerLogo->setScaledContents(true);
    manufacturerLogo->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
    manufacturerLogo->setWordWrap(true);
    manufacturerLogo->setIndent(-3);

    hboxLayout->addWidget(manufacturerLogo);


    vboxLayout1->addLayout(hboxLayout);


    vboxLayout->addLayout(vboxLayout1);


    retranslateUi(TopLevelScreen);

    QMetaObject::connectSlotsByName(TopLevelScreen);
    } // setupUi

    void retranslateUi(QWidget *TopLevelScreen)
    {
    TopLevelScreen->setWindowTitle(QApplication::translate("TopLevelScreen", "NULL", 0, QApplication::UnicodeUTF8));
    printerUrl->setText(QApplication::translate("TopLevelScreen", "http://NPI0040CA990285.test.com", 0, QApplication::UnicodeUTF8));
    printer_IPv4->setText(QApplication::translate("TopLevelScreen", "http://16.23.86.65", 0, QApplication::UnicodeUTF8));
    pushButton->setText(QApplication::translate("TopLevelScreen", "PushButton", 0, QApplication::UnicodeUTF8));
    textToMenu->setText(QApplication::translate("TopLevelScreen", "Press # to enter menu...", 0, QApplication::UnicodeUTF8));
    manufacturerLogo->setText(QString());
    Q_UNUSED(TopLevelScreen);
    } // retranslateUi

};

namespace Ui {
    class TopLevelScreen: public Ui_TopLevelScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOPLEVELSCREEN_H
