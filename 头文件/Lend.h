/*********************************************
	Filename:Lend.h
	Time:2024/7/4
	Author:Haoren wang
	Description:派生类Lend类的声明

**********************************************/

#ifndef _LEND
#define _LEND

#include"Book.h"
#include"Users.h"

class Lend :virtual public Users
{
	friend Book;
public:
	//借阅操作,统计借阅数据:Borrow(int)
	//还书:Return(int)
	//更改用户借阅历史:Resetinfo()
	//排序:Bubble_sort()
	//输出统计结果:Show_top_Books(),Show_top_Users()
	void Borrow();
	void Return();
	virtual void Resethistory(int);
	void Bubble_sort(int[],int,int[],int);
	void Show_top_Books(int[],int);
	void Show_top_Users(int[], int);
private:
	//统计最热门书籍,用于计数:pop_Book[50]
	//统计最勤奋读者,用于计数:pop_User[50]
	//最热门书籍：top_Book[5]
	//最勤奋读者:top_Users[3]
	int pop_Book[50] = { 0 };
	int pop_User[50] = { 0 };
	int top_Books[5] = { 0 };
	int top_Users[3] = { 0 };
};

#endif _LEND
