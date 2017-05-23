#include "Potion.h"



Potion::Potion(int price, char* name, char* desc, int &effectedAttribute, int modifier, int decayRate = 100)
	:ShopItem(price, name, desc), mEffectedAttribute(effectedAttribute), mModifier(modifier), mInuse(0), mDecayRate(decayRate)
{

}


Potion::~Potion()
{
}

void Potion::Use(int numberBeingUsed)
{
	if (numberBeingUsed <= mInPlayerInventory) {
		mInuse += numberBeingUsed;
		mEffectedAttribute += (mModifier * numberBeingUsed);
		mInPlayerInventory -= numberBeingUsed;
	}
	else {
		system("cls");
		std::cout << "You don't have "<< numberBeingUsed << " " << mName << "(s) to use." << std::endl;
		system("pause");
	}
}

void Potion::WearOff()
{
	if (mInuse >= mDecayRate) {
		mInuse -= mDecayRate;
		mEffectedAttribute -= (mDecayRate * mModifier);
	}
	else{
		mEffectedAttribute -= (mModifier * mInuse);
		mInuse = 0;
	}
}

void Potion::ExaminePotion(Fighter & player, int choice, int resaleValue)
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
		cout << "0: Return" << endl;
		cout << "1: Use Item" << endl;
		cout << "2: Sell Item" << endl;

		cin >> choice;
		if (choice == 0) {
			break;
		}
		else if (choice == 1) {
			Use();
		}
		else if(choice == 2){
			Sell(player, resaleValue);
		}

	}


}
