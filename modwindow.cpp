#include "modwindow.h"
#include "ui_modwindow.h"

#include <QLineEdit>
#include <myform.h>

extern void edit_(void);

modwindow::modwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modwindow)
{
    ui->setupUi(this);
}

modwindow::~modwindow()
{
    delete ui;
}

void modwindow::on_pushButton_clicked()
{
    QString numstr,identstr,tempstr;
    int num,temp;

    numstr=ui->lineEdit->text();                    //记得加上对num 用户合法化的判断！！！
    identstr=ui->lineEdit_2->text();
    num=numstr.toInt()-1;

    if(num<0||num>=uvec.size())
        QMessageBox::warning(this,"错误！",("不存在该用户！"));
    else{
        if(identstr=="regularuser"){
            uvec[num].identity="regularuser";
            uvec[num].setFlag(0);
            QMessageBox::about(this,tr("修改成功"),tr("regularuser修改成功"));
            edit_();
            this->close();
        }
        else if(identstr=="moderator"){
            tempstr=ui->lineEdit_3->text();
            temp=tempstr.toInt();
            if(temp>0&&temp<6){
                uvec[num].identity="moderator";
                uvec[num].setFlag(temp);
                QMessageBox::about(this,tr("修改成功"),tr("moderator修改成功"));
                edit_();
                this->close();
            }
            else
                QMessageBox::warning(this,("错误！"),("不存在此版块！"));
        }
        else
            QMessageBox::warning(this,("错误！"),("身份填写有误！"));
    }
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
}
