TEMPLATE = app
TARGET = KDPATray
INCLUDEPATH += ../KPersonalAsistant/gui/DesignerScreens/
QT += core \
    gui \
    network
HEADERS += ping.h \
    KdpaTray.h \
    ui_KNotitaScreen.h
SOURCES += main.cpp \
    KdpaTray.cpp
FORMS += CSServerConfig.ui \
    KdpaTray.ui
RESOURCES += kdpatrayresources.qrc
