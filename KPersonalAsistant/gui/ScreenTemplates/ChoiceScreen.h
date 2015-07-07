/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ChoiceScreen.h
 *  @author Eduard Garcia Castello
 *  @date   Wed May 23 17:29:11 CEST 2007
 *  @brief  
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////

#ifndef CHOICESCREEN_H_
#define CHOICESCREEN_H_

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "WidgetScroll.h"
#include "ScreenTitle.h"

class Ui_ChoiceScreen
{
public:
  QVBoxLayout *vboxLayout;
  QVBoxLayout *vboxLayout1;
  ScreenTitle *screentitle;
  WidgetScroll *widgetscroll;

  void setupUi(QWidget *window)
  {
    if (window->objectName().isEmpty())
      window->setObjectName(QString::fromUtf8("window"));
    window->resize(WIDGET_WIDTH, WIDGET_HEIGHT);
    window->setMinimumSize(QSize(WIDGET_WIDTH, WIDGET_HEIGHT));
    window->setMaximumSize(QSize(WIDGET_WIDTH, WIDGET_HEIGHT));
    vboxLayout = new QVBoxLayout(window);
    vboxLayout->setSpacing(0);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    vboxLayout->setContentsMargins(0, 0, 0, 0);
    vboxLayout1 = new QVBoxLayout();
    vboxLayout1->setSpacing(0);
    vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
    vboxLayout1->setContentsMargins(-1, -1, -1, 0);
    
    screentitle = new ScreenTitle(window);
    screentitle->setObjectName(QString::fromUtf8("screentitle"));
    screentitle->setMinimumSize(QSize(TITLE_WIDTH, TITLE_HEIGHT));
    screentitle->setMaximumSize(QSize(TITLE_WIDTH, TITLE_HEIGHT));

    vboxLayout1->addWidget(screentitle);

    vboxLayout->addLayout(vboxLayout1);

    widgetscroll = new WidgetScroll(window);
    widgetscroll->setObjectName(QString::fromUtf8("widgetscroll"));

    vboxLayout->addWidget(widgetscroll);

    retranslateUi(window);

    QMetaObject::connectSlotsByName(window);
  } // setupUi

  void retranslateUi(QWidget *window)
  {
    window->setWindowTitle(QApplication::translate("window", "NULL", 0,
        QApplication::UnicodeUTF8));
    Q_UNUSED(window);
  } // retranslateUi

};

namespace Ui {
class ChoiceScreen : public Ui_ChoiceScreen
{
};
} // namespace Ui

#endif // UI_FULL_SCREEN_OPTION_H
