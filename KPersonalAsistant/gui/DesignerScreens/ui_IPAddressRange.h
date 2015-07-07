/********************************************************************************
** Form generated from reading ui file 'IPAddressRange.ui'
**
** Created: Fri 21. Nov 11:31:22 2008
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_IPADDRESSRANGE_H
#define UI_IPADDRESSRANGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IPAddressRange
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *finalLabelIP;
    QSpinBox *initialValue;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLabel *startLabelIP;
    QSpinBox *finalValue;

    void setupUi(QWidget *IPAddressRange)
    {
    if (IPAddressRange->objectName().isEmpty())
        IPAddressRange->setObjectName(QString::fromUtf8("IPAddressRange"));
    IPAddressRange->resize(226, 96);
    verticalLayout_2 = new QVBoxLayout(IPAddressRange);
    verticalLayout_2->setSpacing(0);
    verticalLayout_2->setMargin(0);
    verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
    groupBox = new QGroupBox(IPAddressRange);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    verticalLayout = new QVBoxLayout(groupBox);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setSpacing(0);
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    label_3 = new QLabel(groupBox);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    horizontalLayout->addWidget(label_3);

    finalLabelIP = new QLabel(groupBox);
    finalLabelIP->setObjectName(QString::fromUtf8("finalLabelIP"));
    finalLabelIP->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    horizontalLayout->addWidget(finalLabelIP);

    initialValue = new QSpinBox(groupBox);
    initialValue->setObjectName(QString::fromUtf8("initialValue"));
    QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(initialValue->sizePolicy().hasHeightForWidth());
    initialValue->setSizePolicy(sizePolicy);
    initialValue->setMouseTracking(true);
    initialValue->setFrame(false);
    initialValue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
    initialValue->setReadOnly(false);
    initialValue->setAccelerated(true);
    initialValue->setMaximum(255);

    horizontalLayout->addWidget(initialValue);


    verticalLayout->addLayout(horizontalLayout);

    horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setSpacing(0);
    horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
    label_4 = new QLabel(groupBox);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    horizontalLayout_2->addWidget(label_4);

    startLabelIP = new QLabel(groupBox);
    startLabelIP->setObjectName(QString::fromUtf8("startLabelIP"));
    startLabelIP->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    horizontalLayout_2->addWidget(startLabelIP);

    finalValue = new QSpinBox(groupBox);
    finalValue->setObjectName(QString::fromUtf8("finalValue"));
    finalValue->setMouseTracking(true);
    finalValue->setFrame(false);
    finalValue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
    finalValue->setReadOnly(false);
    finalValue->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
    finalValue->setAccelerated(true);
    finalValue->setMaximum(255);

    horizontalLayout_2->addWidget(finalValue);


    verticalLayout->addLayout(horizontalLayout_2);


    verticalLayout_2->addWidget(groupBox);


    retranslateUi(IPAddressRange);
    QObject::connect(initialValue, SIGNAL(valueChanged(int)), finalValue, SLOT(setValue(int)));
    QObject::connect(initialValue, SIGNAL(valueChanged(int)), IPAddressRange, SLOT(publishInicialAddress(int)));
    QObject::connect(finalValue, SIGNAL(valueChanged(int)), IPAddressRange, SLOT(publishFinalAddress(int)));

    QMetaObject::connectSlotsByName(IPAddressRange);
    } // setupUi

    void retranslateUi(QWidget *IPAddressRange)
    {
    IPAddressRange->setWindowTitle(QApplication::translate("IPAddressRange", "Form", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("IPAddressRange", "Server range IP", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("IPAddressRange", "Inicial IP address: ", 0, QApplication::UnicodeUTF8));
    finalLabelIP->setText(QApplication::translate("IPAddressRange", "192.168.2.", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    initialValue->setToolTip(QApplication::translate("IPAddressRange", "Initial IP", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP

    label_4->setText(QApplication::translate("IPAddressRange", "Final IP address:   ", 0, QApplication::UnicodeUTF8));
    startLabelIP->setText(QApplication::translate("IPAddressRange", "192.168.2.", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    finalValue->setToolTip(QApplication::translate("IPAddressRange", "Final IP", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP

    Q_UNUSED(IPAddressRange);
    } // retranslateUi

};

namespace Ui {
    class IPAddressRange: public Ui_IPAddressRange {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IPADDRESSRANGE_H
