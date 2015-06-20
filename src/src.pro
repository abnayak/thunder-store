QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app

TARGET = ../build/thunder-store

SOURCES += \
    main.cpp \
    welcomewidget.cpp \
    mainwindow.cpp \
    backupstackedwidget.cpp \
    backupinitializationwidget.cpp \
    processchecker.cpp

HEADERS += \
    welcomewidget.h \
    mainwindow.h \
    backupstackedwidget.h \
    backupinitializationwidget.h \
    processchecker.h

FORMS += \
    welcomewidget.ui \
    mainwindow.ui \
    backupstackedwidget.ui \
    backupinitializationwidget.ui

OBJECTS_DIR = ../build/objdir

MOC_DIR = ../build/moc

UI_DIR +=

RESOURCES += \
    resources.qrc


