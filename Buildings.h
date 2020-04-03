#pragma once
#include "Lib.h"
#include "Humans.h"
#include "Kingdom.h"
class Buildings
{
public:
	int index;
	int age;
	int workers;
	string name;

	Buildings() {
		name = "none";
		workers = 0;
		index = 0;
		age = 0;
	};
	void CreateBuilding_sawmill(vector <Buildings> Building) {
		
			Buildings sawmill;
			sawmill.name = "sawmill";
			sawmill.index = Building.size();
			Building.push_back(sawmill);
		
	}
	
	void CreateBuilding_fishingpier(vector <Buildings> Building) {
		
			Buildings fishingpier;
			fishingpier.name = "fishingpier";
			fishingpier.index = Building.size();
			Building.push_back(fishingpier);
		
	}
	void CreateBuilding_farm(vector <Buildings> Building) {
		
			Buildings farm;
			farm.name = "farm";
			farm.index = Building.size();
			Building.push_back(farm);
		
	}
	void CreateBuilding_repairservice(vector <Buildings> Building) {
		
			Buildings repairservice;
			repairservice.name = "repairservice";
			repairservice.index = Building.size();
			Building.push_back(repairservice);
		
	}
	

	void BrokenBuilding(vector <Buildings> Building,string name) {
		auto iter = Building.cbegin();
		for (int i = 0; i < Building.size(); i++)
		{
			if (Building[i].name == name)
			{
				Building.erase(iter+i);
				cout<<"сдание"<<name<<"было разрушено!";
			}
		}
	}
	void BrokenBuildingPerTime(vector <Buildings> Building) {
		auto iter = Building.cbegin();
		for (int i = 0; i < Building.size(); i++)
		{
			if (Building[i].age > 30)
			{
				Building.erase(iter + i);
			
			}
		}
	}
	void ToNextDayForBuiding(vector <Buildings> Building) {
		for (int i = 0; i < Building.size(); i++)
		{
			Building[i].age++;
			if (age == 30)
			{
				for (int i = 0; i < Building.size(); i++)
				{
					Building[i].BrokenBuildingPerTime(Building);
				}
			}
		}
		
	}
	void coutBuildingMenu(vector <Buildings> Building) {
	}
	

};

