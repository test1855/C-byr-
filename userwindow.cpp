#include "userwindow.h"
#include "ui_userwindow.h"
#include <QLabel>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

#include <QLineEdit>
#include <QMessageBox>

#include <mainwindow.h>
#include <myform.h>

UserWindow::UserWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserWindow)
{
    ui->setupUi(this);
}

UserWindow::~UserWindow()
{
    delete ui;
}

void UserWindow::on_pushButton_clicked()
{
    QString str,tempstr;
    if(X->identity=="moderator"){
        tempstr=QString("%1").arg(X->getFlag());
        str="ID："+X->getId()+"\n用户名："+X->getUsername()+"\n身份："+X->identity+"\n管理版块："+tempstr;
    }
    else
        str="ID："+X->getId()+"\n用户名："+X->getUsername()+"\n身份："+X->identity;

    QMessageBox::information(this,"个人信息",str);
}

void UserWindow::on_pushButton_2_clicked()
{
    pw.show();
}

void UserWindow::on_pushButton_3_clicked()
{
    QString str;
    for(int i=0;i<5;i++){
        str="";
        auto psize=fvec[i]->pvec.size();
        for(auto j=0;j<psize;j++){
            str=str+fvec[i]->pvec[j].getTime()+"From:"+fvec[i]->pvec[j].getId()+"["+fvec[i]->pvec[j].getTitle()+"]"+fvec[i]->pvec[j].getContent()+"\n";
            auto csize=fvec[i]->pvec[j].cvec.size();
            for(auto k=0;k<csize;k++)
                str=str+"\t评论:"+fvec[i]->pvec[j].cvec[k].getTime()+fvec[i]->pvec[j].cvec[k].getContent()+"\n";
        }
        switch (i) {
            case 0:
                ui->textEdit->setPlainText(str);
                break;
            case 1:
                ui->textEdit_2->setPlainText(str);
                break;
            case 2:
                ui->textEdit_3->setPlainText(str);
                break;
            case 3:
                ui->textEdit_4->setPlainText(str);
                break;
            default:
                ui->textEdit_5->setPlainText(str);
                break;
        }
    }
}

void UserWindow::on_pushButton_4_clicked()
{
    cw.show();
}

void UserWindow::on_pushButton_5_clicked()
{
    if(X->identity=="moderator"){
        dw.show();
    }
    else
        QMessageBox::warning(this,"错误！","对不起，只有版主才能删帖。");

}

void UserWindow::on_pushButton_6_clicked()
{
    X->logoff();
    QMessageBox::about(this,tr("注销成功！"),tr("欢迎下次登录!"));
    this->close();
}

void UserWindow::on_pushButton_7_clicked()
{
    if(X->identity=="moderator"){
        tw.show();
    }
    else
        QMessageBox::warning(this,"错误！","对不起，只有版主才能置顶。");
}

void UserWindow::on_pushButton_8_clicked()
{
    sw.show();
}
