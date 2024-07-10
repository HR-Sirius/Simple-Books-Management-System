/*********************************************
	Filename:Users.h
	Time:2024/7/6
	Author:Haoren wang
	Description:派生类Users类的声明

**********************************************/

#ifndef _USERS
#define _USERS

#include "Management.h"
#include "Book.h"

//为了方便排序时不丢失对书籍、用户编号的跟踪，建立结构体排序对
struct sort_User_pair
{

};

class Users :virtual public Management
{
	//搜索、统计等功能需要用到Book类成员，申明为友元类
	friend Book;

	//统计最热门书籍,用于计数:pop_Book[50]
	//统计最勤奋读者,用于计数:pop_User[50]
	//最热门书籍:top_Book[5]，存放书籍编号
	//最勤奋读者:top_Users[3]，存放用户编号
	static int pop_Book[50];
	static int pop_User[50];
	static int top_Books[5];
	static int top_Users[3];

	//静态对象，自动生成用户编号
	static int currentUsers;

public:
	//输出用户借阅历史:Showhistory()
	void Showhistory();
	//接口函数，返回用户姓名
	char* GetName();
	//输出统计结果:Show_top_Books(),Show_top_Users()
	void Show_top_Books();
	void Show_top_Users();
	//搜索方法(最重要函数)，由于搜索结果是书名若干，因此计划将搜索结果保存在临时创建的数组中，逐一打印
	//输入字符串，遍历所有对象书名，输出对应结果
	void Search() const;

	//无参构造函数User(),实现用户自动编号功能
	//析构函数~Users(),提示作用(可之后改为虚析构函数)
	Users();
	~Users();


	//通过读文件打印用户信息:Getinfo()
	//通过写文件更改用户信息:Resetinfo()
	//借阅操作,统计借阅数据:Borrow(int)
	//还书:Return(int)
	//更改用户借阅历史:Resetinfo()
	virtual void Getinfo() const;
	virtual void Resetinfo();
	void Borrow();
	void Return();
	virtual void Resethistory(int);

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

//静态成员初始化
int Users::currentUsers = 0;

//通过对象数组创建Users类全局对象
Users All_Users[50];

#endif _USERS
