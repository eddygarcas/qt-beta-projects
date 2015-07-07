/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ViewsInkSupply.h
 *  @author Xavier Santotomas
 *  @date   Tue Nov 20 15:35:44 CET 2007
 *  @brief  Views Ink Supply abstract header file
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 


#ifndef __ViewsInkSupply_h_
#define __ViewsInkSupply_h_

#include "ViewsInkSupplyStationCollection/IViewsInkSupply.h"
#include "InkSupply/IInkSupply.h"
#include "ICallback.h"
#include "Logging.h"
#include "Observable.h"
#include "Cds/ICds.h"
#include "LocalizationIdentifiers.h"


/** This class describes the Views Ink Supply implementation.
 */
class ViewsInkSupply : public IViewsInkSupply,
                       public ICallback
{

public:

    /** public constructor.
     *   @param cdsInterface is the CDS interface
     *   @param myCartridge is the engine instance for the Ink supply.
     *   @param componentLogging is the log created by the root component
     */
    ViewsInkSupply(ICds * cdsInterface, IInkSupply *myCartridge, Logging *componentLogging);

    /** public destructor.
     */
    virtual ~ViewsInkSupply();

    /** @name IViewsInkSupply required functions.
     *  @{
     */        
    
    /** Method returning the absolut ink level of this Ink Supply
     *   @return an integer with the absolut ink level (milliliters)
     */
    int32_t getAbsolutInkLevel();
	
    /** Method returning the percentual ink level of this Ink Supply
     *   @return an integer with the percentual ink level (%)
     */
    int32_t getPercentualInkLevel();
	
    /** Method returning if the status of the cartridge is unknown or not
     *   @return boolean flag
     */
    bool isUnknown();
	
    /** Method returning the  expiration date of a Views Ink Supply
     *   @return the expiration date (number of seconds since 1/1/1970)
     */
    uint32_t getExpirationDate();
	
	
    /** Method returning the  labeled size of a Views Ink Supply
     *   @return the maximum ink cartridge capacity (units are milliliters)
     *   @note When it is unknown because the supply is not present or is  not validated the value should be -1.
     */
    int32_t getLabeledSize();

    /** @}
     */
    
    /** @name IInkConsumable required functions.
     *  @{
     */        

    /** Method returning the slot corresponding to this views Ink Supply
     *  @return slot number (0..n-1)
     */
    uint32_t getSlotPosition();

    /** Method returning the status of the Views Ink Consumable as String Key (to be used later to get the real localized string)
     *   @return the string key corresponding to the status of the Views Ink Consumable
     */
    l10n::StringKey getStatusAsStringKey();
	
    /** Method returning the warranty status of the Views Ink Consumable
     *   @return the warranty status of the Views Ink Consumable as defined in IInkConsumable::WarrantyStatus
     */
    uint32_t getWarrantyStatus();
	
    /** Method returning the warranty status of the Pen as String Key
     *   @return the String Key corresponding to the warranty status of the Pen
     */
    l10n::StringKey getWarrantyStatusAsStringKey();

    /** Method returning the Manufacturer date of a Ink Consumable
     *   The units are the number of seconds since 1/1/1970
     *   @return the manufacturer date of this Ink Consumable
     */
    uint32_t getManufacturerDate();
	
    /** Method returning the installation date of a Ink Consumable 
     *   The units are the number of seconds since 1/1/1970
     * @return the installation date of this Ink Consumable
     */
    uint32_t getInstallDate();
	
    /** Method returning the warranty expiration date of a Ink Consumable 
     *   The units are the number of seconds since 1/1/1970
     *   @return the warranty expiration date of this Ink Consumable
     */
    uint32_t getWarrantyExpirationDate();
	
    /** Returns whether a Ink Consumable is missing in a slot and it is required.
     *   There may be no Ink Consumable present but it may not be expected to be there now
     *   
     *   @return true if a Ink Consumable is missing in the slot
     */
    bool isMissing();

    /** Method returning the CDS color(s) associated to this consumable
     *  @return a vector filled with the color(s) identifier(s) as defined in IInkConsumable::CDSColor
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
     * @return the serial number of this Consumable
     */
    std::string getSerialNumber();
	
    /** Method returning the manufacturer type of the Views Consumable
     *   @return the manufacturer type as defined in IConsumable::ManufacturerType
     */
    uint32_t getManufacturer();

    /**
     * Get the order number of this consumable
     * 
     * @return the order number
     */
    std::string getOrderNumber();
	
    /**
     * Get the printable order number of this consumable 
     * usually the printable order number is the order number plus the "HP" prefix 
     * 
     * @return the printable order number
     */
    std::string getPrintableOrderNumber();
	
    /**
     * Get the part number of this consumable
     * 
     * @return the part number
     */
    std::string getPartNumber();

    /** @}
     */
	
    /** @name ICallback required functions.
     *  @{
     */        
	
    /** Method to be called by the observable object.
     *  @param object that forced the execution of this method.
     *  @param reason for the callback, a new value in the status of the engine Ink Supply
     *  @return integer flag indicating if method has finished OK
     */
    uint32_t callback(ICallbacker &object, uint32_t reason);

    /** @}
     */

    /** @name IObservable required public functions.
     *  @{
     */        

    /** Method to register an observer for this views cartridge.
     *  @param observer object to be registered. Later will be notified.
     */
    void registerObserver(IObserver &observer);
	
	
    /** Method to unregister an observer for this views cartridge.
     *  @param observer object to be unregistered. No more notifications will be received.
     */
    void unregisterObserver(IObserver &observer);

    /** @}
     */

    
protected:


    /** @name IObservable required protected functions.
     *  @{
     */        

    /** This method should be called by the observable to notify all the attached observers of this views cartridge.
     *   @param reason is the status of the Engine Ink Supply
     */
    void notify(uint32_t reason);

    /** @}
     */
     
private:
	
    /** @name IInkConsumable required functions.
     *  @{
     */        

    /** Method returning the status of the Views Ink Consumable (warning: this is a bitset)
     *   @return the result of the ORing the bits as defined in ViewsInkSupply::UserReportedStatus
     */
    uint32_t getStatus();

    /** @}
     */
		

    /** Pointer to the engine cartridge. It allows access to his interface.
     */
    IInkSupply *cartridge_;
    	
    /**
     * To write logs in the system
     */
    Logging *log_;

    /**
     * To implement the IObservable interface we will use delegation on a Observable object
     */
    Observable *myObservable_;

    /** The pointer to the engine CDS instance. It allows access to his interface.
     */
    ICds *cds_;

    /** Cds internal class object for IDS-CTG-1..n-WARRANTY-STATUS
     */
    Cds::CdsObject *cdsWarrantyStatusObject_;

    /** Cds internal class object for IDS-CTG-1..n-MANUFACTURER-DATE
     */
    Cds::CdsObject *cdsManufacturerDateObject_;

    /** Cds internal class object for IDS-CTG-1..n-INSTALL-DATE
     */
    Cds::CdsObject *cdsInstallDateObject_;

    /** Cds internal class object for IDS-CTG-1..n-MANUFACTURER-TYPE
     */
    Cds::CdsObject *cdsManufacturerTypeObject_;
    
    /** Cds internal class object for IDS-CTG-1..n-LABELED-SIZE
     */
    Cds::CdsObject *cdsLabeledSizeObject_;

    /** CDS color id for this instance
     */
    CDSColorId color_;

};

#endif
