#pragma once
#include "Equipment.h"
#include "Potion.h"
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

Fighter fPlayer = { "", 1, 1, 1, 1, 0 };
Fighter fAi = { "", 1, 1, 1, 1,0 };
Fighter fTemplateSwordman = { "", 120, 20, 50, 20, 0 };
Fighter fTemplateDefender = { "", 200, 10, 70, 10,0 };
Fighter fTemplateRogue = { "", 90, 25, 30, 25,0 };

//smith Items
Potion pWhetstone = { 5, "Whetstone", "Small oily stone used to sharpen a blade. Could probably work on the edge of a shield, too. This effects stacks, but wears off over time.",fPlayer.mDamage,6,1 };
Equipment eHelm = { 150, "Helm", "A helm... et. It's a helmet.",fPlayer.eHead,fPlayer.mDefence,15 };
Equipment gBreastplate = { 300, "Breastplate","A metal plate used to cover your breast. I wonder how much time the smith wasted putting nipples on.",fPlayer.eTorso,fPlayer.mDefence,20 };


//alchemy items
Potion pHealthPotion = { 10,"Health Potion","Health potions are a dietary supplement, and are not intended to diagnose, treat, cure, or prevent any disease.", fPlayer.mHealth,20,0 };
Potion pStrengthPotion = { 15,"Strength Potion","Where's the beef?",fPlayer.mDamage,20,100 };
Potion pQuickPotion = { 20,"Quck Potion","Wow, that potion is really quick.",fPlayer.mAttack,15,3 };

//Trenchy items
Potion pClover = { 15,"Bag o' Clover","A bag of four leaf clovers to be smoked before battle.",fPlayer.mLuck,5,1 };
ShopItem iLockpick = { 30,"Lockpick","Similar to a tooth pick, but for locks." };
Potion pBearAdrenaline = { 200,"Bear Adrenaline","This is sure to have no side effects...",fPlayer.mLuck,50,100 };

char playerChoice[15] = " "; //used to store text player inputs
int plyrNumChoice = 0;
int aiChoice = 0; //1=Swordman 2=Defender 3=Rogue
int plyrType = 0; //1=Swordman 2=Defender 3=Rogue
				  // swordman beats rogue, rogue beats defender, defender beats swordman
int difficulty = 10; //percent chance that the computer will pick the class that is best at defeating the player's
int fightWinner = 0; //0 = player, 1 = AI, 3 = draw
char plyrName[15] = " ";
int randomizer = 0; //used in dice rolls to keep them random
int color = 0x0F;