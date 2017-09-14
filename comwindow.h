#ifndef COMWINDOW_H
#define COMWINDOW_H

#include <QDialog>

namespace Ui {
class comWindow;
}

class comWindow : public QDialog
{
    Q_OBJECT

public:
    explicit comWindow(QWidget *parent = 0);
    ~comWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::comWindow *ui;
};

#endif // COMWINDOW_H
