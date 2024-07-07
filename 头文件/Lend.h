/*********************************************
	Filename:Lend.h
	Time:2024/7/4
	Author:Haoren wang
	Description:派生类Lend类的声明

**********************************************/

#ifndef _LEND
#define _LEND

#include"Book.h"

class Lend :virtual public Book
{
public:
	//借阅操作函数:Borrow()
	//更改用户借阅历史:Resetinfo()
	//统计借阅数据:statistic()
	void Borrow();
	virtual void Resetinfo();
	void Statistic();
private:
	;
};

#endif _LEND
