#-------------------------------------------------
#
# Project created by QtCreator 2016-12-22T11:21:57
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets opengl

TARGET = egym
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    klabel.cpp \
    glanim.cpp \
    ktexture.cpp \
    tracepoint.cpp \
    kpart.cpp \
    perftimer.cpp

HEADERS  += mainwindow.h \
    klabel.h \
    glanim.h \
    ktexture.h \
    tracepoint.h \
    kpart.h \
    perftimer.h

FORMS    += mainwindow.ui

RESOURCES += \
    form1.qrc

LIBS += opengl32.lib glu32.lib

win32:RC_ICONS += res/basketball.ico

Release:DESTDIR = release
Release:OBJECTS_DIR = release/.obj
Release:MOC_DIR = release/.moc
Release:RCC_DIR = release/.rcc

Debug:DESTDIR = debug
Debug:OBJECTS_DIR = debug/.obj
Debug:MOC_DIR = debug/.moc
Debug:RCC_DIR = debug/.rcc