#ifndef POSTWINDOW_H
#define POSTWINDOW_H

#include <QDialog>

namespace Ui {
class postWindow;
}

class postWindow : public QDialog
{
    Q_OBJECT

public:
    explicit postWindow(QWidget *parent = 0);
    ~postWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::postWindow *ui;
};

#endif // POSTWINDOW_H
