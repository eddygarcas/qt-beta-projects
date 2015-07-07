/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ViewsMediaManagerFake.h
 *  @author Eduard Garcia
 *  @date   Wed May 23 17:29:11 CEST 2007
 *  @brief  ViewsMediaManagerFake class definition
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////

#ifndef VIEWSMEDIAMANAGERATLAS_H_
#define VIEWSMEDIAMANAGERATLAS_H_


#include "atlas_types.h"
#include "IComponent.h"
#include "IEngineStateMachine.h"
#include "UsageCounters/IUsageCounters.h"
#include "engine_interface.h"
#include "Nvm/INvm.h"
#include "Cds/ICds.h"

#include "Media/IViewsMediaManager.h"
#include "ViewsIntray.h"
#include "ViewsOutputTray.h"

#include <string>
#include <vector>

/**
 * Component class which holds the In and output trays interface information.
 * Is possible which uses these engine interfaces:
 *  IEngineStateMachine
 *  IMediaManager
 *  IMediaPath
 * Is defined how IComponent in this way can be instanced by metagod system by means of patumgod config files.
 * All methods give back fake values.
 */
class ViewsMediaManagerAtlas :  public IViewsMediaManager,
                                public IComponent
{
public:

  
  /**
   * Class constructor, we must pass the instance name which we want to create.
   * 
   * @param std::string
   */
  ViewsMediaManagerAtlas(std::string instance_);

  /** @name IViewsMediaManager required public functions.
   *  @{
   */        

  /**
   * Load a intray element into list of papers
   * 
   * @param viewsIntray
   */
  Result loadPaper(IViewsIntray &viewsIntray_);
  
  /**
   * Returns a ViewsMediaCollection of IViewsIntrays pointers
   * 
   * @return ViewsMediaCollection
   */
  ViewsMediaCollection getIntrays();
  
  /**
   * Return the active Intray object.
   * 
   * @return IViewsIntray
   */
  IViewsIntray* getActiveIntray();
  
  /**
   * Return the actual status
   * 
   * @return ViewsMediaStatus 
   */
  ViewsMediaStatus getStatus();
  
  /**
   * Return the active output tray instance.
   * 
   * @return IViewsOutputTray 
   */
  IViewsOutputTray* getActiveOutTray();

  /**
   * Total comsumption of media for print quality.
   * Iterator order makes relationship with ViewsPrintQuality sort enumeration 
   * 
   * @return ViewsMediaPrintQualityCollection
   */ 
  ViewsMediaPrintQualityCollection getUsagePrintQuality();
  
  /**
   * Total consumption of media for print type
   * Iterator order makes relationship with ViewsPrintType sort enumeration
   * 
   * @return ViewsMediaPrintTypeCollection
   */
  ViewsMediaPrintTypeCollection getUsagePrintType();
  
  /**
   * It returns the total media printed in inches.
   * 
   * @return uint32_t
   */
  uint32_t getTotalMediaPrinted();
  
  /**
   * It returns total pages printed.
   * 
   * @return uint32_t
   */
  uint32_t getTotalPagesPrinted();
  
  /**
   * Returns media advance calibration
   * 
   * @return CommonCalibration*
   */
  CommonCalibration* getMediaAdvanceCalibration();
  
  /**
   * @}
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
  
  /** @name Views IObserver public methods.
    @{
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
  
  
  /**Virtual destructor*/
  virtual ~ViewsMediaManagerAtlas();


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
   * Makes a CDS key value by means of parameters.
   * If _index parameter equals zero this function concate component parameter 
   * with element parameter, without index value.
   * 
   * @param const char*
   * @param int16_t
   * @param const char*
   * 
   * @return std::string
   */
  std::string buildCdsKey(const char* _component,int16_t _index,const char* _element);
  
  /**
   * Obtain a media usage from engine
   * 
   * @return Result
   */
  Result obtainMediaUsage();
  
  /**
   * Obtain intray list from engine
   * 
   * @return Result
   */
  Result obtainIntrayList();
  
  /**
   * Obtain print usage.
   * 
   * @param const char*
   * @param std::vector<int32_t>
   * @return Result
   */
  Result obtainPrintUsage(const char* _printTag,std::vector<int32_t>& _printVector);
  
  /**
   * Obtain print type from engine.
   * 
   * @return Result
   */
  Result obtainPrintType();
  
  /**
   * Obtain media advance calibration from engine.
   * 
   * @return Result
   */
  Result obtainMediaAdvanceCalibration();
  
  /** This method should be called to lock access to a resource needing mutex access.*/
  void lock();

  /** This method should be called to unlock access to a resource needing mutex access.*/
  void unlock();
 
  /** This list will keep the list of observers for this printer information.*/
  std::list<IObserver*> onChangeList_;
  /** */
  uint32_t mediaPrinted_;
  /** */
  uint32_t pagesPrinted_;
  /** */
  CommonCalibration* mediaAdvanceCalibration_;
  /** */
  std::vector<int32_t> usagePrintQuality_;
  /** */
  std::vector<int32_t> usagePrintType_;
  /**Vector of intrays*/
  std::vector<ViewsIntray> intrayList;
  /**Vector of output trays*/
  std::vector<IViewsOutputTray*> outputTrayList;
  /** The pointer to the engine CDS instance. It allows access to his interface.*/
  ICds *cds_;
  /** The pointer to the engine media manager instance. It allows access to his interface.*/
  IMediaManager* mediaManager_;
  /** The pointer to the engine engine state machine instance. It allows access to his interface.*/
  IEngineStateMachine* engineStateMachine_;
  /**Engine interface instance.*/
  IUsageCounters* usageCountersInterface_;
  /** */
  INvm* nvmInterface_;
  /**To guarantee mutual exclusion when accessing onChangeList_.*/
  tRedOSMonitor monitor_;
  /**
   * To write logs in the system
   */
  Logging* log_;

};


#endif /*VIEWSMEDIAMANAGERATLAS_H_*/
