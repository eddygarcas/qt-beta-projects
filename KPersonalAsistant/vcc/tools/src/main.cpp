#include "ViewsSettingsParser.h"
#include <iostream>
#include <iomanip>
#include <list>

using namespace std;

int main( int argc, char ** argv )
{
  std::string _xmlFileName;
  std::string _headerFileName;
 

  XERCES_CPP_NAMESPACE::XMLPlatformUtils::Initialize();
  
  ViewsSettingsParser *xmlParse = new ViewsSettingsParser();
  
  _xmlFileName=argv[1];
  _headerFileName=argv[2];

  std::ofstream tsFile(_headerFileName.c_str());
 
  xmlParse->run(_xmlFileName,tsFile);
  
  delete xmlParse;
  xmlParse = 0;
  
  XERCES_CPP_NAMESPACE::XMLPlatformUtils::Terminate();
  return 0;
}
