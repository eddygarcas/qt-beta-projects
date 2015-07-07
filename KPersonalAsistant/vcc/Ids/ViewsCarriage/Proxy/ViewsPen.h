/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ViewsPen.h
 *  @author Josep Giralt
 *  @date   Tue Jun  3 19:28:38 CEST 2008
 *  @brief  ViewsPen Proxy Component.
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2008.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 


#ifndef __ViewsPen_h_
#define __ViewsPen_h_

#include "Observable.h"
#include "IRpc.h"
#include "ViewsCarriage/IViewsPen.h"

/** This class describes the Views Pen.
*/
class ViewsPen : public IViewsPen, public ICallback
{
public:

    /** public constructor.
     *  @param rpc Pointer to the RPC interface to be used to interface with the remote pen.
     *  @param thePen Pointer to the remote pen interface.
     */
    ViewsPen(IRpc * rpc, IViewsPen * thePen);

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
    StringKey getStatusAsStringKey();
	
    /** Method returning the warranty status of the Views Pen
     *   @return the warranty status of the Views Ink Consumable as defined in IInkConsumable::WarrantyStatus
     */
    uint32_t getWarrantyStatus();
	
    /** Method returning the warranty status of the Pen as String Key
     *   @return the String Key corresponding to the warranty status of the Pen
     */
    StringKey getWarrantyStatusAsStringKey();

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

    /** @name IObservable required protected functions.
     *  @{
     */        
	
    /** This method should be called by the observable to notify all the attached observers of this views pen.
     *   @param reason is the reason for the callback, it has to be defined in the class using this callback.
     */
    void notify (uint32_t reason);

    /** @}
     */
private:

    /** Pointer to the Rpc interface
     */
    IRpc *      rpc_;

    /** Pointer to the remote IViewsPen * interface
     */
    IViewsPen * thePen_;

    /** make an RPC call and return an uint32_t
        @param id RPC identifier.
        @return the 32 bit value.
     */
    uint32_t rpcGetUint32 (uint32_t id);
    
    /** make an RPC call and return an std::string
        @param id RPC identifier.
        @return the C++ string value.
     */
    std::string rpcGetString (uint32_t id);
    
    /** make an RPC call and return a boolean
        @param id RPC identifier.
        @return the bool value.
     */
    bool rpcGetBool (uint32_t id);
    
};

#endif
