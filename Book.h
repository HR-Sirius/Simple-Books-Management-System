/*********************************************
	Filename:User.h
	Time:2024/7/4
	Author:Haoren Wang
	Description:派生类Book类的声明

**********************************************/

#ifndef _BOOK
#define _BOOK

#include"Management.h"


enum type
{
	suspense = 1, science = 2, fantasy = 3, romance = 4, criminal = 5, encyclopedia = 6
};

struct Info
{
	//书名:BookName
	//简介:Outline
	//作者:Author
	//类别:Booktype，用枚举类定义，默认每本书只有一种类型
	//关键词:Keywords,最多三个
	char* BookName;
	char* Outline;
	char* Author;
	type Booktype;
	char* Keywords[3];
};

class Book :virtual public Management
{
public:
	//无参构造函数Book(),由于书籍信息通过文件输入，所以可有可无，仅起提示作用
	//析构函数~Book(),提示作用(可之后改为虚析构函数)
	Book();
	~Book();
	
	//通过读文件获取书籍信息:Getinfo()
	//通过写文件更改书籍信息:Resetinfo()
	virtual void Getinfo() const;
	virtual void Resetinfo();

	//搜索方法(最重要函数)，由于搜索结果是书名若干，因此计划将搜索结果保存在临时创建的数组中，逐一打印
	void Search() const;


	//每次修改要重新输入，之后修改为可选择修改的函数
	//流输入运算符重载(1)
	friend istream& operator>>(istream&, Info&);
	//流输入运算符重载(2)
	friend istream& operator>>(istream&, Book&);
	//流输入运算符重载(3)
	friend istream& operator>>(istream&, type&);

	//流输出运算符重载(1)
	friend ostream& operator<<(ostream&, Info&);
	//流输出运算符重载(2)
	friend ostream& operator<<(ostream&, Book&);
	//流输出运算符重载(3)
	friend ostream& operator<<(ostream&, type&);
private:
	//BookInfo为书籍属性
	//BookNo为书籍编号（从1开始）
	//借阅状态;State,0已借出，1可借阅
	Info BookInfo;
	int BookNo;
	bool State;
};

#endif _BOOK
