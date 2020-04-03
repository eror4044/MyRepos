#pragma once
#include"Lib.h"
#include "Humans.h"
#include "Buildings.h"
#include"Castle.h"
class Kingdom
{

public:
	int Day;
	Resorses treasures;
	string Name;
	Castle Castles;
	Humans Residents;
	Buildings build;
	int Coins;
	int Food;
	int ConstructionMaterials;
	int FriendlyIndex;
	int LevelOfevolution;
	Kingdom() {

		Day = 0;
		Coins = 5000;
		Food = 50;
		ConstructionMaterials = 50;
		FriendlyIndex = 0;
		LevelOfevolution = 1;
		Name = "NoName";
		
		
	}
	int getDay() {
		return Day;
	}
	void setday(int Day) {
		this->Day = Day;
	}
	int getCoins() {
		return Coins;
	}
	void setCoins(int Coins) {
		this->Coins = Coins;
	}
	int getFood() {
		return Food;
	}
	void setFood(int Food) {
		this ->Food = Food;
	}
	void setConstructionMaterials(int ConstructionMaterials) {
		this->ConstructionMaterials = ConstructionMaterials;
	}
	int getConstructionMaterials() {
		return ConstructionMaterials;
	}
	void setFriendlyIndex(int FriendlyIndex) {
		this->FriendlyIndex = FriendlyIndex;
	}
	int getFriendlyIndex() {
		return FriendlyIndex;
	}
	int getLevelOfevolution() {
		return LevelOfevolution;
	}
	void setLevelOfevolution(int LevelOfevolution) {
		this->LevelOfevolution = LevelOfevolution;
	}
	void setName(string Kingdomname) {
		
		Name = Kingdomname;
	}
	/*int getQuantityHumans() {
		return QuantityHumans;
	}
	void setQuantityHumans(int getQuantityHumans) {
		this->getQuantityHumans = getQuantityHumans;
	}*/
	string getName() {
		return Name;
	}
	
	void PrintKigdomInfo() {
		cout << "Королевство: " << getName()<<endl;
		cout << "Монеты:" <<getCoins()<<endl;
		cout << "Уровень королевства:" <<getLevelOfevolution()<<endl;
		cout << "Строительные материалы:" <<getConstructionMaterials()<<endl;
		cout << "Индекс дружелюбия:" <<getFriendlyIndex()<<endl;
		cout << "ресурсы:" << endl;
		cout << "рыба: " << treasures.fish << endl;
		cout << "камень: " << treasures.stone << endl;
		cout << "дерево: " << treasures.Tree << endl;
		cout << "строительные материалы: " << treasures.ConstructionMaterials << endl;
		cout << "мясо: " << treasures.meat<< endl;
	
	}
	//эта функция перематывает игру на день вперед по окончанию хода
	//на протяжении одного дня один житель 
	//сьедает 1 еденицу еды
	/*	-стареет на 1 день
		-приносит королевству доход в виде еденицы производимого товара на пример еды
		-если житель имеен класс воин или любой дочерний класс то он просто тратит 1 еду в день ничего при этом не производя
		-также все остальные королевства на карте тоже перематывают один день
		-каждое здание также стареет на один день по истечению срока службы оно приходит в негодность и требует починки
	каждый день королевство получает доход который складывается из 
		-индекса счастливости каждого человека(от этого зависит его продуктивности)
		-100 монет в день как фиксированый дневной доход
		-по 1 монете за кажждую добытую еденицу ресурсов(таким образом можно стимулировать рост)*/
	void EatHuman(vector<Humans> Humany) {
		Food -= Humany.size();
	}
	void ToNextDay(vector<Humans> Humany, vector <Buildings> Building) {
		Coins + 100;
		Residents.ToNextDay_ForHuman(Humany);
		EatHuman(Humany);
		Coins + Residents.CalculateMiningResorses(Humany);
		build.ToNextDayForBuiding(Building);

	}

	int GiveResorses_FROM_Buildings(vector <Buildings> Building) {
		for (int i = 0; i < Building.size(); i++)
		{
			if (Building[i].name == "sawmill")
			{
				treasures.Tree + Building[i].workers * 2;
			}
			else if (Building[i].name == "fishingpier") {
				treasures.fish + Building[i].workers * 2;
			}
			else if (Building[i].name == "farm") {
				treasures.fish + Building[i].workers * 2;
				treasures.meat + Building[i].workers * 2;
				treasures.FurmingCultures + Building[i].workers * 2;
			}

		}

	}
	void coutallhumans(vector<Humans> Humany) {
		for (int i = 0; i < Humany.size(); i++)
		{
			cout << "человек №: " << Humany[i].index << endl;
			cout << "возрвст: " << Humany[i].Age << endl;
			cout << "индекс благополучия: " << Humany[i].HappyIndex << endl;
			cout << "специализация: " << Humany[i].Specialization << endl;
		}
	}
	void coutallBuildings(vector<Buildings> Building) {
		for (int i = 0; i < Building.size(); i++)
		{
			cout << "здание №: " << Building[i].name << endl;
			cout << "возрвст: " << Building[i].age << endl;
			cout << "количество работников: " << Building[i].workers << endl;
		}
	}
	bool payFunktion(int cost) {
		
		if (cost>Coins)
		{
			cout << "не хватает монет!"; return false;
		}
		else
		{
			Coins -= cost;
		}

	}

	

};

