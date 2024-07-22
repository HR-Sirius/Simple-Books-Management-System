/*********************************************
	Filename:Librarian.h
	Time:2024/7/6
	Author:Haoren wang
	Description:派生类Librarian类的声明、定义

**********************************************/

#ifndef _LIBRARIAN
#define _LIBRARIAN

#include"Users.h"
#include"Book.h"

class Librarian:public Users
{
	//需要用到Book类的函数，申明为友元函数
	friend void Book::Getinfo(int);
	friend void Book::Resetinfo(int);

	static string Filepath;

public:
	//新增书籍:Add_Book()
	//新增用户:Add_User()
	//清理文件内容:ClearFile()
	//删除书籍:Del_Book()
	//展示所有用户:DisplayAllUsers()
	//展示所有书籍:DisplayAllBooks();
	//通过读文件打印管理员信息:Getinfo()
	//通过写文件更改管理员信息:Resetinfo()
	//首次录入文件信息:Setinfo()
	//展示全局借阅记录:ShowAllborrow()
	//展示管理员界面:Showmenu()
	void Add_Book();
	void Add_User();
	static void ClearFile();
	void Del_Book();
	void DisplayAllUsers();
	void DisplayAllBooks();
	virtual void Getinfo();
	string GetName();
	virtual void Resetinfo();
	virtual void Setinfo();
	void ShowAllborrow();
	virtual void Showmenu();

	Librarian() = default;
	Librarian(string,string);
	~Librarian();

	//流输入运算符重载
	friend istream& operator>>(istream&, Librarian&);
	//流输出运算符重载
	friend ostream& operator<<(ostream&, Librarian&);

private:
	//Librarian_Name:图书管理员姓名
	//Liibrarian_Sex:图书管理员性别
	string Librarian_Name;
	string Librarian_Sex;
};

string Librarian::Filepath = "C:\\Users\\10904\\Desktop\\BMS\\Librarian_textdata.txt";

//创建Librarian类全局对象
Librarian LibManager("John", "M");

istream& operator>>(istream& input, Librarian& Lib)
{
	cout << "输入管理员姓名:";
	input >> Lib.Librarian_Name;
	cout << "输入管理员性别:";
	input >> Lib.Librarian_Sex;
	return input;
}

ostream& operator<<(ostream& output, Librarian& Lib)
{
	output << "管理员姓名:" << Lib.Librarian_Name << endl;
	output << "管理员性别:" << Lib.Librarian_Sex << endl;
	return output;
}

Librarian::Librarian(string Name,string Sex)
{
	Librarian_Name = Name;
	Librarian_Sex = Sex;
}

Librarian::~Librarian()
{
	cout << "Librarian Destructor called." << endl;
}

void Librarian::Add_Book()
{
	Book Temp_Book;
	cin >> Temp_Book;

	All_Books.push_back(Temp_Book);

	//将对象保存到文件中
	All_Books[All_Books.size() - 1].Setinfo(All_Books[All_Books.size() - 1].GetBookNo()-1);

	//此处会释放旧的存储空间，调用析构函数
	cout << "书籍添加成功" << endl;
}

void Librarian::Add_User()
{
	Users Temp_User;
	cin >> Temp_User;

	All_Users.push_back(Temp_User);

	//将对象保存到文件中
	All_Users[All_Users.size() - 1].Setinfo(All_Users[All_Users.size() - 1].GetNo()-1);

	cout << "用户添加成功" << endl;
}

void Librarian::ClearFile()
{
	ofstream ofile(Librarian::Filepath, ios::trunc);
	if (!ofile)
	{
		cout << "File open failed!" << endl;
	}
	ofile.close();
	cout << "管理员信息文件已清理" << endl;
}

void Librarian::Del_Book()
{
	int BookNo;
	cout << "输入待删除的书籍编号:";
	cin >> BookNo;

	//创建新迭代器pos
	auto pos = All_Books.begin();

	//删除第BookNo个元素
	All_Books.erase(pos + BookNo - 1);

	cout << "书籍删除成功" << endl;
}

void Librarian::Setinfo()
{
	fstream outfile;
	outfile.open("C:\\Users\\10904\\Desktop\\BMS\\Librarian_textdata.txt", ios::out | ios::ate);

	if (!outfile)
	{
		cout << "File open failed!" << endl;
		return;
	}

	outfile << (*this).Librarian_Name << " " << (*this).Librarian_Sex << endl;

	cout << "管理员信息录入成功" << endl;

	outfile.close();
}

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

	Librarian Temp_Lib;	//定义临时Librarian类型对象，用于输入要修改的文件内容

	//文件指针定位到文件开头
	outfile.seekp(sizeof(Librarian), ios::beg);

	cin >> Temp_Lib;

	outfile.write((char*)&Temp_Lib, sizeof(Librarian));	//向指定位置输入更改后的管理员信息,管理员只有一位

	cout << "管理员信息修改成功" << endl;

	outfile.close();
}

void Librarian::Getinfo()
{
	cout << "获取管理员信息" << endl;
}

string Librarian::GetName()
{
	return (*this).Librarian_Name;
}

void Librarian::DisplayAllBooks()
{
	int i = 0;
	cout << "馆藏所有书籍简要信息如下:" << endl;

	for (i = 0; i < All_Books.size(); i++)
	{
		All_Books[i].Brief_Show();
	}
}

void Librarian::DisplayAllUsers()
{
	int i = 0;
	cout << "图书馆所有用户信息如下:" << endl;
	for (i = 0; i < All_Users.size(); i++)
	{
		cout<<All_Users[i]<<endl;
	}
}

void Librarian::ShowAllborrow()
{
	int i;
	int flag = 0;
	//由新到旧输出借阅历史
	cout << "全局借阅历史:" << endl;
	for (i = 14; i >= 0; i--)
	{
		//若All_borrow[i]为空，不输出
		if (All_borrow[i].BookNum == '\0'&& All_borrow[i].UserNum == '\0')
			continue;
		else
		{
			cout << All_borrow[i].UserNum << "号用户借阅了" << All_borrow[i].BookNum << "号书籍" << endl;
			flag++;
		}
	}
	if (!flag)
		cout << "暂无" << endl;
}

void Librarian::Showmenu()
{
	system("cls");
	cout << "==========================欢迎使用图书馆后台管理系统===========================" << endl;;
	cout << "                              1.新书录入" << endl;
	cout << "                              2.图书查询" << endl;
	cout << "                              3.删除图书" << endl;
	cout << "                              4.图书列表" << endl;
	cout << "                              5.借阅记录" << endl;
	cout << "                              6.新增用户" << endl;
	cout << "                              7.用户列表" << endl;
	cout << "                              0.退出登录" << endl;
	cout << "===============================================================================" << endl;
}
#endif //!_LIBRARIAN
