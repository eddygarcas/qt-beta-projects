#ifndef ANIMATIONTEMPLATE_MOC_H_
#define ANIMATIONTEMPLATE_MOC_H_

/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   AnimationTemplate.h
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

#include "ui_AnimationScreen.h"
#include "ScreenTemplate.h"

#include <QtGui/QWidget>
#include <QtGui/QApplication>
#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QTimer>
#include <QtGui/QPixmap>

#include <vector>

using namespace Ui;

/**
 * Defines a animation template
 */
class AnimationTemplate : public QWidget, protected Ui::AnimationScreen, public ScreenTemplate
{
    Q_OBJECT
public:
    /**
     * Generic constructor
     *
     * @param *parent
     */
    AnimationTemplate(QWidget *parent = 0);

    /**
     * Class destructor
     */
    ~AnimationTemplate();

    /**
     * Puts in screen template a window title.
     *
     * @param &_windowTitle
     */
    void setWindowTitle(const std::string &_windowTitle);

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
     * You can add a animation pixmap array by means of this method.
     *
     * @param _pixmapArray[]
     */
    void addAnimation(QPixmap _pixmapArray[]);

    /**
     * You can add an individual pixmap by means of this method.
     * The pixmap passed through parameter will be added in internal array.
     *
     * @param _pixmap
     */
    void addAnimation(const QPixmap _pixmap);

    /**
     * By means of this method you will be able to define the animation interval time.
     */
    void time(int32_t _timeInMilis);

public slots:

    /**
     * It Jump to the next animation frame. This slot will be called when will elapse interval time.
     */
    void next_animation_frame();

    /**
     * Starts timer object
     */
    void start_timer_interval();

    /**
     * Stops timer object
     */
    void stop_timer_interval();

signals:

protected:

private:
    /**
     * Animation index
     */
    unsigned int animationIndex_;

    /**
     * Internal array of pixmaps
     */
    std::vector<QPixmap> animation_;

    /**
     * Timer object
     */
    QTimer *timer_;

};

#endif /*ANIMATIONTEMAPLATE_MOC_H_*/
