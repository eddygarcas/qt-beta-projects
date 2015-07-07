/* -*- c++ -*- */
/**
 *  @file   ActionFactory.cpp
 *  @author GENERATED IN BUILD TIME (see frontpanel_action.xml for changes)
 *  @date   Thu Jan 10 19:29:11 CEST 2007
 *  @brief  Generated file at compile time.
 *  @see    ActionFactory.cpp
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2008.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 */
//////////////////////////////////////////////////////////////////////////////
#include "ActionFactory.h"
#include "IScreenTemplate.h"
//#include "LocalizationIdentifiers.h"

#include "InkLevelModelAction.h"
#include "AnimationTestModelAction.h"
#include "IPv4InsertTestModelAction.h"
#include "MainMenuModelAction.h"
#include "TopLevelModelAction.h"
#include "InkMenuModelAction.h"
#include "ProgressTestModelAction.h"

#include <iostream>

IViewsAction* ActionFactory::getAction(IViewsAction::actionType_enum actionType)
{
    return actionsMap_[actionType];
}

ActionFactory::ActionFactory()
{
    initialize();
}

void ActionFactory::initialize()
{
    IMenuAction *ptrMenu_;


    actionsMap_[IViewsAction::MENU_ACTION]
            = new MainMenuModelAction(0,IScreenTemplate::MENU_TEMPLATE,"l10n::STRING_INK_LIMITING","l10n::STRING_IO_IPV4_CONFIGURATION",":/turbotaj/mainmenu/mainMenu/connectivityIcon.bmp",":/turbotaj/mainmenu/mainMenu/connectivityIconSelected.bmp");

    actionsMap_[IViewsAction::INK_TEXT_MENU_ACTION] = new InkMenuModelAction(0,IScreenTemplate::TEXT_MENU_TEMPLATE,"l10n::STRING_INK_LIMITING","l10n::STRING_IO_IPV4_CONFIGURATION",":/turbotaj/mainmenu/mainMenu/connectivityIcon.bmp",":/turbotaj/mainmenu/mainMenu/connectivityIconSelected.bmp");

    actionsMap_[IViewsAction::INKLEVEL_ACTION]
            = new InkLevelModelAction(0,IScreenTemplate::INKLEVEL_TEMPLATE,"l10n::STRING_INK_LIMITING","l10n::STRING_IO_IPV4_CONFIGURATION",":/turbotaj/mainmenu/mainMenu/connectivityIcon.bmp",":/turbotaj/mainmenu/mainMenu/connectivityIconSelected.bmp");

    actionsMap_[IViewsAction::ANIMATION_TEST_ACTION]
            = new AnimationTestModelAction(0,IScreenTemplate::ANIMATION_TEMPLATE,"l10n::STRING_INK_LIMITING","l10n::STRING_IO_IPV4_CONFIGURATION",":/turbotaj/mainmenu/mainMenu/informationIcon.bmp",":/turbotaj/mainmenu/mainMenu/informationIconSelected.bmp");

    actionsMap_[IViewsAction::INSERT_IPV4_ACTION]
            = new IPv4InsertTestModelAction(0,IScreenTemplate::INPUTADDRESS_TEMPLATE,"l10n::STRING_INK_LIMITING","l10n::STRING_IO_IPV4_CONFIGURATION",":/turbotaj/mainmenu/mainMenu/setupIcon.bmp",":/turbotaj/mainmenu/mainMenu/setupIconSelected.bmp");

    actionsMap_[IViewsAction::TOPLEVEL_ACTION]
            = new TopLevelModelAction(0,IScreenTemplate::TOPLEVEL_TEMPLATE,"l10n::STRING_INK_LIMITING","l10n::STRING_IO_IPV4_CONFIGURATION",":/turbotaj/mainmenu/mainMenu/inkIcon.bmp",":/turbotaj/mainmenu/mainMenu/inkIconSelected.bmp");

    actionsMap_[IViewsAction::TEST_PROGRESSBAR_ACTION]
            = new ProgressTestModelAction(0,IScreenTemplate::PROGRESSBAR_TEMPLATE,"l10n::STRING_INK_LIMITING","l10n::STRING_IO_IPV4_CONFIGURATION",":/turbotaj/mainmenu/mainMenu/inkIcon.bmp",":/turbotaj/mainmenu/mainMenu/inkIconSelected.bmp");

    ptrMenu_
            = dynamic_cast<IMenuAction*>(actionsMap_[IViewsAction::MENU_ACTION]);
    ptrMenu_->addMenuActionElement(IViewsAction::INKLEVEL_ACTION);
    ptrMenu_->addMenuActionElement(IViewsAction::INSERT_IPV4_ACTION);
    ptrMenu_->addMenuActionElement(IViewsAction::ANIMATION_TEST_ACTION);
    ptrMenu_->addMenuActionElement(IViewsAction::INK_TEXT_MENU_ACTION);

    ptrMenu_
            = dynamic_cast<IMenuAction*>(actionsMap_[IViewsAction::INK_TEXT_MENU_ACTION]);
    ptrMenu_->addMenuActionElement(IViewsAction::INKLEVEL_ACTION);
    ptrMenu_->addMenuActionElement(IViewsAction::INSERT_IPV4_ACTION);
    ptrMenu_->addMenuActionElement(IViewsAction::ANIMATION_TEST_ACTION);
    ptrMenu_->addMenuActionElement(IViewsAction::TOPLEVEL_ACTION);
    ptrMenu_->addMenuActionElement(IViewsAction::MENU_ACTION);
    ptrMenu_->addMenuActionElement(IViewsAction::INK_TEXT_MENU_ACTION);
    ptrMenu_->addMenuActionElement(IViewsAction::TEST_PROGRESSBAR_ACTION);

}
