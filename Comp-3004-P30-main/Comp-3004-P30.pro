#-------------------------------------------------
#
# Project created by QtCreator 2021-04-01T20:55:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Comp-3004-P30
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        allergy.cpp \
        battery.cpp \
        bloating.cpp \
        button.cpp \
        cpu.cpp \
        display.cpp \
        electrode.cpp \
        frequency.cpp \
        frequencypage.cpp \
        frequencytherapypage.cpp \
        historypage.cpp \
        kidney.cpp \
        main.cpp \
        mainmenupage.cpp \
        mainwindow.cpp \
        noimplementation.cpp \
        page.cpp \
        powerdownpage.cpp \
        powerlevel.cpp \
        program.cpp \
        programspage.cpp \
        recording.cpp \
        startpage.cpp \
        therapypage.cpp \
        thread.cpp \
        trauma.cpp \
        viewhistorypage.cpp


HEADERS += \
        allergy.h \
        battery.h \
        bloating.h \
        button.h \
        cpu.h \
        display.h \
        electrode.h \
        frequency.h \
        frequencypage.h \
        frequencytherapypage.h \
        historypage.h \
        kidney.h \
        mainmenupage.h \
        mainwindow.h \
        noimplementation.h \
        page.h \
        powerdownpage.h \
        powerlevel.h \
        program.h \
        programspage.h \
        recording.h \
        startpage.h \
        therapypage.h \
        thread.h \
        trauma.h \
        viewhistorypage.h


FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
