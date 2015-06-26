#include "backupinitializationrunner.h"

BackupInitializationRunner::BackupInitializationRunner(QWidget *parentWidget, QString &folder)
{
    parent = (QObject*) parentWidget;
    this->folder = folder;
    processChecker = new ProcessChecker((QObject*)parent);

    // check if thunderbird folder is present
    fileSystemUtils = new FileSystemUtils(folder);

    // Connect signal and slots
    connect(processChecker,SIGNAL(processRunning(int)), parent,SLOT(thunderbirdProcessFound(int)));
    connect(fileSystemUtils,SIGNAL(profileSearchFinished(int)), parent,SLOT(thunderbirdProfileFound(int)));
}

void BackupInitializationRunner::run() {
    processChecker->isThunderbirdRunning();
    incrementProgressBar();
    fileSystemUtils->isProfilePresent();
    incrementProgressBar();
    QMetaObject::invokeMethod(parent, "onBackupInitializationRunnerFinished", Qt::QueuedConnection);
}


void BackupInitializationRunner::incrementProgressBar() {
    for (int var = 0; var < 10; var++) {
        QMetaObject::invokeMethod(parent, "updateProgressBar", Qt::QueuedConnection);
        QThread::msleep(25);
    }
}
