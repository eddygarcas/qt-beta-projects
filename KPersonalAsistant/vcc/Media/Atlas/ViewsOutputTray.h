/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ViewsOutputTray.h
 *  @author Eduard Garcia
 *  @date   Wed May 23 17:29:11 CEST 2007
 *  @brief  ViewsOutputTray class definition
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////

#ifndef VIEWSOUTPUTTRAY_H_
#define VIEWSOUTPUTTRAY_H_

#include "Media/IViewsOutputTray.h"
#include "Cds/ICds.h"
#include "IObserver.h"
#include <list>

/** 
 * In the same way that ViewsIntray, this class define methods to give sense a engine output tray object in views.
 * Contains a setInterface method which behave in  same way in ViewsIntray, receives a ICds interface which will be
 * used for connteting to engine CDS objects for obtaing information.
 */
class ViewsOutputTray : public IViewsOutputTray
{
public:

  /**
   * Void constructor
   */
  ViewsOutputTray();
  
  ViewsOutputTray(ICds* _cds);
 
  /** @name IViewsOutputTray required functions.
   *  @{
   */
  
  float getStatus();

 
  /**
   * }@
   */

  /** @name IObservable required public functions.
   *  @{
   */        

  /** Method to register an observer for this views pen.
   *  @param observer object to be registered. Later will be notified.
   */
  void registerObserver(IObserver &observer);

  
  /** Method to unregister an observer for this views pen.
   *  @param observer object to be unregistered. No more notifications will be received.
   */
  void unregisterObserver(IObserver &observer);

  /** @}
   */

  virtual ~ViewsOutputTray();
 
protected:
  /** @name IObservable required protected functions.
   *  @{
   */        

  /** This method should be called by the observable to notify all the attached observers of this views pen.
   *  @param reason is the reason for the callback, it has to be defined in the class using this callback.
   */
  void notify(uint32_t reason);

  /** @}
   */
 
private:

  
  /**Cds object pointer*/
  ICds* cds_;
  
  /** This list will keep the list of observers for this views pen.
   */
  std::list <IObserver*>  onChangeList_;  
};

#endif /*VIEWSOUTPUTTRAY_H_*/
