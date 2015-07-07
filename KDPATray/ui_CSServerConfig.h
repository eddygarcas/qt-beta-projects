/********************************************************************************
** Form generated from reading ui file 'CSServerConfig.ui'
**
** Created: Fri 21. Nov 11:32:59 2008
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_CSSERVERCONFIG_H
#define UI_CSSERVERCONFIG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CSServerConfig
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QSpinBox *initialValue_4;
    QSpinBox *initialValue_3;
    QSpinBox *initialValue_2;
    QSpinBox *initialValue;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_6;
    QSpinBox *finalValue;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QSpinBox *interval;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QWidget *CSServerConfig)
    {
    if (CSServerConfig->objectName().isEmpty())
        CSServerConfig->setObjectName(QString::fromUtf8("CSServerConfig"));
    CSServerConfig->resize(297, 186);
    verticalLayout_2 = new QVBoxLayout(CSServerConfig);
    verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
    groupBox_2 = new QGroupBox(CSServerConfig);
    groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
    gridLayout = new QGridLayout(groupBox_2);
#ifndef Q_OS_MAC
    gridLayout->setMargin(9);
#endif
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    gridLayout->setHorizontalSpacing(0);
    gridLayout->setVerticalSpacing(6);
    label_3 = new QLabel(groupBox_2);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    gridLayout->addWidget(label_3, 0, 0, 1, 1);

    initialValue_4 = new QSpinBox(groupBox_2);
    initialValue_4->setObjectName(QString::fromUtf8("initialValue_4"));
    QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(initialValue_4->sizePolicy().hasHeightForWidth());
    initialValue_4->setSizePolicy(sizePolicy);
    initialValue_4->setMouseTracking(true);
    initialValue_4->setFrame(false);
    initialValue_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
    initialValue_4->setReadOnly(false);
    initialValue_4->setAccelerated(true);
    initialValue_4->setMinimum(1);
    initialValue_4->setMaximum(255);

    gridLayout->addWidget(initialValue_4, 0, 1, 1, 1);

    initialValue_3 = new QSpinBox(groupBox_2);
    initialValue_3->setObjectName(QString::fromUtf8("initialValue_3"));
    sizePolicy.setHeightForWidth(initialValue_3->sizePolicy().hasHeightForWidth());
    initialValue_3->setSizePolicy(sizePolicy);
    initialValue_3->setMouseTracking(true);
    initialValue_3->setFrame(false);
    initialValue_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
    initialValue_3->setReadOnly(false);
    initialValue_3->setAccelerated(true);
    initialValue_3->setMinimum(1);
    initialValue_3->setMaximum(255);

    gridLayout->addWidget(initialValue_3, 0, 2, 1, 1);

    initialValue_2 = new QSpinBox(groupBox_2);
    initialValue_2->setObjectName(QString::fromUtf8("initialValue_2"));
    sizePolicy.setHeightForWidth(initialValue_2->sizePolicy().hasHeightForWidth());
    initialValue_2->setSizePolicy(sizePolicy);
    initialValue_2->setMouseTracking(true);
    initialValue_2->setFrame(false);
    initialValue_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
    initialValue_2->setReadOnly(false);
    initialValue_2->setAccelerated(true);
    initialValue_2->setMinimum(1);
    initialValue_2->setMaximum(255);

    gridLayout->addWidget(initialValue_2, 0, 3, 1, 1);

    initialValue = new QSpinBox(groupBox_2);
    initialValue->setObjectName(QString::fromUtf8("initialValue"));
    sizePolicy.setHeightForWidth(initialValue->sizePolicy().hasHeightForWidth());
    initialValue->setSizePolicy(sizePolicy);
    initialValue->setMouseTracking(true);
    initialValue->setFrame(false);
    initialValue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
    initialValue->setReadOnly(false);
    initialValue->setAccelerated(true);
    initialValue->setMinimum(1);
    initialValue->setMaximum(255);

    gridLayout->addWidget(initialValue, 0, 4, 1, 1);

    label_4 = new QLabel(groupBox_2);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    gridLayout->addWidget(label_4, 1, 0, 1, 1);

    label_2 = new QLabel(groupBox_2);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setScaledContents(false);
    label_2->setAlignment(Qt::AlignCenter);
    label_2->setMargin(0);

    gridLayout->addWidget(label_2, 1, 1, 1, 1);

    label_5 = new QLabel(groupBox_2);
    label_5->setObjectName(QString::fromUtf8("label_5"));
    label_5->setAlignment(Qt::AlignCenter);

    gridLayout->addWidget(label_5, 1, 2, 1, 1);

    label_6 = new QLabel(groupBox_2);
    label_6->setObjectName(QString::fromUtf8("label_6"));
    label_6->setAlignment(Qt::AlignCenter);

    gridLayout->addWidget(label_6, 1, 3, 1, 1);

    finalValue = new QSpinBox(groupBox_2);
    finalValue->setObjectName(QString::fromUtf8("finalValue"));
    finalValue->setMouseTracking(true);
    finalValue->setFrame(false);
    finalValue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
    finalValue->setReadOnly(false);
    finalValue->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
    finalValue->setAccelerated(true);
    finalValue->setMinimum(1);
    finalValue->setMaximum(255);

    gridLayout->addWidget(finalValue, 1, 4, 1, 1);


    verticalLayout_2->addWidget(groupBox_2);

    groupBox = new QGroupBox(CSServerConfig);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    horizontalLayout = new QHBoxLayout(groupBox);
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    label = new QLabel(groupBox);
    label->setObjectName(QString::fromUtf8("label"));

    horizontalLayout->addWidget(label);

    horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout->addItem(horizontalSpacer_2);

    interval = new QSpinBox(groupBox);
    interval->setObjectName(QString::fromUtf8("interval"));
    interval->setMinimum(1);
    interval->setMaximum(30);

    horizontalLayout->addWidget(interval);

    label->raise();
    interval->raise();
    groupBox_2->raise();

    verticalLayout_2->addWidget(groupBox);

    horizontalLayout_4 = new QHBoxLayout();
    horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
    horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout_4->addItem(horizontalSpacer);

    pushButton = new QPushButton(CSServerConfig);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));

    horizontalLayout_4->addWidget(pushButton);


    verticalLayout_2->addLayout(horizontalLayout_4);


    retranslateUi(CSServerConfig);
    QObject::connect(initialValue, SIGNAL(valueChanged(int)), finalValue, SLOT(setValue(int)));
    QObject::connect(initialValue, SIGNAL(valueChanged(int)), CSServerConfig, SLOT(publishInitalIP(int)));
    QObject::connect(finalValue, SIGNAL(valueChanged(int)), CSServerConfig, SLOT(publishFinalIP(int)));
    QObject::connect(interval, SIGNAL(valueChanged(int)), CSServerConfig, SLOT(publishPingInterval(int)));
    QObject::connect(pushButton, SIGNAL(clicked()), CSServerConfig, SLOT(configEnds()));
    QObject::connect(initialValue_4, SIGNAL(valueChanged(int)), label_2, SLOT(setNum(int)));
    QObject::connect(initialValue_3, SIGNAL(valueChanged(int)), label_5, SLOT(setNum(int)));
    QObject::connect(initialValue_2, SIGNAL(valueChanged(int)), label_6, SLOT(setNum(int)));

    QMetaObject::connectSlotsByName(CSServerConfig);
    } // setupUi

    void retranslateUi(QWidget *CSServerConfig)
    {
    CSServerConfig->setWindowTitle(QApplication::translate("CSServerConfig", "Form", 0, QApplication::UnicodeUTF8));
    groupBox_2->setTitle(QApplication::translate("CSServerConfig", "Server range IP", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("CSServerConfig", "Inicial IP address: ", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    initialValue_4->setToolTip(QApplication::translate("CSServerConfig", "Initial IP", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP


#ifndef QT_NO_TOOLTIP
    initialValue_3->setToolTip(QApplication::translate("CSServerConfig", "Initial IP", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP


#ifndef QT_NO_TOOLTIP
    initialValue_2->setToolTip(QApplication::translate("CSServerConfig", "Initial IP", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP


#ifndef QT_NO_TOOLTIP
    initialValue->setToolTip(QApplication::translate("CSServerConfig", "Initial IP", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP

    label_4->setText(QApplication::translate("CSServerConfig", "Final IP address:   ", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("CSServerConfig", "1", 0, QApplication::UnicodeUTF8));
    label_5->setText(QApplication::translate("CSServerConfig", "1", 0, QApplication::UnicodeUTF8));
    label_6->setText(QApplication::translate("CSServerConfig", "1", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    finalValue->setToolTip(QApplication::translate("CSServerConfig", "Final IP", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP

    groupBox->setTitle(QApplication::translate("CSServerConfig", "Ping options", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("CSServerConfig", "Time internal ping (min.): ", 0, QApplication::UnicodeUTF8));
    pushButton->setText(QApplication::translate("CSServerConfig", "&Start", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(CSServerConfig);
    } // retranslateUi

};

namespace Ui {
    class CSServerConfig: public Ui_CSServerConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSSERVERCONFIG_H
