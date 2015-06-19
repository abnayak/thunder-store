#ifndef WELCOME_H
#define WELCOME_H

#include <QWidget>

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
};

#endif // WELCOME_H
