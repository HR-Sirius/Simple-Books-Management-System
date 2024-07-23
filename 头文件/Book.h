/*********************************************
	Filename:User.h
	Time:2024/7/4
	Author:Haoren Wang
	Description:派生类Book类的声明、定义

**********************************************/

#ifndef _BOOK
#define _BOOK

#include"Management.h"
#include<vector>

enum type
{
	suspense = 1, science = 2, fantasy = 3, romance = 4, criminal = 5, encyclopedia = 6, adventure = 7, realism = 8
};

class Book :virtual public Management
{
	//静态变量，用于计数
	static int currentbook;
	//文件地址
	static string Filepath;

public:
	//析构函数~Book(),提示作用(可之后改为虚析构函数)
	Book();
	Book(string, string, string, int, string, string, string);
	~Book();
	
	//简明输出，用于输出搜索结果:Brief_Show()
	//文件清理:ClearFile()
	//接口函数,返回(*this).BookName:GetBookName()
	//接口函数,返回(*this).BookNo地址:GetBookNo()
	//通过读文件获取书籍信息:Getinfo(int)
	//接口函数,返回(*this).State地址:GetState()
	//通过写文件更改书籍信息:Resetinfo(int)
	//首次录入书籍信息:Setinfo(int)
	void Brief_Show();
	static void ClearFile();
	string GetBookName();
	int GetBookNo();
	virtual void Getinfo(int);
	bool* GetState();
	virtual void Resetinfo(int);
	void Setinfo();

	//流输入运算符重载(1)
	friend istream& operator>>(istream&, type&);
	//流输入运算符重载(2)
	friend istream& operator>>(istream&, Book&);
	
	//流输出运算符重载(1)
	friend ostream& operator<<(ostream&, type&);
	//流输出运算符重载(2)
	friend ostream& operator<<(ostream&, Book&);
private:
	//BookNo为书籍编号（从1开始）
	//借阅状态;State,0已借出,1可借阅,初始状态默认可借阅
	//书名:BookName
	//简介:Outline
	//作者:Author
	//类别:Booktype，用枚举类定义，默认每本书只有一种类型
	//关键词:Keywords,最多三个
	int BookNo;
	bool State;
	string BookName;
	string Outline;
	string Author;
	type Booktype;
	string Keywords[3];
};

//静态成员初始化
int Book::currentbook = 1;
string Book::Filepath = "C:\\Users\\10904\\Desktop\\BMS\\Books_testdata.txt";

//Book类全局对象向量
extern vector<Book> All_Books =
{
	Book("Harry_Potter","A _fantasy_adventure","J.K_Rowling",3,"Harry_Potter","Wonderous","Magic"),
	Book("The_Count_of_Monte_Cristo","A_righteous_revenge","Dumas",7,"Adventure","Monte_Cristo","Revenge"),
	Book("Four_Generarions_Under_One_Roof","AAA","Lao_she",8,"War_of_Resistance_against_Japanese_Aggression","Beijing","Normal_Life"),
	Book("Dou_Po_Cang_Qiong","BBB","Tian_can_tu_dou",3,"Dou_qi","Adventure","Fantasy"),
	Book("Zei_Jing","CCC","Xia_Xie",5,"High-tech_Crime","Justice","Humanity"),
	Book("The_Lord_of_the_Rings","DDD","J.R.R_Tolkien",3,"Frindship_and_Unity","Power_and_Corruption","Bravery_and_crifice"),
	Book("Encyclopaedia_Britannica","A_reference_book","EngLand",6,"Technique","Literary","History"),
	Book("One_Hundred_Thousand_whys","A_set_of_science_books"," Chinese ",2,"EEE","FFF","GGG"),
	Book("Romeo_and_Juliet","A_timeless_tragic_play","Williams_Shakespeare",4,"Love_and_tragedy","Shakespeare","Opera"),
	Book("Twenty_Thousand_Leagues_Under_the_Sea","The_story_of_Professor_Aronnax","Jules_Gabriel_Verne",7,"Ocean","Pioneering_spirit","Nimo")
};

//流输入运算符重载(1)
istream& operator>>(istream& input, type& type) 
{
	cout << "suspense = 1, science = 2, fantasy = 3, romance = 4,criminal = 5, encyclopedia = 6, adventure = 7, realism = 8 " << endl;

	int type_Num;
	input >> type_Num; // 读取整数

	switch (type_Num)
	{
		case 1:type = suspense; break;
		case 2:type = science; break;
		case 3:type = fantasy; break;
		case 4:type = romance; break;
		case 5:type = criminal; break;
		case 6:type = adventure; break;
		case 7:type = realism; break;
		default:type = encyclopedia; break;
	}
	return input;
}

//流输入运算符重载(2)
istream& operator>>(istream& input, Book& Book)
{
	cout << "输入书名：";
	input >> Book.BookName;
	cout << "输入作者姓名：";
	input >> Book.Author;
	cout << "输入书籍类型:";
	input >> Book.Booktype;
	cout << "输入书籍关键词（至多三个）";
	input >> Book.Keywords[0] >> Book.Keywords[1] >> Book.Keywords[2];
	cout << "输入简介：";
	input >> Book.Outline;
	return input;
}

//流输出运算符重载(1)
ostream& operator<<(ostream& output, type& type_Num)
{
	switch (type_Num)
	{
	case suspense:output << 1; break;
	case science:output << 2; break;
	case fantasy:output << 3; break;
	case romance:output << 4; break;
	case criminal:output << 5; break;
	case adventure:output << 6; break;
	case realism:output << 7; break;
	default:output << 8; break;
	}
	return output;
}

//流输出运算符重载(2)
ostream& operator<<(ostream& output, Book& Book)
{
	output << "书籍编号：" << Book.BookNo << endl;
	output << "书名：" << Book.BookName << endl;
	output << "作者姓名：" << Book.Author << endl;
	output << "简介：" << Book.Outline << endl;
	output << "书籍类型：" << Book.Booktype << endl;
	output << "书籍关键词：" << Book.Keywords[0] <<" " << Book.Keywords[1] << " " << Book.Keywords[2] << endl;
	output << "借阅状态：";
	if (Book.State)
		output << "可借出" << endl;
	else
		output << "已借出" << endl;
	return output;
}

void Book::Setinfo()
{
	//No从0开始
	fstream outfile;
	outfile.open(Book::Filepath, ios::out | ios::app);

	//检测文件打开是否成功
	if (!outfile)
	{
		cout << "File open failed!" << endl;
		return;
	}

	//向指定位置输入更改后的书籍信息
	outfile << (*this).BookName << " "
			<< (*this).Author << " "
			<< (*this).Keywords[0] << " " << (*this).Keywords[1] << " " << (*this).Keywords[2] << " "
			<< (*this).Booktype << " "
			<< (*this).Outline << " "
			<< (*this).BookNo << endl;
	cout << "书籍" << (*this).BookNo << "信息录入成功" << endl;

	outfile.close();
}

void Book::Getinfo(int subNo)
{
	fstream infile;		//定义fstream类对象，实现文件信息的接收
	infile.open(Book::Filepath, ios::in );		//infile关联Books_testdata.txt文件

	//检测文件打开是否成功
	if (!infile)
	{
		cout << "File open failed!" << endl;
		return;
	}

	//定义临时string、type类型变量，用于接收文件内容
	Book Temp_Book;

	string line;
	//跳过前面的记录，直接定位到subNo指定的行
	for (int i = 0; i < subNo; ++i)
	{
		getline(infile, line); // 读取并丢弃前面的行
	}
	cin.ignore();

	infile >> Temp_Book.BookName >> Temp_Book.Author >> Temp_Book.Keywords[0] >> Temp_Book.Keywords[1] >> Temp_Book.Keywords[2] >> Temp_Book.Booktype >> Temp_Book.Outline>>Temp_Book.BookNo;

	cout << "书籍名称:" << Temp_Book.BookName << endl;
	cout << "作者:" << Temp_Book.Author << endl;
	cout << "关键词:" << Temp_Book.Keywords[0] << " " << Temp_Book.Keywords[1] << " " << Temp_Book.Keywords[2] << endl;
	//这里输入再输出的过程有问题，导致读文件错误
	cout << "类型:" << Temp_Book.Booktype << endl;
	cout << "简介:" << Temp_Book.Outline << endl;
	cout << "书籍编号:" << Temp_Book.BookNo << endl;

	infile.close();
}

void Book::Resetinfo(int subNo)
{
	fstream outfile;
	outfile.open(Book::Filepath, ios::out);

	//检测文件打开是否成功
	if (!outfile)
	{
		cout << "File open failed!" << endl;
		return;
	}

	Book Temp_Book(All_Books[subNo]);	//定义临时User类型对象，用于输入要修改的文件内容
	cin >> Temp_Book;

	All_Books[subNo].BookName = Temp_Book.BookName;
	All_Books[subNo].Author = Temp_Book.Author;
	All_Books[subNo].Booktype = Temp_Book.Booktype;
	for (int i = 0; i < 3; i++)
	{
		All_Books[subNo].Keywords[i] = Temp_Book.Keywords[i];
	}
	All_Books[subNo].Outline = Temp_Book.Outline;

	for (int i = 0; i < All_Books.size(); i++)
	{
		All_Books[i].Setinfo();
	}
	cout << "书籍信息修改成功" << endl;

	outfile.close();
}

void Book::Brief_Show()
{
	//待添加[]重载函数，增加数组越界功能检测
	//待添加格式化功能，使编号均显示为三位数，如001，015
	//这里改为了(*this).BookName，而不是由索引导出的编号，避免了越界问题
	cout << "书籍编号：" << (*this).BookNo << '\t' << (*this).BookName << endl;
}

bool* Book::GetState()
{
	return &(*this).State;
}

int Book::GetBookNo()
{
	return (*this).BookNo;
}

string Book::GetBookName()
{
	return (*this).BookName;
}

Book::Book() 
{
	State = 1;
	BookNo = currentbook;
	currentbook++;
}

Book::Book(string bookname, string outline, string author, int booktype , string keywords_1=" ", string keywords_2=" ", string keywords_3= " ")
{
	BookName = bookname;
	Outline = outline;
	Author = author;
	Booktype = (enum type)booktype;
	Keywords[0] = keywords_1;
	Keywords[1] = keywords_2;
	Keywords[2] = keywords_3;
	State = 1;
	//自动编号
	BookNo = currentbook;
	currentbook++;
};

Book::~Book()
{
	//cout << BookNo << " " << BookName << " deleted" << endl;
}

void Book::ClearFile()
{
	ofstream ofile(Book::Filepath, ios::trunc);
	if (!ofile)
	{
		cout << "File open failed!" << endl;
	}
	ofile.close();
	cout << "书籍信息文件已清理" << endl;
}

#endif //!_BOOK
