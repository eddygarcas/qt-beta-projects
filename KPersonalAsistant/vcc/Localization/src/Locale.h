/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   Locale.h
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

#ifndef LOCALE_H_
#define LOCALE_H_

#include <string>
#include "ILocale.h"

/**
 * Locale represents a specific language region and country. 
 * The language code are the lower-case, two-letter codes as defined by ISO-639. 
 * The country code are the lower-case, two-letter codes as defined by ISO-3166.
 * Is used by localization mechanism to translate language identifiers to a translated strings.
 */
class Locale : public ILocale
{
  
public:
  
  /**
   * Default constructor
   * Create a Locale instance with english default language
   */
  Locale();
  
  
  Locale(ILocale &_locale);
  /**
   * Create a Locale instance according to costructor parameters
   * 
   * @param *coun Character array of standard country definition
   * @param *lang Character array of standard language definition
   */
  Locale(const char *country, const char *lang);
  
  /**
   * Create a Locale instance according to costructor parameters
   * 
   * @param coun String instance which contains standard country definition
   * @param lang String instance which contains standard language definition
   */
  Locale(const std::string country, const std::string lang);
  
  /** @name ILocale public methods.
    @{
  */

  /**
   * Sets a standard country value
   * @param &country
   */
  void setCountry(const std::string& country);
  
  /**
   * Sets a standard language value
   * @param &language 
   */
  void setLanguage(const std::string& language);
  
  /**
   * It gives back a country value
   * @return std::string
   */
  std::string getCountry(void);
  
  /**
   * It Gives back a language value
   * @return std::string
   */
  std::string getLanguage(void);

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
  std::string formatLocale();
  
  /**
   * @}
   */
  
  /**
   * It Check the locale to verify that contains values
   * @return bool True is contais values, false in otherwise.
   */
  bool empty();
  
  /**
   * It Compares two Locale instances.
   * 
   * @param &locale instance that will be compared
   * @return bool Ture, if the both instance are equal, false in otherwise.
   */
  bool isEqual(ILocale& locale);

  /**
   * It Compares two Locale instances.
   * 
   * @param &locale instance that will be compared
   * @return bool Ture, if the both instance are not equal, false in otherwise.
   */
  bool operator!=(ILocale& locale);

  /**
   * Return all locale information in string format
   * 
   * @return string
   */
  std::string toString(void);
  
  /**Object destructor*/
  virtual ~Locale();

private:
  /**String which contains a contry value*/
  std::string country;
  /**String which contains a language value*/
  std::string language;

};

/**End class definition*/

#endif /*ILOCALE_H_*/
