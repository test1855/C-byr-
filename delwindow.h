#ifndef DELWINDOW_H
#define DELWINDOW_H

#include <QDialog>

namespace Ui {
class delWindow;
}

class delWindow : public QDialog
{
    Q_OBJECT

public:
    explicit delWindow(QWidget *parent = 0);
    ~delWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::delWindow *ui;
};

#endif // DELWINDOW_H
