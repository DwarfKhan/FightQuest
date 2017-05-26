#pragma once
#include<iostream>
using namespace std;
class Fighter
{
public:
	Fighter(char* name, int health, int atk, int defence, int dmg, int luck);
	~Fighter();
	void displayStats();

	char* mName;
	int mAttack, mDamage, mDefence, mMaxHealth, mHealth, mLuck;
	int mAttackTT, mDefenceTT, mDamageTT;
	int mVictoriousFights;
	int mMoney;
    //equipment slots
	bool eHead, eTorso, eLegs, eFeet, eHands, eWeapon;
};

int GetPlayerInput();
