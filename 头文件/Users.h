/*********************************************
	Filename:Users.h
	Time:2024/7/6
	Author:Haoren wang
	Description:������Users�������

**********************************************/

#ifndef _USERS
#define _USERS

#include "Management.h"
#include "Lend.h"

class Users :virtual public Management
{
public:
	//�޲ι��캯��User(),�����û���Ϣͨ���ļ����룬���Կ��п��ޣ�������ʾ����
	//��������~Users(),��ʾ����(��֮���Ϊ����������)
	Users();
	~Users();

	//ͨ�����ļ���ӡ�û���Ϣ:Getinfo()
	//ͨ��д�ļ������û���Ϣ:Resetinfo()
	virtual void Getinfo() const;
	virtual void Resetinfo();

	//���������������
	friend std::istream& operator>>(istream&, Users&);
	//��������������
	friend std::ostream& operator<<(ostream&, Users&);
private:
	//UserName��¼�û�����
	//Sex��¼�û��Ա�
	//History���ַ�����¼������ʷ
	char* UserName;
	char* Sex;
	char* History[5];
};
#endif _USERS