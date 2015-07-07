/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ProgressBarTemplate.h
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

#ifndef PROGRESSBAR_MOC_H_
#define PROGRESSBAR_MOC_H_

#include "ui_ProgressBarScreen.h"
#include "ScreenTemplate.h"

#include <QtCore/QObject>
#include <QtGui/QWidget>
#include <QtGui/QApplication>

#include <QtCore/QString>

using namespace Ui;

/**
 * Defines a progress bar template
 */
class ProgressBarTemplate : public QWidget, protected Ui::ProgressBarScreen, public ScreenTemplate
{
    Q_OBJECT
public:

    /**
     * Generic constructor
     *
     * @param *parent
     */
    ProgressBarTemplate(QWidget *parent = 0);

    /**
     * Class destructor
     */
    ~ProgressBarTemplate();

    /**
     * Puts in screen template a window title.
     *
     * @param &_windowTitle
     */
    void setWindowTitle(const std::string &_windowTitle);

    /**
     * Defines a progress bar title
     *
     * @param &_progressBarTiele
     */
    void setProgressBarTitle(const std::string &_progressBarTitle);

    /**
     * Defines a minimum range value
     */
    void setMinimumRange(int32_t _minRange);

    /**
     * Defines a maximum range value
     */
    void setMaximumRange(int32_t _maxRange);

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

public slots:

    /**
     * Moves the progress bar value to value passed through parameter
     *
     * @param _progressValue
     */
    bool changeProgressValue(int32_t _progressValue);

private:

};

#endif /*PROGRESSBAR_MOC_H_*/

