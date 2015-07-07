/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ViewsInkSupply.cpp
 *  @author Xavier Santotomas
 *  @date   Wed Nov 21 15:56:35 CET 2007
 *  @brief  Views Ink Supply
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 
#include "ViewsInkSupply.h"

//necessary for the assert_removable 
#include "SystemManager/SystemManager.h"


/** public constructor.
 *   @param myCartridge is the engine instance for the Ink supply.
 */
ViewsInkSupply::ViewsInkSupply(IInkSupply *myCartridge, Logging *componentLogging)
{
	log_ = componentLogging;
	
	cartridge_ = myCartridge;

    	log_->log(0,"ViewsInkSupply: My slot is: %d\n", cartridge_->getSlot());

	cartridge_->setOnChange(this);

	myObservable_ = new Observable(componentLogging);
	
}

/** public destructor.
 */
ViewsInkSupply::~ViewsInkSupply()
{
	delete myObservable_;
}

/** Method returning the absolut ink level of this Ink Supply
 *   @return an integer with the absolut ink level (milliliters)
 */
int32_t ViewsInkSupply::getAbsolutInkLevel()
{
	Volume inkLevelVolume;
	Result res = cartridge_->getInkLevel(inkLevelVolume);
	
	if (res == RESULT_OK)
		return inkLevelVolume.getCc();
	else 
		return -1;
}

/** Method returning the percentual ink level of this Ink Supply
 *   @return an integer with the percentual ink level (in 1/10000 units, so 56.78% should be 5678)
 */
int32_t ViewsInkSupply::getPercentualInkLevel()
{
	Volume inkLevelVolume;
	Volume capacityVolume;
	Result res1 = cartridge_->getInkLevel(inkLevelVolume);	
	Result res2 = cartridge_->getInkCapacity(capacityVolume);	
	
	if (res1 == RESULT_OK && res2 == RESULT_OK)
		return (int32_t)(((double)inkLevelVolume.getPl() / (double)capacityVolume.getPl())*10000);
	else 
		return -1;
}
	
/** Method returning if the status of the cartridge is unknown or not
 *   @return boolean flag
 */
bool ViewsInkSupply::isUnknown() 
{
	return (getStatus() & ViewsInkSupply::UNKNOWN) != 0;
}


/** Method returning the  expiration date of a Views Ink Supply
 *   @return the expiration date (number of seconds since 1/1/1970)
 */
uint32_t ViewsInkSupply::getExpirationDate() 
{
	struct tm date;
	
	Result res = cartridge_->getExpirationDate(date);
	if (res == RESULT_OK)
		return (uint32_t)mktime(&date);
	else
		return 0;
}

/** Method returning the Views Ink Supply Type associated to this instance of Ink Supply
 *   @return the type associated to this instance of ink supply (check against null)
 */
IViewsInkSupplyType* ViewsInkSupply::getInkSupplyType()
{
	return type_;
}

/** Method returning the status of the Views Ink Consumable (warning: this is a bitset)
 *   @return the result of the ORing the bits as defined in ViewsInkSupply::UserReportedStatus
 */
uint32_t ViewsInkSupply::getStatus()
{
	return cartridge_->getUserReportedStatus();
}

/** Method returning the status of the Views Ink Consumable as String Key (to be used later to get the real localized string)
 *   @return the string key corresponding to the status of the Views Ink Consumable
 */
StringKey ViewsInkSupply::getStatusAsStringKey()
{
	/* This is the priority schema:
	   Errors:
	       Missing / Not present
	       Empty
	       Faulty / Error
	       Reseat
	   Warnings:
	       Very low level
	       Low level
	       Unknown
	*/
	
	uint32_t value = getStatus();
	
	if ((value | ViewsInkSupply::OK) == 0) {
		return std::string("STRING_OK");
	} else if ((value & ViewsInkSupply::NOT_PRESENT) != 0) {
	    	return std::string("STRING_MISSING");
	} else if ((value & ViewsInkSupply::EMPTY) != 0) {
	    	return std::string("STRING_EMPTY");
	} else if ((value & ViewsInkSupply::ERROR) != 0) {
	    	return std::string("STRING_REPLACE");
	} else if ((value & ViewsInkSupply::RESEAT) != 0) {
	    	return std::string("STRING_RESEAT");
	} else if ((value & ViewsInkSupply::EXPIRED) != 0) {
	    	return std::string("STRING_EXPIRED");
	} else if ((value & ViewsInkSupply::VERY_LOW_LEVEL) != 0) {
	    	return std::string("STRING_VERY_LOW_INK");
	} else if ((value & ViewsInkSupply::LOW_LEVEL) != 0) {
	    	return std::string("STRING_LOW");
	} else if ((value & ViewsInkSupply::UNKNOWN) != 0) {
	    	return std::string("STRING_UNAPPROVED");
	} else {
	    	return std::string("UNKNOWN");
	}
	
}

/** Method returning the warranty status of the Views Ink Consumable
 *   @return the warranty status of the Views Ink Consumable as defined in IInkConsumable::WarrantyStatus
 */
uint32_t ViewsInkSupply::getWarrantyStatus()
{
	//TODO: Pending of the engine providing an alternative interface to the CDS
	return IDS_WARRANTY_STATUS_ON_WARRANTY;
}

/** Method returning the warranty status of the Pen as String Key
 *   @return the String Key corresponding to the warranty status of the Pen
 */
StringKey ViewsInkSupply::getWarrantyStatusAsStringKey()
{	
	switch (getWarrantyStatus()) {
		case IDS_WARRANTY_STATUS_ON_WARRANTY:
                		return std::string("ON_WARRANTY");
		case IDS_WARRANTY_STATUS_OUT_OF_WARRANTY:
                		return std::string("OUT_OF_WARRANTY");
 		case IDS_WARRANTY_STATUS_WARRANTY_WARNING:
                		return std::string("WARRANTY_WARNING");
            		default :
                		return std::string("UNKNOWN");
		}
}


/** Method returning the Manufacturer date of a Ink Consumable
 *  @return the manufacturer date of this Ink Consumable (number of seconds since 1/1/1970)
 */
uint32_t ViewsInkSupply::getManufacturerDate()
{
	//TODO: Pending of the engine providing an alternative interface to the CDS
	return 1158966000;
}


/** Method returning the installation date of a Ink Consumable 
 *   @return the installation date of this Ink Consumable (number of seconds since 1/1/1970)
 */
uint32_t ViewsInkSupply::getInstallDate()
{
	//TODO: Pending of the engine providing an alternative interface to the CDS
	return 1185798888;
}


/** Method returning the warranty expiration date of a Ink Consumable 
 *   @return the warranty expiration date of this Ink Consumable (number of seconds since 1/1/1970)
 */
uint32_t ViewsInkSupply::getWarrantyExpirationDate()
{
	struct tm date;
	
	Result res = cartridge_->getEndWarrantyDate(date);
	if (res == RESULT_OK)
		return (uint32_t)mktime(&date);
	else
		return 0;
}


/** Returns whether a Ink Consumable is missing in a slot and it is required.
 *   There may be no Ink Consumable present but it may not be expected to be there now
 *   @return true if a Ink Consumable is missing in the slot
 */
bool ViewsInkSupply::isMissing()
{
	return (getStatus() & ViewsInkSupply::NOT_PRESENT) != 0;
}


/**
 * Get the serial number of this consumable
 * @return the serial number of this Consumable
 */
std::string ViewsInkSupply::getSerialNumber()
{
	IInkSupply::InkSupplySerialNumber serialNumber;
	std::string sn(""); //initially empty
	
	Result res = cartridge_->getSerialNumber(serialNumber);
	if (res == RESULT_OK) 
	{
		sn = serialNumber.get();
	}
	return sn;
}

/** Method returning the manufacturer type of the Views Consumable
 *   @return the manufacturer type as defined in IConsumable::ManufacturerType
 */
uint32_t ViewsInkSupply::getManufacturer()
{
	//TODO: put here the real implementation
	return IConsumable::HP;
}


/** Method to be called by the observable object.
 *   @param object that forced the execution of this method.
 *   @param reason for the callback, a new value in the status of the engine Ink Supply
 *   @return integer flag indicating if method has finished OK
 */
uint32_t ViewsInkSupply::callback(ICallbacker &object, uint32_t reason)
{    	
    	notify(reason); //the reason for the observers is the status of the callBackerInkSupply
    	return RESULT_OK;
}


/** Method to register an observer for this views cartridge.
 *   @param observer object to be registered. Later will be notified.
 */
void ViewsInkSupply::registerObserver(IObserver &observer)
{
	myObservable_->registerObserver(observer);
}



/** Method to unregister an observer for this views cartridge.
 *   @param observer object to be unregistered. No more notifications will be received.
 */
void ViewsInkSupply::unregisterObserver(IObserver &observer)
{
	myObservable_->unregisterObserver(observer);
}



/** This method should be called by the observable to notify all the attached observers of this views cartridge.
 *   @param reason is the status of the Engine Ink Supply
 */
void ViewsInkSupply::notify(uint32_t reason)
{
	myObservable_->notify(reason);	
}

/** Method to register the type associated to this instance of Ink Supply
 *   @param type is the associated type
 */
void ViewsInkSupply::registerType(ViewsInkSupplyType *type)
{
	type_ = type;
}


/** Method returning the slot corresponding to this views Ink Supply
 *  @return slot number (0..n-1)
 */
uint32_t ViewsInkSupply::getSlotPosition() 
{
	return cartridge_->getSlot();
}

