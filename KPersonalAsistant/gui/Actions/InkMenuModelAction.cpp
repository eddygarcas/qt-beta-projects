//#include "views_types.h"
#include "GuiController.h"
#include "InkMenuModelAction.h"
#include "TextListMenuTemplate.h"

#include "ActionFactory.h"

#include <QtGui/QLabel>

InkMenuModelAction::InkMenuModelAction(int32_t _priority_, IScreenTemplate::screenTemplate_enum _templ_, std::string _label_, std::string _title_,
        const std::string &_image_on_, const std::string &_image_off_) :
    ModelAction(IViewsAction::INK_TEXT_MENU_ACTION, _priority_, _templ_, _label_, _title_, _image_on_, _image_off_)
{

}

const std::string& InkMenuModelAction::getObjectName()
{
    return "InkMenuModelAction";
}

/**
 * This methos adds an option in menu tree.
 *
 * @param _actionType
 */
void InkMenuModelAction::addMenuActionElement(IViewsAction::actionType_enum _actionType_)
{
    menuOptions_.push_back(_actionType_);
}

void InkMenuModelAction::setInterface(std::string interfaceName, void *interface)
{

}

void InkMenuModelAction::execute()
{
    if (GuiController::instance().canBeExecuted(getActionType()))
    {
        createMenuElements();
        GuiController::instance().setCurrentIndex((int32_t)screenTemplate_);
        GuiController::instance().show();
    }
}

bool InkMenuModelAction::hasMenuOption()
{
    return true;
}

void InkMenuModelAction::createMenuElements()
{
    TextListMenuTemplate* _aux = static_cast<TextListMenuTemplate*>(GuiController::instance().getScreenTemplateInstance(screenTemplate_));
    _aux->clear();
    _aux->setWindowTitle("Ink menu");

    MenuActionOptionsIterator it;
    ModelAction *_itModelAction;

    for (it = menuOptions_.begin(); it != menuOptions_.end(); it++)
    {
        IViewsAction::actionType_enum type_ = *it;
        _itModelAction = static_cast<ModelAction*>(ActionFactory::instance().getAction(type_));
        //TODO: Change the getObjectName call to real option title/label
        _aux->addOption(_itModelAction->getObjectName().c_str(), _itModelAction);
    }
}
