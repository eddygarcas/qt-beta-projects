win32:LIBS += ../KPersonalAsistant/release/libKPersonalAsistant.a
TEMPLATE = app
CONFIG += release
INCLUDEPATH = ../KPersonalAsistant/gui/ ../KPersonalAsistant/gui/DesignerScreens ../KPersonalAsistant/gui/Actions ../KPersonalAsistant/gui/GuiController ../KPersonalAsistant/gui/GuiMain ../KPersonalAsistant/gui/ScreenTemplates
TARGET = KDesktopPersonalAsistant
QT += core \
    gui \
    xml \
    network \
    opengl \
    webkit
HEADERS += kdesktoppersonalasistant.h
SOURCES += main.cpp \
    kdesktoppersonalasistant.cpp
#FORMS += kdesktoppersonalasistant.ui
RESOURCES += 
