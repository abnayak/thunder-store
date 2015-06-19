QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app

TARGET = ../build/thunder-store

SOURCES += \
    main.cpp \
    welcomewidget.cpp \
    mainwindow.cpp

HEADERS += \
    welcomewidget.h \
    mainwindow.h


FORMS += \
    welcomewidget.ui \
    mainwindow.ui

OBJECTS_DIR = ../build/objdir

MOC_DIR = ../build/moc

UI_DIR +=

RESOURCES += \
    resources.qrc


