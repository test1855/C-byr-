#include "seawindow.h"
#include "ui_seawindow.h"
#include <myform.h>

seaWindow::seaWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::seaWindow)
{
    ui->setupUi(this);
}

seaWindow::~seaWindow()
{
    delete ui;
}

void seaWindow::on_pushButton_clicked()
{
    QString titlestr,str,tempstr,tempstr1;
    titlestr=ui->textEdit->toPlainText();

    for(int i=0;i<5;i++)
    {
        auto psize=fvec[i]->pvec.size();
        for(auto j=0;j<psize;j++){
            if(fvec[i]->pvec[j].getTitle()==titlestr){
                tempstr=QString("%1").arg(i+1);
                tempstr1=QString("%1").arg(j+1);
                str="该帖子是版块"+tempstr+"中第"+tempstr1+"个帖子\n"+fvec[i]->pvec[j].getTime()+"From："+fvec[i]->pvec[j].getId()+"["+fvec[i]->pvec[j].getTitle()+"]"+fvec[i]->pvec[j].getContent()+"\n";

                auto csize=fvec[i]->pvec[j].cvec.size();
                for(auto k=0;k<csize;k++){
                    str=str+"\t评论："+fvec[i]->pvec[j].cvec[k].getTime()+fvec[i]->pvec[j].cvec[k].getContent()+"\n";
                }

                QMessageBox::information(this,"搜索成功",str);
                return;
            }
        }
    }
    QMessageBox::warning(this,"错误！","不存在该帖子！");
}
