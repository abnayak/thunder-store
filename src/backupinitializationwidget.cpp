#include "backupinitializationwidget.h"
#include "ui_backupinitializationwidget.h"

BackupInitializationWidget::BackupInitializationWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BackupInitializationWidget)
{
    mainWindow = parent;
    ui->setupUi(this);

    // set the min and max of the progress bar
    ui->progressBar->setMinimum(1);
    ui->progressBar->setMaximum(20);

    //  Make the checkboxes to have three stages
    ui->thunderbirdInstanceCB->setTristate(true);
    ui->profileFoundCB->setTristate(true);

    // Create the background process
    QString folderLoc = "/home/abhijeet/.thunderbird/";
    runner = new BackupInitializationRunner(this, folderLoc);
    runner->setAutoDelete(false);
    QThreadPool::globalInstance()->start(runner);

    // Deactivate the next button
    ui->pushButton2->setDisabled(true);
    ui->pushButton1->setDisabled(true);

    // Hide the message level
    ui->message->setVisible(false);

    // Hide file browse widgets
    ui->fileBrowseButton->setVisible(false);
    ui->folderLabel->setVisible(false);
    ui->folderName->setVisible(false);

    connect(ui->fileBrowseButton,SIGNAL(clicked()),this,SLOT(onFileBrowserButtonClick()));
    connect(ui->pushButton1,SIGNAL(clicked()),this,SLOT(onBackButtonPress()));
    connect(ui->pushButton2,SIGNAL(clicked()),this,SLOT(onNextButtonPress()));
}

BackupInitializationWidget::~BackupInitializationWidget()
{
    delete ui;
}

void BackupInitializationWidget::thunderbirdProcessFound(int found) {
    qDebug() << "inside the thunderbirdprocessround slot()" <<endl;
    if(found == 1){
        ui->thunderbirdInstanceCB->setCheckState(Qt::PartiallyChecked);
    } else if( found == 0){
        qDebug() << "checkbox status: " << endl;
        ui->thunderbirdInstanceCB->setChecked(true);
    }
}

void BackupInitializationWidget::thunderbirdProfileFound(int found) {
    if(found == 1) {
        ui->profileFoundCB->setChecked(true);
    } else if ( found == 0) {
        ui->profileFoundCB->setCheckState(Qt::PartiallyChecked);
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
        ui->fileBrowseButton->setVisible(true);
        ui->folderLabel->setVisible(true);
        ui->folderName->setVisible(true);
    }

    if ( ui->thunderbirdInstanceCB->checkState() == Qt::PartiallyChecked ||
         ui->profileFoundCB->checkState() == Qt::PartiallyChecked ) {
        ui->pushButton2->setText("Restart");
    } else {
        ui->pushButton2->setText("Next");
    }
}

void BackupInitializationWidget::onFileBrowserButtonClick() {
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open directory"), "/",
                       QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks );

    ui->folderName->setText(dir);
}

void BackupInitializationWidget::onBackButtonPress() {
    //
    ((MainWindow*)mainWindow)->getCentralStackedWidget()->setCurrentIndex(0);
}

void BackupInitializationWidget::onNextButtonPress() {
    if(ui->pushButton2->text() == "Restart"){
        ui->progressBar->reset();
        ui->thunderbirdInstanceCB->setCheckState(Qt::Unchecked);
        ui->message->setVisible(false);
        if (ui->profileFoundCB->checkState() == Qt::PartiallyChecked) {
            ui->profileFoundCB->setCheckState(Qt::Unchecked);
            if(runner != NULL){
                delete runner;
                QString folderLoc = ui->folderName->text();
                qDebug() << "New folder loc: " << folderLoc ;
                runner = new BackupInitializationRunner(this, folderLoc);
                runner->setAutoDelete(false);
            }
            QThreadPool::globalInstance()->start(runner);
        }
    }
}
