#ifndef WELCOME_H
#define WELCOME_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class WelcomeWidget;
}

class WelcomeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WelcomeWidget(QWidget *parent = 0);
    ~WelcomeWidget();

private:
    Ui::WelcomeWidget *ui;

public slots:
    void backupButtonPressed ();
    QPushButton* getBackupButton();

signals:
    void backupButtonPressSignal (int);
};

#endif // WELCOME_H
