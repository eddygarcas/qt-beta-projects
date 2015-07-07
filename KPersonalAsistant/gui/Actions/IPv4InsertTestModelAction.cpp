//#include "views_types.h"
#include "GuiController.h"
#include "IPv4InsertTestModelAction.h"

IPv4InsertTestModelAction::IPv4InsertTestModelAction(int32_t _priority_, IScreenTemplate::screenTemplate_enum _templ_, std::string _label_,
        std::string _title_, const std::string &_image_on_, const std::string &_image_off_) :
    ModelAction(IViewsAction::INSERT_IPV4_ACTION, _priority_, _templ_, _label_, _title_, _image_on_, _image_off_)
{

}

const std::string& IPv4InsertTestModelAction::getObjectName()
{
    return "IPv4InsertTestModelAction";
}

void IPv4InsertTestModelAction::setInterface(std::string interfaceName, void *interface)
{

}

void IPv4InsertTestModelAction::insertAddressInViews(QString address)
{

}

void IPv4InsertTestModelAction::execute()
{
    IScreenTemplate* aux = GuiController::instance().getScreenTemplateInstance(screenTemplate_);

    if (GuiController::instance().canBeExecuted(getActionType()))
    {
        aux->setWindowTitle("Add printer IP");
        connect(static_cast<IPv4AddressTemplate*>(aux), SIGNAL(giveBackAddress(QString)), this, SLOT(insertAddressInViews(QString)));

        GuiController::instance().setCurrentIndex((int32_t)screenTemplate_);
        GuiController::instance().show();
    }
}

bool IPv4InsertTestModelAction::hasMenuOption()
{
    return false;
}
