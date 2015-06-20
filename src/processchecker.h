#ifndef PROCESSCHECKER_H
#define PROCESSCHECKER_H

#include <QString>
#include <QStringList>
#include <QProcess>

class ProcessChecker
{
private:
    QProcess *ps;
    QProcess *grep;
    QStringList *psArguments;
    QStringList *grepArguments;

public:
    ProcessChecker(QObject * parent);
    bool isThunderbirdRunning();
};

#endif // PROCESSCHECKER_H
