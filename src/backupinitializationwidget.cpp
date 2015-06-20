#include "backupinitializationwidget.h"
#include "ui_backupinitializationwidget.h"

BackupInitializationWidget::BackupInitializationWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BackupInitializationWidget)
{
    ui->setupUi(this);
    processChecker = new ProcessChecker(this);
    //qDebug() << processChecdker->isThunderbirdRunning() << endl;

}

BackupInitializationWidget::~BackupInitializationWidget()
{
    delete ui;
}
