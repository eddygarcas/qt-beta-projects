//#include "views_types.h"
#include "GuiController.h"
#include "InkLevelTemplate.h"
#include "InkLevelModelAction.h"

#include <iostream>

InkLevelModelAction::InkLevelModelAction(int32_t _priority_, IScreenTemplate::screenTemplate_enum _templ_, std::string _label_, std::string _title_,
        const std::string &_image_on_, const std::string &_image_off_) :
    ModelAction(IViewsAction::INKLEVEL_ACTION, _priority_, _templ_, _label_, _title_, _image_on_, _image_off_)
{

}

const std::string& InkLevelModelAction::getObjectName()
{
    return "InkLevelModelAction";
}

void InkLevelModelAction::setInterface(std::string interfaceName, void *interface)
{

}

void InkLevelModelAction::execute()
{
    IScreenTemplate* aux = GuiController::instance().getScreenTemplateInstance(screenTemplate_);

    if (GuiController::instance().canBeExecuted(getActionType()))
    {
        aux->clear();
        aux->setWindowTitle("Ink level sceen InkLevelTemplate");
        for (int index = 0; index < 5; index++)
        {
            (static_cast<InkLevelTemplate*>(aux))->addInkLevel("R", 23+index);
        }

        GuiController::instance().setCurrentIndex((int32_t)screenTemplate_);
        GuiController::instance().show();
    }
}

bool InkLevelModelAction::hasMenuOption()
{
    return false;
}
