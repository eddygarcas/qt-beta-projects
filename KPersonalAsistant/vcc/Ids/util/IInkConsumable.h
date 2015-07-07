/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   IInkConsumable.h
 *  @author Xavier Santotomas
 *  @date   July 18 2007
 *  @brief  Views Ink Consumable (pens, cartridges...) abstract interface
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 


#ifndef __IInkConsumable_h_
#define __IInkConsumable_h_

#include <vector>

#include "IConsumable.h"
#include "CDS/ViewsEnum.h"
#include "LocalizationIdentifiers.h"

/**
 * A CDS Color Id
 */
typedef int16_t CDSColorId;


/** This class describes the Views Ink Consumable abstract interface.
 *    The IInkConsumable interface should contain all the methods from a concrete instance of a IInkConsumable.
 */
class IInkConsumable : public IConsumable
{

public:

    /**
     * Values for the Warranty Status of a Ink consumable (enumeration)
     */
    enum WarrantyStatus 
    {
        /**
         * The ink consumable is still on warranty
         */
	ON_WARRANTY = IDS_WARRANTY_STATUS_ON_WARRANTY,
        /**
         * The ink consumable is out of warranty
         */
	OUT_OF_WARRANTY = IDS_WARRANTY_STATUS_OUT_OF_WARRANTY,
        /**
         * The ink consumable has a warranty warning. Warranty warning means that it is not using HP ink (This doesn't apply to ink supplies)
         */
	WARRANTY_WARNING = IDS_WARRANTY_STATUS_WARRANTY_WARNING,
        /**
         * The ink consumable is still not initialized
         */
	NOT_INITIALIZED = IDS_WARRANTY_STATUS_NOT_INITIALIZED
    };

    /**
     * Values for the CDS color Identifiers (enumeration)
     */
    enum CDSColor 
    {
        /**
         * CYAN
         */
	CYAN = IDS_COLOR_CYAN,
        /**
         * MAGENTA
         */
	MAGENTA = IDS_COLOR_MAGENTA,
        /**
         * YELLOW
         */
	YELLOW = IDS_COLOR_YELLOW,
        /**
         * BLACK
         */
	BLACK = IDS_COLOR_BLACK,
        /**
         * RED
         */
	RED = IDS_COLOR_RED,
        /**
         * GREEN
         */
	GREEN = IDS_COLOR_GREEN,
        /**
         * BLUE
         */
	BLUE = IDS_COLOR_BLUE,
        /**
         * LIGHT_CYAN
         */
	LIGHT_CYAN = IDS_COLOR_LIGHT_CYAN,
        /**
         * LIGHT_MAGENTA
         */
	LIGHT_MAGENTA = IDS_COLOR_LIGHT_MAGENTA,
        /**
         * ORANGE
         */
	ORANGE = IDS_COLOR_ORANGE,
        /**
         * GRAY
         */
	GRAY = IDS_COLOR_GRAY,
        /**
         * LIGHT_GRAY
         */
	LIGHT_GRAY = IDS_COLOR_LIGHT_GRAY,
        /**
         * DARK_GRAY
         */
	DARK_GRAY = IDS_COLOR_DARK_GRAY,
        /**
         * GLOSS_ENHANCER
         */
	GLOSS_ENHANCER = IDS_COLOR_GLOSS_ENHANCER,
        /**
         * VIOLET
         */
	VIOLET = IDS_COLOR_VIOLET,
        /**
         * MATTE_BLACK
         */
	MATTE_BLACK = IDS_COLOR_MATTE_BLACK,
        /**
         * PHOTO_BLACK
         */
	PHOTO_BLACK = IDS_COLOR_PHOTO_BLACK
    };


    /** @name Views Ink Consumable public methods.
        @{
    */
	
    /** Method returning the slot corresponding to this views Ink Consumable
     *   @return slot number (0..n-1)
     */
    virtual uint32_t getSlotPosition() = 0;
		
    /** Method returning the status of the Views Ink Consumable as String Key (to be used later to get the real localized string)
     *   @return the string key corresponding to the status of the Views Ink Consumable
     */
    virtual l10n::StringKey getStatusAsStringKey() = 0;
	
    /** Method returning the warranty status of the Views Ink Consumable
     *   @return the warranty status of the Views Ink Consumable as defined in IInkConsumable::WarrantyStatus
     */
    virtual uint32_t getWarrantyStatus() = 0;
	
    /** Method returning the warranty status of the Pen as String Key
     *   @return the String Key corresponding to the warranty status of the Pen
     */
    virtual l10n::StringKey getWarrantyStatusAsStringKey() = 0;

    /** Method returning the Manufacturer date of a Ink Consumable 
     *   The units are the number of seconds since 1/1/1970
     */
    virtual uint32_t getManufacturerDate() = 0;
	
    /** Method returning the installation date of a Ink Consumable 
     *   The units are the number of seconds since 1/1/1970
     */
    virtual uint32_t getInstallDate() = 0;
	
    /** Method returning the warranty expiration date of a Ink Consumable 
     *   The units are the number of seconds since 1/1/1970
     */
    virtual uint32_t getWarrantyExpirationDate() = 0;
	
    /** Returns whether an Ink Consumable is missing in a slot and it is required.
     *   There may be no Ink Consumable present but it may not be expected to be there now
     *   
     *  @return true if an Ink Consumable is missing in the slot
     */
    virtual bool isMissing() = 0;

    /** Method returning the CDS color(s) associated to this consumable
     *  @return a vector filled with the color(s) identifier(s) as defined in IInkConsumable::CDSColor
     */
    virtual std::vector<CDSColorId> getColors() = 0;

    /** Method returning the String Keys for the color(s) associated to this consumable
     *  @return a vector filled with the color(s) localization identifier(s)
     */
    virtual std::vector<l10n::StringKey> getColorsAsStringKey() = 0;

    /** Method returning the String Keys for the color short identifier(s) associated to this consumable
     *  @return a vector filled with the color(s) localization identifier(s)
     */
    virtual std::vector<l10n::StringKey> getColorShortIdsAsStringKey() = 0;

    /** @}
     */

};

#endif
