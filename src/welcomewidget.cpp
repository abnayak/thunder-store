#include "welcomewidget.h"
#include "ui_welcomewidget.h"

WelcomeWidget::WelcomeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WelcomeWidget)
{
    ui->setupUi(this);
    connect(ui->backupButton,SIGNAL(clicked()), this, SLOT(backupButtonPressed()));

}

QPushButton * WelcomeWidget::getBackupButton(){
    return ui->backupButton;
}

void WelcomeWidget::backupButtonPressed() {
    emit backupButtonPressSignal(1);
}

WelcomeWidget::~WelcomeWidget()
{
    delete ui;
}
