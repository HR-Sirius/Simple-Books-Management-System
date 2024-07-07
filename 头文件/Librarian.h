/*********************************************
	Filename:Librarian.h
	Time:2024/7/6
	Author:Haoren wang
	Description:派生类Librarian类的声明

**********************************************/

#ifndef _LIBRARIAN
#define _LIBRARIAN

#include"Users.h"
#include"Book.h"

class Librarian:public Users
{
	//需要用到Book类的函数，申明为友元类
	friend Book;
public:
	//通过读文件打印管理员信息:Getinfo()
	//通过写文件更改管理员信息:Resetinfo()
	virtual void Getinfo();
	virtual void Resetinfo();

	//流输入运算符重载
	friend std::istream& operator>>(istream&, Librarian&);
	//流输出运算符重载
	friend std::ostream& operator<<(ostream&, Librarian&);

private:
	//Librarian_Name记录图书管理员姓名
	//Liibrarian_Sex记录图书管理员性别
	char* Librarian_Name;
	char* Liibrarian_Sex;
};

#endif _LIBRARIAN