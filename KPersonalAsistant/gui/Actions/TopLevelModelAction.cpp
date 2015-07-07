//#include "views_types.h"
#include "GuiController.h"
#include "MenuPushButton.h"
#include "TopLevelModelAction.h"
#include "TopLevelTemplate.h"

TopLevelModelAction::TopLevelModelAction(int32_t _priority_, IScreenTemplate::screenTemplate_enum _templ_, std::string _label_, std::string _title_,
        const std::string &_image_on_, const std::string &_image_off_) :
    ModelAction(IViewsAction::TOPLEVEL_ACTION, _priority_, _templ_, _label_, _title_, _image_on_, _image_off_)
{

}

const std::string& TopLevelModelAction::getObjectName()
{
    return "TopLevelModelAction";
}

void TopLevelModelAction::setInterface(std::string interfaceName, void *interface)
{
    if (interfaceName == "IPrinterInformation")
    {
        //printerInformation_ = static_cast<IPrinterInformation*>(interface);
    }
}

void TopLevelModelAction::execute()
{
    IScreenTemplate* aux = GuiController::instance().getScreenTemplateInstance(screenTemplate_);

    if (GuiController::instance().canBeExecuted(getActionType()))
    {
        aux->clear();

        (static_cast<TopLevelTemplate*>(aux))->setWindowTitle("Ready");
        (static_cast<TopLevelTemplate*>(aux))->setPrinterUrl(QString("http://NP00040AFDVF34353.test.com"));
        (static_cast<TopLevelTemplate*>(aux))->setPrinterIPv4(QString("http://16.23.86.65"));
        (static_cast<TopLevelTemplate*>(aux))->setManufacturerLogo(QPixmap(":/turbotaj/alerts/specialAlerts/bigRollIcon.bmp"));
        (static_cast<TopLevelTemplate*>(aux))->setTextToMenu(QString("Press # to enter menu..."));

        GuiController::instance().setCurrentIndex((int32_t)screenTemplate_);
        GuiController::instance().show();
    }
}

bool TopLevelModelAction::hasMenuOption()
{
    return false;
}


