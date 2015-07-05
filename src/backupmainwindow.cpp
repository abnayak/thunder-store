#include "backupmainwindow.h"
#include "ui_backupmainwindow.h"

BackupMainWindow::BackupMainWindow(QWidget *parent): QWidget(parent){}

BackupMainWindow::BackupMainWindow(QWidget *parent, QWidget *backupStackedWidget) :
    QWidget(parent),
    ui(new Ui::BackupMainWindow)
{
    ui->setupUi(this);
    this->backupStackedWidget = backupStackedWidget;

    // Hide the error message label
    ui->fileWritableStatus->setVisible(false);

    // Disable backup button until all the conditions are met
    ui->backupButton->setDisabled(true);

    // Disable all the fields related to password
    toglePasswordFields();

    // Connect the signal and slots
    connect(ui->usepasswordCheckBox,SIGNAL(clicked()),this,SLOT(onUsePasswordClicked()));
    connect(ui->allCheckBox,SIGNAL(clicked()),this,SLOT(onBackupAllCheckBoxClick()));
    connect(ui->fileBrowseButton,SIGNAL(clicked()),this,SLOT(onFileBrowseButtonClick()));
}

void BackupMainWindow::toglePasswordFields() {
    if(ui->passwordLineEdit->isEnabled()){
        ui->passwordLineEdit->clear();
        ui->passwordLineEdit->setDisabled(true);
        ui->verifyPasswordLineEdit->clear();
        ui->verifyPasswordLineEdit->setDisabled(true);
        ui->showPasswordCheckBox->setChecked(false);
        ui->showPasswordCheckBox->setDisabled(true);
    } else {
        ui->passwordLineEdit->setEnabled(true);
        ui->verifyPasswordLineEdit->setEnabled(true);
        ui->showPasswordCheckBox->setEnabled(true);
    }
}

BackupMainWindow::~BackupMainWindow()
{
    delete ui;
}

void BackupMainWindow::onUsePasswordClicked() {
    toglePasswordFields();
}

void BackupMainWindow::onFileBrowseButtonClick() {
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "/" "*.zip");
    ui->locationLineEdit->setText(fileName);
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly)){
        ui->fileWritableStatus->setText("<font color='red'>ERROR: Do not have write permission</font>");
        ui->fileWritableStatus->setVisible(true);
        fileWritable=false;
    } else {
        file.close();
        // Remove the file which got created because of open check
        file.remove(fileName);
        ui->fileWritableStatus->setVisible(false);
        fileWritable=true;
        activateBackupButton();
    }
}

void BackupMainWindow::onBackupAllCheckBoxClick() {
    if(!ui->allCheckBox->isChecked()){
        ui->profileCheckBox->setChecked(false);
        ui->dataCheckBox->setChecked(false);
        ui->pluginsCheckBox->setChecked(false);
        ui->profileCheckBox->setEnabled(true);
        ui->dataCheckBox->setEnabled(true);
        ui->pluginsCheckBox->setEnabled(true);
    } else {
        ui->profileCheckBox->setChecked(true);
        ui->dataCheckBox->setChecked(true);
        ui->pluginsCheckBox->setChecked(true);
        ui->profileCheckBox->setDisabled(true);
        ui->dataCheckBox->setDisabled(true);
        ui->pluginsCheckBox->setDisabled(true);
    }
    activateBackupButton();
}

void BackupMainWindow::activateBackupButton() {
    if((ui->profileCheckBox->isChecked() || ui->dataCheckBox->isChecked() || ui->profileCheckBox->isChecked())
            && fileWritable )
    {
        ui->backupButton->setEnabled(true);
    }
}
