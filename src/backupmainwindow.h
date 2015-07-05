#ifndef BACKUPMAINWINDOW_H
#define BACKUPMAINWINDOW_H

#include <QWidget>
#include <QList>
#include <QString>
#include <QFileDialog>
#include <QFileInfo>

namespace Ui {
class BackupMainWindow;
}

class BackupMainWindow : public QWidget
{
    Q_OBJECT

public:
//    QString PRIFILE = "profile";
//    QString DATA = "data";
//    QString PLUGINS = "plugins";

    explicit BackupMainWindow(QWidget *parent = 0);
    explicit BackupMainWindow(QWidget *parent = 0, QWidget *backupStackedWidget = 0);

    ~BackupMainWindow();

private:
    Ui::BackupMainWindow *ui;
    QWidget* backupStackedWidget;
    void toglePasswordFields();
    void activateBackupButton();
    bool fileWritable;

public slots:
    void onUsePasswordClicked();
    void onBackupAllCheckBoxClick();
    void onFileBrowseButtonClick();
};

#endif // BACKUPMAINWINDOW_H
