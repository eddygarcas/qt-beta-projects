win32:UI_DIR = gui/DesignerScreens
INCLUDEPATH = gui/ gui/DesignerScreens gui/Actions gui/GuiController gui/GuiMain gui/ScreenTemplates
DEPENDPATH = gui/DesignerScreens gui/Actions gui/GuiController gui/GuiMain gui/ScreenTemplates
TEMPLATE = lib
CONFIG += qt thread release staticlib static
#TEMPLATE = app
#CONFIG += qt thread release

TARGET = KPersonalAsistant
QT += core \
    gui \
    network
HEADERS += GuiController.h \
ActionFactory.h \
TextListMenuTemplate.h \
IPv4AddressTemplate.h \
AnimationTemplate.h \
MainMenuTemplate.h \
ProgressBarTemplate.h \
TopLevelTemplate.h \
InkLevelTemplate.h \
ChoiceScreenTemplate.h \
ScreenTitle.h \
ScreenTemplate.h \
WidgetScroll.h \
InkLevel.h \
StatusBar.h \
notepadwidget.h \
MenuPushButton.h \
IPv4Address.h \
OptionPushButton.h \
ModelAction.h \
MainMenuModelAction.h \
InkMenuModelAction.h \
AnimationTestModelAction.h \
IPv4InsertTestModelAction.h \
TopLevelModelAction.h \
ProgressTestModelAction.h \
InkLevelModelAction.h


SOURCES += main.cpp \
GuiController.cpp \
ActionFactory.cpp \
TextListMenuTemplate.cpp \
IPv4AddressTemplate.cpp \
AnimationTemplate.cpp \
MainMenuTemplate.cpp \
ProgressBarTemplate.cpp \
TopLevelTemplate.cpp \
InkLevelTemplate.cpp \
ChoiceScreenTemplate.cpp \
ScreenTitle.cpp \
ScreenTemplate.cpp \
WidgetScroll.cpp \
InkLevel.cpp \
StatusBar.cpp \
notepadwidget.cpp \
MenuPushButton.cpp \
IPv4Address.cpp \
OptionPushButton.cpp \
ModelAction.cpp \
MainMenuModelAction.cpp \
InkMenuModelAction.cpp \
AnimationTestModelAction.cpp \
IPv4InsertTestModelAction.cpp \
TopLevelModelAction.cpp \
ProgressTestModelAction.cpp \
InkLevelModelAction.cpp


FORMS += AnimationScreen.ui \
InkLevelScreen.ui \
IPAddressScreen.ui \
MainMenuScreen.ui \
ModelScreen.ui \
ProgressBarScreen.ui \
StatusbarPlugin.ui \
TextListScreen.ui \
TopLevelScreen.ui \
KNotitaPopupMenu.ui \
KNotitaScreen.ui \
IPAddressRange.ui \
IntervalPingValue.ui


VERSION = 1.0.1
RESOURCES += 
#DESTDIR = ../KDesktopPersonalAsistant/release/
