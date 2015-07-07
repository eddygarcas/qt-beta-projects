TEMPLATE = app
TARGET = QGnuPGP
QT += core \
    gui \
    xml \
    network \
    script
HEADERS += qgnupgpmenu.h 
SOURCES += qgnupgpmenu.cpp \
     main.cpp
FORMS += qgnupgpmenu.ui
RESOURCES += QGnuPGPResources.qrc
