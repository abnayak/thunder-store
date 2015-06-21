#ifndef BACKUPINITIALIZATIONWIDGET_H
#define BACKUPINITIALIZATIONWIDGET_H

#include <QDebug>
#include <QWidget>

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

private:
    Ui::BackupInitializationWidget *ui;
    ProcessChecker *processChecker;

public slots:
    void thunderbirdProcessFound(int found);
    void thunderbirdProfileFound(int found);
};

#endif // BACKUPINITIALIZATIONWIDGET_H
