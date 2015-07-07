#include "kdesktoppersonalasistant.h"
#include "io.h"


KDesktopPersonalAsistant::KDesktopPersonalAsistant(QWidget *parent)
    : QMainWindow(parent)
{
	ui.setupUi(this);
 ui.controller->start();

	//GuiController::instance().setParent(this);

	//GuiController::instance(this).setLayout(ui.verticalLayout);

}

KDesktopPersonalAsistant::~KDesktopPersonalAsistant()
{

}

void KDesktopPersonalAsistant::on_action_Exit_triggered (bool triggered)
{
 std::cout << "EEEEEEEEE" << std::endl;
    this->close();
}
