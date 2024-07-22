/*********************************************
	Filename:Management.h
	Time:2024/7/3
	Author:Haoren Wang
	Description:Management抽象基类的声明、定义

***********************************************/

#ifndef _MANAGEMENT
#define _MANAGEMENT

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<assert.h>
#include<string>
#include<vector>
#include<chrono>
#include<thread>
#include<iomanip>
using namespace std;

//为便于管理全局借阅记录，新增结构体Num_Pair,同时记录用户编号和书籍编号
struct Num_Pair
{
	int UserNum;
	int BookNum;
};

class Management
{
public:
	virtual void Getinfo(int) = 0;
	virtual void Resetinfo(int) = 0;
	//排序:Bubble_sort()
	void Bubble_sort(int[], int[], int);
	//string小写转化函数
	void string_lowercase(string&);
};

//建立全局借阅记录
extern struct Num_Pair All_borrow[15] = 
{ 
	{'\0','\0'},{'\0','\0'},{'\0','\0'},{'\0','\0'},{'\0','\0'},
	{'\0','\0'},{'\0','\0'},{'\0','\0'},{'\0','\0'},{'\0','\0'},
	{'\0','\0'},{'\0','\0'},{'\0','\0'},{'\0','\0'},{'\0','\0'} 
};

void Management::Bubble_sort(int pop_[], int top_[], int top_length)
{
	//暂定数组长度均为10，之后可改为动态创建数组
	//将pop_[]的值从大到小排列，不改变原数组的值

	int* parray[20];
	int subnote[20] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};	//记录每一次交换的下标
	int i, j;

	//parray[i]->pop_[i]
	for (i = 0; i < 20; i++)
	{
		parray[i] = &pop_[i];
	}

	//从大到小冒泡排序
	int* temp = NULL;
	int Temp = 0;
	for (j = 19; j > 0; j--)
		for (i = 0; i < j; i++)
		{
			if (*parray[i] < *parray[i + 1])
			{
				// 交换指针指向,使parray[0]指向最大数值
				temp = parray[i];
				parray[i] = parray[i + 1];
				parray[i + 1] = temp;
				//交换记录的下标
				Temp = subnote[i];
				subnote[i] = subnote[i + 1];
				subnote[i + 1] = Temp;
			}
		}
	for (i = 0; i < top_length; i++)
	{
		if (*parray[i] == '\0')
			top_[i] = '\0';
		else
			top_[i] = subnote[i] + 1;
	}
}

void Management::string_lowercase(string& str)
{
	int i;
	//遍历str，大写字母转化为小写，空格及小写字母不变
	for (i = 0; i < size(str); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
	}
}
#endif
