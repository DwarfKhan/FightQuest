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
	void EquipmentDisplay(int &index);
	void ExamineEquipment(Fighter &player, int resaleValue = 0, int choice = 0);
	void EquipmentSell(Fighter &player, int value, int num = 1);

	bool mEquipped = false;
	bool &mEquipmentSlot;
	int &mEffectedAttribute;
	int mModifier;


};

