#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "welcomewidget.h"
#include "backupstackedwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    centralStackedWidget = getCentralStackedWidget();
    // Make backup stacked widget null
    // While creating backup stackwidget and delete any object previosly created
    backupStackedWidget = NULL;

    // Create the first welcome widget
    welcomeWidget = new WelcomeWidget(this);

    centralStackedWidget->addWidget(welcomeWidget);

    // Connect the backup button press event to show backup stackedwidget
    //connect(welcomeWidget, SIGNAL(backupButtonPressSignal(int)), centralStackedWidget,SLOT(setCurrentIndex(int)));

    // Connect backup button press to backup stacked widget, so that backup stacked widget is initialized only after
    // button press
    connect(welcomeWidget, SIGNAL(backupButtonPressedSignal()), this, SLOT(initializeBackupStackedWidget()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeBackupStackedWidget() {
    // Check for any previously created widgets and remove it
    if(backupStackedWidget != NULL) {
        centralStackedWidget->removeWidget(backupStackedWidget);
        delete(backupStackedWidget);
    }

    // Create a backup widget
    backupStackedWidget = new BackupStackedWidget(this);
    centralStackedWidget->addWidget(backupStackedWidget);
    centralStackedWidget->setCurrentIndex(1);
}

QStackedWidget* MainWindow::getCentralStackedWidget() {
    return ui->centralwidget->findChild<QStackedWidget *>("mainStackedWidget");
}
