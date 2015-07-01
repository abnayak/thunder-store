#ifndef BACKUPMAINWINDOW_H
#define BACKUPMAINWINDOW_H

#include <QWidget>

namespace Ui {
class BackupMainWindow;
}

class BackupMainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit BackupMainWindow(QWidget *parent = 0);
    explicit BackupMainWindow(QWidget *parent = 0, QWidget *backupStackedWidget = 0);
    ~BackupMainWindow();

private:
    Ui::BackupMainWindow *ui;
    QWidget* backupStackedWidget;

};

#endif // BACKUPMAINWINDOW_H
