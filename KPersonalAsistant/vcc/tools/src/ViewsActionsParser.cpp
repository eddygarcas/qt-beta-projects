#include "ViewsActionsParser.h"

ViewsActionsParser::ViewsActionsParser()
{
  parser_ = (XERCES_CPP_NAMESPACE::XercesDOMParser*)(0);
}

ViewsActionsParser::~ViewsActionsParser()
{

  if (parser_ != (XERCES_CPP_NAMESPACE::XercesDOMParser*)(0))
    delete parser_;
  actionList_.clear();
  menuList_.clear();

}

bool ViewsActionsParser::run(std::string _xmlFileName,
    std::string _headerFileName)
{
  std::ifstream fFile;
  std::ofstream tsFile;

  tsFile.open(_headerFileName.data(), std::ios::app);

  run(_xmlFileName, tsFile);

  tsFile.close();

  return true;
}

bool ViewsActionsParser::run(std::string xmlUrl, std::ofstream &fileHeader)
{

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
  }
  catch(...)
  {
    std::cout << "XML setting file don't pass the validation process, check it and launch build process again " << xmlUrl << std::endl;
    assert(0);
  }
  getActions();
  getMenus();

  startCode(fileHeader);
  return true;
}

void ViewsActionsParser::getActions()
{
  XERCES_CPP_NAMESPACE::DOMNodeList * actions;
  XERCES_CPP_NAMESPACE::DOMNodeList * optionsList;
  XERCES_CPP_NAMESPACE::DOMNode * child;
  std::string nodeName_;

  actions = parser_->getDocument()->getElementsByTagName(XmlHelpers::StringtoDOM("ACTION").unicodeForm());
  ActionInfo *info_;

  for (uint32_t i = 0; i < (uint32_t) actions->getLength() ; i++)
  {
    info_ = new ActionInfo;

    child = actions->item(i);
    if (child->hasAttributes())
    {
      XERCES_CPP_NAMESPACE::DOMNamedNodeMap *attrs = child->getAttributes();
      for (uint32_t indx = 0; indx < (uint32_t)attrs->getLength(); indx++)
      {
        XERCES_CPP_NAMESPACE::DOMNode *attr = attrs->item(indx);
        if (ACTION_TYPE.compare(XmlHelpers::DOMtoString(attr->getNodeName()))
            ==0)
        {
          info_->actionType_ = XmlHelpers::DOMtoString(attr->getNodeValue());
        }
        if (ACTION_PRIORITY.compare(XmlHelpers::DOMtoString(attr->getNodeName()))
            ==0)
        {
          info_->priority_ = XmlHelpers::DOMtoString(attr->getNodeValue());
        }
        if (ACTION_ID.compare(XmlHelpers::DOMtoString(attr->getNodeName()))==0)
        {
          info_->id_ = XmlHelpers::DOMtoString(attr->getNodeValue());
        }
      }
    }

    child = actions->item(i)->getFirstChild();
    while (child != 0)
    {

      switch (child->getNodeType())
      {
      case XERCES_CPP_NAMESPACE::DOMNode::ELEMENT_NODE:
        nodeName_ = XmlHelpers::DOMtoString (child->getNodeName());
        if (nodeName_ == "HEADERFILE")
        {
          info_->headerFile_= XmlHelpers::DOMtoString(child->getTextContent());
        } else if (nodeName_ == "CLASSNAME")
        {
          info_->className_ = XmlHelpers::DOMtoString(child->getTextContent());
        } else if (nodeName_ == "TEMPLATE")
        {
          if (child->hasChildNodes())
          {
            optionsList = child->getChildNodes();

            for (uint32_t j = 0; j < (uint32_t) optionsList->getLength() ; j++)
            {
              nodeName_ = XmlHelpers::DOMtoString(optionsList->item(j)->getNodeName());
              if (nodeName_ == "TEMPLATE_NAME")
              {
                info_->temaplateName_
                    = XmlHelpers::DOMtoString(optionsList->item(j)->getTextContent());
              } else if (nodeName_ == "LABEL")
              {
                info_->label_ = XmlHelpers::DOMtoString(optionsList->item(j)->getTextContent());
              }
              if (nodeName_ == "TITLE")
              {
                info_->title_ = XmlHelpers::DOMtoString(optionsList->item(j)->getTextContent());
              } else if (nodeName_ == "IMAGE_ON")
              {
                info_->imageOn_ = XmlHelpers::DOMtoString(optionsList->item(j)->getTextContent());
              }
              if (nodeName_ == "IMAGE_OFF")
              {
                info_->imageOff_ = XmlHelpers::DOMtoString(optionsList->item(j)->getTextContent());
              }
            }
          }
        }
      }
      child = child->getNextSibling();
    }
    actionList_.push_back(info_);
  }
}

MenuInfo* ViewsActionsParser::getInternalMenus(
    XERCES_CPP_NAMESPACE::DOMNode *menuChild_)
{
  MenuInfo * info_ = new MenuInfo;
  XERCES_CPP_NAMESPACE::DOMNode * child;
  std::string nodeName_;

  if (menuChild_->hasAttributes())
  {
    XERCES_CPP_NAMESPACE::DOMNamedNodeMap *attrs = menuChild_->getAttributes();
    for (uint32_t indx = 0; indx < (uint32_t)attrs->getLength(); indx++)
    {
      XERCES_CPP_NAMESPACE::DOMNode *attr = attrs->item(indx);
      if (MENU_REFERENCE.compare(XmlHelpers::DOMtoString(attr->getNodeName()))
          ==0)
      {
        info_->menuRef_ = XmlHelpers::DOMtoString(attr->getNodeValue());
      }
    }
  }

  child = menuChild_->getFirstChild();
  while (child != 0)
  {
    switch (child->getNodeType())
    {
    case XERCES_CPP_NAMESPACE::DOMNode::ELEMENT_NODE:
      nodeName_ = XmlHelpers::DOMtoString (child->getNodeName());
      if (nodeName_ == "OPTION")
      {
        XERCES_CPP_NAMESPACE::DOMNamedNodeMap *attrs = child->getAttributes();
        for (uint32_t indx = 0; indx < (uint32_t)attrs->getLength(); indx++)
        {
          XERCES_CPP_NAMESPACE::DOMNode *attr = attrs->item(indx);
          if (MENU_REFERENCE.compare(XmlHelpers::DOMtoString(attr->getNodeName()))
              ==0)
          {
            info_->actionRef_.push_back(XmlHelpers::DOMtoString(attr->getNodeValue()));
          }
        }
      } else if (nodeName_ == "MENU")
      {
        XERCES_CPP_NAMESPACE::DOMNamedNodeMap *attrs = child->getAttributes();
        for (uint32_t indx = 0; indx < (uint32_t)attrs->getLength(); indx++)
        {
          XERCES_CPP_NAMESPACE::DOMNode *attr = attrs->item(indx);
          if (MENU_REFERENCE.compare(XmlHelpers::DOMtoString(attr->getNodeName()))
              ==0)
          {
            info_->actionRef_.push_back(XmlHelpers::DOMtoString(attr->getNodeValue()));
          }
        }
        info_->listOptionMenu_.push_back(getInternalMenus(child));
      }
    }
    child = child->getNextSibling();
  }
  return info_;
}

void ViewsActionsParser::getMenus()
{
  XERCES_CPP_NAMESPACE::DOMNodeList * menus;
  XERCES_CPP_NAMESPACE::DOMNode * child;

  menus = parser_->getDocument()->getElementsByTagName(XmlHelpers::StringtoDOM("MENU").unicodeForm());
  child = menus->item(0);

  menuList_.push_back(getInternalMenus(child));

}

void ViewsActionsParser::startCode(std::ofstream &_fout)
{

  _fout << "/* -*- c++ -*- */\n"<< "/**\n"<< "*  @file   ActionFactory.cpp\n"
      << "*  @author GENERATED IN BUILD TIME (see frontpanel_action.xml for changes)\n"
      << "*  @date   Thu Jan 10 19:29:11 CEST 2007\n"
      << "*  @brief  Generated file at compile time.\n"
      << "*  @see    ActionFactory.cpp\n"<< "*\n"
      << "*  (c) Copyright Hewlett-Packard Company, 2000-2008.\n"
      << "*  All rights reserved. Copying or other reproduction of this program except\n"
      << "*  for archival purposes is prohibited without written consent of\n"
      << "*  Hewlett-Packard Company.\n"<< "*/\n"
      << "//////////////////////////////////////////////////////////////////////////////\n";

  _fout << "#include \"ActionFactory.h\"\n"
      << "#include \"IScreenTemplate.h\"\n"
      << "#include \"LocalizationIdentifiers.h\"\n"<< std::endl;

  generateActionIncludes(_fout);

  _fout
      << "IViewsAction* ActionFactory::getAction(IViewsAction::actionType_enum actionType)\n"
      << "{\n"<< "    return actionsMap_[actionType];\n"<< "}\n"
      << "ActionFactory::ActionFactory()\n"<< "{\n"<< "    initialize();\n"
      << "}\n"<< "void ActionFactory::initialize()\n"<< "{\n";

  generateActionDefinition(_fout);
  generateMenusDefinition(_fout, menuList_);

  _fout << "}\n";

}

void ViewsActionsParser::generateActionIncludes(std::ofstream &_fout)
{
  ActionsListIterator itActionsList_;

  ActionInfo *info_;

  for (itActionsList_ = actionList_.begin(); itActionsList_
      != actionList_.end(); itActionsList_++)
  {
    info_ = (ActionInfo*)*itActionsList_;
    _fout << "#include \""<< info_->headerFile_.c_str() << "\"\n";
  }
  _fout << std::endl;
}

void ViewsActionsParser::generateActionDefinition(std::ofstream &_fout)
{
  ActionsListIterator itActionsList_;

  ActionInfo *info_;
  _fout << "    IViewsAction *ptrMenu_;\n";
  for (itActionsList_ = actionList_.begin(); itActionsList_
      != actionList_.end(); itActionsList_++)
  {
    info_ = (ActionInfo*)*itActionsList_;
    if ( (GENERIC_TYPE.compare(info_->actionType_)==0)
        || (MENUTREE_TYPE.compare(info_->actionType_)==0))
    {
      _fout << "    actionsMap_[IViewsAction::"<< info_->id_.c_str()
          << "] = new "<< info_->className_.c_str()<< "("<< info_->priority_
          << ","<< "IScreenTemplate::"<< info_->temaplateName_<< ",l10n::"
          << info_->label_<< ",l10n::"<< info_->title_<< ",\""
          << info_->imageOn_<< "\",\""<< info_->imageOff_<< "\");\n";

    } else if (BACKGROUND_TYPE.compare(info_->actionType_)==0)
    {
      _fout << "    actionsMap_[IViewsAction::"<< info_->id_.c_str()
          << "] = new "<< info_->className_.c_str()<< "("<< info_->priority_
          << ");\n";
    }
  }
  _fout << std::endl;

}

void ViewsActionsParser::generateMenusDefinition(std::ofstream &_fout,
    MenusList &_mnuList)
{

  MenusListIterator itMenuList_;
  ActionReferenceIterator itActionRefList_;

  MenuInfo *info_;

  _fout << std::endl;
  for (itMenuList_ = _mnuList.begin(); itMenuList_ != _mnuList.end(); itMenuList_++)
  {
    info_ = (MenuInfo*)*itMenuList_;

    _fout << "    ptrMenu_ = dynamic_cast<IMenuAction*>(actionsMap_[IViewsAction::"
        << info_->menuRef_.c_str() << "]);\n";

    for (itActionRefList_ = info_->actionRef_.begin() ; itActionRefList_
        != info_->actionRef_.end(); itActionRefList_++)
    {
      _fout
          << "    ptrMenu_->addMenuActionElement(IViewsAction::"
          << *itActionRefList_ << ");\n";
    }
    generateMenusDefinition(_fout, info_->listOptionMenu_);
  }
}
