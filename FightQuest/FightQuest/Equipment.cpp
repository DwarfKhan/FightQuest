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
	if (mEquipmentSlot == false && mEquipped == false && mInPlayerInventory > 0) {
		mEquipped = true;
		mEquipmentSlot = true;
		mEffectedAttribute += mModifier;
	}
	else {
		system("cls");
		std::cout << "That equipment slot is already occupied." << std::endl;
		system("pause");
	}
}

void Equipment::UnEquip()
{
	if (mEquipped) {
		mEquipped = false;
	mEquipmentSlot = false;
	mEffectedAttribute -= mModifier;
	}
	else {
		system("cls");
		std::cout << "That equipment is alrady not equipped." << std::endl;
		system("pause");
	}
}

void Equipment::EquipmentDisplay(int & index)
{
	if (mInPlayerInventory > 0) {

		cout << "        " << index << ": " << mName << " (x" << mInPlayerInventory << ")";
		if (mEquipped) {
			cout << "<-- This is equipped.";
		}
		cout << endl;
		mInventoryPosition = index;
		index++;
	}
	else {
		mInventoryPosition = 0;
	}
}

void Equipment::ExamineEquipment(Fighter &player, int resaleValue, int choice)
{
	while (true) {
		system("cls");
		resaleValue = ((mPrice * 0.7) + (player.mLuck / 10));
		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
		std::cout << "Item: " << mName << std::endl;
		std::cout << "Value: " << resaleValue << std::endl;
		std::cout << mDesc << std::endl;
		std::cout << "You currently have:" << mInPlayerInventory << std::endl;
		if (mEquipped) {
			cout << "It is currently equipped." << endl;
		}
		else {
			cout << "It is currently not equipped." << endl;
		}
		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
		cout << "0: Return" << endl;
		cout << "1: Equip Item" << endl;
		cout << "2: Un-Equip Item" << endl;
		cout << "3: Sell Item" << endl;

		choice = GetPlayerInput();
		if (choice == 0) {
			break;
		}
		else if (choice == 1) {
			Use();
		}
		else if (choice == 2) {
			UnEquip();
		}
		else if (choice == 3) {
			EquipmentSell(player, resaleValue);
		}

	}


}

void Equipment::EquipmentSell(Fighter & player, int value, int num)
{
	if (num <= mInPlayerInventory) {
		player.mMoney += (value * num);
		mInPlayerInventory -= num;
		if (mInPlayerInventory == 0) {
			UnEquip();
		}
	}
	else {
		system("cls");
		cout << "You don't have that many to sell." << endl;
		system("pause");
	}
}
