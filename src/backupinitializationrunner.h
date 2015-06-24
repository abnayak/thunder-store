#ifndef BACKUPINITIALIZATIONRUNNER_H
#define BACKUPINITIALIZATIONRUNNER_H

#include <QRunnable>
#include <QMetaObject>
#include <QObject>
#include <QThread>

#include "processchecker.h"
#include "filesystemutils.h"

class BackupInitializationRunner : public QObject, public QRunnable
{
    Q_OBJECT
private:
    QObject *parent;
    ProcessChecker *processChecker;
    FileSystemUtils *fileSystemUtils;
    void run();
    void incrementProgressBar();

public:
    BackupInitializationRunner(QWidget *parent);
};

#endif // BACKUPINITIALIZATIONRUNNER_H
