#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QStackedWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set the size of the main window
    this->setFixedSize(this->geometry().width(),this->geometry().height());

}

MainWindow::~MainWindow()
{
    delete ui;
}
