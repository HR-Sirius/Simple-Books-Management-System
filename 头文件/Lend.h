/*********************************************
	Filename:Lend.h
	Time:2024/7/4
	Author:Haoren wang
	Description:������Lend�������

**********************************************/

#ifndef _LEND
#define _LEND

#include"Book.h"

class Lend :virtual public Book
{
public:
	//���Ĳ�������:Borrow()
	//�����û�������ʷ:Resetinfo()
	//ͳ�ƽ�������:statistic()
	void Borrow();
	virtual void Resetinfo();
	void Statistic();
private:
	;
};

#endif _LEND
