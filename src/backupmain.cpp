#include "backupmain.h"
#include "ui_backupmain.h"

BackupMain::BackupMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BackupMain)
{
    ui->setupUi(this);
}

BackupMain::~BackupMain()
{
    delete ui;
}
