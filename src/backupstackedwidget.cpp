#include "backupstackedwidget.h"
#include "ui_backupstackedwidget.h"
#include "backupinitializationwidget.h"

BackupStackedWidget::BackupStackedWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BackupStackedWidget)
{
    mainWindow = parent;
    ui->setupUi(this);
    BackupInitializationWidget *backupInitializationWidget = new BackupInitializationWidget(mainWindow, this);
    BackupMainWindow *backupMainWindow = new BackupMainWindow(parent, this);

    ui->stackedWidget->addWidget(backupInitializationWidget);
    ui->stackedWidget->addWidget(backupMainWindow);
}

BackupStackedWidget::~BackupStackedWidget() {
    delete ui;
}

void  BackupStackedWidget::onShowBackupMainWindow(QString folderLoc) {
    ui->stackedWidget->setCurrentIndex(1);
}
