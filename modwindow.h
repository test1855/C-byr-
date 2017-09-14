#ifndef MODWINDOW_H
#define MODWINDOW_H

#include <QDialog>

namespace Ui {
class modwindow;
}

class modwindow : public QDialog
{
    Q_OBJECT

public:
    explicit modwindow(QWidget *parent = 0);
    ~modwindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::modwindow *ui;
};

#endif // MODWINDOW_H
