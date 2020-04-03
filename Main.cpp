#include "Lib.h"
#include "Kingdom.h"
using namespace std;

void coutMenu() {
	cout << "1 - посмотреть информацию о королевстве" << endl;
	cout << "2 - зайти в меню жителей" << endl;
	cout << "3 - зайти в меню зданий" << endl;
	cout << "4 - закончить ход" << endl;
	cout << "5 - выйти из игры";
}
void coutHumanMenu() {
	cout << "1 - вывести на экран всех жителей" << endl;
	cout << "2 - купить жителя" << endl;
	cout << "3 - дать специализацию жителю" << endl;
	cout << "4 - закончить ход" << endl;
	cout << "5 - выйти в основное меню";
}
void coutBuildingMenu() {
	cout << "1 - вывести на экран все здания" << endl;
	cout << "2 - построить здание" << endl;
	cout << "3 - продать здание" << endl;
	cout << "4 - закончить ход" << endl;
	cout << "5 - выйти в основное меню"<<endl;
}

int main()
{


	setlocale(LC_ALL, "rus");
	int Quontityhuman = 0;
	Kingdom myKingdom;
	Humans firstHuman;
	Resorses treasures;
	Buildings Build;
	vector<Humans> Humany;
	vector<Buildings> Building;
	vector<Resorses> treasuress;
	cout << "\t\t\t\tПоздравляю теперь тебе представился шанс управлять могуществонным" << endl;
	cout << "\t\t\t\t (или не очень) королевством теперь всё будет зависить от твоих решений" << endl;
	cout << "\t\t\t\tбудет твоё королевство процветать или придёт в упадок решать тебе" << endl;
	cout << "\t\t\t\tДа свершится история!!!!!!" << endl;
	cout << "\t\t\t\tвот информация о твоём королевствве\n\n" << endl;
	string name;
	string specialization;
	cout << "Давайте подберём подходящеее имя для нашего королевства (Введите имя): " << endl;
	cin >> name;
	myKingdom.setName(name);
	cout << "МЕНЮ" << endl;
	for (int i = 0; i < 20; i++)
	{
		firstHuman.CreateHuman(Humany);
	}


	int menu = 0;
	while (menu != 9)
	{
		coutMenu();
		cin >> menu;
		switch (menu)
		{
		case 1: {
			system("cls"); myKingdom.PrintKigdomInfo();	break; }
		case 2:
		{
			system("cls");
			while (menu != 5)
			{
				coutHumanMenu();
				cin >> menu;
				switch (menu)
				{
				case 1: { myKingdom.coutallhumans(Humany); break; }
				case 2: {
					if (myKingdom.payFunktion(50))
					{
						firstHuman.CreateHuman(Humany); break;
					}
					else
					{
						break;
					}
				}
				case 3:
				{
					cout << "специализации: \n";
					cout << "sawmill - лесник: \n";
					cout << "fishingpier - рыбак: \n";
					cout << "farm - фермер: \n";
					cout << "repairservice - ремонтник: \n";
					cin >> specialization;
					firstHuman.GiveSpecialization(Humany, specialization);
					break;
				}
				case 4:
				{
					myKingdom.ToNextDay(Humany, Building);
					cout << "день: " << myKingdom.Day;
					break;
				}
				case 5:
				{
					break;
				}



				}
				break;
			}
				case 3: {
					system("cls");
					while (menu != 5)
					{
						coutBuildingMenu();
						cin >> menu;
						switch (menu)
						{
						case 1: { myKingdom.coutallBuildings(Building); break; }
						case 2:
						{
							if (myKingdom.payFunktion(500))
							{
								int bmenu = 0;
								cout << "1 - построить лесопильню" << endl;
								cout << "2 - построить ферму" << endl;
								cout << "3 - построить рыболовный причал" << endl;
								cout << "4 - построить ремонтное здание" << endl;
								cin >> bmenu;
								
								switch (bmenu)
								{
								case 1:Build.CreateBuilding_sawmill(Building); break;
								case 2:Build.CreateBuilding_farm(Building); break;
								case 3:Build.CreateBuilding_fishingpier(Building); break;
								case 4:Build.CreateBuilding_repairservice(Building); break;
								}
							}
							else
							{
								break;
							}
						}
						
						case 3:
						{
							string Buildingname;
							cout << "Введите название здание которое хотите разрушить: " << endl;
							cin >> Buildingname;
							Build.BrokenBuilding(Building, Buildingname);
							break;
						}
						case 4:
						{
							myKingdom.ToNextDay(Humany, Building);
							cout << "день: " << myKingdom.Day;
							break;
						}
						case 5: {break; }



						}
						break;
					}
					break; }
				case 4: {
					myKingdom.ToNextDay(Humany, Building);
					cout << "день: " << myKingdom.Day;
					break; }
				case 5: {cout << "игра окончена" << endl; break; }
				


		}
		};



	}
}







