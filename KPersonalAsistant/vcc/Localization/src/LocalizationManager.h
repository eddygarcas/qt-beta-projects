/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   LocalizationManager.h
 *  @author Eduard Garcia
 *  @date   Wed May 23 17:29:11 CEST 2007
 *  @brief  IViewsLocalizationManager class definition
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////

#ifndef LOCALIZATIONMANAGER_H_
#define LOCALIZATIONMANAGER_H_

#include <list>
#include <string>

#include "Language.h"
#include "Locale.h"
#include "IViewsLocalizationManager.h"


/**
 * Implements all necessary functions for make a LocalizationManager singleton
 * that allows to translate language identifiers to translated strings.
 * 
 * The flow sequence is to obtain the IViewsLocalizationManager instance and call 
 * createLanguage(...) or getLanguage(...) , using the last if the language was created, 
 * to obtain a ILanguage instance that allow to translate language identifiers.
 */
class LocalizationManager : public IViewsLocalizationManager
{

public:
  /**
   * Static method that creates a static instance of LocalizationManager.
   * @return IViewsLocalizationManager&
   */
  static IViewsLocalizationManager& getInstance()
  {
    static LocalizationManager localizationManager;
    return localizationManager;
  }
  
  /**
   * It give back a language reference in vector according to function parameter values.
   * @param locale Define a active locale.
   * @param bundle Define which environment do the request translate (web,gui).
   * @param encoding Define in which encoding will do the translation.
   * 
   * @return ILanguage* Language reference in vector.
   */
  ILanguage* getLanguage(ILocale &locale, const std::string bundle, const std::string &encoding);

  /**
   * It give back a language reference in vector according to function parameter values.
   * 
   * @param &locale Define a active locale.
   * @param &bundle Define which environment do the request translate (web,gui).
   * @return ILanguage* Language reference in vector.
   */
  ILanguage* getLanguage(ILocale &locale, const std::string bundle);
  
  /**
   * It removes a language into languages vector with parameter values.
   * 
   * @param &locale A locale instance
   * @param &bundle
   * @param &encoding 
   * @return bool true, if has been removed the llanguage instance  or false in otherwise
   */
  bool releaseLanguage(ILocale &locale, const std::string bundle, const std::string &encoding);

  /**
   * It removes a language into languages vector with parameter values.
   * 
   * @param &locale A locale instance
   * @param &bundle
   * @return bool true, if has been removed the llanguage instance  or false in otherwise
   */
  bool releaseLanguage(ILocale &locale, const std::string bundle);

  /**
   * Object destructor
   */
  virtual ~LocalizationManager();
  
protected:

  /**
   * Void constructor
   */
  LocalizationManager();
  
  /**
  * Prevents a copy construction
  * 
  * @param &localizationManager
  */
  LocalizationManager(IViewsLocalizationManager &localizationManager);

private:

  /**Internal Language instance vector*/
  std::list<ILanguage*> languages;

  /**Internal vector to store the number of references returned to clients for each language*/
  std::list<int> languagesCounter;


  /**
   * Creates a Language instance inside vector according to function paramter values.
   * 
   * param locale Define a active locale.
   * param bundle Define which environment do the request translate (web,gui).
   * param encoding Define in which encoding will do the translation.
   * return ILanguage* Language reference in vector.
   */
  ILanguage* createLanguage(ILocale &locale, const std::string bundle, const std::string &encoding);


};

/**End class definition*/

#endif /*LOCALIZATIONMANAGER_H_*/
