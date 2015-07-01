#include "backupmainwindow.h"
#include "ui_backupmainwindow.h"

BackupMainWindow::BackupMainWindow(QWidget *parent): QWidget(parent){}

BackupMainWindow::BackupMainWindow(QWidget *parent, QWidget *backupStackedWidget) :
    QWidget(parent),
    ui(new Ui::BackupMainWindow)
{
    ui->setupUi(this);
    this->backupStackedWidget = backupStackedWidget;
}

BackupMainWindow::~BackupMainWindow()
{
    delete ui;
}
