#ifndef WIDGETCONTROLLER_H_
#define WIDGETCONTROLLER_H_

/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   GuiController.h
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

#include <QtGui/QStackedWidget>
#include <QtGui/QWidget>
#include <QtGui/QKeyEvent>
#include <QtCore/QEvent>

#include "FrontPanelEnum.h"
#include "IScreenTemplate.h"
#include "IViewsAction.h"
//#include "gui/ScreenTemplates/IPrinterInformation.h"

#include "ChoiceScreenTemplate.h"
#include "InkLevelTemplate.h"
#include "TopLevelTemplate.h"
#include "ProgressBarTemplate.h"
#include "MainMenuTemplate.h"
#include "AnimationTemplate.h"
#include "IPv4AddressTemplate.h"
#include "TextListMenuTemplate.h"

/**
 * This class allow you to store and manage the standard front panel screens.
 */
class GuiController : public QStackedWidget
{
    Q_OBJECT
public:

    /**
     * Static method which you will be able to obtain a GuiController instance.
     *
     * @return GuiController&
     */
    static GuiController& instance(QWidget *parent = 0)
    {
        QWidget *aux;
        if (parent == NULL) aux = new QWidget();
        else aux = parent;
        static GuiController guiController_(aux);
        return guiController_;
    }


    /**
     * Starts front panel application.
     */
    void start();

    /** provide a pointer of a named interface.
     *
     *  @param instanceName the name of the component instance providing the interface.
     *  @param interfaceName the name of the provided interface.
     *  @param interface a pointer to the provided interface.
     */
    void setInterface(std::string interfaceName, void *interface);

    /**
     * With this method we controlling the front panel button events.
     *
     * @param *target
     * @param *event
     */
    bool eventFilter(QObject *target, QEvent *event);

    /**
     * Appends the given widget to this QStackedWidget and returns the index position.
     * If the QStackedWidget is empty before this function is called, widget becomes the current widget.
     * See also insertWidget(), removeWidget(), and setCurrentWidget().
     *
     * @param *widget
     */
    int32_t addWidget(QWidget *widget);

    /**
     * Method which allows you to insert a screen template in stacked list.
     *
     * @param _screenTemplate
     * @param *widget
     */
    int32_t insertWidget(IScreenTemplate::screenTemplate_enum _screenTemplate,
            QWidget *widget);

    /**
     * Shows current widget
     */
    void show(void);

    /**
     * It Returns the IScreenTemplate identified by means of  parameter _screenTemplate,
     * which is an enumerator value hold in IScreenTemplate interface.
     *
     * @param _screenTemplate
     * @return IScreenTemplate*
     */
    IScreenTemplate* getScreenTemplateInstance(
            IScreenTemplate::screenTemplate_enum _screenTemplate);

    /**
     * by means of enumeration value, passed through parameter, next method determines if action can be executed.
     * If it can, returns true, in otherwise returns false.
     *
     * @param _actionType
     * @return bool
     */
    bool canBeExecuted(IViewsAction::actionType_enum _actionType);

    /**
     * It returns a screen template instance according to _index value
     *
     * @param _index
     * @return IScreenTemplate*
     */
    IScreenTemplate* screenInstance(int32_t _index);

    /**
     * It returns the current widget instance (that is showing in front panel).
     *
     * @return IScreenTemplate*
     */
    IScreenTemplate* currentWidget(void);

public slots:
    /**
     * It Changes the current index by index value passed through parameter.
     * Front panel will show the last screen until show() method will be launched.
     *
     * @param _index
     */
    void setCurrentIndex(int32_t _index);

protected:

    /**
     * Widget controler constructor. To avoid a copy contructor.
     *
     * @param *parent
     */

#ifndef START_ON_WINDOW
    GuiController(QWidget *parent = new QWidget(NULL,Qt::FramelessWindowHint));
#endif
#ifdef START_ON_WINDOW
    GuiController(QWidget *parent = 0);
#endif
    /**
     * In this section, we make screen template instances.
     */
    /**Choice screen template instance*/
    ChoiceScreenTemplate choiceScreen_;
    /**Ink level template instance*/
    InkLevelTemplate inkLevelScreen_;
    /**Top level template instance*/
    TopLevelTemplate topLevelScreen_;
    /**Progress bar template instance*/
    ProgressBarTemplate progressBarTemplate_;
    /**Main menu template instance*/
    MainMenuTemplate mainMenuTemplate_;
    /**Animation template instance*/
    AnimationTemplate animationTemplate_;
    /**Template to insert a IP v4 address*/
    IPv4AddressTemplate ipv4AddressTemplate_;
    /**Instrance of text list menu*/
    TextListMenuTemplate textListMenuTemaplte_;

private:

    /**
     * Puts in added widget the generic widget properties.
     *
     * @param *widget - Widget which we want to add, should be a IScreenTemplate instance.
     */
    void putWidgetCharacteristics(QWidget *widget);

    /**
     * Shows in front panel the main menu screen.
     */
    void loadMainMenu();

    /**
     * Show in front panel the top level screen.
     */
    void loadTopLevel();

    /**Printer information instance will come from metagod*/
    //IPrinterInformation* printerInformation_;

};

#endif /*WIDGETCONTROLLER_H_*/
