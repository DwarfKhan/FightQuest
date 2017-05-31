#pragma once
#include "Instances.h"


int GetPlayerInput() {
	char choice[100];
	cin >> choice;
	return atoi(choice);
}


// Makes a random number between min and max. Use difference to ensure that two dice rolls done at the same time will not always produce the same result.
int DiceRoll(int min, int max) {
	srand(time(NULL) + (randomizer * 42));
	randomizer++;
	return rand() % ((max - min) + 1) + min;
}

char* GenRandomName(int diceHolder = 0) {
	diceHolder = DiceRoll(1, 10);
	if (diceHolder == 1) {
		return "Brent";
	}
	else if (diceHolder == 2) {
		return"Donny";
	}
	else if (diceHolder == 3) {
		return"Luwig Van";
	}
	else if (diceHolder == 4) {
		return"Fudice";
	}
	else if (diceHolder == 5) {
		return"Jerald";
	}
	else if (diceHolder == 6) {
		return"DK";
	}
	else if (diceHolder == 7) {
		return"Eathrider";
	}
	else if (diceHolder == 8) {
		return"Dexter";
	}
	else if (diceHolder == 9) {
		return"Klaus";
	}
	else if (diceHolder == 10) {
		return"Paco";
	}
}

void Damage(Fighter &attacker, Fighter &defender, int damageCount = 0) {
	damageCount = (attacker.mDamage + DiceRoll(0, attacker.mLuck));
	defender.mHealth -= damageCount;
	if (damageCount < 15) {
		SetConsoleTextAttribute(hConsole, 0x08);
	}
	else if (damageCount < 25) {
		SetConsoleTextAttribute(hConsole, 0x0E);
	}
	else if (damageCount < 35) {
		SetConsoleTextAttribute(hConsole, 0x0C);
	}
	else if (damageCount < 45) {
		SetConsoleTextAttribute(hConsole, 0xC0);
	}
	else if (damageCount < 65) {
		SetConsoleTextAttribute(hConsole, 0xCF);
	}
	else {
		SetConsoleTextAttribute(hConsole, 0xCB);
	}
	std::cout << "-" << damageCount << std::endl;
	SetConsoleTextAttribute(hConsole, color);
	Sleep(700);
}

//checks attacker's attack modifier vs defenders defence modifier, returns nonzero for a hit, zero for a miss/ping
int Attack(Fighter attacker, Fighter defender) {
	if ((attacker.mAttack + DiceRoll(1, 100) + DiceRoll(0, attacker.mLuck)) >= defender.mDefence) {
		std::cout << attacker.mName << "'s Attack Suceeded" << std::endl;
		return 1;
	}
	else {
		std::cout << attacker.mName << "'s Attack Failed" << std::endl;
		Sleep(500);
		return 0;
	}



}

//Bashes gPlayer and gAi together until one or both dies, returns 0 for player win, 1 for player loss, 3 for draw.
int Fight(int stakes = 100) {
	system("cls");
	std::cout << "Hero Status" << std::endl;
	fPlayer.displayStats();
	std::cout << "Adversary Status" << std::endl;
	fAi.displayStats();


	system("pause");
	system("cls");

	std::cout << "Lower the gates!" << std::endl;
	system("pause");
	system("cls");
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << fPlayer.mName << " vs " << fAi.mName << std::endl;
	std::cout << fPlayer.mHealth << "    " << fAi.mHealth << std::endl;
	std::cout << "-------------------------------------------------------------" << std::endl;
	Sleep(1000);
	while (true) {
		// Do battle Calculations below this line
		if (Attack(fPlayer, fAi) == 1) {

			Damage(fPlayer, fAi);
		}

		if (Attack(fAi, fPlayer) == 1) {

			Damage(fAi, fPlayer);
		}


		system("cls");
		std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
		std::cout << fPlayer.mName << " vs " << fAi.mName << std::endl;
		std::cout << fPlayer.mHealth << "    " << fAi.mHealth << std::endl;
		std::cout << "-------------------------------------------------------------" << std::endl;
		Sleep(1000);




		if ((fPlayer.mHealth <= 0) && (fAi.mHealth <= 0)) {
			system("cls");
			std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
			std::cout << "We'll call it a draw, then." << std::endl;
			cout << "You get no winnings, but you will live to fight again." << endl;
			std::cout << "-------------------------------------------------------------" << std::endl;
			system("pause");
			if (fPlayer.mHealth <= fPlayer.mMaxHealth) {
				fPlayer.mHealth = fPlayer.mMaxHealth;
			}
			fAi.mHealth = fAi.mMaxHealth;
			return 3;
			break;
		}
		else if (fPlayer.mHealth <= 0) {
			system("cls");
			std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
			std::cout << "You lost, please pick a better fighter next time." << std::endl;
			std::cout << "-------------------------------------------------------------" << std::endl;
			system("pause");
			if (fPlayer.mHealth <= fPlayer.mMaxHealth) {
				fPlayer.mHealth = fPlayer.mMaxHealth;
			}
			fAi.mHealth = fAi.mMaxHealth;
			return 1;
			break;
		}
		else if (fAi.mHealth <= 0) {
			system("cls");
			std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
			std::cout << "You won by a margin of " << fPlayer.mHealth << " health." << std::endl;
			cout << "Winnings: " << stakes << " gold coins" << endl;
			std::cout << "-------------------------------------------------------------" << std::endl;
			system("pause");
			fPlayer.mVictoriousFights++;
			fPlayer.mMoney += stakes;
			if (fPlayer.mHealth <= fPlayer.mMaxHealth) {
				fPlayer.mHealth = fPlayer.mMaxHealth;
			}
			fAi.mHealth = fAi.mMaxHealth;
			return 0;
			break;
		}

	}
}

//Takes a %difficulty and the player type and generates an opponent accordingly
int GenAi(int difficulty, int playerType) {
	if (DiceRoll(1, 100) <= difficulty) {
		if (playerType == 1) {
			fAi = fTemplateDefender;
		}
		else if (playerType == 2) {
			fAi = fTemplateRogue;
		}
		else if (playerType == 3) {
			fAi = fTemplateSwordman;
		}
		else {
			fAi = { "God", 5000, 5000, 5000, 5000, -100};
		}

	}
	else {
		if (playerType == 1) {
			if (DiceRoll(1, 10) >= 5) {
				fAi = fTemplateSwordman;
			}
			else {
				fAi = fTemplateRogue;
			}
		}
		else if (playerType == 2) {
			if (DiceRoll(1, 10) >= 5) {
				fAi = fTemplateDefender;
			}
			else {
				fAi = fTemplateSwordman;
			}

		}
		else if (playerType == 3) {
			if (DiceRoll(1, 10) >= 5) {
				fAi = fTemplateRogue;
			}
			else {
				fAi = fTemplateDefender;
			}

		}
	}
	fAi.mName = GenRandomName();
	fAi.mLuck = ((difficulty / 10) + fPlayer.mVictoriousFights + DiceRoll(0,3));
	if (fPlayer.mVictoriousFights > 3) {
	fAi.mAttack += DiceRoll(0, (difficulty / 10));
	fAi.mDamage += DiceRoll(0, (difficulty / 10));
	fAi.mDefence += DiceRoll(0, (difficulty / 10));
	fAi.mMaxHealth += DiceRoll(0, (difficulty / 10));
	if (DiceRoll(0,1) > 0) {
		fAi.mVictoriousFights = fPlayer.mVictoriousFights + DiceRoll(0, 5);
	}
	else {
		fAi.mVictoriousFights = fPlayer.mVictoriousFights - DiceRoll(0, 5);
	}
	}
	fAi.mHealth = fAi.mMaxHealth;
	return 0;
}

void CharacterCreation() {



	system("cls");

	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << "Choose a name for your champion:" << std::endl;
	std::cout << "-------------------------------------------------------------" << std::endl;
	std::cin >> plyrName;
	system("cls");


	//Choosing a fighter type
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	while (true) {
		std::cout << "What school of combat will " << plyrName << " use?" << std::endl; //people tend to type the wrong selection, need to be able to click one. First instinct of one subject was to use arrowkeys to select type...
		std::cout << " Swordman    Defender   Rogue  " << std::endl;
		std::cout << "    1           2         3      " << std::endl;
		std::cout << "    _          _          _    " << std::endl;
		std::cout << "   | | /      | | ]      | | )-> " << std::endl;
		std::cout << "   ( )/       ( )/|      ( )/  " << std::endl;
		std::cout << "   / \\        / \\        / \\ " << std::endl;
		std::cout << "-------------------------------------------------------------" << std::endl;

		plyrNumChoice = GetPlayerInput();
		system("cls");

		std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
		if (plyrNumChoice == 1) {
			std::cout << "   A sword, way to be original.     " << std::endl;
			std::cout << "                               " << std::endl;
			std::cout << "              /\\              " << std::endl;
			std::cout << "              ||               " << std::endl;
			std::cout << "              ||               " << std::endl;
			std::cout << "              ||               " << std::endl;
			std::cout << "            <====>             " << std::endl;
			std::cout << "              II               " << std::endl;
			std::cout << "              ()               " << std::endl;
			fPlayer = fTemplateSwordman;
			fPlayer.mName = plyrName;
			plyrType = 1;
			break;
		}
		else if (plyrNumChoice == 2) {
			std::cout << "  Your fighter uses only a shield.     " << std::endl;
			std::cout << "        ________                " << std::endl;
			std::cout << "       /   *     \\             " << std::endl;
			std::cout << "      /    *      \\            " << std::endl;
			std::cout << "     |============|             " << std::endl;
			std::cout << "     |     *      |             " << std::endl;
			std::cout << "      \\____*_____/             " << std::endl;
			std::cout << "                                " << std::endl;
			std::cout << "     That's unfortunate...      " << std::endl;
			fPlayer = fTemplateDefender;
			fPlayer.mName = plyrName;
			plyrType = 2;
			break;
		}
		else if (plyrNumChoice == 3) {
			std::cout << "   Here is your bow!     " << std::endl;
			std::cout << "       / |                       " << std::endl;
			std::cout << "      /  |     <--<<                  " << std::endl;
			std::cout << "      |  |                       " << std::endl;
			std::cout << "     /   |     <--<<                  " << std::endl;
			std::cout << "     |   |                       " << std::endl;
			std::cout << "      \\ |                        " << std::endl;
			std::cout << "       \\|                        " << std::endl;
			std::cout << "                               " << std::endl;
			fPlayer = fTemplateRogue;
			fPlayer.mName = plyrName;
			plyrType = 3;
			break;
		}
		// Overpowered class for testing
		else if (plyrNumChoice == 100) {
			std::cout << "   Here is your bow!     " << std::endl;
			std::cout << "             " << std::endl;
			std::cout << "    |)  ->            " << std::endl;
			std::cout << "             " << std::endl;
			std::cout << "                  " << std::endl;
			std::cout << "             " << std::endl;
			std::cout << "              " << std::endl;
			std::cout << "              " << std::endl;
			std::cout << "                               " << std::endl;
			fPlayer = { plyrName, 1000000, 1000000, 1000000, 1000000, 20};
			plyrType = 1;
			fPlayer.mMoney = 100000000;
			break;
		}

	}
	std::cout << "-------------------------------------------------------------" << std::endl;

	//This section is for comedic puposes and changes nothing about the gameplay.
	if (plyrType == 3) {
		std::cout << "Would you like more arrows?" << std::endl;
		std::cout << "(Y/N)" << std::endl;
		std::cin >> playerChoice;
		if ((strcmp(playerChoice, "Y") == 0) || (strcmp(playerChoice, "y") == 0)) {
			while (true) {
				std::cout << "Try asking Nicely." << std::endl;
				std::cin >> playerChoice;
				system("cls");
				if ((strcmp(playerChoice, "please") == 0) || (strcmp(playerChoice, "Please") == 0)) {
					std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
					std::cout << "   Good luck!     " << std::endl;
					std::cout << "       / |                       " << std::endl;
					std::cout << "      /  |     <--<<                  " << std::endl;
					std::cout << "      |  |                       " << std::endl;
					std::cout << "     /   |     <--<<                  " << std::endl;
					std::cout << "     |   |                       " << std::endl;
					std::cout << "      \\ |     <--<<                   " << std::endl;
					std::cout << "       \\|                        " << std::endl;
					std::cout << "                               " << std::endl;
					std::cout << "-------------------------------------------------------------" << std::endl;
					fPlayer.mLuck += 5;
					break;
				}
				else {
					std::cout << "That isn't the magic word..." << std::endl;
				}
			}
		}
	}

	fPlayer.mLuck = fPlayer.mLuck + 10;

	system("pause");
	system("cls");

	GenAi(difficulty, plyrType);

}

