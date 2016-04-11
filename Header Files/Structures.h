// Structures.h
// Main structures of game

#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "Range.h"
#include <string>

struct Armor
{
	std::string ArmorName;
	int armorSellValue;
	int armorBuValue;
	int armorEffect;
};

struct Spell
{
	std::string spellName;
	Range spellDamageRange;
	int spellMagicPointsRequired;
};

struct Weapon 
{ 
	std::string weaponName; 
	int weaponSellValue;
	int weaponBuyValue;
	Range DamageRange;
}; 

#endif // STRUCTURES_H