/*********************************************
	Filename:Users.cpp
	Time:2024/7/6
	Author:Haoren wang
	Description:Users类的定义

**********************************************/

#include "Users.h"

//通过读文件打印用户信息:Getinfo()
void Users::Getinfo() const
{
	fstream infile;		//定义fstream类对象，实现文件信息的接收
	infile.open("C:\\Users\\10904\\Desktop\\BMS\\Users_testdata.txt", ios::in);		//ifile关联Users_testdata.txt文件

	//检测文件打开是否成功
	if (!infile)
	{
		cout << "File open failed!" << endl;
		return;
	}

	Users Temp_User;	 //定义临时User类型对象，用于接收文件内容

	while (infile.eof() != 0)
	{
		infile.read((char*)&Temp_User, sizeof(Users));
		cout << "用户信息：";
		cout << endl << Temp_User;
	}

	infile.close();
}

//用户数据在Main.cpp中输入
//通过写文件更改用户信息:Resetinfo()
void Users::Resetinfo()
{
	fstream outfile;
	outfile.open("C:\\Users\\10904\Desktop\\BMS\\Users_testdata.txt", ios::out | ios::ate);

	//检测文件打开是否成功
	if (!outfile)
	{
		cout << "File open failed!" << endl;
		return;
	}

	int User_No;	//用于用户信息在文件中的定位,用户信息以对象数组形式储存,之后在Main.cpp中添加显示所有用户的数组下标+姓名的函数

	Users Temp_User;	//定义临时User类型对象，用于输入要修改的文件内容

	cout << "输入用户编号：";
	cin >> User_No;
	outfile.seekp(sizeof(Users) * (User_No - 1), ios::beg);

	cin >> Temp_User;
	outfile.write((char*)&Temp_User, sizeof(Users));	//向指定位置输入更改后的用户信息

	cout << "用户信息修改成功" << endl;

	outfile.close();
}

//由新到旧输出用户借阅历史
void Users::Showhistory()
{
	int i;
	for (i = 4; i >= 0; i++)
	{
		int tempNo;
		tempNo = (*this).History[i];
		if (!tempNo)
			break;
		else
		{
			cout << "借阅历史：" << endl;
			cout << All_Books[tempNo - 1].GetBookInfo().BookName << endl;
		}
	}
}

//流输入运算符重载
std::istream& operator>>(istream& input, Users& User)
{
	cout << "输入用户姓名:";
	input >> User.UserName;
	cout << "输入用户性别:";
	input >> User.Sex;
	return input;
}

//流输出运算符重载
std::ostream& operator<<(ostream& output, Users& User)
{
	output << "用户姓名:" << User.UserName << endl;
	output << "用户性别:" << User.Sex << endl;
	return output;
}

char* Users::GetName()
{
	return (*this).UserName;
}

Users::Users()
{
	User_No = currentUsers;
	currentUsers++;
	cout << "Users constructor called." << endl;
}

Users::~Users()
{
	cout << "Users destructor called." << endl;
}

void Users::Borrow()
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

void Users::Return()
{
	int No;
	cout << "选择退还书籍的编号：" << endl;
	cin >> No;

	//遍历Users借阅书籍
	int i = 0;
	for (; i < 3; i++)
	{
		if (No != Borrowing[i] && i != 2)
			continue;
		else if (No == Borrowing[i])
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

void Users::Resethistory(int No)
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

void Users::Show_top_Books()
{
	int i;
	cout << "最受欢迎的书籍：" << endl;
	for (i = 1; i <= 5; i++)
	{
		cout << "第" << i << "名：";
		cout << All_Books[Users::top_Books[i - 1]].GetBookInfo().BookName << endl;
	}
}

void Users::Show_top_Users()
{
	int i;
	cout << "最勤奋的读者：" << endl;
	for (i = 1; i <= 3; i++)
	{
		cout << "第" << i << "名：";
		cout << All_Users[Users::top_Users[i - 1]].GetName() << endl;
	}
}


void Users::Search() const
{

}
