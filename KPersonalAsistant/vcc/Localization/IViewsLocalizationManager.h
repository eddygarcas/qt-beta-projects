/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   IViewsLocalizationManager.h
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

#ifndef IVIEWSLOCALIZATIONMANAGER_H_
#define IVIEWSLOCALIZATIONMANAGER_H_

#include <string>
#include "ILanguage.h"

/**
 * Interface that contais a generic localization manager definition
 * that allows to translate language identifiers to translated strings.
 * 
 * The flow sequence is to obtain the IViewsLocalizationManager instance and call 
 * createLanguage(...) or getLanguage(...) , using the last if the language was created, 
 * to obtain a ILanguage instance that allow to translate language identifiers.
 */

class IViewsLocalizationManager {

public:

  /**
   * It give back a language reference in vector according to function parameter values.
   * 
  * @param & Define a active locale.
  * @param & Define which environment do the request translate (web,gui).
  * @param & Define in which encoding will do the translation.
   * @return ILanguage* Language reference in vector.
   */
  virtual ILanguage* getLanguage(ILocale & locale, const std::string bundle, const std::string & encoding) = 0;
  
  /**
   * It give back a language reference in vector according to function parameter values.
   * 
  * @param & Define a active locale.
  * @param & Define which environment do the request translate (web,gui).
   * @return ILanguage* Language reference in vector.
   */
  virtual ILanguage* getLanguage(ILocale & locale, const std::string bundle) = 0;
  
  /**
   * It removes a language into languages vector with parameter values.
   * 
   * @param & locale instance
  * @param & Define which environment do the request translate (web,gui).
  * @param & Define in which encoding will do the translation.
   * @return bool true, if has been removed the llanguage instance  or false in otherwise
   */
  virtual bool releaseLanguage(ILocale & locale, const std::string bundle, const std::string &encoding) = 0;

  /**
   * It removes a language into languages vector with parameter values.
   * 
   * @param & locale instance
  * @param & Define which environment do the request translate (web,gui).
   * @return bool true, if has been removed the llanguage instance  or false in otherwise
   */
  virtual bool releaseLanguage(ILocale & locale, const std::string bundle) = 0;


};
#endif /*IVIEWSLOCALIZATIONMANAGER_H_*/
