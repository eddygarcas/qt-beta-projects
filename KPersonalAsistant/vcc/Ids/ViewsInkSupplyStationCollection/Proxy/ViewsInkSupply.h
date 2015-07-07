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
#include "ViewsInkSupplyType.h"
#include "InkSupply/IInkSupply.h"
#include "ICallback.h"
#include "CDS/ViewsEnum.h"
#include "Logging.h"
#include "Observable.h"


/** This class describes the Views Ink Supply implementation.
*/
class ViewsInkSupply : public IViewsInkSupply,
		public ICallback
{

public:

/**
 * Values for the pen user reported status (bitset)
 */
enum UserReportedStatus 
{
        	/**
         	 * no bits set
         	 */
	OK = IDS_CARTRIDGE_USER_REPORTED_STATUS_OK,
        	/**
         	 * bit 0
         	 */
	NOT_PRESENT = IDS_CARTRIDGE_USER_REPORTED_STATUS_NOT_PRESENT,
        	/**
         	 * bit 1
         	 */
	EMPTY = IDS_CARTRIDGE_USER_REPORTED_STATUS_EMPTY,
        	/**
         	 * bit 2
         	 */
	ERROR = IDS_CARTRIDGE_USER_REPORTED_STATUS_ERROR,
        	/**
         	 * bit 3
         	 */
	LOW_LEVEL = IDS_CARTRIDGE_USER_REPORTED_STATUS_LOW_LEVEL,
        	/**
         	 * bit 4
         	 */
	RESEAT = IDS_CARTRIDGE_USER_REPORTED_STATUS_RESEAT,
        	/**
         	 * bit 5
         	 */
	UNKNOWN = IDS_CARTRIDGE_USER_REPORTED_STATUS_UNKNOWN,
        	/**
         	 * bit 6
         	 */
	VERY_LOW_LEVEL = IDS_CARTRIDGE_USER_REPORTED_STATUS_VERY_LOW_LEVEL,
        	/**
         	 * bit 7
         	 */
	EXPIRED = IDS_CARTRIDGE_USER_REPORTED_STATUS_EXPIRED
};

    /** public constructor.
        @param myCartridge is the engine instance for the Ink supply.
     */
    ViewsInkSupply(IInkSupply *myCartridge, Logging *componentLogging);

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
	
	/** Method returning the Views Ink Supply Type associated to this instance of Ink Supply
	 *   @return the type associated to this instance of ink supply (check against null)
	 */
	IViewsInkSupplyType *getInkSupplyType();

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
	StringKey getStatusAsStringKey();
	
	/** Method returning the warranty status of the Views Ink Consumable
	 *   @return the warranty status of the Views Ink Consumable as defined in IInkConsumable::WarrantyStatus
	 */
	uint32_t getWarrantyStatus();
	
	/** Method returning the warranty status of the Pen as String Key
 	 *   @return the String Key corresponding to the warranty status of the Pen
 	 */
	StringKey getWarrantyStatusAsStringKey();

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

    /** ViewsInkSupplySlot is a friend class because it needs to access the registerType method
     */
   friend class ViewsInkSupplySlot;
   
   /** Method to register the type associated to this instance of Ink Supply
    *   @param type is the associated type
    */
   void registerType(ViewsInkSupplyType *type);

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
    	
    /**  Type of Ink Supply associated to this instance of Ink Supply
     */
    ViewsInkSupplyType *type_;
    
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
