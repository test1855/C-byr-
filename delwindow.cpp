#include "delwindow.h"
#include "ui_delwindow.h"

#include <myform.h>
#include <QLineEdit>

extern void edit1_(void);

delWindow::delWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::delWindow)
{
    ui->setupUi(this);
}

delWindow::~delWindow()
{
    delete ui;
}

void delWindow::on_pushButton_clicked()
{
    QString fstr,pstr,tempstr;
    int fnum,pnum,i=0;

    fstr=ui->lineEdit->text();
    pstr=ui->lineEdit_2->text();

    fnum=fstr.toInt()-1;
    pnum=pstr.toInt()-1;

    if(fnum<0||fnum>4)
        QMessageBox::warning(this,("错误！"),("不存在该板块！"));
    else if(fnum!=(X->getFlag()-1)){
        tempstr=QString("%1").arg(X->getFlag());
        tempstr="对不起，您只能删除第"+tempstr+"版块！";
        QMessageBox::warning(this,("错误！"),(tempstr));
    }
    else{
        auto psize=fvec[fnum]->pvec.size();
        if(pnum<psize&&pnum>=0){
            QVector<Post>::iterator it=fvec[fnum]->pvec.begin();
            for(;i<pnum;i++)
                it++;
            fvec[fnum]->pvec.erase(it);
            QMessageBox::about(this,tr("删除成功！"),tr("该帖子已删除！"));
            edit1_();
            this->close();
        }
        else
            QMessageBox::warning(this,("错误！"),("不存在该帖子！"));
    }

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}
