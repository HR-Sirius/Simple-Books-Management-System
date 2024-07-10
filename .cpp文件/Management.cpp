/*********************************************
	Filename:Management.cpp
	Time:2024/7/9
	Author:Haoren wang
	Description:Management类的定义

**********************************************/

#include"Management.h"

void Management::Bubble_sort(int pop_[], int top_[],int top_length)
{
	//暂定数组长度均为50，之后可改为动态创建数组
	//将pop_[]的值从大到小排列，并不改变原数组的值
	
	int* parray[50];
	int** pparray[50];
	int i, j;

	//parray[i]->pop_[i]
	for (i = 0; i < 50; i++)
	{
		parray[i] = &pop_[i];
	}

	//从大到小冒泡排序
	int* temp = NULL;
	for (j = 49; j >= 0; j--)
		for (i = 0; i < j; i++)
		{
			if (*parray[i] < *parray[i+1])
			{
				// 交换指针指向,使parray[0]指向最大数值
				temp = parray[i];
				parray[i] = parray[i + 1];
				parray[i + 1] = temp;
			}
			else;
		}

	//储存排序结果(书籍编号)在top_[]中
	for (i = 0; i < top_length; i++)
		for (j = 0; j < 50; j++)
		{
			if (*parray[i] == pop_[j])
			{
				top_[i] = j;
			}
			break;
		}
}
