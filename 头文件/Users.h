/*********************************************
	Filename:Users.h
	Time:2024/7/6
	Author:Haoren wang
	Description:派生类Users类的声明

**********************************************/

#ifndef _USERS
#define _USERS

#include "Management.h"
#include "Lend.h"

class Users :virtual public Management
{
	
public:
	//静态对象，用于计数
	static int currentUsers;
	
	//输出用户借阅历史:Showhistory()
	void Showhistory();
	//接口函数，返回用户姓名
	char* GetName();

	//无参构造函数User(),实现用户自动编号功能
	//析构函数~Users(),提示作用(可之后改为虚析构函数)
	Users();
	~Users();


	//通过读文件打印用户信息:Getinfo()
	//通过写文件更改用户信息:Resetinfo()
	virtual void Getinfo() const;
	virtual void Resetinfo();

	//流输入运算符重载
	friend std::istream& operator>>(istream&, Users&);
	//流输出运算符重载
	friend std::ostream& operator<<(ostream&, Users&);
protected:
	//UserName记录用户姓名
	//Sex记录用户性别
	//History用字符串记录借阅历史
	//User_No:用户编号
	//Borrowing[3]:借阅中书籍
	char* UserName;
	char* Sex;
	int History[5] = { 0 };
	int User_No;
	int Borrowing[3] = { 0 };//之后可添加身份属性，不同身份有着不同的借阅上限
};

int Users::currentUsers = 0;

//通过对象数组创建Users类全局对象
Users All_Users[50];

#endif _USERS
