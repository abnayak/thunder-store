#ifndef BACKUPSTACKEDWIDGET_H
#define BACKUPSTACKEDWIDGET_H

#include <QWidget>

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
};

#endif // BACKUPSTACKEDWIDGET_H
