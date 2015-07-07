/********************************************************************************
** Form generated from reading ui file 'StatusbarPlugin.ui'
**
** Created: Fri 21. Nov 11:31:21 2008
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_STATUSBARPLUGIN_H
#define UI_STATUSBARPLUGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QVBoxLayout *vboxLayout;
    QFrame *statusBar;
    QVBoxLayout *vboxLayout1;
    QLabel *status_text;

    void setupUi(QWidget *Form)
    {
    if (Form->objectName().isEmpty())
        Form->setObjectName(QString::fromUtf8("Form"));
    Form->resize(53, 18);
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(Form->sizePolicy().hasHeightForWidth());
    Form->setSizePolicy(sizePolicy);
    Form->setLayoutDirection(Qt::RightToLeft);
    vboxLayout = new QVBoxLayout(Form);
    vboxLayout->setSpacing(0);
    vboxLayout->setMargin(0);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    statusBar = new QFrame(Form);
    statusBar->setObjectName(QString::fromUtf8("statusBar"));
    QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(statusBar->sizePolicy().hasHeightForWidth());
    statusBar->setSizePolicy(sizePolicy1);
    statusBar->setLayoutDirection(Qt::LeftToRight);
    statusBar->setFrameShape(QFrame::Box);
    statusBar->setFrameShadow(QFrame::Raised);
    vboxLayout1 = new QVBoxLayout(statusBar);
    vboxLayout1->setSpacing(0);
    vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
    vboxLayout1->setContentsMargins(2, 0, 0, 0);
    status_text = new QLabel(statusBar);
    status_text->setObjectName(QString::fromUtf8("status_text"));
    sizePolicy1.setHeightForWidth(status_text->sizePolicy().hasHeightForWidth());
    status_text->setSizePolicy(sizePolicy1);
    status_text->setAutoFillBackground(false);
    status_text->setScaledContents(false);

    vboxLayout1->addWidget(status_text);


    vboxLayout->addWidget(statusBar);


    retranslateUi(Form);

    QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
    Form->setWindowTitle(QApplication::translate("Form", "Form", 0, QApplication::UnicodeUTF8));
    status_text->setText(QApplication::translate("Form", "StatusBar", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Form);
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATUSBARPLUGIN_H
