#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

#include "welcomewidget.h"
#include "backupstackedwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QStackedWidget* getCentralStackedWidget();
    ~MainWindow();

public slots:
    void initializeBackupStackedWidget();

private:
    Ui::MainWindow *ui;
    QStackedWidget *centralStackedWidget;

    // Welcome widget
    WelcomeWidget *welcomeWidget;

    // Backup stacked widget
    BackupStackedWidget *backupStackedWidget;
};

#endif // MAINWINDOW_H
