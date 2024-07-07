/*********************************************
	Filename:Librarian.h
	Time:2024/7/6
	Author:Haoren wang
	Description:������Librarian�������

**********************************************/

#ifndef _LIBRARIAN
#define _LIBRARIAN

#include"Users.h"
#include"Book.h"

class Librarian:public Users
{
	//��Ҫ�õ�Book��ĺ���������Ϊ��Ԫ��
	friend Book;
public:
	//ͨ�����ļ���ӡ����Ա��Ϣ:Getinfo()
	//ͨ��д�ļ����Ĺ���Ա��Ϣ:Resetinfo()
	virtual void Getinfo();
	virtual void Resetinfo();

	//���������������
	friend std::istream& operator>>(istream&, Librarian&);
	//��������������
	friend std::ostream& operator<<(ostream&, Librarian&);

private:
	//Librarian_Name��¼ͼ�����Ա����
	//Liibrarian_Sex��¼ͼ�����Ա�Ա�
	char* Librarian_Name;
	char* Liibrarian_Sex;
};

#endif _LIBRARIAN