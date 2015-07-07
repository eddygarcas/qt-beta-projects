/********************************************************************************
** Form generated from reading ui file 'AnimationScreen.ui'
**
** Created: Fri 21. Nov 11:31:21 2008
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_ANIMATIONSCREEN_H
#define UI_ANIMATIONSCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "ScreenTitle.h"

QT_BEGIN_NAMESPACE

class Ui_AnimationScreen
{
public:
    QVBoxLayout *vboxLayout;
    ScreenTitle *screentitle;
    QLabel *animation;

    void setupUi(QWidget *AnimationScreen)
    {
    if (AnimationScreen->objectName().isEmpty())
        AnimationScreen->setObjectName(QString::fromUtf8("AnimationScreen"));
    AnimationScreen->resize(407, 312);
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(AnimationScreen->sizePolicy().hasHeightForWidth());
    AnimationScreen->setSizePolicy(sizePolicy);
    vboxLayout = new QVBoxLayout(AnimationScreen);
    vboxLayout->setSpacing(0);
    vboxLayout->setMargin(0);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    screentitle = new ScreenTitle(AnimationScreen);
    screentitle->setObjectName(QString::fromUtf8("screentitle"));

    vboxLayout->addWidget(screentitle);

    animation = new QLabel(AnimationScreen);
    animation->setObjectName(QString::fromUtf8("animation"));
    animation->setFrameShadow(QFrame::Plain);
    animation->setLineWidth(0);
    animation->setPixmap(QPixmap(QString::fromUtf8("../../../../../local/CProjects/Samson/resources/hp_logo.bmp")));
    animation->setScaledContents(false);
    animation->setAlignment(Qt::AlignCenter);

    vboxLayout->addWidget(animation);


    retranslateUi(AnimationScreen);

    QMetaObject::connectSlotsByName(AnimationScreen);
    } // setupUi

    void retranslateUi(QWidget *AnimationScreen)
    {
    AnimationScreen->setWindowTitle(QApplication::translate("AnimationScreen", "NULL", 0, QApplication::UnicodeUTF8));
    animation->setText(QString());
    Q_UNUSED(AnimationScreen);
    } // retranslateUi

};

namespace Ui {
    class AnimationScreen: public Ui_AnimationScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANIMATIONSCREEN_H
