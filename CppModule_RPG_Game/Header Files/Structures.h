// Structures.h
// Main structures of game

#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "Range.h"
#include <string>

struct Armor
{
	std::string mName;
	int armorValue;
	int armorEffect;
};

struct Item
{
	std::string itemName;
	std::string itemEffect;
	//int item
	int itemValue;
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
 int weaponValue;
 Range mDamageRange; 
}; 

#endif // STRUCTURES_H