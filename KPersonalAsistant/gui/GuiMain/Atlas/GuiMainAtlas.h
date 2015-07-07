/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   GuiMainAtlas.h
 *  @author Eduard Garcia
 *  @date   Thu Feb 21 16:30:11 CEST 2008
 *  @brief  GuiMainAtlas interface implementation.
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////
#ifndef GuiMainAtlas_H_
#define GuiMainAtlas_H_

#include "atlas_types.h"
#include "IComponent.h"
#include "IGuiMain.h"

#include "IPrinterInformation.h"

/** */
class GuiMainAtlas : public IGuiMain,
					 public IComponent

{
public:
  
  /**
   * GuiMainAtlas constructor,Its called by Metagod.
   * 
   * @param _componentName
   */
	GuiMainAtlas(std::string _componentName);

  
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

  /** launch the component. this method will be called call after the @e start() one so the component knowing that all the system is ready to be used.
          default implementation so it is not mandatory to implement it of not needed (that @e start() provides the desired  functionality).
          @return RESULT_OK if successful, the failure code otherwise.
          @note components could perform any task they want.
          @note this is not a "virtual" function providing an empty "safe" implementation.
       */  
  Result go (void);
  /** @}
   */        
      
  /**
   * Starts the GUI application.
   * 
   */
  void execute();

  /**
   * Virtual class destructor
   */
  virtual ~GuiMainAtlas();
  
protected:
  
private:
  
  void lock();
  
  void unlock();
  
  /**Printer information instance will come from metagod*/
  IPrinterInformation* printerInformation_;
  /**
   * To write logs in the system
   */
  Logging *log_;
  /**To guarantee mutual exclusion when accessing onChangeList_.*/
  tRedOSMonitor monitor_;

};

#endif /*GuiMainAtlas_H_*/
