#pragma once
#include "Lib.h"
class Castle
{
public:
	bool isPresent;
	int Healsh;
	Castle() {
		isPresent = true;
		Healsh = 100;
	}
	int getIsPresent() {
		return isPresent;
	}
	int getHealsh() {
		return Healsh;
	}
	void setHealsh(int Healsh) {
		this->Healsh = Healsh;
	}
	int CastleCrash() {
		isPresent = false;
	}
	int CastleDamage(int Damage) {
		for (int i = 0; i < Damage; i++)
		{
			Healsh--;
		}
	}


};

