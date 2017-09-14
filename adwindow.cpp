#include "adwindow.h"
#include "ui_adwindow.h"
#include <QMessageBox>
#include <myform.h>
AdWindow::AdWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdWindow)
{
    ui->setupUi(this);
}

AdWindow::~AdWindow()
{
    delete ui;
}

void AdWindow::on_pushButton_clicked()
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

void AdWindow::on_pushButton_2_clicked()
{
    mw.show();
}

void AdWindow::on_pushButton_3_clicked()
{
    Y->logoff();
    QMessageBox::about(this,tr("管理员注销成功！"),tr("欢迎下次登录！"));
    this->close();
}
