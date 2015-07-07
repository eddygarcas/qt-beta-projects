#ifndef IMENUTEMPLATE_H_
#define IMENUTEMPLATE_H_

/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   MainMenuModelAction.h
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

#include <Qt>
#include "MenuPushButton.h"
#include "IViewsAction.h"

/**With this class definition we want define the generic aspect of menu actions.*/
class IMenuTemplate {

public:
    /**
     * Adds an option to menu action. The menu action implementation performs the operations to show this option in screen template.
     *
     * @param &_label Text which will show in option
     * @param *_action  Action which this option calls when someone pick up it.
     */
    virtual void addOption(const std::string &_label,IViewsAction *_action) = 0;
    /**
     * Adds an option to menu action. The menu action implementation performs the operations to show this option in screen template.
     *
     * @param *_menuPushButton Instance of MenuPushButton, which contains the operations to perform the action
     */
    virtual void addOption(MenuPushButton *_menuPushButton) = 0;

    /**
     * With this method we want take the control of key event process of front panel. This method will assign a action to each allowed key.
     *
     * @param _key
     * @param *_action
     */
    virtual void addHidden(Qt::Key _key,IViewsAction *_action) = 0;
};


#endif /*IMENUTEMPLATE_H_*/
