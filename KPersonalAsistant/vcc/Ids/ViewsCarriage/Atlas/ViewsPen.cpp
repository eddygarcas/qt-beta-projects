/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ViewsPen.cpp
 *  @author Xavier Santotomas
 *  @date   Jun 29 2007
 *  @brief  Views Pen
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 

#include <string.h>
#include <time.h>
#include "views_util.h"
#include "Pen/PenAcumen.h"
#include "ViewsPen.h"
#include "LocalizationIdentifiers.h"

/** public constructor.
 *   @param cdsInterface is the CDS interface
 *   @param myPen is the Engine Pen interface
 *   @param mySuppliesConfigurator is the Engine Supplies Configurator interface
 *   @param componentLog is the log created by the root component
 */
ViewsPen::ViewsPen(ICds * cdsInterface, IPen *myPen, ISuppliesConfigurator *mySuppliesConfigurator, Logging * componentLog) 
{
    log_ = componentLog;
    pen_ = myPen;
    cds_ = cdsInterface;
    suppliesConfigurator_ = mySuppliesConfigurator;
    pen_->setUserStatusOnChange(this);
	
    myObservable_ = new Observable(componentLog);
	
    //We initialize keys for CDS objects
    Cds::CdsResult result;
    std::string cdsKey;
	
    //IDS-PH-1..n-WARRANTY-STATUS
    cdsKey = buildCdsKey("IDS-PH-",getSlotPosition()+1,"-WARRANTY-STATUS");
    result = cds_->find(cdsKey.c_str(), &cdsWarrantyStatusObject_);
    assert_removable(result == Cds::CDS_SUCCESS);
	
    //IDS-PH-1..n-TOTAL-LIFE-CONSUMPTION
    cdsKey = buildCdsKey("IDS-PH-",getSlotPosition()+1,"-TOTAL-LIFE-CONSUMPTION");
    result = cds_->find(cdsKey.c_str(), &cdsTotalLifeConsumptionObject_);
    assert_removable(result == Cds::CDS_SUCCESS);
	
    //IDS-PH-1..n-PERCENT-FIRED
    cdsKey = buildCdsKey("IDS-PH-",getSlotPosition()+1,"-PERCENT-FIRED");
    result = cds_->find(cdsKey.c_str(), &cdsPercentFiredObject_);
    assert_removable(result == Cds::CDS_SUCCESS);
	
    //IDS-PH-1..n-MAX-RECOVERY-LEVEL
    cdsKey = buildCdsKey("IDS-PH-",getSlotPosition()+1,"-MAX-RECOVERY-LEVEL");
    result = cds_->find(cdsKey.c_str(), &cdsMaxRecoveryLevelObject_);
    assert_removable(result == Cds::CDS_SUCCESS);
	
    //IDS-PH-1..n-NON-HP-INK
    cdsKey = buildCdsKey("IDS-PH-",getSlotPosition()+1,"-NON-HP-INK");
    result = cds_->find(cdsKey.c_str(), &cdsNonHpInkUsedObject_);
    assert_removable(result == Cds::CDS_SUCCESS);
	
    //IDS-PH-1..n-EXPIRED-INK-USED
    cdsKey = buildCdsKey("IDS-PH-",getSlotPosition()+1,"-EXPIRED-INK-USED");
    result = cds_->find(cdsKey.c_str(), &cdsExpiredInkUsedObject_);
    assert_removable(result == Cds::CDS_SUCCESS);
	
	
}

/** public destructor.
 */
ViewsPen::~ViewsPen()
{
    delete myObservable_;
}

/** Method returning the status of the Views Pen
 *   @return the result of the ORing the bits as defined in ViewsPen::UserReportedStatus
 */
uint32_t ViewsPen::getStatus() 
{	
    return pen_->getUserReportedStatus();
}

/** Method returning the status of the Views Pen as String Key (to be used later to get the real localized string)
 *  @return the string key corresponding to the status of the views Pen
 */
l10n::StringKey ViewsPen::getStatusAsStringKey() 
{
  
    uint32_t value = getStatus();
  	  
    if ((value | ViewsPen::WORKING) == 0) { 
        // as ViewsPen::WORKING is 0, this first condition is saying that the pen is working <-> the value of getStatus is 0
        return l10n::STRING_OK;
    } else if ((value & ViewsPen::NO_PEN) != 0) {
        return l10n::STRING_MISSING;
    } else if ((value & ViewsPen::REPLACE) != 0) {
        return l10n::STRING_REPLACE;
    } else if ((value & ViewsPen::RESEAT) != 0) {
        return l10n::STRING_RESEAT;
    } else if ((value & ViewsPen::REMOVE) != 0) {
        return l10n::STRING_REMOVE;
    } else {
        return l10n::UNKNOWN;
    }

}

/** Method returning the warranty status of the Pen as String Key
 *   @return the String Key corresponding to the warranty status of the Pen
 */
l10n::StringKey ViewsPen::getWarrantyStatusAsStringKey()
{
    switch (getWarrantyStatus()) {
    case IDS_WARRANTY_STATUS_ON_WARRANTY:
        return l10n::ON_WARRANTY;
    case IDS_WARRANTY_STATUS_OUT_OF_WARRANTY:
        return l10n::OUT_OF_WARRANTY;
    case IDS_WARRANTY_STATUS_WARRANTY_WARNING:
        return l10n::WARRANTY_WARNING;
    default :
        return l10n::UNKNOWN;
    }
}

/** Method returning the warranty status of the Views Pen
 *   @return the warranty status of the Views Ink Consumable as defined in IInkConsumable::WarrantyStatus
 */
uint32_t ViewsPen::getWarrantyStatus()
{	
    Cds::CdsResult result;
    uint32_t value;
  	
    result = cdsWarrantyStatusObject_->get(value);
    assert_removable(result == Cds::CDS_SUCCESS);
	
    return value;	
}



/** Method to be called by the observable object.
 *  @param object that forced the execution of this method.
 *  @param reason for the callback, a new value in the user reported status of the engine Pen
 *  @return integer flag indicating if method has finished OK
 */
uint32_t ViewsPen::callback(ICallbacker &object, uint32_t reason) 
{
    IPen &callBackerPen = (IPen &)object;
    		
    	
    log_->log(0, "ViewsPen: I'm being notified by Pen%d !!! reason: %d \n",callBackerPen.getSlot(), reason);


    notify(reason); //the reason for the observers is the status of the callBackerPen
    return RESULT_OK;
}


/** Method returning the slot corresponding to this views Pen
 *  @return slot number (0..n-1)
 */
uint32_t ViewsPen::getSlotPosition()
{
    return pen_->getSlot();
}

/** Method to get the feeding cartridges of a views pen
 *   @return a vector with the indexes (0..n-1) of the cartridges binded to this pen
 */
std::vector<uint16_t> ViewsPen::getFeedingCartridges()
{
    std::vector<uint16_t> ctgCollection;

    ISuppliesConfigurator::SlotSet isSlots;
    ISuppliesConfigurator::SlotSet penSlots;
	
    penSlots.insert(pen_->getSlot());
	
    suppliesConfigurator_->getSuppliesFromPh(penSlots, isSlots);
    for (ISuppliesConfigurator::SlotSet::iterator i = isSlots.begin(); i != isSlots.end(); i++)
    {
        // slots are numbered from (0..n-1)
        ctgCollection.push_back(*i);
    }
	
    return ctgCollection;
}


/** Method to get the jams of a views pen
 *   @return the jams of a views pen
 */
uint32_t ViewsPen::getJams()
{
    uint32_t numberOfJams  = 0;
    if (pen_->getAcumen() != NULL) 
    {
        Result res = pen_->getAcumen()->getNumberOfPaperJams( numberOfJams);
        assert_removable(res == RESULT_OK);
    }
            	
    return numberOfJams;
}

/** Method to get the total life consumption of a views pen
 *   @return the total life consumption of a views pen ((number of cubics centimeters))
 */
uint32_t ViewsPen::getTotalLifeConsumption()
{
    Cds::CdsResult result;
    int32_t value;
  	
    result = cdsTotalLifeConsumptionObject_->get(value);
    assert_removable(result == Cds::CDS_SUCCESS);
	
    return (uint32_t)value;	
}


/** Method to get the percent of ink fired for this views pen
 *   @return the percent of ink fired
 */
uint32_t ViewsPen::getPercentFired()
{
    Cds::CdsResult result;
    int32_t value;
  	
    result = cdsPercentFiredObject_->get(value);
    assert_removable(result == Cds::CDS_SUCCESS);
	
    return (uint32_t)value;	
}
	
/** Method to get the maximum recovery level for this views pen
 *   @return the maximum recovery level
 */
uint32_t ViewsPen::getMaxRecoveryLevel()
{
    Cds::CdsResult result;
    int32_t value;
  	
    result = cdsMaxRecoveryLevelObject_->get(value);
    assert_removable(result == Cds::CDS_SUCCESS);
	
    return (uint32_t)value;	
}

/** Method to know whether non HP ink has been used for this views pen
 *   @return a boolean flag: true if non hp ink has been used, false otherwise
 */
bool ViewsPen::getNonHPInkUsed()
{
    Cds::CdsResult result;
    bool value;
  	
    result = cdsNonHpInkUsedObject_->get(value);
    assert_removable(result == Cds::CDS_SUCCESS);
	
    return value;	
}

/** Method to know whether expired ink has been used for this views pen
 *   @return a boolean flag: true if expired ink has been used, false otherwise
 */
bool ViewsPen::getExpiredInkUsed()
{
    Cds::CdsResult result;
    bool value;
  	
    result = cdsExpiredInkUsedObject_->get(value);
    assert_removable(result == Cds::CDS_SUCCESS);
	
    return value;	
}


/** Method to be called to register a new Observer.
 *  @param observer object to be registered. Later will be notified.
 */
void ViewsPen::registerObserver(IObserver &observer)
{
    myObservable_->registerObserver(observer);
}


/** Method to be called to unregister an existant Observer.
 *  @param observer object to be unregistered. No more notifications will be received.
 */
void ViewsPen::unregisterObserver(IObserver &observer)
{
    myObservable_->unregisterObserver(observer);
}


/** Method returning the CDS color(s) associated to this consumable
 *  @return a vector filled with the color(s) identifier(s) as defined in IInkConsumable::CDSColor
 */
std::vector<CDSColorId> ViewsPen::getColors()
{
    std::vector<CDSColorId> colorCollection;
    
    uint32_t numColors;
    
    // colors pointer should be filled by the getColors method 
    // aftet the call, the content of colors will be a pointer to an existent array 
    // (in fact, a pointer to a member variable of the Engine Pen implementation object) 
    Color::Id const *colors;
    
    pen_->getColors(colors, numColors);
    
    for (uint32_t i = 0; i < numColors; i++)
    {
    	colorCollection.push_back(suppliesConfigurator_->getCdsColorFromColor(colors[i]));
    }
    return colorCollection;
	
}

/** Method returning the manufacturer type of the Views Consumable
 *   @return the manufacturer type as defined in IConsumable::ManufacturerType
 */
uint32_t ViewsPen::getManufacturer()
{
    uint32_t oemId;

    uint32_t  oemName = IConsumable::UNKNOWN;
    if (pen_->getAcumen() != NULL) 
    {
        Result res = pen_->getAcumen()->getOEMId(oemId);
        if ( res == RESULT_OK )
        {
            if (oemId == 1)
            {
                oemName = IConsumable::HP;
            }
            else
            {
                oemName = IConsumable::APPROVED_OEM;
            }
        }
    }
    return oemName;    	
}

/** Method returning the Manufacturer date of a Ink Consumable
 *    @return the manufacturer date of the pen (Number of seconds since 1/1/1970)
 */
uint32_t ViewsPen::getManufacturerDate()
{
    struct tm date;
    if (pen_->getAcumen() != NULL) 
    {
        Result res = pen_->getAcumen()->getManufacturingDate(date);
        assert_removable(res == RESULT_OK);
        return (uint32_t)mktime(&date);
    }
    else 
        return 0;
}

/**
 * Get the printable order number of this consumable 
 * usually the printable order number is the order number plus the "HP" prefix 
 * @return the printable order number 
 */
std::string ViewsPen::getPrintableOrderNumber()
{
    std::string str = "HP ";
    return str.append( getOrderNumber() );
}



/**
 * Get the order number of this consumable
 * @return the order number
 */
std::string ViewsPen::getOrderNumber()
{
    return pen_->getOrderNumber();
}

/**
 * Get the part number of this consumable
 * @return the part number
 */
std::string ViewsPen::getPartNumber()
{
    return pen_->getPartNumber();
}

/**
 * Get the serial number of this consumable
 * @return the serial number of this pen
 */
std::string ViewsPen::getSerialNumber()
{
    SerialNumber sn;

    if (pen_->getAcumen() != NULL) 
    {
        Result res = pen_->getAcumen()->getSerialNumber(sn);
        assert_removable(res == RESULT_OK);
        std::string serialNumberString(sn.get());
        return serialNumberString;            
    } 
    else
        return 0;
            	
}

/** Method returning the installation date of a Ink Consumable 
 *   @return the installation date of this pen (Number of seconds since 1/1/1970)
 */
uint32_t ViewsPen::getInstallDate()
{
    struct tm date;

    if (pen_->getAcumen() != NULL) 
    {
        Result res = pen_->getAcumen()->getInsertionDate(date);
        assert_removable(res == RESULT_OK);
        return (uint32_t)mktime(&date);
    }
    else
        return 0;
}

/** Method returning the warranty expiration date of a Ink Consumable 
 *   @return the warranty expiration date of this pen (Number of seconds since 1/1/1970)
 */
uint32_t ViewsPen::getWarrantyExpirationDate() 
{
    struct tm date;

    if (pen_->getAcumen() != NULL) 
    {
        Result res = pen_->getAcumen()->getEndOfWarrantyDate(date);
        assert_removable(res == RESULT_OK);
        return (uint32_t)mktime(&date);
    }
    else
        return 0;

}

/** Returns whether a printhead is missing in a slot and it is required.
 *   There may be no printhead present but it may not be expected to be there now
 *   if you ask for the printhead present, use the boolean negative of this method
 *   
 *  @return true if a printhead is missing in the slot
 */
bool ViewsPen::isMissing()
{
    return (getStatus()  & ViewsPen::NO_PEN) != 0; 
}


/** This method should be called by the observable to notify all the attached observers.
 *  @param reason is the reason for the callback, it has to be defined in the class using this callback.
 */
void ViewsPen::notify(uint32_t reason)
{
    myObservable_->notify(reason);
}


/** Method returning the String Keys for the color(s) associated to this consumable
 *  @return a vector filled with the color(s) localization identifier(s)
 */
std::vector<l10n::StringKey> ViewsPen::getColorsAsStringKey()
{
	std::vector<l10n::StringKey> colorLocIdsCollection;
	std::vector<CDSColorId> colorCollection = getColors();

	for(uint16_t i = 0; i < colorCollection.size(); i++) 
	{
		colorLocIdsCollection.push_back(getColorAsStringKey(colorCollection[i], false));
	}

	return colorLocIdsCollection;
}

/** Method returning the String Keys for the color short identifier(s) associated to this consumable
 *  @return a vector filled with the color(s) localization identifier(s)
 */
std::vector<l10n::StringKey> ViewsPen::getColorShortIdsAsStringKey()
{
	std::vector<l10n::StringKey> colorLocIdsCollection;
	std::vector<CDSColorId> colorCollection = getColors();

	for(uint16_t i = 0; i < colorCollection.size(); i++) 
	{
		colorLocIdsCollection.push_back(getColorAsStringKey(colorCollection[i], true));
	}

	return colorLocIdsCollection;
}
