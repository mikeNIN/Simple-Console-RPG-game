// Store.h

#ifndef STORE_H
#define STORE_H

#include "Structures.h"
#include "Player.h"
#include <vector>

class Player; 

class Store
{
public:
	//Constructor
	Store();
	void enter(Player& player);

private:
	std::vector<Item> shopItems;
	std::vector<Weapon> shopWeapons;
	std::vector<Armor> shopArmor;
};

#endif STORE_H
