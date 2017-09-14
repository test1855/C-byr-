#include "mainwindow.h"
#include <QApplication>
#include <QMainWindow>
#include <QDesktopWidget>
#include <qtextcodec.h>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <myform.h>
#include <QStringList>

User *X=NULL;
ADUser *Y=NULL;
QVector <User> uvec;
QVector <ADUser> aduvec;
QVector <Forum*> fvec(5);


QTextStream& operator <<(QTextStream& outfile,Comment& c)
{
    outfile<<c.getTime()<<c.getContent()<<endl;
}
/*
QTextStream& operator >>(QTextStream& infile,Comment& c)
{
    infile>>c.getTime()>>c.getContent();
}
*/
QTextStream& operator <<(QTextStream& outfile,Post& p)
{
    outfile<<p.getTime()<<p.getId()<<p.getTitle()<<p.getContent()<<endl;
}
/*
QTextStream& operator >>(QTextStream& infile,Post& p)
{
    infile>>p.getTime()>>p.getId()>>p.getTitle()>>p.getContent();
}
*/
QTextStream& operator <<(QTextStream& outfile,User& u)
{
    outfile<<u.getId()<<u.getPassword()<<u.getUsername()<<u.identity<<u.getFlag()<<endl;
}
/*
QTextStream& operator >>(QTextStream& infile,User& u)
{
    infile>>u.getId()>>u.getPassword()>>u.getUsername()>>u.identity>>u.getFlag();
}


int init_(void)
{
    QFile file("1.txt");
    if(!file.open(QFile::ReadOnly|QFile::Text))
        return 0;

    int i=0;
    QTextStream infile(&file);
    while(!infile.atEnd()){
        infile>>fvec[0]->pvec[i];
        i++;
    }
}

*/

int init_(void)
{
    QFile file("1.txt");
    if(!file.open(QFile::ReadOnly|QFile::Text))
        return 0;

    QString str;
    int numm=0;

    while(!file.atEnd()){
        str=file.readLine();

        QStringList sections = str.split(" ");
        if(sections.at(3)=="moderator"){
            User* A=new User;
            if(A){
                A->setId(sections.at(0));A->setPassword(sections.at(1));A->setUsername(sections.at(2));
                A->identity="moderator";
                numm=(sections.at(4)).toInt();
                A->setFlag(numm);
                uvec.append(*A);
//                delete A;
            }
        }
        else if(sections.at(3)=="regularuser\n"){
          //  sections.at(3)=="regularuser";
            User* A=new User;
            if(A){
                A->setId(sections.at(0));A->setPassword(sections.at(1));A->setUsername(sections.at(2));
                A->identity="regularuser";
                A->setFlag(0);
                uvec.append(*A);
//                delete A;
            }
        }
        else{
            ADUser* B=new ADUser;
            if(B){
                B->setId(sections.at(0));B->setPassword(sections.at(1));B->setUsername(sections.at(2));
                B->identity="adminstrator";
                B->setFlag(0);
                aduvec.append(*B);
            }
        }
    }
    file.close();
    fvec.resize(5);

    for(int i=0;i<5;i++)
        fvec[i]=new Forum;

    QFile file1("2.txt");
    QString str1,str2;

    int i=0;
    if(!file1.open(QFile::ReadOnly|QFile::Text))
        return 0;

    QTextStream infile1(&file1);

    while(!infile1.atEnd()){
        str1=infile1.readLine();str2=infile1.readLine();
        while(str2!="//"){
            QStringList sections1;
            sections1=str2.split("||");
            if(sections1.at(0)!="Comments"){
                Post *p=new Post;
                if(p){
                    p->setTime(sections1.at(0));p->setId(sections1.at(1));p->setTitle(sections1.at(2));p->setContent(sections1.at(3));
                    fvec[i]->pvec.append(*p);
                }
            }
            else{
                auto j=fvec[i]->pvec.size()-1;
                Comment *c=new Comment;
                if(c){
                    c->setTime(sections1.at(1));c->setContent(sections1.at(2));
                    fvec[i]->pvec[j].cvec.append(*c);

                }
            }
            str2=infile1.readLine();
        }
        i++;

    }
    file1.flush();
    file1.close();
    return 1;

}

int edit1_(void)
{
    QFile file("3.txt");
    if(!file.open(QFile::WriteOnly|QFile::Text)){
        return 0;
    }

    QTextStream outfile(&file);

    for(auto i=0;i<uvec.size();i++){
        outfile<<uvec[i];
    }
    for(auto i=0;i<aduvec.size();i++){
        outfile<<aduvec[i];
    }
    return 1;
}

int edit2_(void)
{
    QFile file("4.txt");
    if(!file.open(QFile::WriteOnly|QFile::Text)){
        return 0;
    }

    QTextStream outfile(&file);

    for(int i=0;i<5;i++){
        for(auto j=0;j<fvec[i]->pvec.size();j++){
            outfile<<fvec[i]->pvec[j];
            for(auto k=0;k<fvec[i]->pvec[j].cvec.size();k++){
                outfile<<fvec[i]->pvec[j].cvec[k];
            }
        }
    }
    return 1;
}


void edit_(void)
{
    int i=0;
    QString str;
    QFile file("1.txt");
    if(!file.open(QFile::WriteOnly|QFile::Text))
        return;
    QTextStream outfile(&file);

    for(;i<uvec.size();i++)
    {
        str=uvec[i].getId()+" "+uvec[i].getPassword()+" "+uvec[i].getUsername()+" "+uvec[i].identity;
        outfile<<str;
        if(uvec[i].getFlag()!=0)
            outfile<<" "<<uvec[i].getFlag()<<endl;
        else
            outfile<<endl;

    }
    for(i=0;i<aduvec.size();i++)
    {
        str=aduvec[i].getId()+" "+aduvec[i].getPassword()+" "+aduvec[i].getUsername()+" "+aduvec[i].identity;
        outfile<<str;
        if(i!=aduvec.size()-1)
            outfile<<endl;
    }
    file.flush();
    file.close();

}

/*

void edit1_(void)
{
    QString str;
    QFile file("2.txt");
    if(!file.open(QFile::WriteOnly|QFile::Text))
        return;
    QTextStream outfile(&file);

    for(int i=0;i<5;i++)
    {
        switch(i){
        case 0:
            outfile<<"Campus"<<endl;
            break;
        case 1:
            outfile<<"Life"<<endl;
            break;
        case 2:
            outfile<<"Study"<<endl;
            break;
        case 3:
            outfile<<"Technology"<<endl;
            break;
        case 4:
            outfile<<"LookingFor"<<endl;
            break;
        }
        for(auto j=0;j<fvec[i]->pvec.size();j++)
        {
            str=fvec[i]->pvec[j].getTime()+"||"+fvec[i]->pvec[j].getId()+"||"+fvec[i]->pvec[j].getTitle()+"||"+fvec[i]->pvec[j].getContent();
            outfile<<str<<endl;
            for(auto k=0;k<fvec[i]->pvec[j].cvec.size();k++){
                outfile<<"Comments||"<<fvec[i]->pvec[j].cvec[k].getTime()+"||"+fvec[i]->pvec[j].cvec[k].getContent()<<endl;
            }

        }
        outfile<<"//";
        if(i!=4)
            outfile<<endl;
    }
}

*/


int User::login(void)
{
    auto size=uvec.size();
    for(int i=0;i<size;i++){
        if(X->getId()==uvec[i].getId()&&X->getPassword()==uvec[i].getPassword())
            return i;
    }

    return -1;
}

int ADUser::login(void)
{
    auto size=aduvec.size();
    for(int i=0;i<size;i++){
        if(Y->getId()==aduvec[i].getId()&&Y->getPassword()==aduvec[i].getPassword())
            return i;
    }
    return -1;
}

int main(int argc, char *argv[])
{
    init_();

//    edit1_();
//    edit2_();
//    edit_();
//    edit1_();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

void User::logoff(void)
{
    delete X;
//    X=NULL;
}

void ADUser::logoff(void)
{
    delete Y;
}



