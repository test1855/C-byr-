#ifndef ADWINDOW_H
#define ADWINDOW_H

#include <QMainWindow>
#include <myform.h>
#include <modwindow.h>

namespace Ui {
class AdWindow;
}

class AdWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdWindow(QWidget *parent = 0);
    ~AdWindow();
    modwindow mw;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::AdWindow *ui;
};

#endif // ADWINDOW_H
