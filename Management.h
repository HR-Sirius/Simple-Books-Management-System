/*********************************************
	Filename:Management.h
	Time:2024/7/3
	Author:Haoren Wang
	Description:Management������������

***********************************************/

#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

#ifndef _MANAGEMENT
#define _MANAGEMENT

class Management
{
public:
	//��ӡ������Ϣ:Getinfo()
	//���Ķ�����Ϣ:Resetinfo()
	virtual void Getinfo() const = 0;
	virtual void Resetinfo() = 0;
};

#endif