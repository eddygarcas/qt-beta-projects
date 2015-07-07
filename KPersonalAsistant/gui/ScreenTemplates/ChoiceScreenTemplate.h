/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ChoiceScreenTemplate.h
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

#ifndef CHOICESCREENTEMPLATE_H_
#define CHOICESCREENTEMPLATE_H_

#include "FrontPanelEnum.h"
#include "ScreenTemplate.h"
#include "ChoiceScreen.h"

#include <QtGui/QWidget>
#include <QtGui/QApplication>
#include <QtCore/QObject>

#include <QtCore/QSize>

using namespace Ui;

/**
 * Defines a choice screen template
 */
class ChoiceScreenTemplate : public QWidget, public ScreenTemplate, protected Ui::ChoiceScreen
{
    Q_OBJECT
public:

    /**
     * Enumeration of possible widget types. This means that this template only will show its content with
     * specified widget type.
     */
    enum widgetType_enum
    {
        CHECKBOX,
        RADIOBUTTON,
        PUSHBUTTON,
        TEXTLINE,
        LABEL
    }widgetType;

    /**
     * Generic constructor
     *
     * @param *parent
     */
    ChoiceScreenTemplate(QWidget *parent = 0);

    /**
     * Class destructor
     */
    ~ChoiceScreenTemplate();

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

private:

};

#endif /*CHOICESCREENTEMPLATE_H_*/
