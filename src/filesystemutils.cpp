#include "filesystemutils.h"

FileSystemUtils::FileSystemUtils(QString &profileDir)
{
    folderLoc = profileDir;
    folderLoc.append("/");
}

bool FileSystemUtils::isProfilePresent() {
    QDir thunderbirdDir(folderLoc);
    bool profileFound = false;

    if(thunderbirdDir.exists()) {
        qDebug() << "thunderbird directory found" << endl;

        QStringList filePattern;
        filePattern.append("*.default");
        filePattern.append("*.ini");

        QStringList files = thunderbirdDir.entryList(filePattern);

        QStringListIterator itr(files);

        while(itr.hasNext()) {
            QString fileName = itr.next();
            if(fileName.contains("ini")) {
                profileFound = validateProfileFile(fileName);
            }
        }
    }else {
        qDebug() << "thunderbird directory not present" << endl;
    }

    if(profileFound) {
        emit profileSearchFinished(1);
    } else {
        emit profileSearchFinished(0);
    }

    return profileFound;
}

bool FileSystemUtils::validateProfileFile(QString &fileName) {
    QFile profileFile;
    qDebug() << "profile found "<< fileName << endl;
    profileFile.setFileName( folderLoc + fileName);

    if(profileFile.open(QFile::ReadOnly|QFile::Text)) {
        QTextStream textStream(&profileFile);
        while (!textStream.atEnd()) {
            QString line = textStream.readLine();
            if(line.contains("Path=")) {
                line.remove(0,5);
                profileFile.close();
                return validateProfileDir(line);
            }
        }
    }else {
        qDebug() << "Unable to open the file " << fileName << endl;
    }

    profileFile.close();
    return false;
}

bool  FileSystemUtils::validateProfileDir(QString &profileDir) {

    QString profileFolder = folderLoc + profileDir;
    QDir dir(profileFolder);

    if(dir.exists()) {
        qDebug() << "Found data folder: " << profileFolder << endl;
        return true;
    }

    qDebug() << profileFolder << " not found." << endl;
    return false;
}
