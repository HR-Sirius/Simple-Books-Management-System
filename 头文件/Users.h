/*********************************************
	Filename:Users.h
	Time:2024/7/6
	Author:Haoren wang
	Description:派生类Users类的声明、定义

**********************************************/

#ifndef _USERS
#define _USERS

#include "Management.h"
#include "Book.h"

class Users :virtual public Management
{
	//搜索、统计等功能需要用到Book类成员，申明为友元类
	friend Book;

	//统计最热门书籍,用于计数:pop_Book[50]
	//统计最勤奋读者,用于计数:pop_User[50]
	//最热门书籍:top_Book[5]，存放书籍编号
	//最勤奋读者:top_Users[3]，存放用户编号
	static int pop_Book[20];
	static int pop_User[20];
	static int top_Books[5];
	static int top_Users[3];

	//静态变量，自动生成用户编号
	static int currentUsers;
	//文件地址
	static string Filepath;
public:
	//接口函数，返回用户姓名
	string GetName();
	//搜索方法(最重要函数)，由于搜索结果是书名若干，因此计划将搜索结果保存在临时创建的数组中，逐一打印
	//输入字符串，遍历所有对象书名，输出对应结果
	bool Search();

	//析构函数~Users(),提示作用(可之后改为虚析构函数)
	Users();
	Users(string, string);
	~Users();

	//借阅操作,统计借阅数据:Borrow(int)
	//文件清理:ClearFile()
	//通过读文件打印用户信息:Getinfo(int) const
	//返回用户编号:GetNo()
	//更改全局借阅记录:ResetAllborrow(int)
	//更改用户借阅中书籍:Resetborrowing(int)
	//更改用户借阅历史:Resethistory(int)
	//通过写文件更改用户信息:Resetinfo(int)
	//还书:Return()
	//首次录入文件信息:SetUserinfo(int)
	//菜单显示:Showmenu()
	//显示借阅中书籍:Showborrowing()
	//输出用户借阅历史:Showhistory()
	//输出统计结果:Show_top_Books(),Show_top_Users()
	void Borrow();
	static void ClearFile();
	virtual void Getinfo(int);
	int GetNo();
	void ResetAllborrow(int);
	virtual void Resetborrowing(int);
	virtual void Resethistory(int);
	virtual void Resetinfo(int);
	void Return();
	virtual void Setinfo(int);
	virtual void Showmenu();
	void Showborrowing();
	void Showhistory();
	void Show_top_Books();
	void Show_top_Users();

	//流输入运算符重载
	friend istream& operator>>(istream&, Users&);
	//流输出运算符重载
	friend ostream& operator<<(ostream&, Users&);
protected:
	//UserName记录用户姓名
	//Sex记录用户性别
	//History用字符串记录借阅历史
	//User_No:用户编号
	//Borrowing[3]:借阅中书籍
	string UserName;
	string Sex;
	int History[5];
	int User_No;
	int Borrowing[3];//之后可添加身份属性，不同身份有着不同的借阅上限
};

//静态成员初始化
int Users::currentUsers = 0;
int Users::pop_Book[20] = { '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0' };
int Users::pop_User[20] = { '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0' };
int Users::top_Books[5] = { 0 };
int Users::top_Users[3] = { 0 };
string Users::Filepath = "C:\\Users\\10904\\Desktop\\BMS\\Users_testdata.txt";

//Users类全局对象向量
extern vector<Users> All_Users =
{
	Users("Wang","M"),
	Users("Zhang","M"),
	Users("Xian","M"),
	Users("Liu","F"),
	Users("Fan","M"),
	Users("Huang","F"),
	Users("Sun","F"),
	Users("Guo","M"),
	Users("Cai","M"),
	Users("Mu","M")
};

void Users::Setinfo(int subNo)
{
	//No从0开始
	fstream outfile;
	outfile.open("C:\\Users\\10904\\Desktop\\BMS\\Users_testdata.txt", ios::out | ios::app);

	//检测文件打开是否成功
	if (!outfile)
	{
		cerr << "File open failed!" << endl;
		return;
	}

	//向指定位置输入用户姓名、性别，数据均按行输入，便于后续读取和改写
	outfile << setw(6) << All_Users[subNo].UserName << setw(3) << All_Users[subNo].Sex << setw(3) << All_Users[subNo].User_No;
	for (int i = 0; i < 5; i++)
	{
		outfile << setw(3) << All_Users[subNo].History[i];
	}
	for (int i = 0; i < 3; i++)
	{
		outfile << setw(3) << All_Users[subNo].Borrowing[i];
	}
	outfile << endl;

	cout << "用户" << subNo << "信息录入成功" << endl;
	outfile.close();
}

void Users::Getinfo(int subNo)
{
	fstream infile;		//定义fstream类对象，实现文件信息的接收
	infile.open("C:\\Users\\10904\\Desktop\\BMS\\Users_testdata.txt", ios::in);		//infile关联Users_testdata.txt文件

	//检测文件打开是否成功
	if (!infile)
	{
		cout << "File open failed!" << endl;
		return;
	}

	//定义临时对象Temp_User接收消息
	currentUsers--;
	Users Temp_User;

	string line;
	//跳过前面的记录，直接定位到subNo指定的行
	for (int i = 0; i < subNo; ++i)
	{
		getline(infile, line); // 读取并丢弃前面的行
	}

	// 读取指定的记录
	infile >> Temp_User.UserName >> Temp_User.Sex >> Temp_User.User_No;
	for (int i = 0; i < 5; i++)
	{
		infile >> Temp_User.History[i];
	}
	for (int i = 0; i < 3; i++)
	{
		infile >> Temp_User.Borrowing[i];
	}

	cout << "用户姓名:" << Temp_User.UserName << endl;
	cout << "用户性别:" << Temp_User.Sex << endl;
	cout << "用户编号:" << Temp_User.User_No << endl;
	/*cout << "借阅历史:";
	for (int i = 0; i < 5; i++)
	{
		cout<< setw(3) << Temp_User.History[i];
	}
	cout << endl;
	cout << "借阅中书籍:";
	for (int i = 0; i < 3; i++)
	{
		cout<<setw(3)<<Temp_User.Borrowing[i];
	}
	cout << endl;*/
	infile.close();
}

int Users::GetNo()
{
	return (*this).User_No;
}

void Users::Resetinfo(int subNo)
{
	fstream outfile;
	outfile.open("C:\\Users\\10904\\Desktop\\BMS\\Users_testdata.txt", ios::out);

	//检测文件打开是否成功
	if (!outfile)
	{
		cerr << "File open failed!" << endl;
		return;
	}

	//定义临时对象Temp_User
	currentUsers--;
	Users Temp_User(All_Users[subNo]);
	cin >> Temp_User;

	All_Users[subNo].UserName = Temp_User.UserName;
	All_Users[subNo].Sex = Temp_User.Sex;

	for (int i = 0; i < All_Users.size(); i++)
	{
		All_Users[i].Setinfo(i);
	}

	cout << "用户信息修改成功" << endl;
	outfile.close();
}

void Users::ResetAllborrow(int bookNo)
{
	int i = 0;
	//对全局借阅记录的输出
	for (i = 0; i < 15; i++)
	{
		if (All_borrow[i].UserNum != '\0' && i != 14)
		{
			continue;
		}
		else if (All_borrow[i].UserNum == '\0')
		{
			All_borrow[i] = { (*this).User_No,bookNo };
			break;
		}
		else
		{
			int j;
			for (j = 0; j < 14; j++)
			{
				All_borrow[i].BookNum = All_borrow[i + 1].BookNum;
				All_borrow[i].UserNum = All_borrow[i + 1].UserNum;
			}
			All_borrow[14] = { (*this).User_No,bookNo };
		}
	}
}

//由新到旧输出用户借阅历史
void Users::Showhistory()
{
	int i;
	int flag = 0;
	cout << "借阅历史：" << endl;
	for (i = 4; i >= 0; i--)
	{
		if ((*this).History[i] == '\0')
			continue;
		else
		{
			cout << All_Books[(*this).History[i] - 1].GetBookName() << endl;
			flag++;
		}
	}
	if (!flag)
		cout << "暂无" << endl;
}

//流输入运算符重载(只输入姓名和性别)
istream& operator>>(istream& input, Users& User)
{
	cout << "输入用户姓名:";
	input >> User.UserName;
	cout << "输入用户性别:";
	input >> User.Sex;
	return input;
}

//流输出运算符重载(只输出姓名、性别和编号)
ostream& operator<<(ostream& output, Users& User)
{
	output << "用户姓名:" << User.UserName << endl;
	output << "用户性别:" << User.Sex << endl;
	output << "用户编号:" << User.User_No << endl;
	return output;
}

string Users::GetName()
{
	return (*this).UserName;
}

Users::Users()
{
	User_No = currentUsers;
	currentUsers++;
	int i;
	for (i = 0; i < 5; i++)
		History[i] = '\0';
	for (i = 0; i < 3; i++)
		Borrowing[i] = '\0';
	cout << User_No << " " << UserName << " created" << endl;

}

Users::Users(string username, string sex)
{
	UserName = username;
	Sex = sex;
	int i;
	for (i = 0; i < 5; i++)
		History[i] = '\0';
	for (i = 0; i < 3; i++)
		Borrowing[i] = '\0';
	//自动编号
	currentUsers++;
	User_No = currentUsers;
	cout << User_No << " " << UserName << " created" << endl;
}

Users::~Users()
{
	cout << User_No << " " << UserName << " deleted" << endl;
}

void Users::Borrow()
{
	//检查是否达到借书上限
	if ((*this).Borrowing[2] != '\0')
	{
		cout << "已达到借书数量上限，请先退还书籍" << endl;
		return;
	}
	int No;
	cout << "选择借阅书籍的编号:";
	cin >> No;

	//判断书籍借阅状态
	if (!*(All_Books[No - 1].GetState()))
		cout << "无法借阅" << endl;
	else
	{
		//修改书籍借阅状态
		*(All_Books[No - 1].GetState()) = 0;
		cout << "成功借阅!" << endl;

		//修改该用户借阅记录
		this->Resethistory(No);
		//修改该用户借阅中书籍
		this->Resetborrowing(No);
		//修改全局借阅记录
		this->ResetAllborrow(No);

		//增加数据统计功能,若All_Users[i]使用Borrow()成功借出书All_book[j]，则pop_Users[i]++，pop_Books[j]++
		Users::pop_User[(*this).User_No - 1]++;
		Users::pop_Book[No - 1]++;
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
			(*this).Borrowing[i] = '\0';
			for (i = 0; i < 2; i++)
			{
				if ((*this).Borrowing[i] == '\0' && (*this).Borrowing[i + 1] != '\0')
				{
					(*this).Borrowing[i] = (*this).Borrowing[i + 1];
					(*this).Borrowing[i] = '\0';
				}
			}

			//修改书籍借阅状态
			*(All_Books[No - 1].GetState()) = 1;
			cout << "成功退还" << endl;
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
	int i = 0;
	//遍历数组检查是否有空位
	for (i = 0; i < 5; i++)
	{
		if ((*this).History[i] != '\0' && i != 4)
		{
			continue;
		}
		//有空位，直接插入
		else if ((*this).History[i] == '\0')
		{
			(*this).History[i] = No;
			break;
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

void Users::Resetborrowing(int No)
{
	{
		int i = 0;
		//遍历数组检查是否有空位
		for (i = 0; i < 3; i++)
		{
			if ((*this).Borrowing[i] != '\0' && i != 2)
			{
				continue;
			}
			//有空位，直接插入
			else if ((*this).Borrowing[i] == '\0')
			{
				(*this).Borrowing[i] = No;
				break;
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

void Users::Showborrowing()
{
	int i;
	int flag = 0;
	cout << "当前借阅书籍:";
	for (i = 0; i < 3; i++)
	{
		if ((*this).Borrowing[i] != '\0')
		{
			cout << endl;
			All_Books[(*this).Borrowing[i] - 1].Brief_Show();
			flag++;
		}
	}
	if (!flag)
		cout << "无" << endl;
}

void Users::Show_top_Books()
{
	Bubble_sort(pop_Book, top_Books, 5);
	int i;
	cout << "最受欢迎的书籍:" << endl;
	for (i = 1; i <= 5; i++)
	{
		if (Users::top_Books[i - 1] != '\0')
		{
			cout << "第" << i << "名：";
			cout << All_Books[Users::top_Books[i - 1] - 1].GetBookName() << endl;
		}
		else
		{
			cout << "第" << i << "名：";
			cout << "暂无" << endl;
		}
	}
}

void Users::Show_top_Users()
{
	Bubble_sort(Users::pop_User, Users::top_Users, 3);
	int i;
	cout << "最勤奋的读者:" << endl;
	for (i = 1; i <= 3; i++)
	{
		if (Users::top_Users[i - 1] != '\0')
		{
			cout << "第" << i << "名：";
			cout << All_Users[Users::top_Users[i - 1] - 1].GetName() << endl;
		}
		else
		{
			cout << "第" << i << "名：";
			cout << "暂无" << endl;
		}
	}
}

bool Users::Search()
{
	string instr;
	int i;
	int flag = 0;
	string TempBookName[20];

	//输入字符串 
	cout << "输入书名:";
	//清除缓冲区剩余的'\n
	getchar();
	//getline函数能包含空格
	getline(cin, instr);

	//避免因大小写导致未查找，将书名与instr均转化为小写
	string_lowercase(instr);
	cout << "查找结果:" << endl;
	for (i = 0; i < All_Books.size(); i++)
	{
		TempBookName[i] = All_Books[i].GetBookName();
		string_lowercase(TempBookName[i]);
	}

	//从All_Books[0]开始遍历书名
	for (i = 0; i < All_Books.size(); i++)
	{
		//字串匹配
		if (TempBookName[i].find(instr) != instr.npos)
		{
			All_Books[i].Brief_Show();
			flag++;
		}
	}
	if (flag == 0)
	{
		cout << "  " << "未查找到该书籍" << endl;
		return false;
	}
	return true;
}

void Users::Showmenu()
{
	system("cls");
	cout << "==========================欢迎使用图书馆管理系统===========================" << endl;
	cout << "                              1.查询图书" << endl;
	cout << "                              2.借阅图书" << endl;
	cout << "                              3.归还图书" << endl;
	cout << "                              4.借阅记录" << endl;
	cout << "                              5.当前借阅书籍" << endl;
	cout << "                              6.查看个人信息" << endl;
	cout << "                              7.查看热门图书" << endl;
	cout << "                              8.查看最勤奋读者" << endl;
	cout << "                              9.修改个人信息" << endl;
	cout << "                              0.退出登录" << endl;
	cout << "===========================================================================" << endl;
}

void Users::ClearFile()
{
	ofstream ofile(Users::Filepath, ios::trunc);
	if (!ofile)
	{
		cout << "File open failed!" << endl;
	}
	ofile.close();
	cout << "用户信息文件已清理" << endl;
}
#endif //!_USERS
