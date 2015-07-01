#ifndef BACKUPSTACKEDWIDGET_H
#define BACKUPSTACKEDWIDGET_H

#include <QWidget>
#include "backupmainwindow.h"

namespace Ui {
class BackupStackedWidget;
}

class BackupStackedWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BackupStackedWidget(QWidget *parent = 0);
    ~BackupStackedWidget();

private:
    Ui::BackupStackedWidget *ui;
    QWidget *mainWindow;

private slots:
    void onShowBackupMainWindow(QString);
};

#endif // BACKUPSTACKEDWIDGET_H
