#ifndef VIEWSACTIONSPARSER_H_
#define VIEWSACTIONSPARSER_H_

/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ViewsActionsParser.h
 *  @author Hewlett-Packard
 *  @date   Mon Mar 06 10:44:38 METDST 2003
 *  @brief  header file for the implementation of views actions
 *          generator using Xerces-C parser.
 *
 *  (c) Copyright Hewlett-Packard Company, 2006. 
 *  All rights reserved. Copying or other reproduction of this program except 
 *  for archival purposes is prohibited without written consent of 
 *  Hewlett-Packard Company. 
 */
////////////////////////////////////////////////////////////////////////////////


#include "RedOS_pub_api.h"
#include "atlas_types.h"
#include "xml/XmlHelpers.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>

const std::string ACTION_ID       = "ID";
const std::string ACTION_TYPE     = "TYPE";
const std::string ACTION_PRIORITY = "PRIORITY";
const std::string MENU_REFERENCE  = "REFERENCE";

const std::string GENERIC_TYPE    = "GENERIC";
const std::string MENUTREE_TYPE   = "MENUTREE";
const std::string BACKGROUND_TYPE = "BACKGROUND";

/**
 * This is an auxuiliary object to perform the XML actions file parser. 
 */
struct ActionInfo
{
  ActionInfo()
  {
  }
  std::string actionType_;
  std::string priority_;
  std::string id_;
  std::string headerFile_;
  std::string className_;
  std::string temaplateName_;
  std::string label_;
  std::string title_;
  std::string imageOn_;
  std::string imageOff_;
};

/**
 * This is an auxuiliary object to perform the XML menu actions file parser. 
 */
struct MenuInfo
{
  typedef std::vector<MenuInfo*> MenusList;
  MenuInfo()
  {
  }
  std::string menuRef_;
  std::vector<std::string> actionRef_;
  MenusList listOptionMenu_;

};

typedef std::vector<ActionInfo*> ActionsList;
typedef std::vector<MenuInfo*> MenusList;

typedef std::vector<ActionInfo*>::iterator ActionsListIterator;
typedef std::vector<MenuInfo*>::iterator MenusListIterator;
typedef std::vector<std::string>::iterator ActionReferenceIterator;

class ViewsActionsParser
{
public:

  /**Void constructor*/
  ViewsActionsParser();

  /**
   * Launch the actions Xml file parser process. 
   * If this process ends fine, it returns true, otherwise returns false.
   * 
   * @param std::string Path and XML actions file
   * @param std::string Output file
   * @reutrn bool
   */
  bool run(std::string _xmlFileName, std::string _headerFileName);

  /**
   * Has the same functionality that  method above, the only diferences are the parameter types.
   * 
   * @param std::string XML content NOT path.
   * @param std::ofstrem The output stream, where this process writes the header content.
   * @return bool
   */
  bool run(std::string _xmlContent, std::ofstream &_fileHeader);

  /**Class destructor*/
  virtual ~ViewsActionsParser();

protected:
  
  /**
   * Generates the actions code
   */
  void getActions();

  /**
   *Generates the menu code.
   */
  void getMenus();

  /**
   * This method calls itself, until completely construction of  menu tree.
   * 
   * @param XERCES_CPP_NAMESPACE::DOMNode DOMNode which contrais the menu content.
   * @return MenuInfo*
   */
  MenuInfo* getInternalMenus(XERCES_CPP_NAMESPACE::DOMNode *_menuChild);

  /**
   * Generates the header content of header file.
   * 
   * @param std::ofstream&
   */
  void startCode(std::ofstream&);

private:
  /**Internal parser*/
  XERCES_CPP_NAMESPACE::XercesDOMParser *parser_;
  /**Instance of ActionList which holds actions elements.*/
  ActionsList actionList_;
  /**Instance of Menulist which contains menu tree elements*/
  MenusList menuList_;

  /**
   * Generates the code of actions
   * 
   * @param std::ofstream&
   */
  void generateActionsCode(std::ofstream&);
  /**
   * Generates the actions includes code
   * 
   * @param std::ofstream
   */
  void generateActionIncludes(std::ofstream&);
  /**
   * Generates the actions definitions
   * 
   * @param std::ofstream&
   */
  void generateActionDefinition(std::ofstream&);
  /**
   * Generates the menus definition.
   * 
   * @param std::ofstream&
   */
  void generateMenusDefinition(std::ofstream&, MenusList&);

};
#endif /*VIEWSACTIONSPARSER_H_*/
