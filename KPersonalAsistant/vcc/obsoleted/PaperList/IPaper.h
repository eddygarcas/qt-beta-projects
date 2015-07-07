/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   IPaper.h
 *  @author Eduard Garcia
 *  @date   Wed May 23 17:29:11 CEST 2007
 *  @brief  IMedia interface definition
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////

#ifndef IPAPER_H_
#define IPAPER_H_

#include "atlas_types.h"
#include "IObservable.h"
#include "CommonCalibration.h"

/**
 * Contains all information about media component.
 * Media component has a several properties such as media key, name, etc..., that 
 * don't have relationship with external components, but others properties have it, 
 * such as Color paper calibration that establish relationship with Calibration classes. 
 */
class IPaper : public IObservable
{
  
public:
  
  /**
   * Return a media key.
   * 
   * @return std::string
   */
	virtual std::string getMediaKey() = 0;
	
	/**
	 * Return a Media id.
	 * 
	 * @return std::string
	 */
	virtual std::string getName() = 0;
	
	/**
	 * It Returns a paper short name
	 * 
	 * @return std::string
	 */
	virtual std::string getShortName() =0;
	
  /**
   * Retrun a donor key, it's only present for custom media,
   * for factory media it is empty an string.
   * 
   * @return std::string
   */
	virtual std::string getDonorKey() = 0;
	
	/**
	 * Return a vendor
	 * 
	 * @return std::string
	 */
	virtual std::string getVendor() = 0;
	
	/**
	 * Return category id.
	 * 
	 * @return uint32_t
	 */
	virtual uint32_t getCategory() = 0;
	
	/**
	 * It Retruns a category name
	 * 
	 * @return std::string
	 */
	virtual std::string getCategoryName() = 0;

	/**
	 * It returns a category short name
	 * 
	 * @return std::string
	 */
	virtual std::string getShortCategoryName() = 0;

	/**
	 * It returns the paper consume in ft.
	 * 
	 * @return uint32_t
	 */
	virtual uint32_t getConsume() = 0;
	
	/**
	 * Return string from category id.
	 * 
	 * @return std::string
	 */
	virtual std::string getCategoryToString() = 0;
	
	/**
	 * Return a revision version.
	 * 
	 * @return std::string
	 */
	virtual std::string getRevision() = 0;

	/**
	 * Return true if media is a core media, false in otherwise.
	 * 
	 * @return boolean
	 */
	virtual bool isCoreMedia() = 0;
	
  /**
   * Return true if media is erasable, false in otherwise.
   * 
   * @return boolean
   */
	virtual bool isErasable() = 0;
	
  /**
   * Return true if media is calibratalbe or false in otherwise.
   * Whether the media can be scanned or not. If the media cannot be
   * scanned, those calibrations that require scanning of printed
   * patterns (e.g., color calibration) do not apply.
   * 
   * @return bool
   */
	virtual bool isCalibratable() = 0;
	
	/**
	 * It returns true if media cutter supported or false in otherwise.
	 * 
	 * @return bool
	 */
	virtual bool isCutterSupported() = 0;

	/**
	 * It returns true if media borderless supported or false in otherwise.
	 * 
	 * @return bool
	 */
	virtual bool isBorderlesSupported() = 0;

	/**
	 * It returns true if media scanning supported or false in otherwise.
	 * 
	 * @return bool
	 */
	virtual bool isScanningSupported() = 0;
	
  /**
   * Return a paper color calibration intance that contain all ICalibrationStatus of paper.
   * 
   * @return ICalibrationStatus*
   */
	virtual CommonCalibration* getCalibration(CommonCalibration::ViewsCalibrationKind _calibrationType) = 0;
	
};

#endif /*IMEDIA_H_*/
