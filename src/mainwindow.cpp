#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "welcomewidget.h"
#include "backupstackedwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStackedWidget *centralStackedWidget = ui->centralwidget->findChild<QStackedWidget *>("mainStackedWidget");

    // Create the first welcome widget
    WelcomeWidget *welcomeWidget = new WelcomeWidget(this);

    // Create a backup widget
    BackupStackedWidget *backupStackedWidget = new BackupStackedWidget(this);

    centralStackedWidget->addWidget(welcomeWidget);
    centralStackedWidget->addWidget(backupStackedWidget);

    // Connect the backup button press event to show backup stackedwidget
    connect(welcomeWidget, SIGNAL(backupButtonPressSignal(int)), centralStackedWidget,SLOT(setCurrentIndex(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
