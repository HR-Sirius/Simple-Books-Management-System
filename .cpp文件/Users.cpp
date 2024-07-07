/*********************************************
	Filename:Users.h
	Time:2024/7/6
	Author:Haoren wang
	Description:Users��Ķ���

**********************************************/

#include "Users.h"

//ͨ�����ļ���ӡ�û���Ϣ:Getinfo()
void Users::Getinfo() const
{
	fstream infile;		//����fstream�����ʵ���ļ���Ϣ�Ľ���
	infile.open("C:\\Users\\10904\\Desktop\\BMS\\Users_testdata.txt", ios::in);		//ifile����Users_testdata.txt�ļ�

	//����ļ����Ƿ�ɹ�
	if (!infile)
	{
		cout << "File open failed!" << endl;
		return;
	}

	Users Temp_User;	 //������ʱUser���Ͷ������ڽ����ļ�����

	while(infile.eof() != 0)
	{
		infile.read((char*)&Temp_User, sizeof(Users));
		cout << "�û���Ϣ��";
		cout << endl << Temp_User;
	}

	infile.close();
}

//�û�������Main.cpp������
//ͨ��д�ļ������û���Ϣ:Resetinfo()
void Users::Resetinfo()
{
	fstream outfile;
	outfile.open("C:\\Users\\10904\Desktop\\BMS\\Users_testdata.txt", ios::out|ios::ate);

	//����ļ����Ƿ�ɹ�
	if (!outfile)
	{
		cout << "File open failed!" << endl;
		return;
	}

	int User_No;	//�����û���Ϣ���ļ��еĶ�λ,�û���Ϣ�Զ���������ʽ����,֮����Main.cpp�������ʾ�����û��������±�+�����ĺ���

	Users Temp_User;	//������ʱUser���Ͷ�����������Ҫ�޸ĵ��ļ�����

	cout << "�����û���ţ�";
	cin >> User_No;
	outfile.seekp(sizeof(Users)*(User_No-1), ios::beg);

	cin >> Temp_User;
	outfile.write((char*)&Temp_User, sizeof(Users));	//��ָ��λ��������ĺ���û���Ϣ

	cout << "�û���Ϣ�޸ĳɹ�" << endl;

	outfile.close();
}

//���������������
std::istream& operator>>(istream&input, Users&User)
{
	cout << "�����û�����:";
	input >> User.UserName;
	cout << "�����û��Ա�:";
	input >> User.Sex;
	return input;
}

//��������������
std::ostream& operator<<(ostream& output, Users& User)
{
	output << "�û�����:" << User.UserName << endl;
	output << "�û��Ա�:" << User.Sex << endl;
	return output;
}

Users::Users()
{
	cout << "Users constructor called." << endl;
}

Users::~Users()
{
	cout << "Users destructor called." << endl;
}