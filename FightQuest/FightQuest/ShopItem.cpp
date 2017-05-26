#include "ShopItem.h"
using namespace std;



ShopItem::ShopItem(int price, char* name, char* desc)
	: mPrice(price), mName(name), mDesc(desc), mInPlayerInventory(0)
{}


void ShopItem::ShopDisplay(int menuNumber)
{
	std::cout << "  " << menuNumber << "  " << mPrice << "  " << mName << "  " << std::endl;
}

void ShopItem::InventoryDisplay(int & index)
{
	if (mInPlayerInventory > 0) {

	cout <<"        " << index << ": " << mName << " (x" << mInPlayerInventory << ")" << endl;
	mInventoryPosition = index;
	index++;
	}
	else {
		mInventoryPosition = 0;
	}
}

void ShopItem::ExamineShopItem(Fighter &player, int choice)
{
	system("cls");
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "Item: " << mName << std::endl;
	std::cout << "Price: " << mPrice << std::endl;
	std::cout << mDesc << std::endl;
	std::cout << "You currently have:" << mInPlayerInventory << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "How many would you like to buy?" << std::endl;
	std::cout << "Enter 0 to return to the shop." << std::endl;
	choice = GetPlayerInput();
	if (choice == 0) {
		return;
	}
	else {
		Purchase(player, choice);
	}

}

void ShopItem::ExamineInventoryItem(Fighter &player, int resaleValue, int choice)
{
	while (true) {
		system("cls");
	resaleValue = ((mPrice * 0.7) + (player.mLuck / 10));
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "Item: " << mName << std::endl;
	std::cout << "Value: " << resaleValue << std::endl;
	std::cout << mDesc << std::endl;
	std::cout << "You currently have:" << mInPlayerInventory << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	cout << "How many would you like to sell? Enter 0 to return." << endl;
	choice = GetPlayerInput();
	if (choice == 0) {
		break;
	}
	else {
		Sell(player,resaleValue,choice);
	}

	}


}

void ShopItem::Purchase(Fighter &gPlayer, int num)
{
	if (gPlayer.mMoney >= (mPrice * num)) {
		system("cls");
		std::cout << "Thank you for your patronage." << std::endl;
		mInPlayerInventory = mInPlayerInventory + num;
		gPlayer.mMoney = gPlayer.mMoney - (mPrice * num);
		std::cout << "You now have " << mInPlayerInventory << " " << mName << "(s)." << std::endl;
		system("pause");
	}
	else {
		system("cls");
		std::cout << "You dont have enough money." << std::endl;
		system("pause");
	}
}

void ShopItem::Sell(Fighter & player, int value, int num)
{
	if (num <= mInPlayerInventory) {
	player.mMoney += (value * num);
		mInPlayerInventory -= num;
	}
	else {
		system("cls");
		cout << "You don't have that many to sell." << endl;
		system("pause");
	}
}

ShopItem::~ShopItem()
{
}
