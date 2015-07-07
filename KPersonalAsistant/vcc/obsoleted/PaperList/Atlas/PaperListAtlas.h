/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   PaperListAtlas.h
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

#ifndef PAPERLISTATLAS_H_
#define PAPERLISTATLAS_H_

#include "IComponent.h"
#include "Paper.h"
#include "PaperList/IPaperList.h"
#include "PaperListListener.h"
#include "Locale.h"
#include "IEngineStateMachine.h"
#include "engine_interface.h"
#include "MediaManager/IMediaManager.h"
#include "IOMES.h"
#include "autogen/MediaSettings.h"

#include <map>
#include <list>
#include <string>

/**
 * Fake paper list definition. All values obtained from this implementation are hard-coded, 
 * but, establishes relationship to metagod by means of IComponent interface.
 */
class PaperListAtlas : public IPaperList,
					   public IComponent,
					   public IOMES::IListener
{
public:
  
  /**
   * It Creates a paper list and initalizes a IComponent with instance name passed through parameter.
   * 
   * @param instanceName 
   */
  PaperListAtlas(std::string instanceName);
		
  /**
   * It returns a paper list version
   * 
   * @return uint32_t
   */
  int32_t getPaperListVersion(void);

  /**
   * It returns a IPaper instance, by means of media key and locale specified by parameter.
   * 
   * @param _mediaKey Key value of paper item.
   * @param _locale Instance of ILocale interface with system locale value.
   * @return IPaper*
   */
  IPaper* getPaper(std::string const& _mediaKey,ILocale& _locale);
	
  /**
   * It returns a list of IPaper instances, they are kept in an internal list.
   * 
   * @param _locale Instance of ILocale interface with system locale value.
   * @return ViewsIterator<IPaper*>
   */
  ViewsIterator<IPaper*> getPaperIterator(ILocale& _locale);
	

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

  /** @name IObserver required functions.
   *  @{
   */        

  /** pure virtual function declaration.
   *  @param observable is the object that forced the execution of this method.
   *  @param reason is the reason for the callback, it has to be defined in the class using this callback.
   */
  void onChange (IObservable & observable, uint32_t reason);

  /** @}
   */

  
  /** @name IComponent required functions.
   *  @{
   */        

  /** initialize the component.
   *  @note at initialization time components must ask for all the memory and
   *  Operating System services that they are suposed to use. No other component or
   *  hardware access is allowed.
   * 
   *  @return RESULT_OK if successful, the failure code otherwise.
   */
  Result initialize (void);
          

  /** start the component. 
   *  @note components should perform the hardware related actions
   *  to turn into an operative status either through drivers or other
   *  components.
   * 
   *  @return RESULT_OK if successful, the failure code otherwise.
   */
  Result start (void);

  /** perform an emergency shutdown.
   *  @note only the indispensable actions should be performed.
   *
   *  @return  RESULT_OK if successful, the failure code otherwise.
   */
  Result emergencyShutdown (void);

  /** shutdown the component.
   * 
   *  @return RESULT_OK if successful, the failure code otherwise.
   */
  Result shutdown (void);   

  /** enter sleep mode.
   *  @note most likely this would mean doing some power saving activities on it.
   * 
   *  @return  RESULT_OK if successful, the failure code otherwise.
   */
  Result enterSleepMode (void);
   
  /** abandon the sleep mode.
   *
   *  @return  RESULT_OK if successful, the failure code otherwise.
   */
  Result exitSleepMode (void);

  /** provide a pointer of a named interface.
   * 
   *  @param instanceName the name of the component instance providing the interface.
   *  @param interfaceName the name of the provided interface.
   *  @param interface a pointer to the provided interface.
   */
  void setInterface (std::string instanceName, std::string interfaceName, void *interface);

  /** query for an an interface that you implement.
   * 
   *  @param interfaceName the name of the interface that other is asking you to provide.
   *  @param interface a pointer to the memory area where the pointer to the requested interface will be left.
   */
  void getInterface (std::string interfaceName, void **interface);

  /** @}
   */        

  /** @name IPrinterCommands required functions.
   *  @{
   */        

  /**
   * Launch operations against Engine state machine.
   * It pass through parameter a string with operation name.
   * 
   * @parm std::string
   *  
   */
  bool execute (std::string& _executeCommand);

  /** @}
   */

  
  /**Destructor*/
  virtual ~PaperListAtlas();

protected:

  /** @name IObservable required protected functions.
   *  @{
   */        

  /** 
   * This method should be called by the observable to notify all the attached observers of this views pen.
   * 
   *  @param reason is the reason for the callback, it has to be defined in the class using this callback.
   */
  void notify(uint32_t reason);

  /** @}
   */

private:

  /** This method should be called to lock access to a resource needing mutex access.
   */
  void lock();

  /** This method should be called to unlock access to a resource needing mutex access.
   */
  void unlock();

  /**
   * It receives a system locale instance and make up map with paper list engine values.
   * 
   * @param _localeString String which contains a locale value in ISO 8601 format.
   * @param std::map<std::string,IPaper*>&
   */
  Result obtainPaperList(std::string _localeString);
  
  /**
   * For each paper instance, it updates the media name and vendor with value of specified locale.
   * 
   * @param &_loc
   */
  Result changeMediaLocale(ILocale &_loc);
  
  /**
   * It Returns MediaType instance from IOMES media instance.
   * 
   * @param _media
   */
  MediaType localizedMedia(IOMES::MediaLocalization _media);
  
  /**
   * It Returns MediaType instance from media id and MediaType instance.
   * 
   * @param _mediaId
   * @param _mediaName
   */
  MediaType localizedMedia(std::string _mediaId,MediaType _mediaName);

  /**
   * This function will be called by OMES when some change in media list
   * event parameter can be null.
   * It returns true if changes ends well or false in otherwise.
   * 
   * @param &event
   * @return bool
   */
  bool onEventCore(Event const & event) const;
    
  /** This list will keep the list of observers for this paper list.*/
  std::list <IObserver *>  onChangeList_;
  /** Locale instance*/
  Locale locale_; 
  /**Paper list version*/
  std::string paperListVersion;
  /**Map that coitains engine media elements*/
  std::map<std::string,Paper> mediaList;
  /**IOMES interface which allows us to obtain media information*/
  IOMES* omesInterface_;
  /**TODO: deprecated Listener of Omes notifier.*/
  //PaperListListener* listener_;
  /**DONE: 21-04-2008 garciedu@bpo.hp.com*/
  /** The pointer to the engine engine state machine instance. It allows access to his interface.*/
  IEngineStateMachine* engineStateMachine_;
  /** Media manager interface which allows us to obtain the media usage.*/
  IMediaManager* mediaManager_;
  /**To guarantee mutual exclusion when accessing onChangeList_.*/
  tRedOSMonitor monitor_;
  /**
   * To write logs in the system
   */
  Logging* log_;
};

#endif /*PAPERLISTATLAS_H_*/
