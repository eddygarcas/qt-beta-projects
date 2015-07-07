#include "Pdl.h"

Pdl::Pdl(std::string& _descr, std::string& _level)
{
  description_ = _descr;
  langLevel_ = _level;
}

Pdl::~Pdl()
{

}

std::string Pdl::getDescription()
{
  return description_;
}

std::string Pdl::getLangLevel()
{
  return langLevel_;
}
