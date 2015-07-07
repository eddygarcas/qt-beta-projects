#ifndef IMENUACTION_H_
#define IMENUACTION_H_

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

#include "IViewsAction.h"
#include <vector>

typedef std::vector<IViewsAction::actionType_enum> MenuActionOptions;

typedef std::vector<IViewsAction::actionType_enum>::iterator MenuActionOptionsIterator;


/**This interface defines the generic operations of menu actions*/
class IMenuAction {

public:

    /**
     * This methos adds an option in menu tree.
     *
     * @param _actionType
     */
    virtual void addMenuActionElement(IViewsAction::actionType_enum _actionType) = 0;

};
#endif /*IMENUACTION_H_*/
