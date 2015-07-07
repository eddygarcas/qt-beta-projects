/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   IConsumable.h
 *  @author Xavier Santotomas
 *  @date   July 19 2007
 *  @brief  Views Consumable (pens, cartridges, medias ...) abstract interface
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 


#ifndef __IConsumable_h_
#define __IConsumable_h_

#include <string>
#include "CDS/ViewsEnum.h"


/** This class describes the Views Consumable abstract interface.
*    The IConsumable interface should contain all the methods from a concrete instance of a IConsumable.
*/
class IConsumable
{

public:

/**
 * Values for the Manufacturer Type of a Consumable (enumeration)
 */
enum ManufacturerType 
{
        	/**
         	 * Unknown
         	 */
	UNKNOWN = IDS_CTG_MANUFACTURER_TYPE_UNKNOWN, 
        	/**
         	 * HP
         	 */
	HP = IDS_CTG_MANUFACTURER_TYPE_HP,
        	/**
         	 * Approved Original Equipment Manufacturer
         	 */
	APPROVED_OEM = IDS_CTG_MANUFACTURER_TYPE_APPROVED_OEM,
        	/**
         	 * Non approved Original Equipment Manufacturer
         	 */
	NON_APPROVED = IDS_CTG_MANUFACTURER_TYPE_NON_APPROVED,
        	/**
         	 * The consumable is still not initialized
         	 */
	NOT_INITIALIZED = IDS_CTG_MANUFACTURER_TYPE_NOT_INITIALIZED
};

    /** @name IConsumable public methods.
      @{
    */
	
	/** Get the serial number of this consumable
	 *   @return the serial number of this consumable
	 */
	virtual std::string getSerialNumber() = 0;

	/** Method returning the manufacturer type of the Views Consumable
	 *   @return the manufacturer type as defined in IConsumable::ManufacturerType
	 */
	virtual uint32_t getManufacturer() = 0;

	/**
	 * Get the order number of this consumable
	 * 
	 * @return the order number
	 */
	virtual std::string getOrderNumber() = 0;
	
	/**
	 * Get the printable order number of this consumable 
	 * usually the printable order number is the order number plus the "HP" prefix 
	 * 
	 * @return the printable order number
	 */
	virtual std::string getPrintableOrderNumber() = 0;
	
	/**
	 * Get the part number of this consumable
	 * 
	 * @return the part number
	 */
	virtual std::string getPartNumber() = 0;

    /** @}
     */

};

#endif
