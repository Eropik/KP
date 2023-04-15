#include "User.h"
#include"lib.h"
void GoToXY(short x, short y);
void ConsoleCursorVisible(bool show, short size);
void Color1();
void Color2();
void Color3();
void Color4();

void authorization()
{
	string login;
	string password;
	bool isLogged = 0;
	bool isLogCorrect = 0;
	bool isPassCorrect = 1;
	char choise = 0;
	string garbage;
	int i;
	cout << "������� �����" << endl;
	getline(cin, login);
	for (i = 0; i < UserArr.size(); i++)
	{
		if (UserArr[i].login == login)
		{
			isLogCorrect = 1;
			cout << "������� ������" << endl;
			cin >> password;
			getchar();
			if (password == UserArr[i].password)
			{
				cout << "����� ����������, " << UserArr[i].login << "!" << endl;
				isLogged = 1;
				break;
			}
			else
			{
				cout << "�������� ������" << endl;
				isPassCorrect = 0;
				break;
			}
		}
	}
	if (!isLogCorrect)
		cout << "������������ � ����� ������ �� ���������������" << endl;
	if (!isLogCorrect || !isPassCorrect)
	{

		while (choise != '2')
		{
			cout << "1.�����" << endl;
			cout << "2.��������� � ����" << endl;
			choise = getchar();
			getline(cin, garbage);
			if (garbage == "")
			{
				switch (choise)
				{
				case'1':
					authorization();
				case'2':
					break;
				default:
					cout << "������ �������� �����" << endl;
					break;
				}
			}
			else
			{
				cout << "������� ������ ����� ����" << endl;
				choise = 0;
			}
		}
	}
}
void registration()
{
	string login;
	string password;
	string space;
	ofstream fout("accounts.txt", ios::app);
	while (1)
	{
		bool isCorrect = 1;
		cout << "������� �����" << endl;
		getline(cin, login);
		for (int i = 0; i < UserArr.size(); i++)
		{
			if (UserArr[i].login == login)
			{
				cout << "������������ � ����� ������ ��� ���������������" << endl;
				isCorrect = 0;
				break;
			}
		}
		if (isCorrect == 1)
			break;
	}
	while (1)
	{
		cout << "������� ������" << endl;
		cin >> password;
		getline(cin, space);
		if (space != "")
			cout << "������ �� ������ ��������� ��������" << endl;
		else if (size(password) < 8)
			cout << "������ ������ ��������� �� ����� 8 ��������" << endl;
		else
			break;


	}
	UserArr.push_back({ login,password,0,0 });
	fout << login << endl;
	fout << password << endl;
	fout << 0 << endl;
	fout << 0 << endl;
	cout << "�� ������� ������������������!" << endl;
}

void overwritingFromFileToVector1()
{
	ifstream fin("accounts.txt");
	string login;
	string password;
	bool isAdmin = 0;
	bool isBanned = 0;
	if (!fin.is_open())
		cout << "�� ������� ������� ����" << endl;
	else
	{
		while (!fin.eof())
		{
			fin >> login;
			fin >> password;
			fin >> isAdmin;
			fin >> isBanned;
			UserArr.push_back({ login,password,isAdmin,isBanned });
		}
	}
	fin.close();
}
void overwritingFromFileToVector2()
{
	ifstream fin("users.txt");
	string name;
	int number;
	float score;
	float activityRating;
	float income;
	if (!fin.is_open())
		cout << "�� ������� ������� ����" << endl;
	else
	{
		while (fin >> name)
		{
			
			fin >> number;
			fin >> score;
			fin >> activityRating;
			fin >> income;
			StudentArr.push_back({ name,number,score,activityRating,income});
		}
	}
	fin.close();
}
void overwritingFromVectorToFile()
{
		fstream fos("users.txt", fstream::out);
		if (!fos.is_open())
			cout << "�� ������� ������� ����" << endl;
		else
		{
			for (int i = 0; i < StudentArr.size(); i++) 
			{
				fos << StudentArr[i].name << endl;
				fos << StudentArr[i].number << endl;
				fos << StudentArr[i].score << endl;
				fos << StudentArr[i].activityRating << endl;
				fos << StudentArr[i].income << endl;
			}
		}
		fos.close();
}

void addStudents() 
{
	bool isRight = 0;
	student t;
	cout << "������� ��� ��������:";
	getline(cin, t.name);
	
	while (isRight == 0)
	{
		cout << "������� ����� ������ �������� (6 ����):";
		cin >> t.number;
		if (t.number < 0)
			cout << "����� ������ ������ �����������. ����� �� ����� ���� �������������." << endl;
		else if ( t.number>999999)
			cout << "����� ������ ������ �����������. ����� �� ����� ��������� ����� 6 ����." << endl;
		else isRight = 1;
	}
	isRight = 0;
	
	while (isRight == 0)
	{
		cout << "������� ������� ���� ��������:";
		cin >> t.score;
		if (t.score < 0)
			cout << "������� ���� ������ �����������. �������� �� ����� ���� �������������." << endl;
		else if (t.score > 10)
			cout << "������� ���� ������ �����������. �������� �� ����� ���� ������ 10." << endl;
		else isRight = 1;
	}
	isRight = 0;
	
	while (isRight == 0) 
	    {
			cout << "������� ������� ���������� ��������:";
		cin >> t.activityRating;
		if (t.activityRating < 0 )
			cout << "������� ���������� ������ �����������. �������� �� ����� ���� �������������." << endl;
		else if (t.activityRating > 100)
			cout << "������� ���������� ������ �����������. �������� �� ����� ���� ������ 100." << endl;
		else isRight = 1;
	    }
	isRight = 0;
	
	while (isRight == 0)
	{
		cout << "������� ����� �� ������ ����� �����:";
		cin >> t.income;
		if (t.income < 0)
			cout << "����� ������ �����������. �������� �� ����� ���� �������������." << endl;
		else isRight = 1;
	}
	isRight = 0;

	StudentArr.push_back(t);
}

void display() {
	int i = 0;
	for (; i < StudentArr.size(); i++)
		cout << StudentArr[i].name << "," << StudentArr[i].number << "," << StudentArr[i].score
		<< "," << StudentArr[i].activityRating << "," << StudentArr[i].income << endl;

}

void sortByScore()
{
	for (int j = 0; j < StudentArr.size(); j++)
		for (int i = 0; i < StudentArr.size() - 1; i++)
			if (StudentArr[i].score < StudentArr[i + 1].score)
				swap(StudentArr[i + 1], StudentArr[i]);
}
void sortByActivityRating()
{
	for (int j = 0; j < StudentArr.size(); j++)
		for (int i = 0; i < StudentArr.size() - 1; i++)
			if (StudentArr[i].activityRating < StudentArr[i + 1].activityRating)
				swap(StudentArr[i + 1], StudentArr[i]);
}
void sortByIncome()
{
	for (int j = 0; j < StudentArr.size(); j++)
		for (int i = 0; i < StudentArr.size() - 1; i++)
			if (StudentArr[i].income > StudentArr[i + 1].income)
				swap(StudentArr[i + 1], StudentArr[i]);
}
void sortByMainInf()
{
	int a = 0;
	int minIncome = 0;
	cout << "B������ �������� ����������� ���������� �����:" << endl;
	cin >> minIncome;
	sortByIncome();
	minIncome *= 2;
	if (minIncome <= 0)
		cout << "������� ��������." << endl;
	else {
		for (int i = 0; minIncome > StudentArr[i].income; i++, a++);
	}
	for (int j = 0; j < StudentArr.size(); j++)
		for (a; a < StudentArr.size() - 1; a++)
			if (StudentArr[a].score * 0.9 + StudentArr[a].activityRating * 0.1 < StudentArr[a + 1].score * 0.9 + StudentArr[a + 1].activityRating * 0.1)
				swap(StudentArr[a + 1], StudentArr[a]);
}
void sortMenu()
{
	string choice_s;
	bool isCorrect = 0;
	string menu[] = { "����������� �� �������� �����", "����������� �� �������� ����������","����������� �� ������ �� ������ ����� �����","������������� �� ����������� ��������� ����� � ����������","����� ������ ���������","exit" };
	int active_menu = 0;
	while (isCorrect == 0)
	{

		int x = 50, y = 13;
		for (int i = 0; i < size(menu); i++)
		{
			if (i == active_menu)
				Color1();
			else Color3();
			if (i == size(menu) - 1)
				GoToXY(x, y += 2);
			else
				GoToXY(x, y++);
			cout << menu[i] << endl;
		}
		GoToXY(x, y++);

		char ch = _getch();
		if (ch == -32) ch = _getch();
		switch (ch)
		{
		case UP:
		{
			if (active_menu > 0)
				--active_menu;
		}
		break;
		case DOWN: {
			if (active_menu < size(menu) - 1)
				++active_menu;
		}
				 break;
		case ENTER:
			switch (active_menu)
			{
			case 0:
				system("cls");
				sortByScore();
				_getch();
				system("cls");
				break;
			case 1: {
				system("cls");
				sortByActivityRating();
				_getch();
				system("cls");
			}
				  break;
			case 2:
				system("cls");
				sortByIncome();
				_getch();
				system("cls");

				break;

			case 3:
			{
				system("cls");
				sortByMainInf();
				_getch();
				system("cls");
			}
			break;
			case 4:
			{
				system("cls");
				display();
				_getch();
				system("cls");

			}
			break;

			case 5:
			{
				Color3();
				system("cls");
				isCorrect = 1;
			}
			break;
			}
			break;
		}
	}

}

void searchName()
{
	bool isRight = 0;
	bool first = 1;
	int numOfResult = 0;
	string search;
	cout << "������� ������ ��� ������: ";
	cin >> search;
	for (int i = 0; i < StudentArr.size(); i++)
	{
		if (StudentArr[i].name.find(search) != string::npos)
		{
			if (first == 1)
			{

				first = 0;
			}
			cout << " ���:" << StudentArr[i].name <<
				"; ������:" << StudentArr[i].number <<
				"; ������� ����:" << StudentArr[i].score <<
				"; ������� ����������:" << StudentArr[i].activityRating <<
				"; ����� �� ������ ����� �����:" << StudentArr[i].income << endl;
			numOfResult++;
		}

	}


	if (numOfResult == 0)
		cout << "�� ������ ������� ������ �� �������" << endl;

	system("pause");

}
void searchNumber()
{
	bool isRight = 0;
	int numOfResult = 0;
	int search;

	while (isRight == 0)
	{
		cout << "������� ��� ������ ����� ������ �������� (6 ����): ";
		cin >> search;
		if (search < 0)
			cout << "����� ������ ������ �����������. ����� �� ����� ���� �������������." << endl;
		else if (search > 999999)
			cout << "����� ������ ������ �����������. ����� �� ����� ��������� ����� 6 ����." << endl;
		else isRight = 1;
	}
	isRight = 0;

	for (int i = 0; i < StudentArr.size(); i++)
	{
		if (StudentArr[i].number == search)
		{
			cout << " ���:" << StudentArr[i].name <<
				"; ������:" << StudentArr[i].number <<
				"; ������� ����:" << StudentArr[i].score <<
				"; ������� ����������:" << StudentArr[i].activityRating <<
				"; ������� ����������:" << StudentArr[i].income << endl;
			numOfResult++;
		}
	}


	if (numOfResult == 0)
		cout << "�� ������ ������� ������ �� �������" << endl;

	system("pause");

}
void searchScore()
{
	bool isRight = 0;
	bool first = 1;
	int numOfResult = 0;
	float search;

	while (isRight == 0)
	{
		cout << "������� ������� ���� �������� ��� ������: ";
		cin >> search;
		if (search < 0)
			cout << "������� ���� ������ �����������. �������� �� ����� ���� �������������." << endl;
		else if (search > 10)
			cout << "������� ���� ������ �����������. �������� �� ����� ���� ������ 10." << endl;
		else isRight = 1;
	}
	isRight = 0;
	for (int i = 0; i < StudentArr.size(); i++)
	{
		if (StudentArr[i].score == search)
		{
			if (first == 1)
			{

				first = 0;
			}
			cout << " ���:" << StudentArr[i].name <<
				"; ������:" << StudentArr[i].number <<
				"; ������� ����:" << StudentArr[i].score <<
				"; ������� ����������:" << StudentArr[i].activityRating <<
				"; ������� ����������:" << StudentArr[i].income << endl;
			numOfResult++;
		}
	}


	if (numOfResult == 0)
		cout << "�� ������ ������� ������ �� �������" << endl;

	system("pause");

}
void searchActivityRating()
{
	bool isRight = 0;
	bool first = 1;
	int numOfResult = 0;
	float search;

	while (isRight == 0)
	{
		cout << "������� ������� ���������� ��� ������: ";
		cin >> search;
		if (search < 0)
			cout << "������� ���������� ������ �����������. �������� �� ����� ���� �������������." << endl;
		else if (search > 100)
			cout << "������� ���������� ������ �����������. �������� �� ����� ���� ������ 100." << endl;
		else isRight = 1;
	}
	isRight = 0;


	for (int i = 0; i < StudentArr.size(); i++)
	{
		if (StudentArr[i].activityRating == search)
		{
			if (first == 1)
			{

				first = 0;
			}
			cout << " ���:" << StudentArr[i].name <<
				"; ������:" << StudentArr[i].number <<
				"; ������� ����:" << StudentArr[i].score <<
				"; ������� ����������:" << StudentArr[i].activityRating <<
				"; ������� ����������:" << StudentArr[i].income << endl;
			numOfResult++;
		}

	}


	if (numOfResult == 0)
		cout << "�� ������ ������� ������ �� �������" << endl;

	system("pause");

}
void searchIncome()
{
	bool isRight = 0;
	string name;
	bool first = 1;
	int length = 104;
	int numOfResult = 0;
	float search;
	while (isRight == 0)
	{
		cout << "������� ����� �� ������ ����� ����� ��� ������: ";
		cin >> search;
		if (search < 0)
			cout << "����� ������ �����������. �������� �� ����� ���� �������������." << endl;
		else isRight = 1;
	}

	isRight = 0;
	for (int i = 0; i < StudentArr.size(); i++)
	{
		if (StudentArr[i].income == search)
		{
			if (first == 1)
			{

				first = 0;
			}
			cout << " ���:" << StudentArr[i].name <<
				"; ������:" << StudentArr[i].number <<
				"; ������� ����:" << StudentArr[i].score <<
				"; ������� ����������:" << StudentArr[i].activityRating <<
				"; ������� ����������:" << StudentArr[i].income << endl;
			numOfResult++;
		}

	}


	if (numOfResult == 0)
		cout << "�� ������ ������� ������ �� �������" << endl;

	system("pause");

}
void searchMenu()
{
	string choice_s;
	bool isCorrect = 0;
	string menu[] = { "����� �� �����", "����� �� ������", "����� �� �������� �����" , "����� �� �������� ����������","����� �� ������ �� ������ ����� �����","exit" };
	int active_menu = 0;
	while (isCorrect == 0)
	{

		int x = 50, y = 13;
		for (int i = 0; i < size(menu); i++)
		{
			if (i == active_menu)
				Color1();
			else Color3();
			if (i == size(menu) - 1)
				GoToXY(x, y += 2);
			else
				GoToXY(x, y++);
			cout << menu[i] << endl;
		}
		GoToXY(x, y++);

		char ch = _getch();
		if (ch == -32) ch = _getch();
		switch (ch)
		{
		case UP:
		{
			if (active_menu > 0)
				--active_menu;
		}
		break;
		case DOWN: {
			if (active_menu < size(menu) - 1)
				++active_menu;
		}
				 break;
		case ENTER:
			switch (active_menu)
			{
			case 0:
			{
			system("cls");
			searchName();
			_getch();
			system("cls");
			}
			break;
			case 1: 
			{
			system("cls");
			searchNumber();
			_getch();
			system("cls");
			}
			break;
			case 2:
			system("cls");
			searchScore();
			_getch();
			system("cls");
			break;
			case 3:
			{
			system("cls");
			searchActivityRating();
			_getch();
			system("cls");
			}
			break;
			case 4:
			{
			system("cls");
			searchIncome();
			_getch();
			system("cls");
			}
			break;
			case 5:
			{
			Color3();
			system("cls");
			isCorrect = 1;
			}
			break;
		    }
			break;
		}
	}

}

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void GoToXY(short x, short y)
{
	SetConsoleCursorPosition(hStdOut, { x, y });
}

void ConsoleCursorVisible(bool show, short size)
{
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = show;
	structCursorInfo.dwSize = size;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}

void Color1() 
{
	SetConsoleTextAttribute(hStdOut, 5|712);
}

void Color2() 
{
	SetConsoleTextAttribute(hStdOut, 12|12);
}

void Color3() 
{
	SetConsoleTextAttribute(hStdOut, 12);
}

void Color4() 
{
	SetConsoleTextAttribute(hStdOut, 12);
}
