QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aboutdialog.cpp \
    consoleoutput.cpp \
    fworker.cpp \
    main.cpp \
    dsamainwindow.cpp

HEADERS += \
    aboutdialog.h \
    consoleoutput.h \
    dsamainwindow.h \
    fworker.h

FORMS += \
    aboutdialog.ui \
    consoleoutput.ui \
    dsamainwindow.ui

TRANSLATIONS += \
    DSA-Multitool-GUI_en_US.ts

RESOURCES += \
    rsc.qrc

TARGET = "DSA Multitool"

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RC_ICONS = Icon-Black-Win.ico
ICON = Icon-Black-macOS.icns

DISTFILES += \
    Icon-Black-Win.ico \
    Icon-Black-macOS.icns
