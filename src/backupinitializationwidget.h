#ifndef BACKUPINITIALIZATIONWIDGET_H
#define BACKUPINITIALIZATIONWIDGET_H

#include <QWidget>
#include "processchecker.h"
#include <QDebug>

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

};

#endif // BACKUPINITIALIZATIONWIDGET_H
