#ifndef PROCESSCHECKER_H
#define PROCESSCHECKER_H

#include <QString>
#include <QStringList>
#include <QProcess>
#include <QObject>
#include <QDebug>

class ProcessChecker : public QObject
{
    Q_OBJECT

private:
    QProcess *ps;
    QProcess *grep;
    QStringList *psArguments;
    QStringList *grepArguments;

public:
    ProcessChecker(QObject * parent);
    bool isThunderbirdRunning();

signals:
    void processRunning(int status);
};

#endif // PROCESSCHECKER_H
