//Store.cpp

#include "Store.h"
#include <iostream>
#include <vector>


Store::Store()
{
	Weapon w1, w2, w3, w4, w5, w6, w7, w8;
	w1.weaponName = "bastard sword";
	w1.DamageRange.Low = 4;
	w1.DamageRange.High = 12;
	w1.weaponBuyValue = 1100;
	w1.weaponSellValue = 500;
	w2.weaponName = "two handed sword";
	w2.DamageRange.Low = 8;
	w2.DamageRange.High = 18;
	w2.weaponBuyValue = 2700;
	w2.weaponSellValue = 1300;
	w3.weaponName = "war bow";
	w3.DamageRange.Low = 4;
	w3.DamageRange.High = 9;
	w3.weaponBuyValue = 900;
	w3.weaponSellValue = 450;
	w4.weaponName = "spear";
	w4.DamageRange.Low = 5;
	w4.DamageRange.High = 11;
	w4.weaponBuyValue = 1200;
	w4.weaponSellValue = 600;
	w5.weaponName = "lighter staff of power";
	w5.DamageRange.Low = 3;
	w5.DamageRange.High = 6;
	w5.weaponBuyValue = 600;
	w5.weaponSellValue = 300;
	w6.weaponName = "staff of power";
	w6.DamageRange.Low = 5;
	w6.DamageRange.High = 9;
	w6.weaponBuyValue = 900;
	w6.weaponSellValue = 450;
	w7.weaponName = "lighter flail";
	w7.DamageRange.Low = 3;
	w7.DamageRange.High = 8;
	w7.weaponBuyValue = 550;
	w7.weaponSellValue = 275;
	w8.weaponName = "heavy flail";
	w8.DamageRange.High = 7;
	w8.DamageRange.Low = 11;
	w8.weaponBuyValue = 850;
	w8.weaponSellValue = 420;
	
	shopWeapons.push_back(w1);
	shopWeapons.push_back(w2);
	shopWeapons.push_back(w3);
	shopWeapons.push_back(w4);
	shopWeapons.push_back(w5);
	shopWeapons.push_back(w6);
	shopWeapons.push_back(w7);
	shopWeapons.push_back(w8);

	Armor a1,a2;
	a1.ArmorName = "simple armor";
	a1.armorEffect = 3;
	a1.armorSellValue = 100;
	a1.armorBuValue = 600;
	
	a2.ArmorName = "advanced armor";
	a2.armorEffect = 7;
	a2.armorSellValue = 300;
	a2.armorBuValue = 900;

	shopArmor.push_back(a1);
	shopArmor.push_back(a2);

	Item i1("minor health potion", 20, 60, 5, 'H');
	Item i2("minor mana potion", 20, 80, 5, 'M');
	Item i3("scroll of small fireball", 30, 100, 10, 'S');
	Item i4("health potion", 50, 90, 10, 'H');
	Item i5("mana potion", 30, 1100, 10, 'M');
	Item i6("scroll of fireball", 60, 130, 20, 'S');
	
	shopItems.push_back(i1);
	shopItems.push_back(i2);
	shopItems.push_back(i3);
	shopItems.push_back(i4);
	shopItems.push_back(i5);
	shopItems.push_back(i6);
}



void Store::enter(Player& player)
{	
	bool done = false;
	int selection = 1;
	//greet player and display main select window
	std::cout << "hello " + player.getName() + " in the shop";
	std::cout << std::endl;
	std::cout << "Please make your selection: ";
	std::cout << std::endl;

	while(!done)
	{
		std::cout << "1)Show what's in shop, 2)Buy, 3)Sell,  4)Quit";
		std::cout << std::endl;
		std::cin >> selection;
		while(std::cin.fail())
		{
			std::cout << "Wrong input!" << std::endl;
			std::cin.clear();
			std::cin.ignore(256,'\n');
			std::cin >> selection;
		}
		
		//process choices
		switch(selection)
		{
		case 1:
			showShop();
			break;
		case 2:
			buyScreen(player);
			break;
		case 3:
			sellScreen(player);
			break;
		case 4:
			done = true;
			shopWeapons.clear();
			shopArmor.clear();
			shopItems.clear();
			break;
		}
	}
}


//void Store::showShop(std::vector<Weapon> shopWeapons, std::vector<Armor> shopArmor)
void Store::showShop()
{
	
	std::cout << "Showing weapons: " << std::endl;
	std::cout << std::endl;
	std::cout << "weapon name, sell value, buy value, damage range: " << std::endl;
	std::cout << std::endl;

	for(std::vector<Weapon>::iterator weapon_it = shopWeapons.begin(); weapon_it < shopWeapons.end(); ++weapon_it)
	{
		std::cout << std::distance(shopWeapons.begin(),weapon_it)+1  << ": " << weapon_it->weaponName << " " << weapon_it->weaponSellValue 
			<< " " << weapon_it->weaponBuyValue << " " << weapon_it->DamageRange.Low << "-" << weapon_it->DamageRange.High << std::endl;
	}


	std::cout << "Showing armor: " << std::endl;
	std::cout << std::endl;
	std::cout << "armor name, sell value, buy value, armor effect: " << std::endl;

	for(std::vector<Armor>::iterator armor_it = shopArmor.begin(); armor_it < shopArmor.end(); ++armor_it)
	{
		std::cout << std::distance(shopArmor.begin(),armor_it)+1  << ": " << armor_it->ArmorName<< " " << armor_it->armorSellValue 
			<< " " << armor_it->armorBuValue << " " << "+" << armor_it->armorEffect << std::endl;
	}
	
	std::cout << "Showing items: " << std::endl;
	std::cout << std::endl;
	std::cout << "item name, sell value, buy value, item effect: " << std::endl;
	for(std::vector<Item>::iterator item_it = shopItems.begin(); item_it < shopItems.end(); ++item_it)
	{
		std::cout << std::distance(shopItems.begin(),item_it)+1 << ": " << item_it->getName() << " " << item_it->getsellValue()
			<< " " << item_it->getBuyValue() << "" << item_it->getLabel() << std::endl;	
	}

	std::cout << std::endl;

}

void Store::buyScreen(Player& player)
{
	int selection = 0;
	std::cout << "What would you like to buy? " << std::endl;
	std::cout << "1) Weapon, 2)Armor 3)Item 4)Nothing" << std::endl;
	std::cin >> selection;
	while(std::cin.fail())
	{
		std::cout << "Wrong input!" << std::endl;
		std::cin.clear();
		std::cin.ignore(256,'\n');
		std::cin >> selection;
	}
	std::cout << std::endl;
	
	switch(selection)
	{
	case 1:
		{
			int weaponSel = 0;
			for(std::vector<Weapon>::iterator weapon_it = shopWeapons.begin(); weapon_it < shopWeapons.end(); ++weapon_it)
			{
				std::cout << std::distance(shopWeapons.begin(),weapon_it)+1  << ": " << weapon_it->weaponName << " " << weapon_it->weaponSellValue 
				<< " " << weapon_it->weaponBuyValue << " " << weapon_it->DamageRange.Low << "-" << weapon_it->DamageRange.High << std::endl;
			}
			std::cout << shopWeapons.size()+1 << ": Quit" << std::endl;
			std::cout << "Make a purchase or quit:" << std::endl;
			std::cin >> weaponSel;
			std::cout << shopWeapons.size();
			if (weaponSel > int(shopWeapons.size()))
			{
				std::cout << "Thanks for buying!" << std::endl;
				break;
			}
			else
			{
				if (player.buyWeapon(shopWeapons.at(weaponSel-1).weaponName, shopWeapons.at(weaponSel-1).weaponSellValue, shopWeapons.at(weaponSel-1).DamageRange.Low,
					shopWeapons.at(weaponSel-1).DamageRange.High, shopWeapons.at(weaponSel-1).weaponBuyValue))
				{
					std::cout << "You bought a weapon!" << std::endl;
				}
				else break;
			}
		}
	case 2:
		{
			int armorSel = 0;
			for(std::vector<Armor>::iterator armor_it = shopArmor.begin(); armor_it < shopArmor.end(); ++armor_it)
			{
				std::cout << std::distance(shopArmor.begin(),armor_it)+1  << ": " << armor_it->ArmorName<< " " << armor_it->armorSellValue 
					<< " " << armor_it->armorBuValue << " " << "+" << armor_it->armorEffect << std::endl;
			}
			std::cout << shopArmor.size() +1 << ": Quit" << std::endl;
			std::cout << "Make a purchase or quit:" << std::endl;
			std::cin >> armorSel;
			if (armorSel > int(shopArmor.size()))
			{
				std::cout << "Thanks for buying!" << std::endl;
				break;
			}
			else
			{
				if (player.buyArmor(shopArmor.at(armorSel-1).ArmorName, shopArmor.at(armorSel-1).armorSellValue,
					shopArmor.at(armorSel-1).armorEffect, shopArmor.at(armorSel-1).armorBuValue))
				{
					std::cout << "You bought an armor!" << std::endl;
				}
				else break;
			}
		}
	case 3:
		{
			int itemSel = 0;
			for(std::vector<Item>::iterator item_it = shopItems.begin(); item_it < shopItems.end(); ++item_it)
			{
				std::cout << std::distance(shopItems.begin(),item_it)+1 << ": " << item_it->getName() << " " << item_it->getsellValue()
					<< " " << item_it->getBuyValue() << "" << item_it->getLabel() << std::endl;	
			}
			std::cout << shopItems.size() +1 << ": Quit" << std::endl;
			std::cout << "Make a purchase or quit:" << std::endl;
			std::cin >> itemSel;
			if (itemSel > int(shopItems.size()))
			{
				std::cout << "Thanks for buying!" << std::endl;
				break;
			}
			else
			{
				if (player.buyItem(shopItems[itemSel-1]))
				{
					std::cout << "You bought!" << shopItems[itemSel-1].getName() << std::endl;
				}
				else break;
			}
		}
	case 4:
		break;
	}

}


void Store::sellScreen(Player& player)
{
	int selection = 0;
	std::cout << "What would you like to sell? " << std::endl;
	std::cout << "1) Weapon 2)Armor 3)Item 4)Nothing" << std::endl;
	std::cin >> selection;
	while(std::cin.fail())
	{
		std::cout << "Wrong input!" << std::endl;
		std::cin.clear();
		std::cin.ignore(256,'\n');
		std::cin >> selection;
	}
	switch(selection)
	{
	case 1:
		player.sellWeapon();
		break;
	case 2:
		player.sellArmor();
		break;
	case 3:
		player.sellItem();
	case 4:
		break;
	}


}