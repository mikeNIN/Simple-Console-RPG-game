// Store.h

#ifndef STORE_H
#define STORE_H

#include "Player.h"
#include <vector>

//class Player; 



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
	//template<typename T, typename A>
	//void showShop(std::vector<T,A> const& vec);
	void showShop();
	void buyScreen(Player& player);
	void sellScreen(Player& player);
};

#endif STORE_H
