#include <sstream>
#include <stdlib.h>
#include "Language.h"
#include "LocalizationIdentifiers.h"
#include "localization_types.h"

#define APPLICATION_NAME "atlas"
#define APPLICATION_ROOT_PATH "BCD_VIEWS_TARGET_ROOT"
#define LOCALIZATION_RELATIVE_PATH "/home/localization/"

/**
 * Default constructor
 * Creates a new default locale, encoding and bundle.
 * The default values are:
 *  Locale   -> en_US
 *  encoding -> UTF-8
 *  bundle   -> gui (Front panel by default).
 * 
 */
Language::Language()
{
    locale = new Locale();
    encoding = "UTF-8";
    bundle = COMMON_BUNDLE;
}

/**
 * Creates a new language with specified locale.
 * 
 * @param &loc It Specify which locale will be defined in this instance. 
 * 
 */
Language::Language(ILocale &loc)
{
    locale = new Locale(loc.getCountry(),loc.getLanguage());
}

/**
 * Creates a new language according to locale and bundle parameters.
 * 
 * @param &loc Define a active locale.
 * @param &_bundle Define which environment do the request translate (web,gui).
 */
Language::Language(ILocale &loc, const std::string _bundle)
{
    bundle = _bundle;
    locale = new Locale(loc.getCountry(),loc.getLanguage());
    isInitTranslator = false;
}

/**
 * Creates a new language according to locale, bundle and endoding function parameters.
 * 
 * @param &loc Define a active locale.
 * @param &_bundle Define which environment do the request translate (web,gui).
 * @param &_encoding Define in which encoding will do the translation.
 */
Language::Language(ILocale &loc, const std::string _bundle,
    const std::string &_encoding)
{
    bundle = _bundle;
    encoding = _encoding;
    locale = new Locale(loc.getCountry(),loc.getLanguage());
    isInitTranslator = false;

}

/**
 * From Language instance cretates a new language.
 * @param &lang
 */
Language::Language(ILanguage& lang)
{
  
    bundle = ((Language)lang).getBundle();
    encoding = ((Language)lang).getEncoding();
    locale = ((Language)lang).getLocale();

}

/**
 * Self copy
 * 
 *@return ILanguage* 
 */
ILanguage* Language::clone() 
{
    ILanguage *aux = this;
    return new Language(*aux);
}

/**
 * Override assigment operator
 * 
 * @param const ILanguage&
 * @return ILanguage&
 * 
 */
ILanguage& Language::operator =(ILanguage& lang)
{
    return *((Language)lang).clone();
}
/**
 * Override equals operator
 * @param const Language& The instance that we want compare.
 * @return bool True if comparation equals, false in otherwise
 */
bool Language::isEqual(ILanguage& language)
{
    bool result = false;
    result = (locale->isEqual(*(language.getLocale())));

    return result;
}

/**
 * Gets the internal locale reference.
 * 
 * @return ILocale* 
 */
ILocale* Language::getLocale()
{
    return locale;
}
/**
 * Gets the bundle value
 * 
 * @return std::string
 */
std::string Language::getBundle()
{
    return bundle;
}
/**
 * Gets encoding value
 * 
 * @return std::string
 */
std::string Language::getEncoding()
{
    return encoding;
}

/**
 * This function gets a translated string from translator instance with the specified identity parameter.
 * The parameter must be a std::string instance.
 * @param id_string Identifier with which it gives back a translated string
 * 
 * @return std::string
 * 
 */
std::string Language::getString(const l10n::StringKey id)
{
    QByteArray encodedString;
    if (!isInitTranslator) {
      initTranslatorInstance();
    }

    if (isInitTranslator) {
        QTextCodec *codec = QTextCodec::codecForName(encoding.data());

        std::ostringstream stringId;
        stringId << id;
        encodedString = codec->fromUnicode(bundle_translator.translate(COMMON_BUNDLE,
        stringId.str().data(), new char(1)));
        if (encodedString.isNull() || encodedString.isEmpty())
        {
            encodedString = codec->fromUnicode(bundle_translator.translate(GUI_BUNDLE,
            stringId.str().data(), new char(1)));
        } 
        if (encodedString.isNull() || encodedString.isEmpty()) 
        {
            encodedString = codec->fromUnicode(bundle_translator.translate(WEB_BUNDLE,
            stringId.str().data(), new char(1)));
        } 
        if (encodedString.isNull() || encodedString.isEmpty()) 
        {
            encodedString.append("######");
        }
    }
    else 
    {
        encodedString.append("######");
    }
    return encodedString.data();
}

/**
 * Creates a translator file name format.
 */
bool Language::initTranslatorInstance()
{
    std::string localizationFilesPath(getenv(APPLICATION_ROOT_PATH));
    localizationFilesPath.append(LOCALIZATION_RELATIVE_PATH);

    if( bundle_translator.load(QString(getFileName(bundle).data()), QString(localizationFilesPath.data()))) 
    {
        isInitTranslator = true;
    }
    else
    {
        isInitTranslator = false;
    }
    return isInitTranslator;
}
/**
 * Return filepath to translator file name
 * @param string& File name
 */
std::string Language::getFileName(const std::string param_bundle)
{
    //We are currently not using the bundle. Might be useful in the future.
    std::string file_composite(APPLICATION_NAME);
    file_composite.append("_");
    file_composite.append(locale->getLanguage());
    file_composite.append("_");
    file_composite.append(locale->getCountry());
    return file_composite;
}
/**
 * Returns all language information in string format.
 * @return string 
 */
std::string Language::toString(void)
{
    std::string tostring("---Language--\n");
    tostring.append(((Locale*)locale)->toString());
    tostring.append("Encoding: " + encoding + "\n");
    tostring.append("  Bundle: " + bundle + "\n");
    return tostring;
}
/**
 * Delete a languages internal instances.
 */
Language::~Language()
{
    delete locale;
    locale = 0;
}

