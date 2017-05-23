#pragma once
#include "ShopItem.h"
class Equipment :
	public ShopItem
{
public:
	Equipment(int price, char* name, char* desc, bool &equipmentSlot, int &effectedAttribute, int modifier);
	~Equipment();
	void Use();
	void UnEquip();

	bool &mEquipmentSlot;
	int &mEffectedAttribute;
	int mModifier;


};

