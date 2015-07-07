#include "ViewsPreventiveMaintenanceKit.h"

ViewsPreventiveMaintenanceKit::ViewsPreventiveMaintenanceKit(
    std::string& _descr, std::string& _number, uint16_t _percentUsed) :
  percentUsed_(_percentUsed)
{
  description_ = _descr;
  partNumber_ = _number;
}

ViewsPreventiveMaintenanceKit::~ViewsPreventiveMaintenanceKit()
{

}

std::string ViewsPreventiveMaintenanceKit::getDescription()
{
  return description_;
}

std::string ViewsPreventiveMaintenanceKit::getPartNumber()
{
  return partNumber_;
}

uint16_t ViewsPreventiveMaintenanceKit::getPercentUsed()
{
  return percentUsed_;
}

