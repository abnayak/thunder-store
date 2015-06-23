#ifndef BACKUPINITIALIZATIONWIDGET_H
#define BACKUPINITIALIZATIONWIDGET_H

#include <QDebug>
#include <QWidget>
#include <QThread>

#include "filesystemutils.h"
#include "processchecker.h"



namespace Ui {
class BackupInitializationWidget;
}

class BackupInitializationWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BackupInitializationWidget(QWidget *parent = 0);
    ~BackupInitializationWidget();
    void run();

private:
    Ui::BackupInitializationWidget *ui;
    ProcessChecker *processChecker;
    FileSystemUtils *fileSystemUtils;
    void incrementProgressBar();

public slots:
    void thunderbirdProcessFound(int found);
    void thunderbirdProfileFound(int found);

};

#endif // BACKUPINITIALIZATIONWIDGET_H
