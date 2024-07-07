/*********************************************
	Filename:Librarian.h
	Time:2024/7/6
	Author:Haoren wang
	Description:Librarian��Ķ���

**********************************************/

#include"Librarian.h"

//����Ա������Main.cpp������
//ͨ��д�ļ����Ĺ���Ա��Ϣ:Resetinfo()
void Librarian::Resetinfo()
{
	fstream outfile;
	outfile.open("C:\\Users\\10904\\Desktop\\BMS\\Librarian_textdata.txt", ios::out | ios::ate);

	//����ļ����Ƿ�ɹ�
	if (!outfile)
	{
		cout << "File open failed!" << endl;
		return;
	}

	Users Temp_Lib;	//������ʱLibrarian���Ͷ�����������Ҫ�޸ĵ��ļ�����

	//�ļ�ָ�붨λ���ļ���ͷ
	outfile.seekp(sizeof(Librarian), ios::beg);

	cin >> Temp_Lib;

	outfile.write((char*)&Temp_Lib, sizeof(Librarian));	//��ָ��λ��������ĺ�Ĺ���Ա��Ϣ,����Աֻ��һλ

	cout << "����Ա��Ϣ�޸ĳɹ�" << endl;

	outfile.close();
}

//���������������
std::istream& operator>>(istream& input, Librarian&Lib)
{
	cout << "�������Ա����:";
	input >> Lib.Librarian_Name;
	cout << "�������Ա�Ա�:";
	input >> Lib.Liibrarian_Sex;
	return input;
}

//��������������
std::ostream& operator<<(ostream& output, Librarian& Lib)
{
	output << "����Ա����:" << Lib.Librarian_Name << endl;
	output << "����Ա�Ա�:" << Lib.Liibrarian_Sex << endl;
	return output;
}