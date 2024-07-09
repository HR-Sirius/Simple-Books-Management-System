/*********************************************
	Filename:Book.cpp
	Time:2024/7/7
	Author:Haoren Wang
	Description:Book类的定义

**********************************************/

#include"Book.h"

void Book::Getinfo() const
{
	fstream infile;		//定义fstream类对象，实现文件信息的接收
	infile.open("C:\\Users\\10904\\Desktop\\BMS\\Books_testdata.txt", ios::in);		//infile关联Books_testdata.txt文件

	//检测文件打开是否成功
	if (!infile)
	{
		cout << "File open failed!" << endl;
		return;
	}

	Book Temp_Book;	 //定义临时User类型对象，用于接收文件内容

	while (infile.eof() != 0)
	{
		infile.read((char*)&Temp_Book, sizeof(Book));
		cout << "书籍信息：";
		cout << endl << Temp_Book;
	}

	infile.close();
}

//通过写文件更改书籍信息:Resetinfo()
void Book::Resetinfo()
{
	fstream outfile;
	outfile.open("C:\\Users\\10904\Desktop\\BMS\\Books_testdata.txt", ios::out | ios::ate);

	//检测文件打开是否成功
	if (!outfile)
	{
		cout << "File open failed!" << endl;
		return;
	}

	Book Temp_Book;	//定义临时User类型对象，用于输入要修改的文件内容

	int Book_No;

	cout << "输入书籍编号:";
	cin >> Book_No;

	outfile.seekp(sizeof(Book)*(Book_No-1), ios::beg);

	cin >> Temp_Book;
	outfile.write((char*)&Temp_Book, sizeof(Book));	//向指定位置输入更改后的书籍信息

	cout << "书籍信息修改成功" << endl;

	outfile.close();
}

//流输入运算符重载(1)
istream& operator>>(istream&input, Info&Info)
{
	cout << "输入书名：";
	input >> Info.BookName;
	cout << "输入作者姓名：";
	input >> Info.Author;
	cout << "输入简介：";
	input >> Info.Outline;
	cout << "输入书籍类型";
	input >> Info.Booktype;
	cout << "输入书籍关键词（至多三个）";
	input >> Info.Keywords[0] >> Info.Keywords[1] >> Info.Keywords[2];
	return input;
}

//流输入运算符重载(2)
istream& operator>>(istream&input, Book&Book)
{
	cout << "输入书籍编号:";
	input >> Book.BookNo;
	input >> Book.BookInfo;
	return input;
}

//流输入运算符重载(3)
istream& operator>>(istream&input, type&type)
{
	//将整型数强行转换为enum type类
	int type_Num;

	cout << endl << "书籍类型：suspense = 1, science = 2, fantasy = 3, romance = 4, criminal = 5, encyclopedia = 6" << endl << endl;

	cout << "输入书籍类型：";
	input >> type_Num;
	type = (enum type)type_Num;
	return input;
}


//流输出运算符重载(1)
ostream& operator<<(ostream&output, Info&Info)
{
	output << "书名：" << Info.BookName << endl;
	output << "作者姓名：" << Info.Author << endl;
	output << "简介：" << Info.Outline << endl;
	output << "书籍类型：" << Info.Booktype << endl;
	output <<"书籍关键词："<< Info.Keywords[0] << '\t' << Info.Keywords[1] << '\t' << Info.Keywords[2] << endl;
	return output;
}

//流输出运算符重载(2)
ostream& operator<<(ostream&output, Book&Book)
{
	output << "书籍编号：" << Book.BookNo << endl;
	output << Book.BookInfo << endl;
	output << "借阅状态：";
	if (Book.State)
		output << "可借出" << endl;
	else
		output << "已借出" << endl;
	return output;
}

//流输出运算符重载(3)
ostream& operator<<(ostream&output, type&type_Num)
{
	switch (type_Num)
	{
		case suspense:output << "suspense" << endl; break;
		case science:output << "science" << endl; break;
		case fantasy:output << "fantasy" << endl; break;
		case romance:output << "romance" << endl; break;
		case criminal:output << "criminal" << endl; break;
		default:cout << "encyclopedia" << endl;
	}
	return output;
}

//Book类构造函数
Book::Book()
{
	BookNo = currentbook;
	currentbook++;
}

void Book::Brief_Show(int No)
{
	//待添加[]重载函数，增加数组越界功能检测
	//待添加格式化功能，使编号均显示为三位数，如001，015
	cout << "书籍编号：" << No << '\t' << All_Books[No-1].BookInfo.BookName << endl;
}

bool* Book::GetState()
{
	return &(*this).State;
}

int* Book::GetBookNo()
{
	return &(*this).BookNo;
}

Info Book::GetBookInfo()
{
	return (*this).BookInfo;
}
