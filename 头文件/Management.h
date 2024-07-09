/*********************************************
	Filename:Management.h
	Time:2024/7/3
	Author:Haoren Wang
	Description:Management抽象基类的声明

***********************************************/

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<assert.h>
using namespace std;

#ifndef _MANAGEMENT
#define _MANAGEMENT

class Management
{
public:
	//打印对象信息:Getinfo()
	//更改对象信息:Resetinfo()
	virtual void Getinfo() const = 0;
	virtual void Resetinfo() = 0;

	//排序:Bubble_sort()
	void Bubble_sort(int[], int[], int);

#endif
