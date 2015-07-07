//#include "views_types.h"
#include "GuiController.h"
#include "AnimationTemplate.h"
#include "AnimationTestModelAction.h"

#include <iostream>

AnimationTestModelAction::AnimationTestModelAction(int32_t _priority_, IScreenTemplate::screenTemplate_enum _templ_, std::string _label_,
        std::string _title_, const std::string &_image_on_, const std::string &_image_off_) :
    ModelAction(IViewsAction::ANIMATION_TEST_ACTION, _priority_, _templ_, _label_, _title_, _image_on_, _image_off_)
{

}

const std::string& AnimationTestModelAction::getObjectName()
{
    return "AnimationModelAction";
}

void AnimationTestModelAction::setInterface(std::string interfaceName, void *interface)
{

}

void AnimationTestModelAction::execute()
{
    IScreenTemplate* aux = GuiController::instance().getScreenTemplateInstance(screenTemplate_);

    if (GuiController::instance().canBeExecuted(getActionType()))
    {
        aux->clear();
        aux->setWindowTitle("Initialising test animation screen...");

        (static_cast<AnimationTemplate*>(aux))->addAnimation(QPixmap(":/turbtaj/clock/clock/Clock01.bmp"));
        (static_cast<AnimationTemplate*>(aux))->addAnimation(QPixmap(":/turbtaj/clock/clock/Clock02.bmp"));
        (static_cast<AnimationTemplate*>(aux))->addAnimation(QPixmap(":/turbtaj/clock/clock/Clock03.bmp"));
        (static_cast<AnimationTemplate*>(aux))->addAnimation(QPixmap(":/turbtaj/clock/clock/Clock04.bmp"));
        (static_cast<AnimationTemplate*>(aux))->addAnimation(QPixmap(":/turbtaj/clock/clock/Clock05.bmp"));
        (static_cast<AnimationTemplate*>(aux))->addAnimation(QPixmap(":/turbtaj/clock/clock/Clock06.bmp"));
        (static_cast<AnimationTemplate*>(aux))->addAnimation(QPixmap(":/turbtaj/clock/clock/Clock07.bmp"));
        (static_cast<AnimationTemplate*>(aux))->addAnimation(QPixmap(":/turbtaj/clock/clock/Clock08.bmp"));
        (static_cast<AnimationTemplate*>(aux))->addAnimation(QPixmap(":/turbtaj/clock/clock/Clock09.bmp"));
        (static_cast<AnimationTemplate*>(aux))->addAnimation(QPixmap(":/turbtaj/clock/clock/Clock10.bmp"));
        (static_cast<AnimationTemplate*>(aux))->addAnimation(QPixmap(":/turbtaj/clock/clock/Clock11.bmp"));
        (static_cast<AnimationTemplate*>(aux))->addAnimation(QPixmap(":/turbtaj/clock/clock/Clock12.bmp"));
        (static_cast<AnimationTemplate*>(aux))->time(200);

        GuiController::instance().setCurrentIndex((int32_t)screenTemplate_);
        GuiController::instance().show();
    }
}

bool AnimationTestModelAction::hasMenuOption()
{
    return false;
}
