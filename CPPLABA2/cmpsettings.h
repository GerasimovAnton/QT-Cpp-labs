#ifndef CMPSETTINGS_H
#define CMPSETTINGS_H

#include <QWidget>
#include "component.h"

namespace Ui {
    class cmpSettings;
}

class cmpSettings : public QWidget
{
    Q_OBJECT

public:
    explicit cmpSettings(QWidget *parent = nullptr);
    ~cmpSettings();
    //newCmpWindow *ui;

private slots:
    void on_pushButton_clicked();

    //void on_newCmpWindow_destroyed();

private:
   Ui::cmpSettings *ui;
};

#endif // NEWCMPWINDOW_H
