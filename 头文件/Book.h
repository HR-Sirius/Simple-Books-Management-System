/*********************************************
	Filename:User.h
	Time:2024/7/4
	Author:Haoren Wang
	Description:派生类Book类的声明、定义

**********************************************/

#ifndef _BOOK
#define _BOOK

#include"Management.h"

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
	Book() = default;
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
	int* GetBookNo();
	virtual void Getinfo(int) const;
	bool* GetState();
	virtual void Resetinfo(int);
	void Setinfo(int);

	//流输入运算符重载(1)
	friend istream& operator>>(istream&, type&);
	//流输入运算符重载(2)
	friend istream& operator>>(istream&, Book&);
	
	//流输出运算符重载(1)
	friend ostream& operator<<(ostream&, type&);
	//流输出运算符重载(2)
	friend ostream& operator<<(ostream&, Book&);
private:
	//BookNo为书籍编号（从001开始）
	//借阅状态;State,0已借出,1可借阅,初始状态默认可借阅
	//书名:BookName
	//简介:Outline
	//作者:Author
	//类别:Booktype，用枚举类定义，默认每本书只有一种类型
	//关键词:Keywords,最多三个
	int BookNo;
	bool State = 1;
	string BookName;
	string Outline;
	string Author;
	type Booktype;
	string Keywords[3];
};

//静态成员初始化
int Book::currentbook = 1;
string Book::Filepath = "C:\\Users\\10904\\Desktop\\BMS\\Books_testdata.txt";

//Book类全局对象数组
Book All_Books[10] =
{
	//Booktype Code:suspense = 1, science = 2, fantasy = 3, romance = 4, criminal = 5, encyclopedia = 6, adventure = 7, realism = 8
	Book("Harry Potter","A fantasy adventure","J.K Rowling",3,"Harry Potter","Wonderous","Magic"),
	Book("The Count of Monte Cristo","A righteous revenge","Dumas",7,"Adventure","Monte Cristo","Revenge"),
	Book("Four Generarions Under One Roof","The detailed description of the life of four generations of an ordinary family shows the great changes in Chinese society and the sufferings of the people during the War of Resistance against Japan","Lao she",8,"War of Resistance against Japanese Aggression","Beijing","Normal Life"),
	Book("Dou Po Cang Qiong","A teenager with excellent qualifications suddenly became a disrcard person, after experiencing the frustration of three consecutive years of stagnant abilities, he accidentally obtained the help of a mysterious soul named Yao Lao, thus opening a new road to cultivation.","Tian can tu dou",3,"Dou qi","Adventure","Fantasy"),
	Book("Zei Jing"," ","Xia Xie",5,"High-tech Crime","Justice","Humanity"),
	Book("The Lord of the Rings","Set in a fictional world called Middle-Earth, the story centers on a hobbit named Frodo Baggins, who inherits a powerful magic ring from his uncle Bilbo Baggins. This ring, forged by the dark Lord Sauron, has the power to enslave the entire world. In order to destroy the ring and save Middle-Earth from falling into darkness, Frodo and his friends form the Guardians of the Ring and embark on a journey full of danger and sacrifice.","J.R.R Tolkien",3,"Frindship and Unity","Power and Corruption","Bravery and Scrifice"),
	Book("Encyclopaedia Britannica","A globally recognized authoritative reference book"," ",6,"Technique","Literary","History"),
	Book("One Hundred Thousand whys","A set of popular science books featuring popular, small encyclopedic style"," ",2," "," "," "),
	Book("Romeo and Juliet","A timeless tragic play","Williams Shakespeare",4,"Love and tragedy","Shakespeare","Opera"),
	Book("Twenty Thousand Leagues Under the Sea","The story of the naturalist Professor Aronnax, his servant Consay, and the harpooner Ned Land, who accompany Nemo, captain of the submarine Nautilus, on an underwater expedition","Jules Gabriel Verne",7,"Ocean","Pioneering spirit"," ")
};

//流输入运算符重载(1)
istream& operator>>(istream& input, type& type)
{
	//将整型数强行转换为enum type类
	int type_Num;
	cout << endl << "书籍类型：suspense = 1, science = 2, fantasy = 3, romance = 4, criminal = 5, encyclopedia = 6,adventure = 7, realism = 8" << endl << endl;
	cout << "输入书籍类型：";
	input >> type_Num;
	type = (enum type)type_Num;
	return input;
}

//流输入运算符重载(2)
istream& operator>>(istream& input, Book& Book)
{
	cout << "输入书名：";
	input >> Book.BookName;
	cout << "输入作者姓名：";
	input >> Book.Author;
	cout << "输入书籍类型";
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
	case suspense:output << "suspense" << endl; break;
	case science:output << "science" << endl; break;
	case fantasy:output << "fantasy" << endl; break;
	case romance:output << "romance" << endl; break;
	case criminal:output << "criminal" << endl; break;
	default:cout << "encyclopedia" << endl;
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
	output << "书籍关键词：" << Book.Keywords[0] << '\t' << Book.Keywords[1] << '\t' << Book.Keywords[2] << endl;
	output << "借阅状态：";
	if (Book.State)
		output << "可借出" << endl;
	else
		output << "已借出" << endl;
	return output;
}


void Book::Setinfo(int No)
{
	//No从0开始
	fstream outfile;
	outfile.open("C:\\Users\\10904\\Desktop\\BMS\\Books_testdata.txt", ios::out | ios::app);

	//检测文件打开是否成功
	if (!outfile)
	{
		cout << "File open failed!" << endl;
		return;
	}

	//向指定位置输入更改后的书籍信息
	outfile << All_Books[No].BookName << endl
		<< All_Books[No].Author << endl
		<< All_Books[No].Keywords[0] << " " << All_Books[No].Keywords[1] << " " << All_Books[No].Keywords[2] << endl
		<< All_Books[No].Booktype << endl
		<< All_Books[No].Outline << endl;
	cout << "书籍" << No << "信息录入成功" << endl;

	outfile.close();
}

void Book::Getinfo(int No) const
{
	fstream infile;		//定义fstream类对象，实现文件信息的接收
	infile.open("C:\\Users\\10904\\Desktop\\BMS\\Books_testdata.txt", ios::in );		//infile关联Books_testdata.txt文件

	//检测文件打开是否成功
	if (!infile)
	{
		cout << "File open failed!" << endl;
		return;
	}

	//定义临时string、type类型变量，用于接收文件内容
	string Temp_BookName;
	string Temp_Author;
	string Temp_Keywords[3];
	string Temp_Outline;
	type Temp_BookType = (enum type)1;

	//文件指针重定位
	infile.seekp((sizeof(Book) * 6 + sizeof(type)) * No, ios::beg);
	infile >> Temp_BookName >> Temp_Author >> Temp_Keywords[0] >> Temp_Keywords[1] >> Temp_Keywords[2] >> Temp_BookType >> Temp_Outline;

	cout << "书籍名称:" << Temp_BookName << endl;
	cout << "作者:" << Temp_Author << endl;
	cout << "关键词:" << Temp_Keywords[0] << " " << Temp_Keywords[1] << " " << Temp_Keywords[2] << endl;
	cout << "类型:" << Temp_BookType << endl;
	cout << "简介:" << Temp_Outline << endl;

	infile.close();
	system("pause");
}

void Book::Resetinfo(int No)
{
	fstream outfile;
	outfile.open("C:\\Users\\10904\\Desktop\\BMS\\Books_testdata.txt", ios::out | ios::ate );

	//检测文件打开是否成功
	if (!outfile)
	{
		cout << "File open failed!" << endl;
		return;
	}

	Book Temp_Book;	//定义临时User类型对象，用于输入要修改的文件内容
	cin >> Temp_Book;

	outfile.seekp((sizeof(Book) * 6 + sizeof(type)) * No, ios::beg);
	outfile << Temp_Book.BookName <<" "
			<< Temp_Book.Author <<" "
			<< Temp_Book.Keywords[0]<< " " << Temp_Book.Keywords[1]<< " " << Temp_Book.Keywords[2] << " "
			<< Temp_Book.Booktype <<" "
			<< Temp_Book.Outline<<endl;	//向指定位置输入更改后的书籍信息

	cout << "书籍信息修改成功" << endl;

	outfile.close();
}

void Book::Brief_Show()
{
	//待添加[]重载函数，增加数组越界功能检测
	//待添加格式化功能，使编号均显示为三位数，如001，015
	cout << "书籍编号：" << (*this).BookNo << '\t' << All_Books[(*this).BookNo - 1].BookName << endl;
}

bool* Book::GetState()
{
	return &(*this).State;
}

int* Book::GetBookNo()
{
	return &(*this).BookNo;
}

string Book::GetBookName()
{
	return (*this).BookName;
}

Book::Book(string bookname, string outline, string author, int booktype =1, string keywords_1="	", string keywords_2="	", string keywords_3= "	")
{
	BookName = bookname;
	Outline = outline;
	Author = author;
	Booktype = (enum type)booktype;
	Keywords[0] = keywords_1;
	Keywords[1] = keywords_2;
	Keywords[2] = keywords_3;
	//自动编号
	BookNo = currentbook;
	currentbook++;
};

Book::~Book()
{
	cout << "Book destructor called." << endl;
}

void Book::ClearFile()
{
	ofstream ofile(Book::Filepath, ios::trunc);
	if (!ofile)
	{
		cout << "File open failed!" << endl;
	}
	ofile.close();
	cout << "文件已清理" << endl;
}

#endif //!_BOOK
