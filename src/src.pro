QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app

TARGET = ../build/thunder-store

SOURCES += \
    mainwindow.cpp \
    welcome.cpp \
    main.cpp

HEADERS += \
    mainwindow.h \
    welcome.h


FORMS += \
    mainwindow.ui \
    welcome.ui

OBJECTS_DIR = ../build/objdir

MOC_DIR = ../build/moc

UI_DIR +=


