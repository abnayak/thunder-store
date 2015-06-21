#include "processchecker.h"

ProcessChecker::ProcessChecker(QObject *parent) : QObject(parent){
    ps = new QProcess(parent);
    grep = new QProcess(parent);

    ps->setStandardOutputProcess(grep);

    psArguments = new QStringList();
    grepArguments = new QStringList();

    psArguments->append("-aux");
    grepArguments->append("[t]hunderbird");

}

bool ProcessChecker::isThunderbirdRunning() {
    ps->start("ps",*psArguments);
    grep->start("grep", *grepArguments);
    grep->waitForFinished();
    QString result = grep->readAll();
    ps->close();
    grep->close();

    if (result ==  ""){
        qDebug() << "Emitting process not runnig signal" << endl;
        emit processRunning(0);
        return false;
    } else {
        qDebug() << "Emitting process running signal" << endl;
        emit processRunning(1);
        return true;
    }
}

