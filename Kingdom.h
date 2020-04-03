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
		cout << "�����������: " << getName()<<endl;
		cout << "������:" <<getCoins()<<endl;
		cout << "������� �����������:" <<getLevelOfevolution()<<endl;
		cout << "������������ ���������:" <<getConstructionMaterials()<<endl;
		cout << "������ ����������:" <<getFriendlyIndex()<<endl;
		cout << "�������:" << endl;
		cout << "����: " << treasures.fish << endl;
		cout << "������: " << treasures.stone << endl;
		cout << "������: " << treasures.Tree << endl;
		cout << "������������ ���������: " << treasures.ConstructionMaterials << endl;
		cout << "����: " << treasures.meat<< endl;
	
	}
	//��� ������� ������������ ���� �� ���� ������ �� ��������� ����
	//�� ���������� ������ ��� ���� ������ 
	//������� 1 ������� ���
	/*	-������� �� 1 ����
		-�������� ����������� ����� � ���� ������� ������������� ������ �� ������ ���
		-���� ������ ����� ����� ���� ��� ����� �������� ����� �� �� ������ ������ 1 ��� � ���� ������ ��� ���� �� ���������
		-����� ��� ��������� ����������� �� ����� ���� ������������ ���� ����
		-������ ������ ����� ������� �� ���� ���� �� ��������� ����� ������ ��� �������� � ���������� � ������� �������
	������ ���� ����������� �������� ����� ������� ������������ �� 
		-������� ������������ ������� ��������(�� ����� ������� ��� ��������������)
		-100 ����� � ���� ��� ������������ ������� �����
		-�� 1 ������ �� ������� ������� ������� ��������(����� ������� ����� ������������� ����)*/
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
			cout << "������� �: " << Humany[i].index << endl;
			cout << "�������: " << Humany[i].Age << endl;
			cout << "������ ������������: " << Humany[i].HappyIndex << endl;
			cout << "�������������: " << Humany[i].Specialization << endl;
		}
	}
	void coutallBuildings(vector<Buildings> Building) {
		for (int i = 0; i < Building.size(); i++)
		{
			cout << "������ �: " << Building[i].name << endl;
			cout << "�������: " << Building[i].age << endl;
			cout << "���������� ����������: " << Building[i].workers << endl;
		}
	}
	bool payFunktion(int cost) {
		
		if (cost>Coins)
		{
			cout << "�� ������� �����!"; return false;
		}
		else
		{
			Coins -= cost;
		}

	}

	

};

