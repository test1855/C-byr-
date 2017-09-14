#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QMainWindow>
#include <myform.h>
#include <postwindow.h>
#include <comwindow.h>
#include <delwindow.h>
#include <topwindow.h>
#include <seawindow.h>

namespace Ui {
class UserWindow;
}

class UserWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserWindow(QWidget *parent = 0);
    void showInformationMsg();
    ~UserWindow();
    postWindow pw;
    comWindow cw;
    delWindow dw;
    topWindow tw;
    seaWindow sw;


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::UserWindow *ui;
};

#endif // USERWINDOW_H
