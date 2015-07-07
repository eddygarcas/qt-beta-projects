/********************************************************************************
** Form generated from reading ui file 'IntervalPingValue.ui'
**
** Created: Fri 21. Nov 11:31:22 2008
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_INTERVALPINGVALUE_H
#define UI_INTERVALPINGVALUE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InternalPingValue
{
public:
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *interval;

    void setupUi(QWidget *InternalPingValue)
    {
    if (InternalPingValue->objectName().isEmpty())
        InternalPingValue->setObjectName(QString::fromUtf8("InternalPingValue"));
    InternalPingValue->resize(208, 74);
    horizontalLayout_2 = new QHBoxLayout(InternalPingValue);
    horizontalLayout_2->setSpacing(0);
    horizontalLayout_2->setMargin(0);
    horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
    groupBox = new QGroupBox(InternalPingValue);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    horizontalLayout = new QHBoxLayout(groupBox);
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    label = new QLabel(groupBox);
    label->setObjectName(QString::fromUtf8("label"));

    horizontalLayout->addWidget(label);

    interval = new QSpinBox(groupBox);
    interval->setObjectName(QString::fromUtf8("interval"));
    interval->setMinimum(1);
    interval->setMaximum(30);

    horizontalLayout->addWidget(interval);


    horizontalLayout_2->addWidget(groupBox);


    retranslateUi(InternalPingValue);
    QObject::connect(interval, SIGNAL(valueChanged(int)), InternalPingValue, SLOT(publishPingInterval(int)));

    QMetaObject::connectSlotsByName(InternalPingValue);
    } // setupUi

    void retranslateUi(QWidget *InternalPingValue)
    {
    InternalPingValue->setWindowTitle(QApplication::translate("InternalPingValue", "Form", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("InternalPingValue", "Ping options", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("InternalPingValue", "Time internal ping (min.): ", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(InternalPingValue);
    } // retranslateUi

};

namespace Ui {
    class InternalPingValue: public Ui_InternalPingValue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERVALPINGVALUE_H
