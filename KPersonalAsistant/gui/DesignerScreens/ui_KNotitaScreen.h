/********************************************************************************
** Form generated from reading ui file 'KNotitaScreen.ui'
**
** Created: Fri 21. Nov 11:31:22 2008
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_KNOTITASCREEN_H
#define UI_KNOTITASCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KNotaForm
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QWidget *KNotaForm)
    {
    if (KNotaForm->objectName().isEmpty())
        KNotaForm->setObjectName(QString::fromUtf8("KNotaForm"));
    KNotaForm->setWindowModality(Qt::NonModal);
    KNotaForm->resize(221, 218);
    QPalette palette;
    QBrush brush(QColor(0, 0, 0, 255));
    brush.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
    QBrush brush1(QColor(255, 170, 0, 255));
    brush1.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Button, brush1);
    QBrush brush2(QColor(234, 255, 0, 255));
    brush2.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Light, brush2);
    QBrush brush3(QColor(255, 204, 0, 255));
    brush3.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
    QBrush brush4(QColor(157, 105, 0, 255));
    brush4.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
    palette.setBrush(QPalette::Active, QPalette::Text, brush);
    palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    QBrush brush5(QColor(255, 255, 255, 255));
    brush5.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Base, brush5);
    QBrush brush6(QColor(255, 255, 0, 255));
    brush6.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Window, brush6);
    palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
    palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
    palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
    palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette.setBrush(QPalette::Inactive, QPalette::Base, brush5);
    palette.setBrush(QPalette::Inactive, QPalette::Window, brush6);
    palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
    palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
    palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
    palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
    palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
    palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
    palette.setBrush(QPalette::Disabled, QPalette::Base, brush6);
    palette.setBrush(QPalette::Disabled, QPalette::Window, brush6);
    KNotaForm->setPalette(palette);
    gridLayout = new QGridLayout(KNotaForm);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    verticalLayout = new QVBoxLayout();
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    plainTextEdit = new QPlainTextEdit(KNotaForm);
    plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
    plainTextEdit->setEnabled(true);
    QPalette palette1;
    palette1.setBrush(QPalette::Active, QPalette::BrightText, brush5);
    palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
    palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush5);
    palette1.setBrush(QPalette::Inactive, QPalette::Base, brush6);
    palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush5);
    palette1.setBrush(QPalette::Disabled, QPalette::Base, brush6);
    plainTextEdit->setPalette(palette1);
    plainTextEdit->setAutoFillBackground(true);
    plainTextEdit->setFrameShape(QFrame::NoFrame);
    plainTextEdit->setFrameShadow(QFrame::Plain);
    plainTextEdit->setLineWidth(0);
    plainTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    plainTextEdit->setLineWrapMode(QPlainTextEdit::WidgetWidth);
    plainTextEdit->setBackgroundVisible(false);

    verticalLayout->addWidget(plainTextEdit);


    gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


    retranslateUi(KNotaForm);

    QMetaObject::connectSlotsByName(KNotaForm);
    } // setupUi

    void retranslateUi(QWidget *KNotaForm)
    {
    KNotaForm->setWindowTitle(QApplication::translate("KNotaForm", "KNotita", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(KNotaForm);
    } // retranslateUi

};

namespace Ui {
    class KNotaForm: public Ui_KNotaForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KNOTITASCREEN_H
