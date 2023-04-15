//2 Разработка программы распределения мест в общежитии
//Для получения места в общежитии формируется писоск студентов,
// который включает : ФИО студента, номер группы(шесть цифр),средний балл, 
// участие в общественной деятельности, доход на одного члена семьи.
// Общежитие в первую очередь предоставляется тем студентам, чьи доходы 
// на члена семьи меньше двух минимальных зарплат, затем остальным
//  в порядке уменьшения среднего балла(при равных баллах приоритет отдается тем,
//  кто участвовал в общественной деятельности).
//Индивидуальное задание : вывести список очередности 
//предоставления места в общежитии при условии, что размер 
//минимальной зарплаты вводится с клавиатуры.Общее для всех вариантов задание : 
//реализовать авторизацию для входа в систему, функционал администратора и 
//функционал пользователя(см.более подробно в функциональных требованиях к курсовой 
//  работе, подраздел 1.2).
#include <iostream>


#include"User.h"
void GoToXY(short x, short y);
void ConsoleCursorVisible(bool show, short size);
void Color1();
void Color2();
void Color3();
void Color4();


void registration();
void authorization();
	
void overwritingFromFileToVector1();
void overwritingFromFileToVector2();
void overwritingFromVectorToFile();
	
void display();

void sortMenu();
void sortByScore();
void sortByActivityRating();
void sortByIncome();
void sortByMainInf();

void addStudents();
	
void searchMenu();
void searchName();
void searchNumber();
void searchScore();
void searchActivityRating();
void searchIncome();

vector <User> UserArr;
vector <student> StudentArr;

int main()
{
		overwritingFromFileToVector1();
        overwritingFromFileToVector2();
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		string choice_s;
		bool isCorrect = 0;
		string menu[] = { "Регистрация", "Авторизация", "Вывод" , "Сортировка","Поиск","Ввод студента","exit"};
		int active_menu = 0;
		while (isCorrect == 0)
		{

			int x = 50, y = 13;
			for (int i = 0; i < size(menu); i++) {
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
					registration();
					_getch();
					system("cls");
					break;
				case 1: {
					system("cls");
					authorization();
					_getch();
					system("cls");
				}
					  break;
				case 2:
					system("cls");
					display();
					_getch();
					system("cls");
					
					break;

				case 3: 
				{
			    system("cls");
				sortMenu();
				_getch();
			    system("cls");
				}
			     break;
				case 4:
				{
			    system("cls");
				searchMenu();
				_getch();
				system("cls");
								}
				break;
			    case 5: {
				system("cls");
				addStudents();
				system("cls");
			    }
			    break;
			    case 6: 
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
		overwritingFromVectorToFile();
		return 0;
}
		
	



