#include "mainwindow.h"
#include <QApplication>
#include <backupstackedwidget.h>
#include <backupinitializationwidget.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Set the style sheet of the group box
    //a.setStyleSheet("QGroupBox { border: 1px solid gray; border-radius: 9px; margin-top: 0.5em;}");
    //a.setStyleSheet("QGroupBox::title { subcontrol-origin: margin;left: 10px; padding: 0 3px 0 3px;}");

    MainWindow w;
    w.show();

    return a.exec();
}
