/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ILanguage.h
 *  @author Eduard Garcia
 *  @date   Wed May 23 17:29:11 CEST 2007
 *  @brief  Language class definition
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////

#ifndef ILANGUAGE_H_	
#define ILANGUAGE_H_

#include <string> 
#include <vector>
#include <QTranslator>
#include <QTextCodec>
#include <iostream>
#include "ILocale.h"
#include "LocalizationIdentifiers.h"

/**it enumerate available bundle types.*/
enum BundleTypes
{
  gui = 0,
  web = 1,
};


/** 
 * The ILanguage interface defines a way to create a language standard definition for all third party applications.
 * 
 * Third party are Web application and Front panel and we must specify a 'bundle' tag with two 
 * possible values, such as web and gui, it is thus because them have different dictionary files.
 * 
 * Aside bundle parameter, must define a encoding value. By default is UTF-8, but by means of encoding 
 * parameter you can define other one, in all cases must be Unicode values.
 * 
 * This interface makeing a relationship with ILocale interface for defining a specific language region and country.
 * 
 * Once these parameters will be defined you will have a standard Language instance and using getString(...) method 
 * will get a translated string. 
 */
class ILanguage
{

public:
 
  /**
   * Gets the bundle value
   * 
   * @return std::string
   */
  virtual std::string getBundle(void) = 0;
  
  /**
   * Gets encoding value
   * 
   * @return std::string
   */
  virtual std::string getEncoding(void) = 0;

  /**
  * Override equals operator
  * @param const Language& The instance that we want compare.
  * @return bool True if comparation equals, false in otherwise
  */
  virtual bool isEqual(ILanguage& language) = 0;

  
  /**
   * This function gets a translated string from translator instance with the specified identity parameter.
   * The parameter must be a std::string instance.
   * 
   * @param & Identifier with which it gives back a translated string
   * @return std::string
   * 
   */
  virtual std::string getString(const l10n::StringKey id) = 0;
  
  /**
   * Gets the internal locale reference.
   * 
   * @return ILocale* 
   */
  virtual ILocale* getLocale() = 0;

};

#endif /*ILANGUAGE_H_*/
