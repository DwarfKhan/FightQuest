#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include<windows.h>
#include "Utilities.h"
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
TODO:


widen the window
title screen
inventory function
flavor text for each shop that displays the first time you enter them
save to a text file
mkae a function that calls all the WearOff functions of all the potions at the end of a fight


*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int MainMenu(int choice = 0) {
	SetConsoleTextAttribute(hConsole, color);
		system("cls");
		cout << "0O0O0O0O0O0O0O0O0O0O0O0O0O0O0O0O0O0O0O0O0O0O0O0O0O0O0O0O0O0O0O0O0" << endl;
		cout << "                   Welcome to Fight Quest" << endl;
		cout << "                    1:    Start Game" << endl;
		cout << "                    2: View High Scores" << endl;
		cout << "                    3:     Options" << endl;
		cout << "                    4:    Exit Game" << endl;
		cout << "0O0O0O0O0O0O0O0O0O0O0O0O0O0O0O0O0O0O0O0O0O0O0O0O0O0O0O0O0O0O0O0O0" << endl;
		choice = GetPlayerInput();
		if ((choice > 0) && (choice < 5)) {
			return choice;
		}
		else {
			return 4;
	}
}

void Inventory(int choice = 0, int index = 1) {

	while (true) {
	index = 1;
		system("cls");
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
	cout << "                     Inventory" << endl;
	cout << "                     Money:"<< fPlayer.mMoney << endl;
	pWhetstone.InventoryDisplay(index);
	pHealthPotion.InventoryDisplay(index);
	pStrengthPotion.InventoryDisplay(index);
	pQuickPotion.InventoryDisplay(index);
	pClover.InventoryDisplay(index);
	iLockpick.InventoryDisplay(index);
	pBearAdrenaline.InventoryDisplay(index);
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
	cout << "Make a number selection. Enter 0 to return to the barracks." << endl;
	choice = GetPlayerInput();
	if (choice == 0) {
		break;
	}
	else if (choice == iLockpick.mInventoryPosition) {
	iLockpick.ExamineInventoryItem(fPlayer);
	}
	else if (choice == pWhetstone.mInventoryPosition) {
		pWhetstone.ExaminePotion(fPlayer);
	}
	else if (choice == pHealthPotion.mInventoryPosition) {
		pHealthPotion.ExaminePotion(fPlayer);
	}
	else if (choice == pStrengthPotion.mInventoryPosition) {
		pStrengthPotion.ExaminePotion(fPlayer);
	}
	else if (choice == pQuickPotion.mInventoryPosition) {
		pQuickPotion.ExaminePotion(fPlayer);
	}
	else if (choice == pClover.mInventoryPosition) {
		pClover.ExaminePotion(fPlayer);
	}
	else if (choice == pBearAdrenaline.mInventoryPosition) {
		pBearAdrenaline.ExaminePotion(fPlayer);
	}
 }
}

void Equipment(int choice = 0, int index = 1) {
	while (true) {
		index = 1;
	system("cls");
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
	cout << "                     Equipment" << endl;
	eHelm.EquipmentDisplay(index);
	eBreastplate.EquipmentDisplay(index);
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
	cout << "Make a number selection. Enter 0 to return to the barracks." << endl;
	choice = GetPlayerInput();
	if (choice == 0) {
		break;
	}
	else if (choice == eHelm.mInventoryPosition) {
		eHelm.ExamineEquipment(fPlayer);
	}
	else if (choice == eBreastplate.mInventoryPosition) {
		eBreastplate.ExamineEquipment(fPlayer);
	}

	}
}

// loops the shop sequence until the playr decides to leave.
void ShopSequence() {
	while (true) {
		system("cls");
		std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
		std::cout << "Would you like to take a look at the shops?" << std::endl;
		std::cout << "0 - Back to the arena" << std::endl;
		std::cout << "1 - Blacksmith" << std::endl;
		std::cout << "2 - Alchemist" << std::endl;
		std::cout << "3 - Shady man in trench coat" << std::endl;
		std::cout << "-------------------------------------------------------------" << std::endl;
		plyrNumChoice = GetPlayerInput();
		if (plyrNumChoice == 1) {
			while (true) {
				system("cls");
				std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
				std::cout << "Welcome to the blacksmith." << std::endl;
				std::cout << "You have " << fPlayer.mMoney << " gold coins." << std::endl;
				std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
				std::cout << "  #  Cost  Item" << std::endl;
				pWhetstone.ShopDisplay(1);
				eHelm.ShopDisplay(2);
				eBreastplate.ShopDisplay(3);
				std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
				std::cout << "Enter a number to view an item." << std::endl;
				std::cout << "Enter 0 to exit the shop." << std::endl;
				std::cout << "-------------------------------------------------------------" << std::endl;
				plyrNumChoice = GetPlayerInput();
				if (plyrNumChoice == 0) {
					break;
				}
				else if (plyrNumChoice == 1) {
					pWhetstone.ExamineShopItem(fPlayer);
				}
				else if (plyrNumChoice == 2) {
					eHelm.ExamineShopItem(fPlayer);
				}
				else if (plyrNumChoice == 3) {
					eBreastplate.ExamineShopItem(fPlayer);
				}
			}
		}
		else if (plyrNumChoice == 2) {
			while (true) {
				system("cls");
				std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
				std::cout << "Welcome to the alchemist shop." << std::endl;
				std::cout << "You have " << fPlayer.mMoney << " gold coins." << std::endl;
				std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
				std::cout << "  #  Cost  Item" << std::endl;
				pHealthPotion.ShopDisplay(1);
				pStrengthPotion.ShopDisplay(2);
				pQuickPotion.ShopDisplay(3);
				std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
				std::cout << "Enter a number to view an item." << std::endl;
				std::cout << "Enter 0 to exit the shop." << std::endl;
				std::cout << "-------------------------------------------------------------" << std::endl;
				plyrNumChoice = GetPlayerInput();
				if (plyrNumChoice == 0) {
					break;
				}
				else if (plyrNumChoice == 1) {
					pHealthPotion.ExamineShopItem(fPlayer);
				}
				else if (plyrNumChoice == 2) {
					pStrengthPotion.ExamineShopItem(fPlayer);
				}
				else if (plyrNumChoice == 3) {
					pQuickPotion.ExamineShopItem(fPlayer);
				}
			}
		}
		else if (plyrNumChoice == 3) {
			while (true) {
				system("cls");
				std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
				std::cout << "Are you going to buy something, or just stand there?" << std::endl;
				std::cout << "You have " << fPlayer.mMoney << " gold coins." << std::endl;
				std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
				std::cout << "  #  Cost  Item" << std::endl;
				pClover.ShopDisplay(1);
				iLockpick.ShopDisplay(2);
				pBearAdrenaline.ShopDisplay(3);
				std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
				std::cout << "Enter a number to view an item." << std::endl;
				std::cout << "Enter 0 to exit the shop." << std::endl;
				std::cout << "-------------------------------------------------------------" << std::endl;
				plyrNumChoice = GetPlayerInput();
				if (plyrNumChoice == 0) {
					break;
				}
				else if (plyrNumChoice == 1) {
					pClover.ExamineShopItem(fPlayer);
				}
				else if (plyrNumChoice == 2) {
					iLockpick.ExamineShopItem(fPlayer);
				}
				else if (plyrNumChoice == 3) {
					pBearAdrenaline.ExamineShopItem(fPlayer);
				}
			}
		}
		else if (plyrNumChoice == 0) {
			break;
	}
	}
}

void Bet(int choice = 0) {
	system("cls");
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
	cout << "                     Money:" << fPlayer.mMoney << endl;
	cout << "How much would you like to bet on the Fight?" << endl;
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
	choice = GetPlayerInput();
	fPlayer.mMoney -= choice;
	betAmount += choice;
}

void Arena(int choice = 0) {
	while (true) {
		system("cls");
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
	cout << "               You are in the Arena" << endl;
	cout << "                   Current Bet: "<< betAmount << endl;
	cout << "               You Have Won " << fPlayer.mVictoriousFights << " Times" << endl;
	cout << "        1:             Inventory" << endl;
	cout << "        2:             Equipment" << endl;
	cout << "        3:     Place a Bet on Yourself" << endl;
	cout << "        4:          Begin the Fight" << endl;
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
	cout << "Make a number selection. Enter 0 to return." << endl;
	choice = GetPlayerInput();

	if (choice == 1) {
		Inventory();
	}
	else if (choice == 2) {
		Equipment();
	}
	else if (choice == 3) {
		Bet();
	}
	else if (choice == 4) {
		GenAi((10*fPlayer.mVictoriousFights),plyrType);
		fightWinner = Fight((betAmount + (fPlayer.mVictoriousFights * 5)));
		betAmount = 0;
	}
	else if (choice == 0) {
		break;
	}
	}
}

// Main hub of the game
void Barracks(int choice = 0) {

	while (true) {
		system("cls");
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
	cout << "               You are in the barracks." << endl;
	cout << "        1:             Inventory" << endl;
	cout << "        2:             Equipment" << endl;
	cout << "        3:         Enter the Arena" << endl;
	cout << "        4:         Enter the Market" << endl;
	cout << "        5:    Bargain for Your Freedom" << endl;
	cout << "        6:        Visit the Lenders" << endl;
	cout << "        7:  Give up and Submit to JEFFREY" << endl;
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
	choice = GetPlayerInput();

	if (choice == 1) {
		Inventory();
	}
	else if (choice == 2) {
		Equipment();
	}
	else if (choice == 3) {
		Arena();
	}
	else if (choice == 4) {
		ShopSequence();
	}
	else if (choice == 5) {
		//TODO
		//AttemptFreedomPurchase();
	}
	else if (choice == 6) {
		//TODO
		//Lenders();
	}
	else if (choice == 7) {
		//TODO
		//JEFEREY();
	}

	}
}


int main(int argc, char *argv[])
{

	while (true) {
		plyrNumChoice = MainMenu();
		if (plyrNumChoice == 1) {
		CharacterCreation();
		fightWinner = Fight();

		if (fightWinner == 0) {
			Barracks();
		}
		else if (fightWinner == 3) {
			Barracks();
		}

		}
		else if (plyrNumChoice == 2) {
			//TODO high scores
		}
		else if (plyrNumChoice == 3) {
			//TODO options
		}
		else if (plyrNumChoice == 4) {
			break;
		}
	}
	

	//Offer the player a way out of the debt by using his skills outside of the arena

system("pause");
	return 0;
}