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
	//无参构造函数User(),由于用户信息通过文件输入，所以可有可无，仅起提示作用
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
private:
	//UserName记录用户姓名
	//Sex记录用户性别
	//History用字符串记录借阅历史
	char* UserName;
	char* Sex;
	char* History[5];
};
#endif _USERS