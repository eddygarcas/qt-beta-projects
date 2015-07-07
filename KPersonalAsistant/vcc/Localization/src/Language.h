/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   Language.h
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

#ifndef LANGUAGE_H_ 
#define LANGUAGE_H_

#include <string> 
#include <vector>
#include <QTranslator>
#include <QTextCodec>
#include <iostream>
#include "ILanguage.h"
#include "Locale.h"
#include "LocalizationIdentifiers.h"

//using namespace std;

/** 
 * The ILanguage interface defines a way to create a language standard definition for all third party applications.
 * 
 * Third party are Web application and Front panel and we must specify a 'bundle' tag with two 
 * possible values, such as web and gui, it is thus because them have different dictionary files.
 * 
 * Aside bundle parameter, must define a encoding value. By default is UTF-8, but by means of encoding 
 * parameter you can define other one, in all cases must be Unicode values.
 * 
 * This interface to make a relationship with ILocale interface to define a specific language region and country.
 * 
 * Once these parameters will be defined you will have a standard Language instance and using getString(...) method 
 * will get a translated string. 
 */
class Language : public ILanguage
{

public:

  /**
   * Default constructor
   * Creates a new default locale, encoding and bundle.
   * The default values are:
   *  Locale   -> en_US
   *  encoding -> UTF-8
   *  bundle   -> gui (Front panel by default).
   */
  Language();

  /**
   * Creates a new language with specified locale.
   * 
   * @param &_language It Specify which locale will be defined in this instance. 
   */
  Language(ILanguage& _language);

  /**
   * Creates a new language according to locale and bundle parameters.
   * 
   * @param &_locale Define a active locale.
   */
  Language(ILocale &_locale);
  
  /**
   * Creates a new language according to locale, bundle and endoding function parameters.
   * 
   * @param &_locale Define a active locale.
   * @param &_bundle Define which environment do the request translate (web,gui).
   */
  Language(ILocale &_locale, const std::string _bundle);
  
  /**
   * From Language instance cretates a new language.
   * 
   * @param &_locale
   * @param &_bundle
   * @param &_encoding
   */
  Language(ILocale &_locale, const std::string _bundle, const std::string &_encoding);
  
  /**
   * Override assigment operator
   * 
   * @param &language
   * @return ILanguage&
   * 
   */
  ILanguage& operator=(ILanguage &language);
  
  /**
   * Override equals operator
   * 
   * @param &language The instance that we want compare.
   * @return bool True if comparation equals, false in otherwise
   */
  bool isEqual(ILanguage &language);
  
  /**
   * Self copy
   * 
   *@return Language* 
   */
  ILanguage* clone();
  
  /** @name ILanguage public methods.
    @{
  */

  /**
   * Gets the bundle value
   * 
   * @return std::string
   */
  std::string getBundle(void);
  
  /**
   * Gets encoding value
   * 
   * @return std::string
   */
  std::string getEncoding(void);
  
  /**
   * This function gets a translated string from translator instance with the specified identity parameter.
   * The parameter must be a std::string instance.
   * @param id_string Identifier with which it gives back a translated string
   * 
   * @return std::string
   * 
   */
  std::string getString(const l10n::StringKey id);
  
  /**
   * Gets the internal locale reference.
   * 
   * @return Locale* 
   */
  ILocale* getLocale();
  
  /**
   * @}
   */
  
  /**
   * Returns all language information in string format.
   * @return string 
   */
  std::string toString(void);
  
  /**
   * Delete a languages internal instances.
   */
  virtual ~Language();

private:
  
  /**
   * Creataes a translatator file name format.
   */
  bool initTranslatorInstance();
  
  /**
   * Return filepath to translator file name
   * 
   * @param &fileName File name
   */
  std::string getFileName(const std::string param_bundle);

  ILocale    *locale;
  std::string   bundle;
  std::string   encoding;

  QTranslator   bundle_translator;
  QTranslator   common_translator;
  bool      isInitTranslator;
  
};

#endif /*LANGUAGE_H_*/
