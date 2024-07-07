/*********************************************
	Filename:Users.h
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

	while(infile.eof() != 0)
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
	outfile.open("C:\\Users\\10904\Desktop\\BMS\\Users_testdata.txt", ios::out|ios::ate);

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
	outfile.seekp(sizeof(Users)*(User_No-1), ios::beg);

	cin >> Temp_User;
	outfile.write((char*)&Temp_User, sizeof(Users));	//向指定位置输入更改后的用户信息

	cout << "用户信息修改成功" << endl;

	outfile.close();
}

//流输入运算符重载
std::istream& operator>>(istream&input, Users&User)
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

Users::Users()
{
	cout << "Users constructor called." << endl;
}

Users::~Users()
{
	cout << "Users destructor called." << endl;
}