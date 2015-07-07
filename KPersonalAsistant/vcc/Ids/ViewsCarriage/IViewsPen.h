/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   IViewsPen.h
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


#ifndef __IViewsPen_h_
#define __IViewsPen_h_

#include "IObservable.h"
#include "util/IInkConsumable.h"
#include "CDS/ViewsEnum.h"


/** This class describes the Views Pen abstraction interface.
*/
class IViewsPen : public IObservable,
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
	WORKING = IDS_PRINT_HEAD_USER_REPORTED_STATUS_WORKING,
        /**
         * bit 0
         */
	NO_PEN = IDS_PRINT_HEAD_USER_REPORTED_STATUS_NO_PEN,
        /**
         * bit 1
         */
	REPLACE = IDS_PRINT_HEAD_USER_REPORTED_STATUS_REPLACE,
        /**
         * bit 2
         */
	RESEAT = IDS_PRINT_HEAD_USER_REPORTED_STATUS_RESEAT,
        /**
         * bit 3
         */
	REMOVE = IDS_PRINT_HEAD_USER_REPORTED_STATUS_REMOVE,
        /**
         * bit 4
         */
	REPLACEMENT_INCOMPLETE = IDS_PRINT_HEAD_USER_REPORTED_STATUS_REPLACEMENT_INCOMPLETE,
        /**
         * bit 5
         */
	TEST_SEPARATELY = IDS_PRINT_HEAD_USER_REPORTED_STATUS_TEST_SEPARATELY
    };



    /** @name IViewsPen public methods.
      @{
    */
	
    /** Method to get the feeding cartridges of a views pen
     *   @return a vector with the indexes (0..n-1) of the cartridges binded to this pen
     */
    virtual std::vector<uint16_t> getFeedingCartridges() = 0;
		
    /** Method to get the jams of a views pen
     *   @return the jams of a views pen
     */
    virtual uint32_t getJams() = 0;
	
    /** Method to get the total life consumption of a views pen
     *   @return the total life consumption of a views pen (number of cubics centimeters)
     */
    virtual uint32_t getTotalLifeConsumption() = 0;
	
    /** Method to get the percent of ink fired for this views pen
     *   @return the percent of ink fired
     */
    virtual uint32_t getPercentFired() = 0;
	
    /** Method to get the maximum recovery level for this views pen
     *   @return the maximum recovery level
     */
    virtual uint32_t getMaxRecoveryLevel() = 0;
	
    /** Method to know whether non HP ink has been used for this views pen
     *   @return a boolean flag: true if non hp ink has been used, false otherwise
     */
    virtual bool getNonHPInkUsed() = 0;
	
    /** Method to know whether expired ink has been used for this views pen
     *   @return a boolean flag: true if expired ink has been used, false otherwise
     */
    virtual bool getExpiredInkUsed() = 0;

    /** @}
     */

};

#endif
