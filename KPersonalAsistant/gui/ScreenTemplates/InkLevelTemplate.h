/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   InkLevelTemplate.h
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

#ifndef INKLEVELSCREEN_MOC_H_
#define INKLEVELSCREEN_MOC_H_

#include "ui_InkLevelScreen.h"
#include "ScreenTemplate.h"
#include "InkLevel.h"

#include <QtCore/QObject>
#include <QtGui/QWidget>
#include <QtGui/QApplication>

#include <QtCore/QString>

#include <vector>
#include <cstdlib>

using namespace Ui;

/**
 * Defines a ink level template
 */
class InkLevelTemplate : public QWidget, protected Ui::InkLevelScreen, public ScreenTemplate
{
    Q_OBJECT
public:

    /**
     * Generic constructor
     *
     * @param *parent
     */
    InkLevelTemplate(QWidget *parent = 0);

    /**
     * Class destructor
     */
    ~InkLevelTemplate();

    /**
     * Puts in screen template a window title.
     *
     * @param &_windowTitle
     */
    void setWindowTitle(const std::string &_windowTitle_);

    /**
     * Shows the screen template in front panel.
     */
    void show();

    /**
     * Removes all components which are in screen template.
     *
     * @return bool
     */
    bool clear();

    /**
     * By means of this methos you will be able to insert a new ink value.
     *
     * @param _color
     * @param _percent
     */
    void addInkLevel(const QString _color, int32_t _percent);

public slots:

signals:

private:

};

#endif /*INKLEVELSCREEN_MOC_H_*/
