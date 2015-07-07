/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   PaperListListener.h
 *  @author Eduard Garcia
 *  @date   Wed May 23 17:29:11 CEST 2007
 *  @brief  Paper list class definition
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////

#ifndef PAPERLISTLISTENER_H_
#define PAPERLISTLISTENER_H_

#include "IOMES.h"
#include "IObserver.h"
#include "IObservable.h"


/**
 * With this class we will be able to receive all changes in medias.
 * In engine, IOMES knows when media list have changed. 
 */
class PaperListListener : public IOMES::IListener,
                          public IObservable
{
public:

  /**
   * Passing by parameter a IOberver interface implementation which will be called 
   * its onChange(...) when some  changes in media list.
   * 
   * @param IObserver*
   */
  PaperListListener(IObserver* observer);

  /** pure virtual function declaration.
   *  @param observer object to be registered. Later will be notified.
   */
  void registerObserver(IObserver& observer);

  /** virtual function declaration.
   *  @param observer object to be registered. Later will be notified.
   *  @param interest parameter allows registering observers only for specific events of interest.
   */
  void registerObserver(IObserver& observer, Aspect& interest);

  /** pure virtual function declaration.
   *  @param observer object to be unregistered. No more notifications will be received.
   */
  void unregisterObserver(IObserver& observer);

protected:

  /** pure virtual function declaration. 
   *  This method should be called by the observable to notify all the attached observers.
   *  @param reason is the reason for the callback, it has to be defined in the class using this callback.
   */
  void notify(uint32_t reason);

    
private:
    
  /**
   * This function will be called by OMES when some change in media list
   * event parameter can be null.
   * It returns true if changes ends well or false in otherwise.
   * 
   * @param Event
   * @return bool
   */
  bool onEventCore(Event const & event) const;
    
  IObserver* observer_;
};

#endif
