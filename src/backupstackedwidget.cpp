#include "backupstackedwidget.h"
#include "ui_backupstackedwidget.h"
#include "backupinitializationwidget.h"

BackupStackedWidget::BackupStackedWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BackupStackedWidget)
{
    mainWindow = parent;
    ui->setupUi(this);
    BackupInitializationWidget *backupInitializationWidget = new BackupInitializationWidget(mainWindow);

    ui->stackedWidget->addWidget(backupInitializationWidget);
}

BackupStackedWidget::~BackupStackedWidget() {
    delete ui;
}
