/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   IObserver.h
 *  @author Xavier Santotomas
 *  @date   July 12 2007
 *  @brief  Views Observer Abstract
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 


#ifndef __IObserver_h_
#define __IObserver_h_

#include "atlas_types.h"

class IObservable;
#include "Aspect.h"

/** This class describes the Views Observer abstraction interface.
*/
class IObserver
{

public:


    /** @name Views Observer public methods.
      @{
    */

    /** pure virtual function declaration.
     *  @param observable is the object that forced the execution of this method.
     *  @param reason is the reason for the callback, it has to be defined in the class using this callback.
     */
    virtual void onChange (IObservable & observable, uint32_t reason) = 0;

    /** virtual function declaration.
     *  @param observable is the object that forced the execution of this method.
     *  @param reason callback associated data. Typically will be encoded as a more complex class named Aspect.
     */
    virtual void onChange (IObservable & observable, Aspect& reason)
    {
    	 // empty: to be defined if a more complex reason were needed
    }

    virtual ~IObserver() {};


    /** @}
     */


};

#endif
