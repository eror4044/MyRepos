#pragma once
#include "Lib.h"
#include "Buildings.h"
#include "Kingdom.h"
class Resorses
{
public:
	int Tree;
	int FurmingCultures;
	int fish;
	int stone;
	int meat;
	int ConstructionMaterials;

	Resorses() {
		Tree = 0;
		FurmingCultures = 0;
		fish = 0;
		stone = 0;
		meat = 0;
		ConstructionMaterials = 0;
	}
	void CreateConstructionMaterials(vector<Resorses> treasures) {
		if (Tree > 2 || stone > 2 || meat > 2) {
			treasures[0].Tree - 2;
			treasures[0].stone - 2;
			treasures[0].meat - 2;
			ConstructionMaterials++;
		}
		else
		{
			cout << "Ќе достаточно –есурсов";
		}
	}
	


};


class Humans
{
public:
	int Age;
	int HappyIndex;
	string Specialization;
	int index;

	//—пециализации дл€ жител€
	/*-¬ начале игры по€вл€етс€ 10 жителей со специализацией житель это универсалина€ рабоча€ еденица котора€ может производить ресурсы
	-—пециализаци€ воин любого жител€ можно сделать воином это не обратимо каждый воин потребл€ет ресурсы ничего не производит и
	используетс€ исключительно дл€ обороны в случае нападени€
	-—пециализаци€ посланник существует исключительно дл€ взаимодействи€ с другими королевствами на пример дл€ заключени€ союза также не обратимо
	*/
	/*	--дописать функцию create humans дописать дочерние классы
		--написать функцию tonextday описать механику игры(нападени€ распределени€ людей строительство зданий)
		--напсать ии дл€ противника;*/
	Humans() {
		index = 0;
		Age = 0;
		HappyIndex = 0;
		Specialization = "NoSpez";

	}
	
	
	void CreateHuman(vector<Humans> Humany) {
		
			Humans Resident;
			Resident.index = Humany.size();
			Humany.push_back(Resident);
		
	}
	void KillHuman(vector<Humans> Humany) {
		auto iter = Humany.cbegin();
		for (int i = 0; i < Humany.size(); i++)
		{
			if (Humany[i].Age > 30)
			{
				Humany.erase(iter + i);
				cout << "человек" << index << "умер!";
			}
		}
	}
	
	void ToNextDay_ForHuman(vector<Humans> Humany) {
		for (int i = 0; i < Humany.size(); i++)
		{
			Humany[i].Age++;
			if (Humany[i].Age > 100)
			{
				Humany[i].KillHuman(Humany);
			}
		}
	}

	int CalculateMiningResorses(vector<Humans> Humany) {
		int PlusCoins = 0;//монеты за каждую еденицу добытого ресурса
		for (int i = 0; i < Humany.size(); i++)
		{
			if (Humany[i].Specialization == "NoSpez")
			{
				continue;
			}
			else
			{
				PlusCoins++;
			}
		}
	}

	void GiveSpecialization(vector<Humans> Humany, string specialization) {
		for (int i = 0; i < Humany.size(); i++) {
			if (Humany[i].Specialization == "NoSpez")
			{
				Humany[i].Specialization = specialization;
			}
		}
	}
	
};

//
//class Warrior : public Humans
//{
//public:
//	
//
//
//};
//class Spy : public Warrior
//{
//
//public:
//
//
//
//};
//class lumberjack : public Humans
//{
//
//public:
//
//
//
//};
//class herder : public Humans
//{
//
//public:
//
//
//
//};
