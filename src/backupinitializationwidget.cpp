#include "backupinitializationwidget.h"
#include "ui_backupinitializationwidget.h"

BackupInitializationWidget::BackupInitializationWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BackupInitializationWidget)
{
    ui->setupUi(this);

    //  Make the checkboxes to have three stages
    ui->thunderbirdInstanceCB->setTristate(true);
    ui->profileFoundCB->setTristate(true);

    processChecker = new ProcessChecker(this);

    //check if thunderbird folder is present
    QString folderLoc = "";
    FileSystemUtils *fileSystemUtils = new FileSystemUtils(folderLoc);

    // Connect the signal and slots of the process profile checker
    connect(processChecker,SIGNAL(processRunning(int)),this,SLOT(thunderbirdProcessFound(int)));
    connect(fileSystemUtils,SIGNAL(profileSearchFinished(int)),this,SLOT(thunderbirdProfileFound(int)));

    processChecker->isThunderbirdRunning();
    fileSystemUtils->isProfilePresent();


}

BackupInitializationWidget::~BackupInitializationWidget()
{
    delete ui;
}

void BackupInitializationWidget::thunderbirdProcessFound(int found) {
    qDebug() << "inside the thunderbirdprocessround slot()" <<endl;
    if(found == 1){
        ui->thunderbirdInstanceCB->setCheckState( Qt::PartiallyChecked );
    } else if( found == 0){
        qDebug() << "checkbox status: " << endl;
        ui->thunderbirdInstanceCB->setChecked(true);
    }

}

void BackupInitializationWidget::thunderbirdProfileFound(int found) {
    if(found) {
        ui->profileFoundCB->setChecked(true);
    }
}
