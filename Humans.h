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
			cout << "�� ���������� ��������";
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

	//������������� ��� ������
	/*-� ������ ���� ���������� 10 ������� �� �������������� ������ ��� ������������� ������� ������� ������� ����� ����������� �������
	-������������� ���� ������ ������ ����� ������� ������ ��� �� �������� ������ ���� ���������� ������� ������ �� ���������� �
	������������ ������������� ��� ������� � ������ ���������
	-������������� ��������� ���������� ������������� ��� �������������� � ������� ������������� �� ������ ��� ���������� ����� ����� �� ��������
	*/
	/*	--�������� ������� create humans �������� �������� ������
		--�������� ������� tonextday ������� �������� ����(��������� ������������� ����� ������������� ������)
		--������� �� ��� ����������;*/
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
				cout << "�������" << index << "����!";
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
		int PlusCoins = 0;//������ �� ������ ������� �������� �������
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
