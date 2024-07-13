#include"Users.h"
#include"Book.h"
#include"Librarian.h"

int main()
{
	int i = 0;
	//将All_Users[10],All_Books[10]保存到对应文件中
	for (i = 0; i < 10; i++)
	{
		All_Users[i].Setinfo(i);
	}
	for (i = 0; i < 10; i++)
	{
		All_Books[i].Setinfo(i);
	}
	//程序暂停一秒再运行
	std::chrono::seconds sec(1);
	std::this_thread::sleep_for(sec);
	system("cls");

	string Name;
	//记录登录状态
	bool is_login = false;
	//输入用户名以确定对象
	while (!is_login)
	{
		cout << "输入用户名：";
		cin >> Name;
		for (i = 0; i < 10; i++)
		{
			if (!Name.compare(All_Users[i].GetName()))
			{
				is_login = true;
				break;
			}
			if (i == 9)
			{
				cout << "未查找到该用户" << endl;
				cout << "按任意键继续..." << endl;
				cin.get();
			}
		}
	}

	//记录指令
	int command_code = 1;
	while (command_code != 0)
	{
		//显示用户菜单界面
		All_Users[i].Showmenu();
		cout << "输入功能代码：";
		cin >> command_code;
		switch (command_code)
		{
		case 1: 
			{
				int No;
				if (All_Users[i].Search())
				{
					cout << "输入书籍编号查看详细信息:";
					cin >> No;
					All_Books[No - 1].Getinfo(No - 1);
				}
				system("pause");
				break;
			}
		case 2:All_Users[i].Borrow(); system("pause"); break;
		case 3:All_Users[i].Return(); system("pause"); break;
		case 4:All_Users[i].Showhistory(); system("pause"); break;
		case 5:All_Users[i].Showborrowing(); system("pause"); break;
		case 6:All_Users[i].Getinfo(i); system("pause"); break;
		case 7:All_Users[i].Show_top_Books(); system("pause"); break;
		case 8:All_Users[i].Show_top_Users(); system("pause"); break;
		case 9:All_Users[i].Resetinfo(i); system("pause"); break;
		case 0:cout << "您已退出图书管理系统" << endl; system("pause"); break;
		default:break;
		}
	}

	//清空文件
	Users::ClearFile();
	Book::ClearFile();
	return 0;
}
