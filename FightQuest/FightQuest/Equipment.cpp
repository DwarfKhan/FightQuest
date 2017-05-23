#include "Equipment.h"



Equipment::Equipment(int price, char* name, char* desc, bool &equipmentSlot, int &effectedAttribute, int modifier)
: ShopItem(price, name, desc), mEquipmentSlot(equipmentSlot), mEffectedAttribute(effectedAttribute), mModifier(mModifier)
{
}


Equipment::~Equipment()
{
}

void Equipment::Use()
{
	if (mEquipmentSlot == false) {
		mEquipmentSlot = true;
		mEffectedAttribute += mModifier;
	}
	else {
		std::cout << "That equipment slot is already occupied." << std::endl;
	}
}

void Equipment::UnEquip()
{
	mEquipmentSlot = false;
	mEffectedAttribute -= mModifier;
}
