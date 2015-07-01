#ifndef BACKUPINITIALIZATIONWIDGET_H
#define BACKUPINITIALIZATIONWIDGET_H

#include <QDebug>
#include <QWidget>
#include <QThread>
#include <QThreadPool>
#include <QFileDialog>

#include "mainwindow.h"
#include "filesystemutils.h"
#include "processchecker.h"
#include "backupinitializationrunner.h"


namespace Ui {
class BackupInitializationWidget;
}

class BackupInitializationWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BackupInitializationWidget(QWidget *parent = 0, QWidget *stackedWidget =0);
    ~BackupInitializationWidget();

private:
    Ui::BackupInitializationWidget *ui;
    ProcessChecker *processChecker;
    FileSystemUtils *fileSystemUtils;
    BackupInitializationRunner *runner;
    QWidget *mainWindow;
    QWidget *stackedWidget;
    QString folderLoc;

public slots:
    void thunderbirdProcessFound(int found);
    void thunderbirdProfileFound(int found);
    void updateProgressBar();

    // Slot called when backupInitializationRunner thread finishes
    void onBackupInitializationRunnerFinished();

    // Button press slots
    void onFileBrowserButtonClick();
    void onBackButtonPress();
    void onNextButtonPress();
signals:
    void showBackupMainWindow(QString);
};

#endif // BACKUPINITIALIZATIONWIDGET_H
