/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   WindowMain.h
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

#ifndef TOPLEVELTEMPLATE_H_
#define TOPLEVELTEMPLATE_H_

#include "ui_TopLevelScreen.h"
#include "ScreenTemplate.h"

#include <QtCore/QObject>
#include <QtGui/QWidget>
#include <QtGui/QApplication>

#include <QtGui/QLabel>
#include <QtGui/QPixmap>
#include <QtGui/QKeyEvent>
#include <QtCore/QEvent>
#include <QtCore/QString>

using namespace Ui;

class TopLevelTemplate : public QWidget, protected Ui::TopLevelScreen, public ScreenTemplate
{
Q_OBJECT

public:

  TopLevelTemplate(QWidget *parent = 0);

  ~TopLevelTemplate();

  void setWindowTitle(const std::string &_windowTitle);

  void show();

  bool clear();

  void setPrinterUrl(const QString _printerUrl_);

  void setPrinterIPv4(const QString _printerIPv4_);

  void setManufacturerLogo(const QPixmap _manufacturerLogo_);

  void setTextToMenu(const QString _textToMenu_);

private:

};

#endif // TOPLEVELTEMPLATE_H_
