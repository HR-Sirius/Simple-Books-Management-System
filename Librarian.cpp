/*********************************************
	Filename:Librarian.h
	Time:2024/7/6
	Author:Haoren wang
	Description:Librarian类的定义

**********************************************/

#include"Librarian.h"

//管理员数据在Main.cpp中输入
//通过写文件更改管理员信息:Resetinfo()
void Librarian::Resetinfo()
{
	fstream outfile;
	outfile.open("C:\\Users\\10904\\Desktop\\BMS\\Librarian_textdata.txt", ios::out | ios::ate);

	//检测文件打开是否成功
	if (!outfile)
	{
		cout << "File open failed!" << endl;
		return;
	}

	Users Temp_Lib;	//定义临时Librarian类型对象，用于输入要修改的文件内容

	//文件指针定位到文件开头
	outfile.seekp(sizeof(Librarian), ios::beg);

	cin >> Temp_Lib;

	outfile.write((char*)&Temp_Lib, sizeof(Librarian));	//向指定位置输入更改后的管理员信息,管理员只有一位

	cout << "管理员信息修改成功" << endl;

	outfile.close();
}

//流输入运算符重载
std::istream& operator>>(istream& input, Librarian&Lib)
{
	cout << "输入管理员姓名:";
	input >> Lib.Librarian_Name;
	cout << "输入管理员性别:";
	input >> Lib.Liibrarian_Sex;
	return input;
}

//流输出运算符重载
std::ostream& operator<<(ostream& output, Librarian& Lib)
{
	output << "管理员姓名:" << Lib.Librarian_Name << endl;
	output << "管理员性别:" << Lib.Liibrarian_Sex << endl;
	return output;
}