/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   CommonCalibration.h
 *  @author Eduard Garcia
 *  @date   Wed May 23 17:29:11 CEST 2007
 *  @brief  CalibrationStatus class definition
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////

#ifndef COMMONCALIBRATION_H_
#define COMMONCALIBRATION_H_

#include <list>
#include <string>  

#include "atlas_types.h"
#include "IObserver.h"
#include "Logging.h"
#include "IObservable.h"
#include "CDS/ViewsEnum.h"
#include "IOMES.h"

/** 
 * Generic CommonCalibration implementation. all Calibrations must inherit from this.
 * If you inherit from this class, you must implement doClibration(...) method in your own class.
 */
class CommonCalibration : public IObservable
{
public:

    /** @name CommonCalibration public types.
     *  @{
     */        
  
    /**
     * Next enumeration contains all calibration kinds.
     * */
    enum ViewsCalibrationKind 
    {
        /** Color calibration*/
        VIEWS_CLC_CONFIGURATION     = IOMES::CLC_CONFIGURATION,
        /** */
        VIEWS_CLC_ISV_CONFIGURATION = IOMES::CLC_ISV_CONFIGURATION,
        /** Paper CAD calibration*/
        VIEWS_BVC_CAD_CONFIGURATION = IOMES::BVC_CAD_CONFIGURATION,
        /** Paper advance GA calibration*/
        VIEWS_BVC_GA_CONFIGURATION  = IOMES::BVC_GA_CONFIGURATION,
        VIEWS_IQ_CAD_CONFIGURATION  = IOMES::IQ_CAD_CONFIGURATION,
        VIEWS_IQ_GA_CONFIGURATION   = IOMES::IQ_GA_CONFIGURATION,
        /** Printer aligment calibration*/
        VIEWS_ALIGNMENT             = IOMES::ALIGNMENT,
        /** Paper/Media advance calibrations*/
        VIEWS_ADVANCE               = IOMES::ADVANCE
    };
  
    /**
     * This enum contains all possible status calibration values that engine be able to have.
     */
    enum ViewsCalibrationStatus 
    {
        /**Undefinides calibration status*/
        VIEWS_UNDEFINED       = 0,
        /**The calibration is disabled*/
        VIEWS_NOT_AVAILABLE   = CALIBRATION_STATUS_CALIBRATION_DISABLED,
        /**The calibration is done.*/
        VIEWS_VALID           = CALIBRATION_STATUS_CALIBRATED, 
        /**The calibrations is pending.*/
        VIEWS_TODO            = CALIBRATION_STATUS_CALIBRATION_PENDING,
        /**Selected calibration is obsolete*/
        VIEWS_OBSOLETE        = CALIBRATION_STATUS_CALIBRATION_OBSOLETE
    };
  
 
    /** @}
     */ 
       
    /**
     * Creates a CalibrationStatus object. Must specify a calibration type, the status and timestamp
     * are optional.
     * 
     * @param _calibrationType
     * @param _status
     * @param _timeStamp
     */
    CommonCalibration(ViewsCalibrationKind _calibrationType,ViewsCalibrationStatus _status = CommonCalibration::VIEWS_UNDEFINED,ulong_t _timeStamp =0,Logging* _log = 0);
	

    /**Calibration status destructor*/
    virtual ~CommonCalibration();

    /** @name CommonCalibration methods.
     *  @{
     */        
  
    /**
     * Return a calibration status type.
     * 
     * @return std::string
     */
    ViewsCalibrationKind getCalibrationType();
	
    /**
     * Return a status of calibration, will be:
     *
     * @return ViewsCalibrationStatus
     */
    ViewsCalibrationStatus getCalibrationStatus();
	
    /**
     * Sets calibrations status value.
     * 
     * @param ViewsCalibrationStatus
     */
    void setCalibrationStatus(ViewsCalibrationStatus& _calibrationStatus);
	
	
    /**
     * Returns the string key value of status code.
     * 
     * @return std::string
     */
    std::string getStatusAsStringKey();
	
    /**
     * Return a long type with timestamp value
     * 
     * @return ulong_t
     */
    ulong_t getTimeStamp();
  
    /**
     * Static method which returns a standard views calibration status value.
     * 
     * @param uint32_t
     * @return ViewsCalibrationStatus
     */
    static ViewsCalibrationStatus getCdsCalibrationStatus(uint32_t _calibrationStatus);

    /**
     * Static method which returns a standard views calibration status value.
     * 
     * @param uint32_t
     * @return ViewsCalibrationStatus
     */
    static ViewsCalibrationStatus getCdsCalibrationStatus(IOMES::IMediaCalibrationStatus::MediumCalibrationStatus::Status status);
	
    /**
     * @}
     */
  
    /** @name IObservable required functions.
     *  @{
     */        
       
    /**
     * Method for register a IObserver object.
     * 
     * @param observer object to be registered. Later will be notified.
     */
    void registerObserver(IObserver& observer);
  
    /**
     * Method for unregister a IObserver object.
     *  
     * @param observer object to be unregistered. No more notifications will be received.
     */
    void unregisterObserver(IObserver& observer);
  
    /**
     * @}
     */
	
protected:

    /** @name IObservable required functions.
     *  @{
     */        
  
    /**
     * This method should be called by the observable to notify all the attached observers.
     * 
     * @param reason is the reason for the callback, it has to be defined in the class using this callback.
     */
    void notify(uint32_t reason);

    /**
     * @}
     */

private:


    /**It contains the calibration type name*/
    ViewsCalibrationKind calibrationType_;

    /**It contains the status of calibration.*/
    ViewsCalibrationStatus status_;

    /**It contains the time stamp expressed in miliseconds*/ 
    ulong_t timeStamp_;
  
    Logging* log_;

    std::list<IObserver*>  onChangeList_;  

};

#endif /* COMMONCALIBRATION_H_ */
