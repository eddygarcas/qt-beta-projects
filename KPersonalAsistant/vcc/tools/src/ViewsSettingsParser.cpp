#include "ViewsSettingsParser.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>

ViewsSettingsParser::ViewsSettingsParser()
{
  parser_ = (XERCES_CPP_NAMESPACE::XercesDOMParser*)(0);
  vmin_range_ = -1;
  vmax_range_ = -1;

}

ViewsSettingsParser::~ViewsSettingsParser()
{
  if (parser_ != (XERCES_CPP_NAMESPACE::XercesDOMParser*)(0))
    delete parser_;
  settingsList_.clear();
}

bool ViewsSettingsParser::run(std::string xmlUrl, std::ofstream &fileHeader)
{

  XERCES_CPP_NAMESPACE::DOMNodeList * settings;
  XERCES_CPP_NAMESPACE::DOMNodeList * optionsList;
  XERCES_CPP_NAMESPACE::DOMNodeList * result_option_list;
  XERCES_CPP_NAMESPACE::DOMNode * child;

  if (parser_ == (XERCES_CPP_NAMESPACE::XercesDOMParser *)(0))
  {
    parser_ = new XERCES_CPP_NAMESPACE::XercesDOMParser;
  }
  std::cout << "We define a validation option "<< std::endl;

  parser_->setValidationScheme(XERCES_CPP_NAMESPACE::XercesDOMParser::Val_Always);
  parser_->setDoNamespaces(false);
  parser_->setCreateEntityReferenceNodes(false);

  std::cout << "Next, parse xml file "<< xmlUrl << std::endl;
  try
  {
    parser_->parse(xmlUrl.c_str());
  } catch(...)
  {
    std::cout << "XML setting file don't pass the validation process, check it and launch build process again " << xmlUrl << std::endl;
    assert(0);
  }

  settings = parser_->getDocument()->getElementsByTagName(XmlHelpers::StringtoDOM("setting").unicodeForm());

  SettingInfo *info_;

  for (uint32_t i = 0; i < (uint32_t) settings->getLength() ; i++)
  {
    info_ = new SettingInfo;

    child = settings->item(i);
    if (child->hasAttributes())
    {
      XERCES_CPP_NAMESPACE::DOMNamedNodeMap *attrs = child->getAttributes();
      for (uint32_t indx = 0; indx < (uint32_t)attrs->getLength(); indx++)
      {
        XERCES_CPP_NAMESPACE::DOMNode *attr = attrs->item(indx);
        if (SETTINGID.compare(XmlHelpers::DOMtoString(attr->getNodeName()))==0)
        {
          info_->settingId = XmlHelpers::DOMtoString(attr->getNodeValue());
        }
      }
    }
    child = settings->item(i)->getFirstChild();
    while (child != 0)
    {
      switch (child->getNodeType())
      {
      case XERCES_CPP_NAMESPACE::DOMNode::ELEMENT_NODE:
        if (XmlHelpers::DOMtoString (child->getNodeName()) == "objectname")
        {
          info_->cdsObjectName
              = XmlHelpers::DOMtoString(child->getTextContent());
        } else if (XmlHelpers::DOMtoString (child->getNodeName()) == "label")
        {
          info_->label = XmlHelpers::DOMtoString(child->getTextContent());
        } else if (XmlHelpers::DOMtoString (child->getNodeName()) == "title")
        {
          info_->title = XmlHelpers::DOMtoString(child->getTextContent());
        } else if (XmlHelpers::DOMtoString (child->getNodeName()) == "type")
        {
          info_->type = XmlHelpers::DOMtoString(child->getTextContent());
        } else if (XmlHelpers::DOMtoString (child->getNodeName()) == "options")
        {
          if (child->hasChildNodes())
          {
            optionsList = child->getChildNodes();
            for (uint32_t j = 0; j < (uint32_t) optionsList->getLength() ; j++)
            {
              if (XmlHelpers::DOMtoString (optionsList->item(j)->getNodeName()) == "option")
              {
                if (optionsList->item(j)->hasChildNodes())
                {
                  result_option_list = optionsList->item(j)->getChildNodes();
                  for (uint32_t f = 0; f
                      < (uint32_t) result_option_list->getLength() ; f++)
                  {
                    if (XmlHelpers::DOMtoString (result_option_list->item(f)->getNodeName()) == "label")
                    {
                      info_->optionLabel.push_back(XmlHelpers::DOMtoString(result_option_list->item(f)->getTextContent()));
                    } else if (XmlHelpers::DOMtoString (result_option_list->item(f)->getNodeName()) == "value")
                    {
                      info_->optionValue.push_back(XmlHelpers::DOMtoString(result_option_list->item(f)->getTextContent()));
                    }
                  }
                }
              }
            }
          }
        } else if (XmlHelpers::DOMtoString (child->getNodeName()) == "range")
        {
          if (child->hasChildNodes())
          {
            optionsList = child->getChildNodes();
            for (uint32_t f = 0; f < (uint32_t) optionsList->getLength() ; f++)
            {
              if (XmlHelpers::DOMtoString (optionsList->item(f)->getNodeName()) == "min")
              {
                info_->min_range_= XmlHelpers::DOMtoString(optionsList->item(f)->getTextContent());
              } else if (XmlHelpers::DOMtoString (optionsList->item(f)->getNodeName()) == "max")
              {
                info_->max_range_= XmlHelpers::DOMtoString(optionsList->item(f)->getTextContent());
              }
            }
          }
        } else if (XmlHelpers::DOMtoString (child->getNodeName())
            == "characters")
        {
          if (child->hasChildNodes())
          {
            optionsList = child->getChildNodes();
            for (uint32_t f = 0; f < (uint32_t) optionsList->getLength() ; f++)
            {
              if (XmlHelpers::DOMtoString (optionsList->item(f)->getNodeName()) == "char")
              {
                info_->allowed_chars_.push_back(XmlHelpers::DOMtoString(optionsList->item(f)->getTextContent()));
              }
            }
          }
        }

      }
      child = child->getNextSibling();
    }
    settingsList_.push_back(info_);
  }

  startCode(fileHeader);
  return true;
}

void ViewsSettingsParser::startCode(std::ofstream &_fout)
{

  _fout << "/* -*- c++ -*- */\n"<< "/**\n"
      << "*  @file   SettingsStaticInformation.h\n"
      << "*  @author Generated in build time\n"
      << "*  @date   Thu Jan 10 19:29:11 CEST 2007\n"
      << "*  @brief  Generated file at compile time.\n"
      << "*  @see    ViewsSettingParser.h\n"<< "*\n"
      << "*  (c) Copyright Hewlett-Packard Company, 2000-2008.\n"
      << "*  All rights reserved. Copying or other reproduction of this program except\n"
      << "*  for archival purposes is prohibited without written consent of\n"
      << "*  Hewlett-Packard Company.\n"<< "*/\n"
      << "//////////////////////////////////////////////////////////////////////////////\n"
      << std::endl<< "#ifndef __SettingsStaticInformation_h_\n"
      << "#define __SettingsStaticInformation_h_\n"
      << "#include \"ViewsSetting.h\"\n"
      << "#include \"Atlas/SettingsManagerAtlas.h\"\n"
      << "namespace SettingUtils{\n";

  generateSettingCode(_fout);

  _fout << "}\n"<< "#endif\n";

}

void ViewsSettingsParser::generateSettingCode(std::ofstream &_fout)
{
  generateSettingId(_fout);
  generateObjectNameCode(_fout);
  generateSettingLabelCode(_fout);
  generateSettingTitleCode(_fout);
  generateSettingTypeCode(_fout);
  generateMinRangeCode(_fout);
  generateMaxRangeCode(_fout);
  generateRangeCode(_fout);
  generateOptionsCode(_fout);

}

void ViewsSettingsParser::generateSettingId(std::ofstream &_fout)
{
  _fout << "  const std::string ViewsSetting::objId[] = {";
  printSettingTag(ID, STRING, _fout);
  _fout << "};\n";

}

void ViewsSettingsParser::generateObjectNameCode(std::ofstream &_fout)
{
  _fout << "  const std::string ViewsSetting::cdsObjNames[] = {";
  printSettingTag(CDS_OBJECT_NAME, STRING, _fout);
  _fout << "};\n";
}

void ViewsSettingsParser::generateSettingLabelCode(std::ofstream &_fout)
{
  _fout << "  const int32_t ViewsSetting::labelNames[] = {";
  printSettingTag(LABEL, INT, _fout);
  _fout << "};\n";
}

void ViewsSettingsParser::generateSettingTitleCode(std::ofstream &_fout)
{
  _fout << "  const int32_t ViewsSetting::titleNames[] = {";
  printSettingTag(TITLE, INT, _fout);
  _fout << "};\n";
}

void ViewsSettingsParser::generateSettingTypeCode(std::ofstream &_fout)
{
  _fout << "  const int32_t ViewsSetting::settingsType[] = {";
  printSettingTag(TYPE, INT, _fout);
  _fout << "};\n";
}

void ViewsSettingsParser::generateOptionsCode(std::ofstream &_fout)
{
  generateOptionCode(_fout);
}

void ViewsSettingsParser::generateOptionCode(std::ofstream &_fout)
{

  _fout << "\n  void initialize(SettingsManagerAtlas &_vset)\n"<< "  {\n";

  printSettingTag(OPTION_LABEL, INT, _fout);
  printSettingTag(OPTION_VALUE, INT, _fout);
  printSettingTag(ALLOWED_CHARS, INT, _fout);

  _fout << "}\n";
}

void ViewsSettingsParser::generateRangeCode(std::ofstream &_fout)
{
  _fout << "  const int32_t ViewsSetting::min_setting_range_ = "<< vmin_range_
      << ";\n";

  _fout << "  const int32_t ViewsSetting::max_setting_range_ = "<< vmax_range_
      << ";\n";

}

void ViewsSettingsParser::generateMinRangeCode(std::ofstream &_fout)
{
  _fout << "  const int32_t ViewsSetting::minRange[] = {";
  printSettingTag(MIN_RANGE, INT, _fout);
  _fout << "};\n";
}

void ViewsSettingsParser::generateMaxRangeCode(std::ofstream &_fout)
{
  _fout << "  const int32_t ViewsSetting::maxRange[] = {";
  printSettingTag(MAX_RANGE, INT, _fout);
  _fout << "};\n";
}

void ViewsSettingsParser::printSettingTag(SettingType settingType,
    SettingValueType _valueType, std::ofstream & _fout)
{
  SettingsListIterator itSettingsList_;
  bool hasFirst = true;
  SettingInfo *info_;

  for (itSettingsList_ = settingsList_.begin(); itSettingsList_
      != settingsList_.end(); itSettingsList_++)
  {
    info_ = (SettingInfo*)*itSettingsList_;
    printStartSeparator(hasFirst, _valueType, _fout);

    switch (settingType)
    {
    case CDS_OBJECT_NAME:
      _fout << info_->cdsObjectName;
      break;
    case LABEL:
      _fout << info_->label;
      break;
    case TITLE:
      _fout << info_->title;
      break;
    case TYPE:
      _fout << "ViewsSetting::";
      _fout << info_->type;
      break;
    case MIN_RANGE:
      _fout << info_->min_range_;
      break;
    case MAX_RANGE:
      _fout << info_->max_range_;
      break;

    case OPTION_LABEL:
      printOptionElements(info_->cdsObjectName, 1, info_->optionLabel, INT,
          _fout);
      hasFirst = true;
      break;
    case OPTION_VALUE:
      printOptionElements(info_->cdsObjectName, 2, info_->optionValue, INT,
          _fout);
      hasFirst = true;
      break;
    case ALLOWED_CHARS:
      printOptionElements(info_->cdsObjectName, 3, info_->allowed_chars_, CHAR,
          _fout);
      hasFirst = true;
      break;
    case ID:
      int aux = atoi(info_->settingId.c_str());
      if ((vmin_range_ == -1) && (vmax_range_ == -1))
      {
        vmin_range_ = aux;
        vmax_range_ = vmin_range_;
      } else
      {
        vmin_range_= aux<vmin_range_ ? aux : vmin_range_;
        vmax_range_= aux>vmax_range_ ? aux : vmax_range_;
      }
      _fout << info_->settingId;
      break;

    }
    printEscapeCaracter(_valueType, _fout);
  }

}

void ViewsSettingsParser::printOptionElements(std::string &object_,
    int _optionList, std::vector<std::string> _options,
    SettingValueType _valueType, std::ofstream &_fout)
{
  OptionIterator itOp;
  bool hasOptFirst = true;
  if (_options.size()>0)
  {
    switch (_optionList)
    {
    case 1:
      _fout << "   _vset.addLabelOption(";
      break;
    case 2:
      _fout << "   _vset.addValueOption(";
      break;
    case 3:
      _fout << "   _vset.addAllowedCharsOption(";
      break;
    }

    _fout << "\""<< object_ << "\",";
    switch (_valueType)
    {
    case INT:
      _fout << "(int32_t[])";
      break;
    case STRING:
      _fout << "(std::string[])";
      break;
    case CHAR:
      _fout << "(char[])";
      break;
    }

    _fout << "{";
    for (itOp = _options.begin(); itOp != _options.end(); itOp++)
    {
      printStartSeparator(hasOptFirst, _valueType, _fout);
      _fout << (std::string)*itOp;
      printEscapeCaracter(_valueType, _fout);
    }
    _fout << "}"<< ","<< _options.size()<< ");"<< std::endl;
  }
}

void ViewsSettingsParser::printStartSeparator(bool &hasFirst,
    SettingValueType _valueType, std::ofstream & _fout)
{
  if (hasFirst)
  {
    hasFirst = false;
    printEscapeCaracter(_valueType, _fout);
  } else
  {
    switch (_valueType)
    {
    case INT:
      _fout << ",";
      break;
    case STRING:
      _fout << ",\"";
      break;
    case CHAR:
      _fout << ",'";
      break;
    }
  }
}

void ViewsSettingsParser::printEscapeCaracter(SettingValueType _valueType,
    std::ofstream &_fout)
{
  switch (_valueType)
  {
  case STRING:
    _fout << "\"";
    break;
  case CHAR:
    _fout << "'";
    break;
  }
}
