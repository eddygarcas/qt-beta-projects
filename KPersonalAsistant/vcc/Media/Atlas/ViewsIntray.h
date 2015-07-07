/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ViewsTray.h
 *  @author Eduard Garcia
 *  @date   Wed May 23 17:29:11 CEST 2007
 *  @brief  ViewsTray class definition
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////


#ifndef VIEWSINTRAY_H_
#define VIEWSINTRAY_H_

#include "Media/IViewsIntray.h"
#include "IObserver.h"
#include "Cds/ICds.h"
#include <list>

/** 
 *  This class defines methods that make sense a Views intray object.
 *  It Define a method to specify a ICds interface instance, by means of 
 *  that instance can obtain information from CDS engine objects to complete its information.
 *  We are using the next CDS elements, to define a Intray object:
 * 
 *  INTRAY-TOTAL-NUMBER
 *  INTRAY-{0}-LAST-SELECTED-LENGTH
 *  INTRAY-{0}-MAX-CAPACITY
 *  INTRAY-{0}-MEDIA-LENGTH
 *  INTRAY-{0}-MEDIA-NAME
 *  INTRAY-{0}-MEDIA-VENDOR
 *  INTRAY-{0}-MEDIA-WIDTH
 *  INTRAY-{0}-MODEL
 *  INTRAY-{0}-PAGE-COUNT
 *  INTRAY-{0}-PAGE-STORE
 *  INTRAY-{0}-SOURCE
 *  INTRAY-{0}-SERIAL-NUMBER
 *  INTRAY-{0}-STATUS
 *  INTRAY-BY-DEFAULT
 *  
 */ 
class ViewsIntray : public IViewsIntray
{
public:

  ViewsIntray();
  /**
   * In this constructor we pass through parameter a input media path and CDS instance, 
   * with these parameters ViewsIntray can make itself.
   * 
   * @param IMediaPath::InputPath&
   * @param ICds*
   */
  ViewsIntray(IMediaPath::InputPath& _inputPath,ICds* _cds = 0);
  

  /** @name IViewsIntray required functions.
   *  @{
   */
  
   
  /**
   * It returns a intray max capacity expressed in inches.
   * 
   * @return uint32_t
   */
  int32_t getMaxCapacity(); // in inch
  /**
   * It return the views intray status.
   * 
   * @return long
   */
  IViewsIntray::ViewsPathStatus getStatus();

  /**
   * Returns a source code. See IMediaPath for more information about souce codes.
   * 
   * @return unint32_t

   */
  IViewsIntray::ViewsInputPath getSource(); // Roll1 Roll2 etc...

  /**
   * It returns de model name.
   * 
   * @return std::string
   */
  std::string getModel();
 
  /**
   * Number of pages printed from this intray.
   *
   * @return Number of pages printed from this intray
   */
  int32_t getPageCount();
  
  /**
   * Number of pages currently stored (available) by tray n.  This
   * is only valid if the tray is of type 'tray', use length for
   * rolls.
   *
   * The value 0 means that there is no media available.  This value
   * does not apply for roll type, so -1 should be returned for this
   * type.
   *
   * @return pages currently stored (-1 if roll)
   */
  int32_t getPageStore();
  
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

  /**
   * Override equals operator
   * This function olny compare source value.
   * @param &_intray The instance that we want compare.
   * @return bool True if comparation equals, false in otherwise
   */
  bool operator==(IViewsIntray &_intray);

  /**
   * Override non-equals operator
   * This function olny compare source value.
   * @param &_intray The instance that we want compare.
   * @return bool True if comparation equals, false in otherwise
   */
  bool operator!=(IViewsIntray &_intray);
  
  /**Object destructor, makes relationship with shutdown IComponent method.*/
  virtual ~ViewsIntray();
  
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
  
  /**
   * 
   */
  std::string buildCdsKey(const char* _component,int16_t _index,const char* _element);
  
  /**
   * Converts a media path enumeration value to a readable value for Views.
   * 
   * @param IMediaPath::InputPath&
   */
  void convertToViewsInputPath(IMediaPath::InputPath& inputPath_);
  
  /**
   * Converts a media status path enumeration value to a readable value for Views.
   * 
   * @param IMediaPath::PathStatus&
   */
  void convertToViewsStatusPath(IMediaPath::PathStatus& pathStatus_);

  /**Intray model name*/
  std::string model_;
  /**Intray statuc enumaretion value*/
  IViewsIntray::ViewsPathStatus status_;
  /**Intray max capacity*/
  int32_t maxCapacity_;
  /**Number of pages printed from this intray.*/
  int32_t pageCount_;
  /**Number of pages currently stored (available) by tray.*/
  int32_t pageStore_;
  /**Views Intray input path*/ 
  IViewsIntray::ViewsInputPath source_;
  /**Cds object pointer*/
  ICds* cds_;
  /** This list will keep the list of observers for this views pen.*/
  std::list <IObserver*>  onChangeList_;
  
};

#endif /*VIEWSINTRAY_H_*/
