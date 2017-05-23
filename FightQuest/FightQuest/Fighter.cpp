
#include "Fighter.h"



Fighter::Fighter(char* name, int health, int atk, int defence, int dmg, int luck)
: mName(name), mAttack(atk), mDamage(dmg), mDefence(defence), mMaxHealth(health), mHealth(health), mLuck(luck), eHead(false), eTorso(false), eLegs(false), eHands(false), eWeapon(false)
{
}


Fighter::~Fighter()
{
}

void Fighter::displayStats()
{
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << "Name: " << mName << std::endl;
	std::cout << "Health: " << mHealth << std::endl;
	std::cout << "Defence: " << mDefence << std::endl;
	std::cout << "Attack: " << mAttack << std::endl;
	std::cout << "Damage: " << mDamage << std::endl;
	std::cout << "Victorious Fights: " << mVictoriousFights << std::endl;
	std::cout << "Luck: " << mLuck << std::endl;
	std::cout << "-------------------------------------------------------------" << std::endl;
}

