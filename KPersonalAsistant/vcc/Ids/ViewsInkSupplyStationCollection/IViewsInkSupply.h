/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   IViewsInkSupply.h
 *  @author Xavier Santotomas
 *  @date  Tue Nov 20 15:24:10 CET 2007
 *  @brief  Views Ink Supply Abstract
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 


#ifndef __IViewsInkSupply_h_
#define __IViewsInkSupply_h_

#include "IObservable.h"
#include "util/IInkConsumable.h"
#include "CDS/ViewsEnum.h"

/** This class describes the Views Ink Supply abstraction interface.
 *    This interface (IViewsInkSupply) should contain the methods belonging to a specific instance of a Ink Supply,
 */
class IViewsInkSupply : public IObservable,
                        public IInkConsumable
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

    /** @name IViewsInkSupply public methods.
        @{
    */

    /** Method returning the absolut ink level of this Ink Supply
     *   @return an integer with the absolut ink level (milliliters)
     */
    virtual int32_t getAbsolutInkLevel() = 0;
	
    /** Method returning the percentual ink level of this Ink Supply
     *   @return an integer with the percentual ink level (in 1/10000 units, so 56.78% should be 5678)
     */
    virtual int32_t getPercentualInkLevel() = 0;
	
    /** Method returning if the status of the cartridge is unknown or not
     *   @return boolean flag
     */
    virtual bool isUnknown() = 0;
	
    /** Method returning the  expiration date of a Views Ink Supply
     *   @return the expiration date (number of seconds since 1/1/1970)
     */
    virtual uint32_t getExpirationDate() = 0;
		
    /** Method returning the  labeled size of a Views Ink Supply
     *   @return the maximum ink cartridge capacity (units are milliliters)
     *   @note When it is unknown because the supply is not present or is  not validated the value should be -1.
     */
    virtual int32_t getLabeledSize() = 0;

    /** @}
     */
    
};

#endif
