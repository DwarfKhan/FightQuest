#pragma once
#include "ShopItem.h"
class Potion :
	public ShopItem
{
public:
	Potion(int price, char* name, char* desc, int &effectedAttribute, int modifier, int decayRate);
	~Potion();

	void Use(int numberBeingUsed = 1);
	void WearOff();
	void ExaminePotion(Fighter &player, int choice = 0, int resaleValue = 0);



	int &mEffectedAttribute;
	int mModifier;
	int mInuse;
	int mDecayRate;
};

