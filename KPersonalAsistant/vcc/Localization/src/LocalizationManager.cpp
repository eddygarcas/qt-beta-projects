#include "LocalizationManager.h"
#include "localization_types.h"

/**
 * Default constructor. Create a Translator instance with the specific parameters to translate a Front
 * panel strings.
 * 
 */
LocalizationManager::LocalizationManager()
{

}

/**
 * Localization manager destructor.
 * Removes all Language instance in language vector.
 */
LocalizationManager::~LocalizationManager()
{
    std::list<ILanguage*>::iterator startIterator;
    std::list<int>::iterator languagesCounterIterator = languagesCounter.begin();
    for (startIterator = languages.begin(); startIterator != languages.end(); startIterator++)
    {
        languages.erase(startIterator);
        languagesCounter.erase(languagesCounterIterator);
    }
    languages.clear();
    languagesCounter.clear();
}

/**
* Prevents a copy construction
* 
* @param const IViewsLocalizationManager
*/
LocalizationManager::LocalizationManager(IViewsLocalizationManager& locManager)
{
 /**Is not necesary implements anything*/ 
}

/**
 * It give back a language reference in vector according to function parameter values.
 * @param locale Define a active locale.
 * @param bundle Define which environment do the request translate (web,gui).
 * @param encoding Define in which encoding will do the translation.
 * 
 * @return Language* Language reference in vector.
 */
ILanguage* LocalizationManager::getLanguage(ILocale &locale,
    const std::string bundle, const std::string &encoding)
{
    bool found = false;
    ILanguage *lang = new Language(locale,bundle,encoding);

    std::list<ILanguage*>::iterator startIterator;
    std::list<int>::iterator languagesCounterIterator = languagesCounter.begin();
    for (startIterator = languages.begin(); startIterator != languages.end(); startIterator++)
    {
        if ((static_cast<ILanguage*>(*startIterator))->isEqual(*lang))
        {
            delete lang;
            lang = (ILanguage*)*startIterator;
            found = true;
            break;
        }
        else {
            languagesCounterIterator++;
        }
    }

    if (found)
    {
        (*languagesCounterIterator)++;
        return lang;
    }
    else
    {
        delete lang;
        return createLanguage(locale, bundle, encoding);
    }
}

/**
 * It give back a language reference in vector according to function parameter values.
 * @param locale Define a active locale.
 * @param bundle Define which environment do the request translate (web,gui).
 * @param encoding Define in which encoding will do the translation.
 * 
 * @return Language* Language reference in vector.
 */
ILanguage* LocalizationManager::getLanguage(ILocale &locale,
    const std::string bundle)
{
    std::string aux_encoding = UTF8;
    return getLanguage(locale, bundle, aux_encoding);
}

/**
 * It removes a language into languages vector with parameter values.
 * @param &locale A locale instance
 * @param &lbundle
 * @param &encoding 
 * 
 * @return bool true, if has been removed the llanguage instance  or false in otherwise
 */
bool LocalizationManager::releaseLanguage(ILocale &locale,
    const std::string bundle, const std::string &encoding)
{
    bool ret = false;
    ILanguage *lang = new Language(locale,bundle,encoding);
    std::list<ILanguage*>::iterator startIterator;
    std::list<int>::iterator languagesCounterIterator = languagesCounter.begin();

    for (startIterator = languages.begin(); startIterator != languages.end(); startIterator++)
    {
        if ((static_cast<ILanguage*>(*startIterator))->isEqual(*lang))
        {
            delete lang;
            (*languagesCounterIterator)--;
            if(static_cast<int>((*languagesCounterIterator)) == 0) 
            {
                languages.erase(startIterator);
                languagesCounter.erase(languagesCounterIterator);
            }
            ret = true;
        }
        else 
        {
            languagesCounterIterator++;
        }
    }
    return ret;
}

/**
 * It removes a language into languages vector with parameter values.
 * 
 * @param &locale A locale instance
 * @param &bundle
 * @return bool true, if has been removed the llanguage instance  or false in otherwise
 */
bool LocalizationManager::releaseLanguage(ILocale &locale, const std::string bundle)
{
    return releaseLanguage(locale, bundle, UTF8);
}

/**
  Creates a Language instance inside vector according to function paramter values.
  /param locale Define a active locale.
  /param bundle Define which environment do the request translate (web,gui).
  /param encoding Define in which encoding will do the translation.
  
  /return Language* Language reference in vector.
 */
ILanguage* LocalizationManager::createLanguage(ILocale &locale, const std::string bundle, const std::string &encoding)
{
  languages.push_back(new Language(locale,bundle,encoding));
  languagesCounter.push_back(1);
  return (ILanguage*)languages.back();
}

