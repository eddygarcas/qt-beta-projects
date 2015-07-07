/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ViewsSetting.h
 *  @author Eduard Garcia
 *  @date   Thu Dec 20 19:29:11 CEST 2007
 *  @brief  Setting representation for views.
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 


#ifndef VIEWSSETTING_H_
#define VIEWSSETTING_H_

#include "IViewsSetting.h"
#include "IDiscreteSetting.h"
#include "IStringSetting.h"
#include "Cds/ICds.h"
#include <sstream>
#include <vector>

/** This class describes the Views Setting abstraction interface.
 */
class ViewsSetting : public IViewsSetting 
{
public:

  /** @name Enumeration for the different types of setting.
   @{
   */
  enum ViewsSettingType
  {
    /* A continuos setting represented by an integer of 8 bits. */
    CDSINT8CONTINUOUS,
    CDSINT16CONTINUOUS,
    CDSINT32CONTINUOUS,
    CDSRANGECONTINUOUS,
    CDSINT8DISCRETE,
    CDSINT16DISCRETE,
    CDSINT32DISCRETE,
    CDSSTRING,
    CDSBOOLDISCRETE
  };

  /* Type identifiers to know the type of each setting. 
   * This is used to create the correct instance of the object  */
  static const int32_t settingsType[];

  /**Minimum range in range objects*/
  static const int32_t min_setting_range_;

  /**Maximum range in range objects*/
  static const int32_t max_setting_range_;

  /* Here we store all the strings with the names of the objects needed by the settings. 
   * The Settings will use the settingID to access the array.*/
  static const std::string cdsObjNames[];

  /** @}
   */

  /** @name IViewsSetting public methods.
   @{
   */

  /** Method returning the value of the setting. 
   @return the current value of the setting.
   */
  virtual std::string getStringValue() = 0;

  /**
   * It returns the type of setting, which will be able to be one of next values:
   *   IViewsSetting::CONTINUOUSSETTING
   *   IViewsSetting::DISCRETESETTING
   *   IViewsSetting::STRINGSETTING
   * 
   * @return IViewsSetting::TypeofSetting
   */
  virtual IViewsSetting::TypeofSetting getType();

  /** Method to return whether the Setting only accepts discrete values
   @return whether the value has to be discrete (i.e only a range of values are accepted)
   */
  virtual int32_t getId();

  /**
   * It returns the key value of title setting.
   * 
   * return int
   */
  virtual int32_t getTitle(void);

  /**
   * It returns the key value of label setting.
   * 
   * return int
   */
  virtual int32_t getLabel(void);

  /** @}
   */

  virtual ~ViewsSetting();
  
protected:

  /** @name ViewsSetting protected methods.
   @{
   */
  /* Number to identify the setting. It is also used to access to the static information shared by all settings.*/
  int32_t settingId_;

  IViewsSetting::TypeofSetting typeofSetting_;

  /* Once we have made the find to get the cds key we store it to avoid calling the find again.*/
  Cds::CdsObject* cdsObject_;

  /* Reference to the CDS.*/
  ICds* cds_;

  /**This array contains objects id*/
  static const std::string objId[];

  /* String identifiers to display the label of the setting. The Settings will use the settingID to access the array. */
  static const int32_t labelNames[];

  /* String identifiers to display the title of the setting. The Settings will use the settingID to access the array. */
  static const int32_t titleNames[];

  /**Array of minimum range*/
  static const int32_t minRange[];

  /**Array of maximum range*/
  static const int32_t maxRange[];

  /**Vector which contains all option label key*/
  DiscreteOptionsCollection optionLabels_;

  /**Vector which contaion all values of option*/
  DiscreteOptionsCollection optionValues_;

  /**Vector which contaion all values of option*/
  AllowedCharsCollection allowedCharactersValues_;

  /** 
   * Gets (finds) the CDS object and returns the pointer to it. It will make an assert if the object does not exist
   * because would mean that the ViewsSetting object is corrupted. 
   */
  void getCdsObject();

  /** 
   @}
   */

private:

};

#endif //VIEWSSETTING_H_
