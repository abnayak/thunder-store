#include "backupstackedwidget.h"
#include "ui_backupstackedwidget.h"
#include "backupinitializationwidget.h"

BackupStackedWidget::BackupStackedWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BackupStackedWidget)
{
    ui->setupUi(this);
    BackupInitializationWidget *backupInitializationWidget = new BackupInitializationWidget(this);

    ui->stackedWidget->addWidget(backupInitializationWidget);

}

BackupStackedWidget::~BackupStackedWidget()
{
    delete ui;
}
