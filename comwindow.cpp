#include "comwindow.h"
#include "ui_comwindow.h"
#include <QDateTime>
#include <myform.h>

extern void edit1_(void);

comWindow::comWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::comWindow)
{
    ui->setupUi(this);
}

comWindow::~comWindow()
{
    delete ui;
}

void comWindow::on_pushButton_clicked()
{
    Comment* temp;
    temp=new Comment;

    if(temp){
        QString fstr,pstr;
        int fnum,pnum;
        fstr=ui->lineEdit->text();
        pstr=ui->lineEdit_2->text();

        fnum=fstr.toInt()-1;

        if(fnum<0||fnum>4)
            QMessageBox::warning(this,("错误！"),("不存在该版块！"));
        else{
            pnum=pstr.toInt()-1;
            auto psize=fvec[fnum]->pvec.size();
            if(pnum>=0&&pnum<psize){
                temp->setContent(ui->textEdit->toPlainText());
                QDateTime current_date_time = QDateTime::currentDateTime();
                QString current_date = current_date_time.toString("yyyy-MM-dd hh:mm:ss ddd");
                temp->setTime(current_date);
                fvec[fnum]->pvec[pnum].cvec.append(*temp);
                QMessageBox::about(this,tr("评论成功！"),tr("评论已发送！"));
                edit1_();
                this->close();
            }
            else
                QMessageBox::warning(this,("错误！"),("不存在该帖子！"));
        }

    }
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->textEdit->clear();
}
