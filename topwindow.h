#ifndef TOPWINDOW_H
#define TOPWINDOW_H

#include <QDialog>

namespace Ui {
class topWindow;
}

class topWindow : public QDialog
{
    Q_OBJECT

public:
    explicit topWindow(QWidget *parent = 0);
    ~topWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::topWindow *ui;
};

#endif // TOPWINDOW_H
