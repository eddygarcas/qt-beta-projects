#include "Locale.h"

/**
 * Default constructor
 * Create a Locale instance with english default language
 */
Locale::Locale()
{
  Locale::country = "en";
  Locale::language = "US"; 
}


Locale::Locale(ILocale &loc):
	country(loc.getCountry()),
	language(loc.getLanguage())
{
  	
}
/**
 * Create a Locale instance according to costructor parameters
 * @param *country Value of standard country definition
 * @param *language Value of standard language definition
 */
Locale::Locale(const char *coun, const char* lang):
	country(coun),
	language(lang)
{
  
}

/**
 * Create a Locale instance according to costructor parameters
 * @param coun Value of standard country definition
 * @param lang Value of standard language definition
 */
Locale::Locale(const std::string coun, const std::string lang)
{
  country=coun;
  language=lang;
}

/**
 * Sets a standard country value
 * @param &country
 */
void Locale::setCountry(const std::string &_country)
{
  Locale::country = _country;
}

/**
 * Sets a standard language value
 * @param &language 
 */
void Locale::setLanguage(const std::string &language)
{
  Locale::language = language;
}
  
/**
 * It gives back a country value
 * @return std::string
 */
std::string Locale::getCountry()
{
  return country;
}

/**
 * It Gives back a language value
 * @return std::string
 */
std::string Locale::getLanguage()
{
  return language;
}

/**
 * Returns a locale value with starndard format such as follows:
 *  en-US
 * 
 * @return std::string
 */
std::string Locale::formatLocale()
{
  std::string ret(language);
  ret.append("-");
  ret.append(country);
  return ret;
}

/**
 * It Check the locale to verify that contains values
 * @return bool True is contais values, false in otherwise.
 */
bool Locale::empty(void)
{
  return (country.empty() && language.empty());
}

/**
 * It Compares two Locale instances.
 * @param &localeLeft instance that will be compared
 * 
 * @return bool Ture, if the both instance are equal, false in otherwise.
 */
bool Locale::isEqual(ILocale &localeLeft)
{
    bool result = false;
    result = localeLeft.getCountry().compare(country) && 
  localeLeft.getLanguage().compare(language);
    return result;
}


/**
 * It Compares two Locale instances.
 * @param &localeLeft instance that will be compared
 * 
 * @return bool Ture, if the both instance are not equal, false in otherwise.
 */
bool Locale::operator !=(ILocale &localeLeft)
{
  return (localeLeft.getCountry()!=getCountry() || 
  localeLeft.getLanguage()!=getLanguage());
}

std::string Locale::toString(void)
{
  std::string tostring("---Locale---\n");
  tostring.append(" Country: " + country + "\n");
  tostring.append("Language: " + language + "\n");
  return tostring;
}

/**
 * Delete a Locale instance.
 */
Locale::~Locale()
{
  
}

