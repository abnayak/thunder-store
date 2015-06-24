#include "backupinitializationrunner.h"

BackupInitializationRunner::BackupInitializationRunner(QWidget *parentWidget)
{
    parent = (QObject*) parentWidget;

    processChecker = new ProcessChecker((QObject*)parent);

    // check if thunderbird folder is present
    QString folderLoc = "";
    fileSystemUtils = new FileSystemUtils(folderLoc);

    // Connect signal and slots
    connect(processChecker,SIGNAL(processRunning(int)), parent,SLOT(thunderbirdProcessFound(int)));
    connect(fileSystemUtils,SIGNAL(profileSearchFinished(int)), parent,SLOT(thunderbirdProfileFound(int)));
}

void BackupInitializationRunner::run() {
    processChecker->isThunderbirdRunning();
    incrementProgressBar();
    fileSystemUtils->isProfilePresent();
    incrementProgressBar();
}


void BackupInitializationRunner::incrementProgressBar() {
    for (int var = 0; var < 10; var++) {
        QMetaObject::invokeMethod(parent, "updateProgressBar", Qt::QueuedConnection);
        QThread::msleep(25);
    }
}
