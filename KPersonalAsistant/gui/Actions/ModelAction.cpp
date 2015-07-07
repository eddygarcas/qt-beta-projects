#include "ModelAction.h"

ModelAction::ModelAction(IViewsAction::actionType_enum actionType, int32_t priority, IScreenTemplate::screenTemplate_enum screenTemplate,
        std::string label, std::string title, const std::string &image_on, const std::string &image_off) :
    actionType_(actionType), priority_(priority), screenTemplate_(screenTemplate), label_(label), title_(title), image_on_(image_on), image_off_(image_off)
{

}

IViewsAction::actionType_enum ModelAction::getActionType()
{
    return actionType_;
}

int32_t ModelAction::getPriority()
{
    return priority_;
}

std::string ModelAction::getActionLabel()
{
    return label_;
}

std::string ModelAction::getActionTitle()
{
    return title_;
}

std::string ModelAction::getImageOn()
{
    return image_on_;
}

std::string ModelAction::getImageOff()
{
    return image_off_;
}

ModelAction::~ModelAction()
{

}
