/*********************************************
	Filename:Management.cpp
	Time:2024/7/9
	Author:Haoren wang
	Description:Management类的定义

**********************************************/

#include"Management.h"

extern Book All_Books[50];
extern Users All_Users[50];

void Management::Bubble_sort(int N[], int M[], int length)
{
	//将数组的值从大到小排列，并不改变原数组的值
	//动态创建指针数组，将原数组的排列在指针数组中进行
	int** parray = (int**)malloc(sizeof(int*) * length);
	int i, j;
	for (i = 0; i < length; i++)
	{
		parray[i] = (int*)malloc(sizeof(int));
	}

	//指针数组元素与原数组元素一一对应
	for (i = 0; i < length; i++)
	{
		parray[i] = &N[i];
	}

	//从大到小冒泡排序
	int* temp = NULL;
	for (j = length - 1; j >= 0; j--)
		for (i = 0; i < j; i++)
		{
			if (*parray[i] < *parray[i + 1])
			{
				// 交换指针指向,使parray[1]指向最大数值
				temp = parray[i];
				parray[i] = parray[i + 1];
				parray[i + 1] = temp;
			}
			else;
		}

	//储存排序结果在M[]中
	for (i = 0; i < length; i++)
	{
		M[i] = N[i];
	}

	//逐一释放空间
	for (i = 0; i < length; i++)
	{
		free(parray[i]);
	}
	free(parray);
}