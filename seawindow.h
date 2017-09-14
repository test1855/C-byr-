#ifndef SEAWINDOW_H
#define SEAWINDOW_H

#include <QDialog>

namespace Ui {
class seaWindow;
}

class seaWindow : public QDialog
{
    Q_OBJECT

public:
    explicit seaWindow(QWidget *parent = 0);
    ~seaWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::seaWindow *ui;
};

#endif // SEAWINDOW_H
