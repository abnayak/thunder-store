#ifndef FILESYSTEMUTILS_H
#define FILESYSTEMUTILS_H

#include <QString>
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QTextStream>
#include <QObject>

class FileSystemUtils : public QObject
{
    Q_OBJECT

private:
    QString folderLoc;

public:
    FileSystemUtils(QString &profileDir);
    bool validateProfileFile(QString &fileName);
    bool isProfilePresent();
    bool validateProfileDir (QString &profileDir);

signals:
    void profileSearchFinished(int ProfileFound);
};

#endif // FILESYSTEMUTILS_H
