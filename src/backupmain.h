#ifndef BACKUPMAIN_H
#define BACKUPMAIN_H

#include <QWidget>

namespace Ui {
class BackupMain;
}

class BackupMain : public QWidget
{
    Q_OBJECT

public:
    explicit BackupMain(QWidget *parent = 0);
    ~BackupMain();

private:
    Ui::BackupMain *ui;
};

#endif // BACKUPMAIN_H
