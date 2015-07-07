//#include "views_types.h"
#include "GuiController.h"
#include "ProgressBarTemplate.h"
#include "ProgressTestModelAction.h"

#include <iostream>


ProgressTestModelAction::ProgressTestModelAction(int32_t _priority_, IScreenTemplate::screenTemplate_enum _templ_, std::string _label_,
        std::string _title_, const std::string &_image_on_, const std::string &_image_off_) :
    ModelAction(IViewsAction::TEST_PROGRESSBAR_ACTION, _priority_, _templ_, _label_, _title_, _image_on_, _image_off_)
{

}

const std::string& ProgressTestModelAction::getObjectName()
{
    return "ProgressTestModelAction";
}

void ProgressTestModelAction::setInterface(std::string interfaceName, void *interface)
{
}

void ProgressTestModelAction::execute()
{
    IScreenTemplate* aux = GuiController::instance().getScreenTemplateInstance(screenTemplate_);

    if (GuiController::instance().canBeExecuted(getActionType()))
    {
        aux->clear();
        aux->setWindowTitle("Progress bar test template...");

        GuiController::instance().setCurrentIndex((int32_t)screenTemplate_);
        GuiController::instance().show();
    }
}

bool ProgressTestModelAction::hasMenuOption()
{
    return false;
}
