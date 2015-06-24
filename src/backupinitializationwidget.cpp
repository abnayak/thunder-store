#include "backupinitializationwidget.h"
#include "ui_backupinitializationwidget.h"

BackupInitializationWidget::BackupInitializationWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BackupInitializationWidget)
{
    ui->setupUi(this);

    // set the min and max of the progress bar
    ui->progressBar->setMinimum(1);
    ui->progressBar->setMaximum(20);

    //  Make the checkboxes to have three stages
    ui->thunderbirdInstanceCB->setTristate(true);
    ui->profileFoundCB->setTristate(true);

    // Create the background process
    runner = new BackupInitializationRunner(this);
    runner->setAutoDelete(false);
    QThreadPool::globalInstance()->start(runner);

    // Deactivate the next button
    ui->pushButton2->setDisabled(true);
    ui->pushButton1->setDisabled(true);

    // Hide the message level
    ui->message->setVisible(false);

    // Hide file browse widgets

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

void BackupInitializationWidget::updateProgressBar() {
    ui->progressBar->setValue(ui->progressBar->value()+1);
}

void BackupInitializationWidget::onBackupInitializationRunnerFinished() {
    ui->pushButton1->setDisabled(false);
    ui->pushButton2->setDisabled(false);

    if (ui->thunderbirdInstanceCB->checkState() == Qt::PartiallyChecked) {
        // This means thunderbird instance is running
        // Show use warning to close the thunderbird instance and restart
        // the process
        ui->message->setText("ERROR: Thunderbird is running. Please close it and restart the process");
        ui->message->setVisible(true);
    }


    if (ui->profileFoundCB->checkState() == Qt::PartiallyChecked) {
        // This means thunderbird profile not found.
        // Show use appropriate message

    }

}

