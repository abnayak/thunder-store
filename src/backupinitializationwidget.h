#ifndef BACKUPINITIALIZATIONWIDGET_H
#define BACKUPINITIALIZATIONWIDGET_H

#include <QDebug>
#include <QWidget>
#include <QThread>
#include <QThreadPool>

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
    explicit BackupInitializationWidget(QWidget *parent = 0);
    ~BackupInitializationWidget();

private:
    Ui::BackupInitializationWidget *ui;
    ProcessChecker *processChecker;
    FileSystemUtils *fileSystemUtils;
    BackupInitializationRunner *runner;

public slots:
    void thunderbirdProcessFound(int found);
    void thunderbirdProfileFound(int found);
    void updateProgressBar();
};

#endif // BACKUPINITIALIZATIONWIDGET_H
