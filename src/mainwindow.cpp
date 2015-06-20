#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "welcomewidget.h"
#include "backupstackedwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStackedWidget *stackedWidget = ui->centralwidget->findChild<QStackedWidget *>("mainStackedWidget");

    // Create the first welcome widget
    WelcomeWidget *welcomeWidget = new WelcomeWidget(this);

    // Create a backup widget
    BackupStackedWidget *backupStackedWidget = new BackupStackedWidget(this);

    stackedWidget->addWidget(welcomeWidget);
    stackedWidget->addWidget(backupStackedWidget);

    connect(welcomeWidget, SIGNAL(backupButtonPressSignal(int)), stackedWidget,SLOT(setCurrentIndex(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
