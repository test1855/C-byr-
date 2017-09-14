#include "postwindow.h"
#include "ui_postwindow.h"

#include <QDateTime>
#include <QString>
#include <myform.h>

extern void edit1_(void);

postWindow::postWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::postWindow)
{
    ui->setupUi(this);
}

postWindow::~postWindow()
{
    delete ui;
}

void postWindow::on_pushButton_clicked()
{
    Post* temp;
    temp=new Post;
    if(temp){
        QString numstr=ui->lineEdit->text();
        temp->setTitle(ui->lineEdit_2->text());
        temp->setContent(ui->textEdit->toPlainText());

        int num;
        num=numstr.toInt()-1;
        if(num>=0&&num<=4){
            temp->setId(X->getId());
            //获取系统当前时间并设置显示格式
            QDateTime current_date_time = QDateTime::currentDateTime();
            QString current_date = current_date_time.toString("yyyy-MM-dd hh:mm:ss ddd");
            temp->setTime(current_date);
            fvec[num]->pvec.append(*temp);
            QMessageBox::about(this,("发帖成功！"),("帖子已发送！"));
            edit1_();
            this->close();
        }
        else
            QMessageBox::warning(this,("错误！"),("不存在该版块！"));

   }
   ui->lineEdit->clear();
   ui->lineEdit_2->clear();
   ui->textEdit->clear();
}
