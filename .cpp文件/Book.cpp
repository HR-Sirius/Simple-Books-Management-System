/*********************************************
	Filename:Book.cpp
	Time:2024/7/7
	Author:Haoren Wang
	Description:Book��Ķ���

**********************************************/

#include"Book.h"

void Book::Getinfo() const
{
	fstream infile;		//����fstream�����ʵ���ļ���Ϣ�Ľ���
	infile.open("C:\\Users\\10904\\Desktop\\BMS\\Books_testdata.txt", ios::in);		//infile����Books_testdata.txt�ļ�

	//����ļ����Ƿ�ɹ�
	if (!infile)
	{
		cout << "File open failed!" << endl;
		return;
	}

	Book Temp_Book;	 //������ʱUser���Ͷ������ڽ����ļ�����

	while (infile.eof() != 0)
	{
		infile.read((char*)&Temp_Book, sizeof(Book));
		cout << "�鼮��Ϣ��";
		cout << endl << Temp_Book;
	}

	infile.close();
}

//ͨ��д�ļ������鼮��Ϣ:Resetinfo()
void Book::Resetinfo()
{
	fstream outfile;
	outfile.open("C:\\Users\\10904\Desktop\\BMS\\Books_testdata.txt", ios::out | ios::ate);

	//����ļ����Ƿ�ɹ�
	if (!outfile)
	{
		cout << "File open failed!" << endl;
		return;
	}

	Book Temp_Book;	//������ʱUser���Ͷ�����������Ҫ�޸ĵ��ļ�����

	int Book_No;

	cout << "�����鼮���:";
	cin >> Book_No;

	outfile.seekp(sizeof(Book)*(Book_No-1), ios::beg);

	cin >> Temp_Book;
	outfile.write((char*)&Temp_Book, sizeof(Book));	//��ָ��λ��������ĺ���鼮��Ϣ

	cout << "�鼮��Ϣ�޸ĳɹ�" << endl;

	outfile.close();
}

//���������������(1)
istream& operator>>(istream&input, Info&Info)
{
	cout << "����������";
	input >> Info.BookName;
	cout << "��������������";
	input >> Info.Author;
	cout << "�����飺";
	input >> Info.Outline;
	cout << "�����鼮����";
	input >> Info.Booktype;
	cout << "�����鼮�ؼ��ʣ�����������";
	input >> Info.Keywords[0] >> Info.Keywords[1] >> Info.Keywords[2];
	return input;
}

//���������������(2)
istream& operator>>(istream&input, Book&Book)
{
	cout << "�����鼮���:";
	input >> Book.BookNo;
	input >> Book.BookInfo;
	return input;
}

//���������������(3)
istream& operator>>(istream&input, type&type)
{
	//��������ǿ��ת��Ϊenum type��
	int type_Num;

	cout << endl << "�鼮���ͣ�suspense = 1, science = 2, fantasy = 3, romance = 4, criminal = 5, encyclopedia = 6" << endl << endl;

	cout << "�����鼮���ͣ�";
	input >> type_Num;
	type = (enum type)type_Num;
	return input;
}


//��������������(1)
ostream& operator<<(ostream&output, Info&Info)
{
	cout << "������";
	output << Info.BookName << endl;
	cout << "����������";
	output << Info.Author << endl;
	cout << "��飺";
	output << Info.Outline << endl;
	cout << "�鼮���ͣ�";
	output << Info.Booktype << endl;
	cout << "�鼮�ؼ��ʣ�";
	output << Info.Keywords[0] << '\t' << Info.Keywords[1] << '\t' << Info.Keywords[2] << endl;
	return output;
}

//��������������(2)
ostream& operator<<(ostream&output, Book&Book)
{
	cout << "�鼮��ţ�";
	output << Book.BookNo << endl;
	output << Book.BookInfo << endl;
	return output;
}

//��������������(3)
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

void Book::Search() const
{

}