/********************************************************************************
** Form generated from reading ui file 'IPAddressScreen.ui'
**
** Created: Fri 21. Nov 11:31:21 2008
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_IPADDRESSSCREEN_H
#define UI_IPADDRESSSCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "IPv4Address.h"
#include "ScreenTitle.h"
#include "notepadwidget.h"

QT_BEGIN_NAMESPACE

class Ui_IPv4AddressScreen
{
public:
    QVBoxLayout *vboxLayout;
    ScreenTitle *screentitle;
    IPv4Address *iplineeditwidget;
    NotepadWidget *textpadwidget;

    void setupUi(QWidget *IPv4AddressScreen)
    {
    if (IPv4AddressScreen->objectName().isEmpty())
        IPv4AddressScreen->setObjectName(QString::fromUtf8("IPv4AddressScreen"));
    IPv4AddressScreen->resize(333, 229);
    QPalette palette;
    QBrush brush(QColor(255, 255, 255, 255));
    brush.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Base, brush);
    palette.setBrush(QPalette::Active, QPalette::Window, brush);
    palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
    palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
    palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
    palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
    IPv4AddressScreen->setPalette(palette);
    vboxLayout = new QVBoxLayout(IPv4AddressScreen);
    vboxLayout->setSpacing(0);
    vboxLayout->setMargin(0);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    screentitle = new ScreenTitle(IPv4AddressScreen);
    screentitle->setObjectName(QString::fromUtf8("screentitle"));

    vboxLayout->addWidget(screentitle);

    iplineeditwidget = new IPv4Address(IPv4AddressScreen);
    iplineeditwidget->setObjectName(QString::fromUtf8("iplineeditwidget"));
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(iplineeditwidget->sizePolicy().hasHeightForWidth());
    iplineeditwidget->setSizePolicy(sizePolicy);
    QPalette palette1;
    iplineeditwidget->setPalette(palette1);

    vboxLayout->addWidget(iplineeditwidget);

    textpadwidget = new NotepadWidget(IPv4AddressScreen);
    textpadwidget->setObjectName(QString::fromUtf8("textpadwidget"));
    QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(textpadwidget->sizePolicy().hasHeightForWidth());
    textpadwidget->setSizePolicy(sizePolicy1);
    textpadwidget->setProperty("activeReturnKey", QVariant(false));
    textpadwidget->setProperty("autoHide", QVariant(false));

    vboxLayout->addWidget(textpadwidget);


    retranslateUi(IPv4AddressScreen);
    QObject::connect(textpadwidget, SIGNAL(sendCharacter(QChar)), iplineeditwidget, SLOT(append_ip_address_value(QChar)));
    QObject::connect(textpadwidget, SIGNAL(deletePreviousCharacter()), iplineeditwidget, SLOT(remove_last_ip_address_value()));
    QObject::connect(textpadwidget, SIGNAL(closeTextPad()), iplineeditwidget, SLOT(finished_edition()));

    QMetaObject::connectSlotsByName(IPv4AddressScreen);
    } // setupUi

    void retranslateUi(QWidget *IPv4AddressScreen)
    {
    IPv4AddressScreen->setWindowTitle(QApplication::translate("IPv4AddressScreen", "NULL", 0, QApplication::UnicodeUTF8));
    iplineeditwidget->setProperty("addressTextLavel", QVariant(QString()));
    textpadwidget->setProperty("wordArray", QVariant(QApplication::translate("IPv4AddressScreen", "1,2,3,4,5,6,7,8,9,0", 0, QApplication::UnicodeUTF8)));
    Q_UNUSED(IPv4AddressScreen);
    } // retranslateUi

};

namespace Ui {
    class IPv4AddressScreen: public Ui_IPv4AddressScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IPADDRESSSCREEN_H
