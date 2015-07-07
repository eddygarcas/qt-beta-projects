/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   Paper.h
 *  @author Eduard Garcia
 *  @date   Wed May 23 17:29:11 CEST 2007
 *  @brief  Paper class definition
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////

#ifndef PAPER_H_
#define PAPER_H_

#include <map>
#include <list>
#include <string>

#include "PaperList/IPaper.h"
#include <ICallback.h>
#include <ICallbacker.h>
#include "atlas_types.h"
#include "media/MediaType.h"
#include "IObserver.h"
#include "CommonCalibration.h"

/**
 * Contains all information about media component.
 * Media component has a several properties such as media key, name, etc..., that 
 * don't have relation with external components, but others properties have it, 
 * such as Color paper calibration that establish relationship with Calibration classes. 
 */
class Paper : public IPaper
{
public:
  //The theoric media constructor are thus:
  //Media(MediaEngine* mediaEngine,Locale* locale);
  //but in fake test not apply.
  /**Void constructor*/
  Paper();
  /**
   * Contructor for paper.
   * Media key and name are necesary to create a media instance, the rest are optional.
   * All status constans are defined in CommonCalibration
   * This constructor its only necesary in fake implementation of paper list.
   * 
   * @param mediaKey
   * @param mediaName
   * @param colorStatus
   * @param gaStatus
   * @param cadStatus
   */
  Paper(std::string* mediaKey, std::string* mediaName=0,
      uint32_t colorStatus=0, uint32_t gaStatus=0,
      uint32_t cadStatus=0);

  /**
   * Contructor for paper.
   * Media key and name are necesary to create a media instance, the rest are optional.
   * All status constans are defined in ????
   * This constructor its only necesary in fake implementation of paper list.
   * 
   * @param mediaKey
   * @param mediaName
   * @param colorStatus
   * @param gaStatus
   * @param cadStatus
   */
  Paper(char* mediaKey, char* mediaName=0, uint32_t colorStatus=0, uint32_t gaStatus=0,
      uint32_t cadStatus=0);

  /** @name IPaper public methods.
   @{
   */

  /**
   * Return the omes media type
   * 
   * @return MediaType
   */
  MediaType getMediaType();
  void setMediaType(MediaType &_mediaType);
  
  /**
   * Return a media key.
   * 
   * @return std::string
   */
  std::string getMediaKey();
  void setMediaKey(const std::string &_mediaKey);

  /**
   * Return a Media id.
   * 
   * @return std::string
   */
  std::string getName();
  void setName(const std::string &_name);

  /**
   * Return a media short name
   * 
   * @return std::string
   */
  std::string getShortName();
  void setShortName(const std::string &_shortName);
  
  /**
   * Return vendor name
   * 
   * @return std::string
   */
  std::string getVendor();
  void setVendor(const std::string &_vendor);
  
  /**
   * Retrun a donor key, it's only present for custom media,
   * for factory media it is empty an string.
   * 
   * @return std::string*
   */
  std::string getDonorKey();
  void setDonorKey(const std::string &_donorKey);
  
  /**
   * Return category id.
   * 
   * @return uint32_t
   */
  uint32_t getCategory();
  void setCategory(const uint32_t _category);

  /**
   * Return a name category
   * 
   * @return std::string
   */
  std::string getCategoryName();
  void setCategoryName(const std::string &_categoryName);
  
  /**
   * Return a short descrption of category
   * 
   * @return std::string
   */
  std::string getShortCategoryName();
  void setShortCategoryName(const std::string &_shortCategoryName);
  
  /**
   * Return string from category id.
   * 
   * @return std::string
   */
  std::string getCategoryToString();
  void setCategoryToString(const std::string &_categoryString);

  /**
   * Return a revision version.
   * 
   * @return std::string
   */
  std::string getRevision();
  void setRevision(const std::string &_revision);
  
  /**
   * It returns the paper consume in ft.
   * 
   * @return uint32_t
   */
  uint32_t getConsume();
  void setConsume(const uint32_t _consume);
  
  /**
   * Return true if media is a core media, false in otherwise.
   * 
   * @return boolean
   */
  bool isCoreMedia();
  void setCoreMedia(const bool _coreMedia);
  
  /**
   * Return true if media is erasable, false in otherwise.
   * 
   * @return boolean
   */
  bool isErasable();
  void setErasable(const bool _erasable);

  /**
   * Return true if media is calibratalbe or false in otherwise.
   * Whether the media can be scanned or not. If the media cannot be
   * scanned, those calibrations that require scanning of printed
   * patterns (e.g., color calibration) do not apply.
   * 
   * @return boolean
   */
  bool isCalibratable();
  void setCalibratable(const bool _calibratable);

  /**
   * Return true if media can be cutter.
   * 
   * @return bool 
   */
  bool isCutterSupported();
  void setCutterSupported(const bool _cutterSupported);
    
  /**
   * Return true if media supports borderless.
   * 
   * @return bool 
   */
  bool isBorderlesSupported();
  void setBorderlesSupported(const bool _borderlesSupported);

  /**
   * Return true if media supports scanning.
   * 
   * @return bool 
   */
  bool isScanningSupported();
  void setScanningSupported(const bool _scanningSupported);
  
  /**
   * Return a paper color calibration intance that contain all ICalibrationStatus of paper.
   * 
   * @return ICalibrationStatus*
   */
  CommonCalibration* getCalibration(CommonCalibration::ViewsCalibrationKind _calibrationType);
  void setCalibration(CommonCalibration &_colorCalibration);


  /**
   * @}
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

  /**Destructor*/
  virtual ~Paper();

  
protected:

  /** @name IObservable required protected functions.
   *  @{
   */

  /** This method should be called by the observable to notify all the attached observers of this views pen.
   *  @param reason is the reason for the callback, it has to be defined in the class using this callback.
   */
  void notify(uint32_t reason);

  /** @}
   */

private:

  /** This list will keep the list of observers for this views pen.
   */
  std::list <IObserver *> onChangeList_;
  
  MediaType   mediaType_;
  std::string mediaKey_;
  std::string mediaName_;
  std::string mediaShortName_;
  std::string vendorName_;
  std::string donorKey_;
  uint32_t    category_;
  std::string categoryString_;
  std::string categoryName_;
  std::string shortCategoryName_;
  std::string revision_;
  uint32_t	  consume_;
  bool        coreMedia_;
  bool        erasable_;
  bool        calibratable_;
  bool        cutter_;
  bool        borderless_;
  bool        scanning_;
  std::map<CommonCalibration::ViewsCalibrationKind,CommonCalibration*> calibrationMap_;
  
};

#endif /*PAPER_H_*/
