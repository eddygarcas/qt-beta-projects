/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ILocale.h
 *  @author Eduard Garcia
 *  @date   Wed May 23 17:29:11 CEST 2007
 *  @brief  Samson standard locale class definition
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////

#ifndef ILOCALE_H_
#define ILOCALE_H_

#include <string>

/**
 * ILocale represents a specific language region and country. 
 * The language code are the lower-case, two-letter codes as defined by ISO-639. 
 * The country code are the lower-case, two-letter codes as defined by ISO-3166.
 * Is used by localization mechanism to translate language identifiers to a translated strings.
 */
class ILocale
{
	
public:
  
  /**
   * Sets a standard country value
   * 
   * @param & Country value
   */
  virtual void setCountry(const std::string& country) = 0;
  
  /**
   * Sets a standard language value
   * 
   * @param & Language value 
   */
  virtual void setLanguage(const std::string& language) = 0;

  /**
   * It Compares two Locale instances.
   * 
   * @param &locale instance that will be compared
   * @return bool Ture, if the both instance are equal, false in otherwise.
   */
  virtual bool isEqual(ILocale& locale) = 0;

  
  /**
   * It gives back a country value
   * 
   * @return std::string
   */
  virtual std::string getCountry(void) = 0;
  
  /**
   * It Gives back a language value
   * 
   * @return std::string
   */
  virtual std::string getLanguage(void) = 0;

  /**
   * Returns a locale value with standarized ISO 8601 format, such as follows:
   * 
   *  en-US
   *  en-EN
   *  es-CA
   *  es-ES
   * 
   * @return std::string
   */
  virtual std::string formatLocale() = 0;
  
};

/**End class definition*/

#endif /*ILOCALE_H_*/
