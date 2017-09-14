#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <myform.h>
#include <userwindow.h>
#include <adwindow.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString idd=ui->lineEdit->text();
    QString passs=ui->lineEdit_2->text();
    int i=-1;
    X=new User;

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();

    if(X){
        X->setId(idd);
        X->setPassword(passs);
        i=X->login();
        if(i!=-1){
            X->setId(uvec[i].getId());X->setUsername(uvec[i].getUsername());X->identity=uvec[i].identity;X->setFlag(uvec[i].getFlag());
            QMessageBox::about(this,tr("用户登录成功！"),tr("欢迎登录!"));
            uw.show();
        }

        else{ 
            delete X;
            i=-1;
            Y=new ADUser;
            Y->setId(idd);
            Y->setPassword(passs);
            i=Y->login();
            if(i!=-1){
                Y->setId(aduvec[i].getId());Y->setUsername(aduvec[i].getUsername());Y->identity=aduvec[i].identity;Y->setFlag(aduvec[i].getFlag());
                QMessageBox::about(this,tr("管理员登录成功！"),tr("欢迎登录!"));
                aw.show();
            }
            else{
                QMessageBox::warning(this,("登录失败！"),("账号或密码错误!"));
                delete Y;
            }
        }
    }
}
