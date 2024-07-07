/*********************************************
	Filename:User.h
	Time:2024/7/4
	Author:Haoren Wang
	Description:������Book�������

**********************************************/

#ifndef _BOOK
#define _BOOK

#include"Management.h"


enum type
{
	suspense = 1, science = 2, fantasy = 3, romance = 4, criminal = 5, encyclopedia = 6
};

struct Info
{
	//����:BookName
	//���:Outline
	//����:Author
	//���:Booktype����ö���ඨ�壬Ĭ��ÿ����ֻ��һ������
	//�ؼ���:Keywords,�������
	char* BookName;
	char* Outline;
	char* Author;
	type Booktype;
	char* Keywords[3];
};

class Book :virtual public Management
{
public:
	//�޲ι��캯��Book(),�����鼮��Ϣͨ���ļ����룬���Կ��п��ޣ�������ʾ����
	//��������~Book(),��ʾ����(��֮���Ϊ����������)
	Book();
	~Book();
	
	//ͨ�����ļ���ȡ�鼮��Ϣ:Getinfo()
	//ͨ��д�ļ������鼮��Ϣ:Resetinfo()
	virtual void Getinfo() const;
	virtual void Resetinfo();

	//��������(����Ҫ����)����������������������ɣ���˼ƻ������������������ʱ�����������У���һ��ӡ
	void Search() const;


	//ÿ���޸�Ҫ�������룬֮���޸�Ϊ��ѡ���޸ĵĺ���
	//���������������(1)
	friend istream& operator>>(istream&, Info&);
	//���������������(2)
	friend istream& operator>>(istream&, Book&);
	//���������������(3)
	friend istream& operator>>(istream&, type&);

	//��������������(1)
	friend ostream& operator<<(ostream&, Info&);
	//��������������(2)
	friend ostream& operator<<(ostream&, Book&);
	//��������������(3)
	friend ostream& operator<<(ostream&, type&);
private:
	//BookInfoΪ�鼮����
	//BookNoΪ�鼮��ţ���1��ʼ��
	//����״̬;State,0�ѽ����1�ɽ���
	Info BookInfo;
	int BookNo;
	bool State;
};

#endif _BOOK
