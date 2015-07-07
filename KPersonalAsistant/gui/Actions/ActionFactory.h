#ifndef ACTIONFACTORY_H_
#define ACTIONFACTORY_H_

/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ActionFactory.h
 *  @author Hewlett-Packard
 *  @date   Wed May 23 17:29:11 CEST 2007
 *  @brief
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.1
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////


//#include "views_types.h"
#include "IViewsAction.h"
#include <map>

/*Please see the TODO tags in code for more information
 *
 * TODO: The parser actions file (ViewsActionsParser.h in tools directory) process must be put in makelele file.
 */

/**
 * This class allows you to store and manage the model actions.
 */
class ActionFactory
{
public:

    /**
     * Static method which you will be able to obtain a ActionFactory instance.
     *
     * @return ActionFactory&
     */
    static ActionFactory& instance()
    {
        static ActionFactory actionFactory_;
        return actionFactory_;
    }

    IViewsAction* getAction(IViewsAction::actionType_enum _actionType);

protected:

    /**Action factory constructor
     *
     * @param *parent
     */
    ActionFactory();

    /**
     * Initializes model actions and store them in actionMap_
     * This methos will be called by action factory void constructor.
     */
    void initialize();

private:

    /**With structure as follows we want to store model actions.*/
    std::map<IViewsAction::actionType_enum,IViewsAction*> actionsMap_;

};

#endif /*ACTIONFACTORY_H_*/
