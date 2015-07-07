/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ViewsJobManagerAtlas.h
 *  @author Eduard Garcia
 *  @date   Thu Feb 21 16:30:11 CEST 2008
 *  @brief  ViewsJobManagerAtlas interface implementation.
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////
#ifndef VIEWSJOBMANAGERATLAS_H_
#define VIEWSJOBMANAGERATLAS_H_

#include "atlas_types.h"
#include "IComponent.h"
#include "ViewsJobManagerNotifier.h"
#include "JobManager/IViewsJobManager.h"
#include "IObservable.h"

/** */
class ViewsJobManagerAtlas :  public IViewsJobManager,
                              public IComponent

{
public:
  
  /**
   * ViewsJobManager constructor,Its called by Metagod.
   * 
   * @param _componentName
   */
  ViewsJobManagerAtlas(std::string _componentName);

  
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
  
  /** @name Views Observer public methods.
        @{
   */

  /** pure virtual function declaration.
   *  @param observable is the object that forced the execution of this method.
   *  @param reason is the reason for the callback, it has to be defined in the class using this callback.
   */
   void onChange (IObservable & observable, uint32_t reason);

   /** @}
    */        
      
  /**
   * Returns a IViewsJobQueue interface instances holds in ViewsJobManager.
   * 
   * @return IViewsJobQueue* 
   */
  IViewsJobQueue* getJobQueue();

  /**
   * Virtual class destructor
   */
  virtual ~ViewsJobManagerAtlas();
  
protected:
  
private:
  
  /**
   * Gets from JobMananger the job list.
   * 
   * @return Result
   */
  Result obtainJobsList();
  
  /**
   * Clear elements holds in internal queue.
   */
  void clear();
  
  /** This method should be called to lock access to a resource needing mutex access.*/
  void lock();

  /** This method should be called to unlock access to a resource needing mutex access.*/
  void unlock();
  
  /**Internal IViewsJobQueue instance, holds a ViewsJob(s)*/
  IViewsJobQueue *viewsJobQueue_;
  /**To guarantee mutual exclusion when accessing onChangeList_.*/
  tRedOSMonitor monitor_;
  /**Views job notifier instance*/
  ViewsJobManagerNotifier *jobNotifier_;
  /**JobManager key subscribe value*/
  int jobSubscribeKey_;
  /**
   * To write logs in the system
   */
  Logging *log_;
  
};

#endif /*VIEWSJOBMANAGERATLAS_H_*/
