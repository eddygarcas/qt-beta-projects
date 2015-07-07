#ifndef MODELACTION_H_
#define MODELACTION_H_

/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ModelAction.h
 *  @author Hewlett-Packard
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

//#include "Logging.h"
#include "IViewsAction.h"
#include "IScreenTemplate.h"
//#include "LocalizationIdentifiers.h"

#include <QtCore/QObject>

/**Abstract class which defines the generic behavior of model action*/
class ModelAction : public QObject, public IViewsAction
{
    Q_OBJECT
public:

    /**
     * Returns the action type whose are defined in IViewsAction actionType_enum enumerator.
     *
     * @return actioType_enum
     */
    IViewsAction::actionType_enum getActionType();

    /**
    *Returns the action object name. This name will be used to create a menu option list.
    *
    * @return std::string
    */
    virtual const std::string& getObjectName() = 0;

    /**
     * Return the action model priority
     *
     * @return int32_t
     */
    int32_t getPriority();

    /**
     * Return the option label string key
     *
     * @return l10n::StringKey
     */
    std::string getActionLabel();

    /**
     * Returns the action title string key
     *
     * @return l10n::StringKey
     */
    std::string getActionTitle();

    /**
     * Returns the path to image which will be showed when the cursor pointer will pass over this option.
     *
     * @return std::string
     */
    std::string getImageOn();

    /**
     * Returns the path to image which will be showed when the cursor pointer will have passed over this option.
     *
     * @return std::string
     */
    std::string getImageOff();

    /**
     * By means of this method we will be able to assign views common classes interfaces into
     * model actions.
     *
     * @param interfaceName
     * @param *interface
     */
    virtual void setInterface(std::string interfaceName, void *interface) = 0;

    /**
     * Next method will contains the logical functionality.
     */
    virtual void execute() = 0;

    /**
     * Determines if this option is a action option or otherwise as a menu option.
     *
     */
    virtual bool hasMenuOption() = 0;

    /**
     * Generic destructor
     */
    virtual ~ModelAction();

protected:

    /**Loggin instance*/
    //Logging* log_;

    /**This varaible holds the screen template identifier*/
    IScreenTemplate::screenTemplate_enum screenTemplate_;

    std::string label_;
    std::string title_;

    std::string image_on_;
    std::string image_off_;

    /**
     * Model action constructor
     *
     * @param _actionType
     * @param log
     */
    ModelAction(
            IViewsAction::actionType_enum _actionType = IViewsAction::MENU_ACTION,
            int32_t _priority = 0,
            IScreenTemplate::screenTemplate_enum _screen = IScreenTemplate::MENU_TEMPLATE,
            std::string _label = (std::string)0, std::string _title = (std::string)0,
            const std::string &_image_on = 0,
            const std::string &_image_off = 0);

private:

    /**Priority value of action*/
    int32_t priority_;

    /**Variable which holds the action type.*/
    IViewsAction::actionType_enum actionType_;

    /**Void constructor, to avoid the self copy*/
    ModelAction();
};

#endif /*FrontPanelService_H_*/
