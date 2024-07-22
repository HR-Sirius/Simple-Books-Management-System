#include"Users.h"
#include"Book.h"
#include"Librarian.h"

int main()
{
	int i = 0;
	//防止调试非正常退出导致文件未清空，先调用清空文件函数
	Users::ClearFile();
	Book::ClearFile();
	Librarian::ClearFile();

	cout << endl;
	//将All_Users,All_Books,LibManagerxinxi保存到对应文件中
	for (i = 0; i < All_Users.size(); i++)
	{
		All_Users[i].Setinfo(i);
	}
	cout << endl;
	for (i = 0; i < All_Books.size(); i++)
	{
		All_Books[i].Setinfo();
	}
	cout << endl;
	LibManager.Setinfo();
	//程序暂停一秒再运行
	std::chrono::seconds sec(1);
	std::this_thread::sleep_for(sec);
	system("cls");

	string Name;
	//身份代码
	int Identity_code = 1;
	//登录状态
	bool is_login = false;
	//是否退出
	bool is_exit = false;
	//记录指令
	int command_code = 1;
	cout << "Notice:" << "管理员姓名为John,可进入管理员界面查看用户列表" << endl;
	while (!is_exit)
	{
		command_code = 1;
		is_login = false;
		//输入身份代码以确定身份
		cout << "请选择您的身份:" << endl;
		cout << "      0.管理员" << endl;
		cout << "      1.用户" << endl;
		cin >> Identity_code;
		cin.ignore();
		while (Identity_code != 1&&Identity_code != 0)
		{
			cout << "重新输入:";
			cin >> Identity_code;
			cin.ignore();
		}
		if (Identity_code == 0)
		{
			while (!is_login)
			{
				cout << "输入管理员姓名:";
				cin >> Name;
				if (!Name.compare(LibManager.GetName()))
				{
					is_login = true;
				}
				else
				{
					cout << "未查找到该管理员" << endl;
					cout << "按任意键继续..." << endl;
					cin.get();
				}
			}

			while (command_code != 0)
			{
				//显示管理员操作界面
				LibManager.Showmenu();
				cout << "输入功能代码：";
				cin >> command_code;
				switch (command_code)
				{
				case 1:LibManager.Add_Book(); system("pause"); break;
				case 2: {
							int No;
							if (LibManager.Search())
							{
								cout << "输入书籍编号查看详细信息:";
								cin >> No;
								All_Books[No - 1].Getinfo(No - 1);
							}
							system("pause"); 
							break; 
						}
				case 3:LibManager.Del_Book(); system("pause"); break;
				case 4:LibManager.DisplayAllBooks(); system("pause"); break;
				case 5:LibManager.ShowAllborrow(); system("pause"); break;
				case 6:LibManager.Add_User(); system("pause"); break;
				case 7:LibManager.DisplayAllUsers(); system("pause"); break;
				case 0:cout << "您已退出登录" << endl; system("pause"); break;
				default:break;
				}
			}
		}
		else
		{
			//输入用户名以确定对象
			while (!is_login)
			{
				cout << "输入用户名：";
				cin >> Name;
				for (i = 0; i < All_Users.size(); i++)
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
				case 0:cout << "您已退出登录" << endl; system("pause"); break;
				default:break;
				}
			}
		}
		cout << "是否退出图书管理系统？ 0否，1是" << endl;
		cin >> is_exit;
		cin.ignore();
		while (is_exit != 1 &&is_exit != 0)
		{
			cout << "重新输入:";
			cin >> is_exit;
			cin.ignore();
		}
		system("cls");
	}
	cout << "欢迎下次使用" << endl << endl;

	std::chrono::seconds wait(1);
	std::this_thread::sleep_for(wait);

	//清空文件
	Users::ClearFile();
	Book::ClearFile();
	Librarian::ClearFile();
	return 0;
}
