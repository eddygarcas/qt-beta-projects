/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ViewsSettingsParser.h
 *  @author Eduard Garcia (eduard.garcia.castellon@hp.com)
 *  @date   Mon Mar 06 10:44:38 METDST 2003
 *  @brief  header file for the implementation of views settings
 *          generator using Xerces-C parser.
 *
 *  (c) Copyright Hewlett-Packard Company, 2006. 
 *  All rights reserved. Copying or other reproduction of this program except 
 *  for archival purposes is prohibited without written consent of 
 *  Hewlett-Packard Company. 
 */
////////////////////////////////////////////////////////////////////////////////

#ifndef VIEWSSETTINGSPARSER_H_
#define VIEWSSETTINGSPARSER_H_

#include "RedOS_pub_api.h"
#include "atlas_types.h"
#include "xml/XmlHelpers.h"
#include <string>
#include <vector>
#include <fstream>
/**
 * Views setting estructure
 */
struct SettingInfo {
  SettingInfo()
  {
    min_range_ = std::string("-1");
    max_range_ = std::string("-1");
  }
  std::string settingId;
  std::string cdsObjectName;
  std::string label;
  std::string title;
  std::string type;
  std::string min_range_;
  std::string max_range_;
  std::vector<std::string> allowed_chars_;
  std::vector<std::string> optionLabel;
  std::vector<std::string> optionValue;
};

enum SettingType
{
  CDS_OBJECT_NAME,
  LABEL,
  TITLE,
  TYPE,
  OPTION_LABEL,
  OPTION_VALUE,
  MIN_RANGE,
  MAX_RANGE,
  ALLOWED_CHARS,
  ID
};

enum SettingValueType
{
  INT,
  STRING,
  CHAR
};

const std::string SETTINGID = "id";

typedef std::vector<SettingInfo*> SettingsList;

typedef std::vector<SettingInfo*>::iterator SettingsListIterator;

typedef std::vector<std::string>::iterator OptionIterator;

/** This class allow us a XML files with views settings to header file.*/
class ViewsSettingsParser {
public:
  /**Void constructor*/
  ViewsSettingsParser();

  /**
   * It will do the parse operation.
   *  
   * @param std::string
   * @param std::ofstream&
   */
  bool run(std::string _xmlContent, std::ofstream &_fileHeader);

  /**Object destructor*/
  virtual ~ViewsSettingsParser();

protected:

  /**
   * Writes header content in file
   * 
   * @param std::ofstream&
   */
  void startCode(std::ofstream&);

private:
  /** List of settings after parse xml file */
  SettingsList settingsList_;

  /** Xerces xml parser*/
  XERCES_CPP_NAMESPACE::XercesDOMParser *parser_;

  int vmin_range_;
  int vmax_range_;

  void generateSettingId(std::ofstream&);
  void generateSettingCode(std::ofstream&);
  void generateObjectNameCode(std::ofstream&);
  void generateSettingLabelCode(std::ofstream&);
  void generateSettingTitleCode(std::ofstream&);
  void generateSettingTypeCode(std::ofstream&);
  void generateOptionsCode(std::ofstream&);
  void generateOptionCode(std::ofstream&);
  void generateRangeCode(std::ofstream&);
  void generateMinRangeCode(std::ofstream&);
  void generateMaxRangeCode(std::ofstream&);

  void printSettingTag(SettingType _setType, SettingValueType valueType,
      std::ofstream &fout);
  void printStartSeparator(bool &_hasFirstElement, SettingValueType valueType,
      std::ofstream &fout);
  void printOptionElements(std::string &_object_, int optionList,
      std::vector<std::string> options, SettingValueType valueType,
      std::ofstream &fout);
  void printEscapeCaracter(SettingValueType valueType, std::ofstream &fout);

};
#endif /*VIEWSSETTINGSPARSER_H_*/
