/*********************************************
	Filename:Lend.cpp
	Time:2024/7/7
	Author:Haoren wang
	Description:Lend类的定义

**********************************************/

#include"Lend.h"

extern Book All_Books[50];
extern Users All_Users[50];

void Lend::Borrow()
{
	int No;
	cout << "选择借阅书籍的编号：" << endl;
	cin >> No;

	fstream outfile;
	outfile.open("C:\\Users\\10904\Desktop\\BMS\\Books_testdata.txt", ios::out | ios::ate);

	//检测文件打开是否成功
	if (!outfile)
	{
		cout << "File open failed!" << endl;
		return;
	}

	//文件指针定位
	outfile.seekp(sizeof(Book) * (No - 1), ios::beg);

	//创建临时对象复制信息
	Book tempbook(All_Books[No - 1]);

	//条件判断，之后可改为使用 assert()
	if (!*(tempbook.GetState()))
		cout << "无法借阅" << endl;
	else
		//将更改借阅状态后的信息覆盖原信息
	{
		*(tempbook.GetState()) = 0;
		outfile.write((char*)&tempbook, sizeof(Book));
		cout << "成功借阅!" << endl;
		//增加数据统计功能,若All_Users[i]使用Borrow()成功借出书All_bookk[j]，则pop_Users[i]++，pop_Books[j]++
		(*this).pop_User[(*this).User_No]++;
		pop_Book[No - 1]++;
	}
}

void Lend::Return()
{
	int No;
	cout << "选择退还书籍的编号：" << endl;
	cin >> No;

	//遍历Users借阅书籍
	int i = 0;
	for (; i < 3; i++)
	{
		if (No != Borrowing[i]&& i != 2)
			continue;
		else if(No == Borrowing[i])
		{
			//修改用户借阅中书籍的记录
			(*this).Borrowing[i] = 0;

			//修改书籍借阅状态
			fstream outfile;
			outfile.open("C:\\Users\\10904\Desktop\\BMS\\Books_testdata.txt", ios::out | ios::ate);
			if (!outfile)
			{
				cout << "File open failed!" << endl;
				return;
			}
			outfile.seekp(sizeof(Book) * (No - 1), ios::beg);
			Book tempbook(All_Books[No - 1]);
			*(tempbook.GetState()) = 1;
			outfile.write((char*)&tempbook, sizeof(Book));
		}
		else
		{
			cout << "未借阅本书籍" << endl;
		}
	}
}

void Lend::Resethistory(int No)
{
	//借阅历史通过由新到旧自上到下输出，超出范围时新历史覆盖旧历史
	{
		int i;
		//遍历数组检查是否有空位
		for (; i < 5; i++)
		{
			if ((*this).History[i] != 0 && i != 4)
			{
				continue;
			}
			//有空位，直接插入
			else if ((*this).History[i] == 0)
			{
				(*this).History[i] = No;
			}
			//无空位，覆盖旧历史
			else
			{
				int j;
				for (j = 0; j < 4; j++)
				{
					(*this).History[j] = (*this).History[j + 1];
				}
				(*this).History[4] = No;
			}
		}
	}
}

void Lend::Bubble_sort(int N[],int M[],int length)
{
	//将数组的值从大到小排列，并不改变原数组的值

	//动态创建指针数组，将原数组的排列在指针数组中进行
	int** parray = (int**)malloc(sizeof(int*) * length);
	int i,j;
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
	for (j = length-1; j >= 0; j--)
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

void Lend::Show_top_Books(int M[], int M_length)
{
	int i;
	cout << "最受欢迎的书籍：" << endl;
	for (i = 1; i <= M_length; i++)
	{
		cout << "第" << i << "名：";
		cout << All_Books[i - 1].GetBookInfo().BookName << endl;
	}
}

void Lend::Show_top_Users(int M[], int M_length)
{
	int i;
	cout << "最勤奋的读者：" << endl;
	for (i = 1; i <= M_length; i++)
	{
		cout << "第" << i << "名：";
		cout << All_Users[i - 1].GetName() << endl;
	}
}
