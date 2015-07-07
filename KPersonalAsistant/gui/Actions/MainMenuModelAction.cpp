//#include "views_types.h"
#include "GuiController.h"
#include "MenuPushButton.h"
#include "MainMenuModelAction.h"
#include "MainMenuTemplate.h"

#include "ActionFactory.h"


MainMenuModelAction::MainMenuModelAction(int32_t _priority_, IScreenTemplate::screenTemplate_enum _templ_, std::string _label_, std::string _title_,
        const std::string &_image_on_, const std::string &_image_off_) :
    ModelAction(IViewsAction::MENU_ACTION, _priority_, _templ_, _label_, _title_, _image_on_, _image_off_)
{

}

const std::string& MainMenuModelAction::getObjectName()
{
    return "MainMenuModelAction";
}

/**
 * This methos adds an option in menu tree.
 *
 * @param _actionType
 */
void MainMenuModelAction::addMenuActionElement(IViewsAction::actionType_enum _actionType_)
{
    menuOptions_.push_back(_actionType_);
}

void MainMenuModelAction::setInterface(std::string interfaceName, void *interface)
{

}

void MainMenuModelAction::execute()
{

    if (GuiController::instance().canBeExecuted(getActionType()))
    {

        createMenuElements();

        GuiController::instance().setCurrentIndex((int32_t)screenTemplate_);
        GuiController::instance().show();
    }
}

bool MainMenuModelAction::hasMenuOption()
{
    return true;
}

void MainMenuModelAction::createMenuElements()
{
    MainMenuTemplate* _aux = static_cast<MainMenuTemplate*>(GuiController::instance().getScreenTemplateInstance(screenTemplate_));
    _aux->clear();
    _aux->setWindowTitle("Turbo Taj main menu");

    MenuActionOptionsIterator it;

    MenuPushButton *_buttonConn;
    ModelAction *_itModelAction;
    for (it = menuOptions_.begin(); it != menuOptions_.end(); it++)
    {
        _buttonConn = new MenuPushButton(QSize(51,51),_aux);

        IViewsAction::actionType_enum type_ = *it;

        _itModelAction = static_cast<ModelAction*>(ActionFactory::instance().getAction(type_));

        _buttonConn->setOutfocusIcon(QIcon(QString::fromUtf8(_itModelAction->getImageOff().c_str())));
        _buttonConn->setOnfocusIcon(QIcon(QString::fromUtf8(_itModelAction->getImageOn().c_str())));

        //TODO: _buttonConn->setButtonInformation(_itModelAction->getActionLabel());
        _buttonConn->setActionModel(ActionFactory::instance().getAction(type_));
        _aux->addOption(_buttonConn);
    }

}
