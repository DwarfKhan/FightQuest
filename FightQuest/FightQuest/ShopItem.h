#pragma once
#include "Fighter.h"
class ShopItem
{
public:
	ShopItem(int price, char* name, char* desc);
	~ShopItem();

	char* mDesc;
	char* mName;
	int mPrice;
	int mInPlayerInventory; // represents how many of this item the player currently has in their inventory
	int mInventoryPosition = 0;


	// displays the item for a shop menu
	void ShopDisplay(int menuNumber);

	void InventoryDisplay(int &index);

	// desplay's item's details and allows purchase
	void ExamineShopItem(Fighter &player, int choice = 0);

	void ExamineInventoryItem(Fighter &player, int resaleValue = 0, int choice = 0);

	// takes money from player to buy num of this item
	void Purchase(Fighter &player, int num = 1);

	void Sell(Fighter &player, int value, int num = 1);








};

