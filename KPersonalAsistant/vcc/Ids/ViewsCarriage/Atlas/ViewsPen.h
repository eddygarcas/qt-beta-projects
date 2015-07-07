/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ViewsPen.h
 *  @author Xavier Santotomas
 *  @date   Jun 29 2007
 *  @brief  Views Pen Abstract
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 


#ifndef __ViewsPen_h_
#define __ViewsPen_h_

#include "Logging.h"
#include "SuppliesConfigurator/ISuppliesConfigurator.h"
#include "ICallback.h"
#include "Observable.h"
#include "ViewsCarriage/IViewsPen.h"
#include "Pen/IPen.h"
#include "LocalizationIdentifiers.h"
#include "Cds/ICds.h"

class ViewsPenSlot;


/** This class describes the Views Pen.
*/

class ViewsPen : public IViewsPen,
                 public ICallback
{
public:

    /** public constructor.
     *   @param cdsInterface is the CDS interface
     *   @param myPen is the Engine Pen interface
     *   @param mySuppliesConfigurator is the Engine Supplies Configurator interface
     *   @param componentLog is the log created by the root component
     */
    ViewsPen(ICds * cdsInterface, IPen *myPen, ISuppliesConfigurator *mySuppliesConfigurator, Logging * componentLog);

    /** public destructor.
     */
    virtual ~ViewsPen();


    /** @name IViewsPen required functions.
     *  @{
     */        

    /** Method to get the feeding cartridges of a views pen
     *   @return a vector with the indexes (0..n-1) of the cartridges binded to this pen
     */
    std::vector<uint16_t> getFeedingCartridges();
	
	
    /** Method to get the jams of a views pen
     *   @return the jams of a views pen
     */
    uint32_t getJams();
	
    /** Method to get the total life consumption of a views pen
     *   @return the total life consumption of a views pen (number of cubics centimeters)
     */
    uint32_t getTotalLifeConsumption();
	
    /** Method to get the percent of ink fired for this views pen
     *   @return the percent of ink fired
     */
    uint32_t getPercentFired();
	
    /** Method to get the maximum recovery level for this views pen
     *   @return the maximum recovery level
     */
    uint32_t getMaxRecoveryLevel();
	
    /** Method to know whether non HP ink has been used for this views pen
     *   @return a boolean flag: true if non hp ink has been used, false otherwise
     */
    bool getNonHPInkUsed();
	
    /** Method to know whether expired ink has been used for this views pen
     *   @return a boolean flag: true if expired ink has been used, false otherwise
     */
    bool getExpiredInkUsed();


    /** @}
     */
    
    /** @name IInkConsumable required functions.
     *  @{
     */        

    /** Method returning the slot corresponding to this views Pen
     *  @return slot number (0..n-1)
     */
    uint32_t getSlotPosition();
	
	
    /** Method returning the status of the Views Pen as String Key (to be used later to get the real localized string)
     *   @return the string key corresponding to the status of the views Pen
     */
    l10n::StringKey getStatusAsStringKey();
	
    /** Method returning the warranty status of the Views Pen
     *   @return the warranty status of the Views Ink Consumable as defined in IInkConsumable::WarrantyStatus
     */
    uint32_t getWarrantyStatus();
	
    /** Method returning the warranty status of the Pen as String Key
     *   @return the String Key corresponding to the warranty status of the Pen
     */
    l10n::StringKey getWarrantyStatusAsStringKey();

    /** Method returning the Manufacturer date of a Ink Consumable
     *   The units are the number of seconds since 1/1/1970
     *   @return the manufacturer date of this pen
     */
    uint32_t getManufacturerDate();
	
    /** Method returning the installation date of a Ink Consumable 
     *   The units are the number of seconds since 1/1/1970
     *   @return the installation date of this pen
     */
    uint32_t getInstallDate();
	
    /** Method returning the warranty expiration date of a Ink Consumable 
     *   The units are the number of seconds since 1/1/1970
     *   @return the warranty expiration date of this pen
     */
    uint32_t getWarrantyExpirationDate();
	
    /** Returns whether a printhead is missing in a slot and it is required.
     *   There may be no printhead present but it may not be expected to be there now
     *   if you ask for the printhead present, use the boolean negative of this method
     *   
     *  @return true if a printhead is missing in the slot
     */
    bool isMissing();

    /** Method returning the CDS color(s) associated to this consumable
     *  @return a vector filled with the color(s)
     */
    std::vector<CDSColorId> getColors();

    /** Method returning the String Keys for the color(s) associated to this consumable
     *  @return a vector filled with the color(s) localization identifier(s)
     */
    std::vector<l10n::StringKey> getColorsAsStringKey();

    /** Method returning the String Keys for the color short identifier(s) associated to this consumable
     *  @return a vector filled with the color(s) localization identifier(s)
     */
    std::vector<l10n::StringKey> getColorShortIdsAsStringKey();

    /** @}
     */

    /** @name IConsumable required functions.
     *  @{
     */        

    /**
     * Get the serial number of this consumable
     * @return the serial number of this pen
     */
    std::string getSerialNumber();

    /** Method returning the manufacturer type of the Views Consumable
     *   @return the manufacturer type as defined in IConsumable::ManufacturerType
     */
    uint32_t getManufacturer();

    /**
     * Get the order number of this consumable
     * @return the order number of this pen
     */
    std::string getOrderNumber();
	
    /**
     * Get the part number of this consumable
     * @return the part number of this pen
     */
    std::string getPartNumber();
	
    /**
     * Get the printable order number of this consumable 
     * usually the printable order number is the order number plus the "HP" prefix 
     * 
     * @return the printable order number of this pen
     */
    std::string getPrintableOrderNumber();
	
    /** @}
     */


    /** @name ICallback required functions.
     *  @{
     */        
	
    /** Method to be called by the observable object.
     *  @param object that forced the execution of this method.
     *  @param reason for the callback, a new value in the user reported status of the engine Pen
     *  @return integer flag indicating if method has finished OK
     */
    uint32_t callback(ICallbacker &object, uint32_t reason);

    /** @}
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

protected:

    /** ViewsPenSlot is a friend class because it needs to access the getEnginePen method
     */
    
    /** @name IObservable required protected functions.
     *  @{
     */        
	
    /** This method should be called by the observable to notify all the attached observers of this views pen.
     *   @param reason is the reason for the callback, it has to be defined in the class using this callback.
     */
    void notify(uint32_t reason);

    /** @}
     */


private:

    /** @name IInkConsumable required functions.
     *  @{
     */        

    /** Method returning the status of the Views Pen
     *   @return the result of the ORing the bits as defined in ViewsPen::UserReportedStatus
     */
    uint32_t getStatus();
	
    /** @}
     */
	
    
    /** Pointer to the engine pen. It allows access to his interface.
     */
    IPen *pen_;

    /** The pointer to the engine CDS instance. It allows access to his interface.
     */
    ICds *cds_;

    /** Cds internal class object for IDS-PH-1..n-WARRANTY-STATUS
     */
    Cds::CdsObject *cdsWarrantyStatusObject_;
    
    /** Cds internal class object for IDS-PH-1..n-TOTAL-LIFE-CONSUMPTION
     */
    Cds::CdsObject *cdsTotalLifeConsumptionObject_;
            
    /** Cds internal class object for IDS-PH-1..n-PERCENT-FIRED
     */
    Cds::CdsObject *cdsPercentFiredObject_;
    
    /** Cds internal class object for IDS-PH-1..n-MAX-RECOVERY-LEVEL
     */
    Cds::CdsObject *cdsMaxRecoveryLevelObject_;

    /** Cds internal class object for IDS-PH-1..n-NON-HP-INK
     */
    Cds::CdsObject *cdsNonHpInkUsedObject_;

    /** Cds internal class object for IDS-PH-1..n-EXPIRED-INK-USED
     */
    Cds::CdsObject *cdsExpiredInkUsedObject_;


    /** Pointer to the engine supplies configurator. It allows access to his interface.
     */
    ISuppliesConfigurator *suppliesConfigurator_;

    /**
     * To write logs in the system
     */
    Logging *log_;
    
    /**
     * To implement the IObservable interface we will use delegation on a Observable object
     */
    Observable *myObservable_;

};

#endif
