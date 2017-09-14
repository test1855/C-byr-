#ifndef MYFORM_H
#define MYFORM_H

#include <QString>
#include <QVector>
#include <QLabel>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <userwindow.h>
#include <adwindow.h>
#include <postwindow.h>
#include <comwindow.h>
#include <delwindow.h>
#include <modwindow.h>
#include <topwindow.h>
#include <seawindow.h>
#include <QFile>
#include <QTextStream>


class Comment{
private:
    QString content;
    QString time;

public:
    QString getContent()				{	return content;	}
    QString getTime()					{	return time;	}
    void setContent(QString c)          {	content=c;		}
    void setTime(QString t)             {	time=t;			}
    friend QTextStream& operator <<(QTextStream& outfile,Comment& c);
    friend QTextStream& operator >>(QTextStream& infile,Comment& c);
};



class Post{
private:
    QString id;
    QString title;
    QString content;
    QString time;

public:
    QVector <Comment> cvec;
    QString getId()                     {	return id;			}
    QString getTitle()                  {	return title;		}
    QString getContent()				{	return content;		}
    QString getTime()					{	return time;		}

    void setId(QString i)               {	id=i;				}
    void setTitle(QString t)			{	title=t;			}
    void setContent(QString c)          {	content=c;			}
    void setTime(QString t)             {	time=t;				}

    friend QTextStream& operator <<(QTextStream& outfile,Post& p);
    friend QTextStream& operator >>(QTextStream& infile,Post& p);
};

class Forum{
public:
    QVector<Post> pvec;
};

class User {
private:
    QString id;
    QString username;
    QString password;
    int flag;
public:
//    ~User();
    QString getId(void)				{	return id;	 			}
    QString getPassword(void)		{	return password;		}
    QString getUsername(void)		{	return username;	 	}
    int getFlag(void)               {   return flag;            }
    void setId(QString idd)			{	id=idd;		 			}
    void setUsername(QString namee)	{	username=namee;			}
    void setPassword(QString wordd)	{	password=wordd;			}
    void setFlag(int f)             {   flag=f;                 }

    virtual int login(void);        //登录
    virtual void logoff(void);      //注销
    QString identity;				//身份

    friend QTextStream& operator <<(QTextStream& outfile,User& u);
    friend QTextStream& operator >>(QTextStream& infile,User& u);
};

class ADUser:public User{
public:
    virtual int login(void);
    virtual void logoff(void);

 //   friend QTextStream& operator <<(QTextStream& outfile,ADUser& a);
  //  friend QTextStream& operator >>(QTextStream& infile,ADUser& a);
};

extern User* X;
extern QVector<User> uvec;
extern QVector<Forum*> fvec;
extern ADUser* Y;
extern QVector<ADUser> aduvec;

#endif // MYFORM_H
