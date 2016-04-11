// Player.cpp


#include "Player.h"
#include "Random.h"
#include "Map.h"
#include <iostream>
#include <string>
#include <vector>


// constructor
Player::Player() 
{
	pName			= "Default"; 
	pClassName		= "Default";
	pRace			= "Default";
	pAccuracy		= 0; 
	pHitPoints		= 0; 
	pMaxHitPoints	= 0;
	pMagicPoints	= 0;
	pMaxMagPoints	= 0;
	pExpPoints		= 0; 
	pNextLevelExp	= 0; 
	pLevel			= 0; 
	pArmor.ArmorName = "rags";
	pArmor.armorEffect = 0;
	pArmor.armorSellValue = 0;
	pGold			= 0;	
	pWeapon.weaponName = "Stick";
	pWeapon.weaponSellValue = 0;
	pWeapon.DamageRange.Low  = 0; 
	pWeapon.DamageRange.High = 0;
	

	// creating spellBook
	//fireball
	Spell s1;
	s1.spellName = "Fireball";
	s1.spellDamageRange.High = 18;
	s1.spellDamageRange.Low = 5;
	s1.spellMagicPointsRequired = 15;
	pSpellBook.push_back(s1);
	Spell s2;
	s2.spellName = "Magic missle";
	s2.spellDamageRange.High = 13;
	s2.spellDamageRange.Low = 7;
	s2.spellMagicPointsRequired = 15;
	pSpellBook.push_back(s2);
	Spell s3;
	s3.spellName = "Shield";
	s3.spellDamageRange.High = 0;
	s3.spellDamageRange.Low = 0;
	s3.spellMagicPointsRequired = 40;
	pSpellBook.push_back(s3);


	//fill inventory with items


	Item i1("minor health potion", 20, 60, 5, 'H');
	Item i2("minor mana potion", 20, 80, 5, 'M');
	Item i3("scroll of small fireball", 30, 100, 10, 'S');

	pItemsInventory.push_back(i1);
	pItemsInventory.push_back(i2);
	pItemsInventory.push_back(i3);
}






// check if players is dead
bool Player::isDead()
{
	return pHitPoints <= 0; 
}


// accessor method
int Player::getArmor() const
{
	return pArmor.armorEffect;
}

// This method is called when a monster hits a player
void Player::takeDamage(int damage)
{
	pHitPoints -= damage;
}

// this code performs the character generation process
void Player::createClass()
{
	std::cout << "CHARACTER CLASS GENERATION" << std::endl;
	std::cout << "==========================" << std::endl;
	
	// Input character's name.
	std::cout << "Enter your character's name: "; 
	getline(std::cin, pName);
	std::cout << std::endl;
	//Race selection
	std::cout << "Please select a character race number..." << std::endl;
	std::cout << "1)Human 2)Elf 3)Dwarf : ";
	int raceNum = 1;
	std::cin >> raceNum;
	while(std::cin.fail())
	{
		std::cout << "Wrong input!" << std::endl;
		std::cin.clear();
        std::cin.ignore(256,'\n');
		std::cin >> raceNum;
	}
	std::cout << std::endl;
	
	// Character selection.
	std::cout << "Please select a character class number..."<< std::endl;  
	std::cout << "1)Fighter 2)Wizard 3)Cleric 4)Thief : ";  
	int characterNum = 1;  
	std::cin >> characterNum;
	while(std::cin.fail())
	{
		std::cout << "Wrong input!" << std::endl;
		std::cin.clear();
        std::cin.ignore(256,'\n');
		std::cin >> characterNum;
	}
	std::cout << std::endl;

	switch( characterNum ) 
	{
		case 1:
			{// Fighter
			pClassName		= "Fighter"; 
			pAccuracy		= 10; 
			pHitPoints		= 20; 
			pMaxHitPoints	= 20;
			pMagicPoints	= 30;
			pMaxMagPoints	= 30;
			pExpPoints		= 0;
			pNextLevelExp	= 1000; 
			pLevel			= 1; 
			pArmor.ArmorName = "chain mail";
			pArmor.armorEffect = 10;
			pArmor.armorSellValue = 250;
			//Weapon pWeapon;
			pWeapon.weaponName	= "Long Sword";
			pWeapon.weaponSellValue = 100;
			pWeapon.DamageRange.Low  = 3; 
			pWeapon.DamageRange.High = 10; 
			break;
			}
		case 2:
			{// Wizard
			pClassName    = "Wizard"; 
			pAccuracy     = 5; 
			pHitPoints    = 10; 
			pMaxHitPoints = 10; 
			pMagicPoints	= 80;
			pMaxMagPoints	= 80;
			pExpPoints    = 0; 
			pNextLevelExp = 1000;
			pLevel        = 1; 
			pArmor.ArmorName = "Robe";
			pArmor.armorEffect = 3;
			pArmor.armorSellValue = 75;
			//Weapon pWeapon;
			pWeapon.weaponName = "Staff";
			pWeapon.weaponSellValue = 100;
			pWeapon.DamageRange.Low  = 3; 
			pWeapon.DamageRange.High = 6; 
			break;
			}
		case 3:
			{// Cleric
			pClassName		= "Cleric";
			pAccuracy		= 8; 
			pHitPoints		= 15;
			pMaxHitPoints	= 15;
			pMagicPoints	= 60;
			pMaxMagPoints	= 60;
			pExpPoints		= 0;
			pNextLevelExp	= 1000;
			pLevel			= 1;
			pArmor.ArmorName = "iron armor";
			pArmor.armorEffect = 7;
			pArmor.armorSellValue = 175;
			//Weapon pWeapon;
			pWeapon.weaponName	= "Flail";
			pWeapon.weaponSellValue = 100;
			pWeapon.DamageRange.Low  = 3;
			pWeapon.DamageRange.High = 8;
			break;
			}
		default:
			{// Thief
			pClassName		= "Thief";
			pAccuracy		= 7; 
			pHitPoints		= 12;
			pMaxHitPoints	= 12;
			pMagicPoints	= 50;
			pMaxMagPoints	= 50;
			pExpPoints		= 0;
			pNextLevelExp	= 1000;
			pLevel			= 1;
			pArmor.ArmorName = "leather armor";
			pArmor.armorEffect = 5;
			pArmor.armorSellValue = 100;
			//Weapon pWeapon;
			pWeapon.weaponName	= "Short Sword";
			pWeapon.weaponSellValue = 100;
			pWeapon.DamageRange.Low  = 3;
			pWeapon.DamageRange.High = 8;
			break;
			}
	}
	
	switch(raceNum)
	{
	case 1:
			pRace			= "Human";
			pAccuracy		-= 1;
			pHitPoints		+= 2;
			pMaxHitPoints	+= 2;
			pMagicPoints	+= 1;
			pMaxMagPoints	+= 1;
			break;
	case 2:
			pRace			= "Elf";
			pAccuracy		+= 3; 
			pHitPoints		-= 4;
			pMaxHitPoints	-= 4;
			pMagicPoints	+= 4;
			pMaxMagPoints	+= 4;
			break;
	default:
			pRace			= "Dwarf";
			pAccuracy		-= 3; 
			pHitPoints		+= 5; 
			pMaxHitPoints	+= 5;
			pMagicPoints	-= 2;
			pMaxMagPoints	-= 2;
			break;
	}
}


bool Player::attack(Monster& monster)
{
	int selection = 1;
	std::cout << "1) Attack, 2) Cast spell 3) Use item 4) Run: "; 
	std::cin >> selection;
	while(std::cin.fail())
	{
		std::cout << "Wrong input!" << std::endl;
		std::cin.clear();
        std::cin.ignore(256,'\n');
		std::cin >> selection;
	}
	std::cout << std::endl;
	switch( selection ) 
	{
		case 1: 
			std::cout << "You attack an " << monster.getName()  
				<< " with a " << pWeapon.weaponName << std::endl; 
			if( Random(0, 20) < pAccuracy ) 
			{ 
				int damage = Random(pWeapon.DamageRange); 
				int totalDamage = damage - monster.getArmor(); 
				if( totalDamage <= 0 ) 
				{ 
					std::cout << "Your attack failed to penetrate the armor." << std::endl;
				} 
				else 
				{ 
					std::cout << "You attack for " << totalDamage << " damage!" << std::endl; 
 
					// Subtract from monster's hitpoints. 
					monster.takeDamage(totalDamage); 
				} 
				return false;
			}
			else 
			{ 
				std::cout << "You miss!" << std::endl; 
			} 
			std::cout << std::endl; 
			return false;
			break;
		case 2:
			//display possible spells
			{
				int select = 1;
				std::string spellName = " ";
				std::cout << "Choose spell :" << std::endl;
				for (int i = 0; i < (int)pSpellBook.size(); ++i)
				{
					std::cout << i+1 << ") " << pSpellBook[i].spellName << " ";
				}
				std::cout << std::endl;
				std::cin >> select;
				while(std::cin.fail() || select > (int)pSpellBook.size())
				{
					std::cout << "Wrong input!" << std::endl;
					std::cin.clear();
					std::cin.ignore(256,'\n');
					std::cin >> select;
				}
				spellName = pSpellBook[select-1].spellName;
				//check if spell chosen by player is shield
				if (spellName == "Shield")
				{
					// check magic points
					if (pMagicPoints < pSpellBook[select-1].spellMagicPointsRequired)
					{
						std::cout << " You don't have enough magica !" << std::endl;
						break;
					}
					else
					{
						std::cout << " Your armor has been doubled! " << std::endl;
						pArmor.armorEffect *= 2;
						pMagicPoints -= pSpellBook[select-1].spellMagicPointsRequired;
					}
					return false;
				}
				else // try to attack monster with this spell
				{
					// check magic points
					if (pMagicPoints < pSpellBook[select-1].spellMagicPointsRequired)
					{
						std::cout << " You don't have enough magica !" << std::endl;
						break;
					}
					// now attack
					else
					{
						std::cout << "You attack an " << monster.getName()  
					<< " with a " << pSpellBook[select-1].spellName << std::endl; 
						if( Random(0, 20) < pAccuracy ) 
						{ 
							int damage = Random(pSpellBook[select-1].spellDamageRange); 
							int totalDamage = damage - monster.getArmor(); 
							if( totalDamage <= 0 ) 
							{ 
								std::cout << "Your attack failed to penetrate " 
									<< "the armor." << std::endl;
							} 
							else 
							{ 
								std::cout << "You attack for " << totalDamage  
									<< " damage!" << std::endl; 

								// Subtract from monster's hitpoints. 
								monster.takeDamage(totalDamage);
								// Substruct magica
								pMagicPoints -= pSpellBook[select-1].spellMagicPointsRequired;
							} 
							return false;
						}
						else 
						{ 
							std::cout << "You miss!" << std::endl; 
						} 
						std::cout << std::endl; 
						return false;
					}
				}
			break;
			}
		case 3:
			{
				int itemSel = 0;
				for(std::vector<Item>::iterator item_it = pItemsInventory.begin(); item_it < pItemsInventory.end(); ++item_it)
					{
						std::cout << std::distance(pItemsInventory.begin(), item_it)+1 << item_it->getName() << " " << item_it->getLabel() << std::endl;	
					}
				std::cout << pItemsInventory.size()+1 << "Quit." << std::endl;
				std::cout << std::endl;
				std::cout << "Choose item: ";

				std::cin >> itemSel;
				while(std::cin.fail() || itemSel > (int)pItemsInventory.size())
				{
					std::cout << "Wrong input!" << std::endl;
					std::cin.clear();
					std::cin.ignore(256,'\n');
					std::cin >> itemSel;
				}

				char use = pItemsInventory[itemSel-1].iType;
				switch(use)
				{
					case 'H':
						{
						int health = pItemsInventory[itemSel-1].getHealth();
						if (pMaxHitPoints - pHitPoints < health && pMaxHitPoints - pHitPoints != 0)
						{
							this->pHitPoints = pMaxHitPoints;
							std::cout << "You have now max HP" << std::endl;
						}
						else
						{
							this->pHitPoints += health;
							std::cout << "You're HP has been replenished" << std::endl;
						}
						break;
						}
					case 'M':
						{
						int mana = pItemsInventory[itemSel-1].getMana();
						if (pMaxMagPoints - pMagicPoints < mana && pMaxMagPoints - pMagicPoints != 0)
						{
							this->pMagicPoints = pMaxMagPoints;
							std::cout << "You have now max mana" << std::endl;
						}
						else
						{
							this->pMagicPoints += mana;
							std::cout << "You're HP has been replenished" << std::endl;
						}
						break;
						}
					case 'S':
						{
						std::cout << "You attack with " << pItemsInventory[itemSel-1].getName() << std::endl;
						int totalDamage = pItemsInventory[itemSel-1].getDamage() - monster.getArmor();
						if( totalDamage <= 0 ) 
						{ 
							std::cout << "Your attack failed to penetrate " 
								<< "the armor." << std::endl;
						} 
						else 
						{
							std::cout << "You attack for " << totalDamage  
								<< " damage!" << std::endl; 

							// Subtract from monster's hitpoints. 
							monster.takeDamage(totalDamage);
						}
						break;
						}
				}

			break;
			}
		case 4: 
			// 25 % chance of being able to run. 
			int roll = Random(1, 4); 
			if( roll == 1 ) 
			{ 
				std::cout << "You run away!" << std::endl; 
				return true;//<--Return out of the function. 
			} 
			else 
			{ 
				std::cout << "You could not escape!" << std::endl; 
				return false;
				break;
			}
	}
}


// tests whether or not the player has acquired enough experience points  to level up
void Player::levelUp(int playerArmor)
{
	//check if armor has changed 
	if (playerArmor != pArmor.armorEffect)
	{
		pArmor.armorEffect = playerArmor;
	}
	if( pExpPoints >= pNextLevelExp ) 
	{ 
		std::cout << "You gained a level!" << std::endl; 
 
		// Increment level. 
		pLevel++; 
 
		// Set experience points required for next level. 
		pNextLevelExp = pLevel * pLevel * 1000; 
 
		// Increase stats (added - depending of the class) 
		if (pClassName == "Fighter")
		{
			pAccuracy     += 3; 
			pMaxHitPoints += 6; 
			pMaxMagPoints	+= 1;
		}
		if (pClassName == "Wizard")
		{
			pAccuracy     += 1; 
			pMaxHitPoints += 3;
			pMaxMagPoints	+= 5;
		}
		if (pClassName == "Cleric")
		{
			pAccuracy     += 2; 
			pMaxHitPoints += 5;
			pMaxMagPoints	+= 4;
		}
		if (pClassName == "Thief")
		{
			pAccuracy     += 2; 
			pMaxHitPoints += 4;
			pMaxMagPoints	+= 3;
		}
		// Give player full hitpoints when they level up. 
		pHitPoints = pMaxHitPoints; 
		pMagicPoints = pMaxMagPoints;
	}
}

//This method is called when the player chooses to rest.
//trying to modify
void Player::rest()
{
	std::cout << "Resting..." << std::endl; 
	pHitPoints = pMaxHitPoints;
	pMagicPoints = pMaxMagPoints;
}

void Player::viewStats()
{
	std::cout << "PLAYER STATS" << std::endl; 
 std::cout << "============" << std::endl; 
 std::cout << std::endl; 
 
 std::cout << "Name            = " << pName         << std::endl;
 std::cout << "Race            = " << pRace         << std::endl;
 std::cout << "Class           = " << pClassName    << std::endl; 
 std::cout << "Accuracy        = " << pAccuracy     << std::endl;
 std::cout << "Hitpoints       = " << pHitPoints    << std::endl;
 std::cout << "MaxHitpoints    = " << pMaxHitPoints << std::endl;
 std::cout << "MagicPoints     = " << pMagicPoints << std::endl;
 std::cout << "MaxMagPoints    = " << pMaxMagPoints << std::endl;
 std::cout << "Gold            = " << pGold			<< std::endl;
 std::cout << "XP              = " << pExpPoints    << std::endl; 
 std::cout << "XP for Next Lvl = " << pNextLevelExp << std::endl; 
 std::cout << "Level           = " << pLevel        << std::endl; 
 std::cout << "Armor Name      = " << pArmor.ArmorName << std::endl;
 std::cout << "Armor Value     = " << pArmor.armorEffect << std::endl;
 std::cout << "Weapon Name     = " << pWeapon.weaponName << std::endl; 
 std::cout << "Weapon Damage   = " << pWeapon.DamageRange.Low  
	 << "-" << pWeapon.DamageRange.High << std::endl; 
 
 std::cout << std::endl; 
 std::cout << "END PLAYER STATS" << std::endl; 
 std::cout << "================" << std::endl; 
 std::cout << std::endl; 
}

//called after a player is victorious in battle
void Player::victory(int xp, int gold)
{
	std::cout << "You won the battle!" << std::endl; 
	std::cout << "You win " << xp 
	 << " experience points!" << std::endl << std::endl;
	pExpPoints += xp;
	std::cout << "You get " << gold << " gold!" << std::endl;
	pGold += gold;
}

std::string Player::getName() const 
{ 
  return pName; 
} 

//This method is called if the player dies in battle
void Player::gameover()
{
	std::cout << "You died in battle..." << std::endl; 
	std::cout << std::endl; 
	std::cout << "================================" << std::endl; 
	std::cout << "GAME OVER!" << std::endl; 
	std::cout << "================================" << std::endl; 
	std::cout << "Press 'q' to quit: "; 
	char q = 'q'; 
	std::cin >> q; 
	std::cout << std::endl; 
}

//This method simply outputs the player’s hit points to the console window
void Player::displayHitPoints()
{
	std::cout << pName << "'s hitpoints = " << pHitPoints << std::endl;
}

bool Player::buyWeapon(std::string name, int sellValue, int lowDmg, int highDmg, int cost)
{
	if (cost > this->pGold)
	{
		std::cout << "Insufficient gold";
		return false;
	}

	this->pWeapon.weaponName = name;
	this->pWeapon.weaponSellValue = sellValue;
	this->pWeapon.DamageRange.Low = lowDmg;
	this->pWeapon.DamageRange.High = highDmg;
	return true;
}

bool Player::buyArmor(std::string name, int sellValue, int effect, int cost)
{
	if (cost > this->pGold)
	{
		std::cout << "Insufficient gold";
		return false;
	}
	
	this->pArmor.ArmorName = name;
	this->pArmor.armorSellValue = sellValue;
	this->pArmor.armorEffect = effect;
	return true;
}

bool Player::buyItem(Item& item)
{
	if (item.getBuyValue() > this->pGold)
	{
		std::cout << "Insufficient gold";
		return false;
	}
	
	pItemsInventory.push_back(item);

}

void Player::sellArmor()
{
	std::cout << "Selling armor..." << std::endl;
	this->pGold += this->pArmor.armorSellValue;
	this->pArmor.ArmorName = "rags";
	this->pArmor.armorEffect = 0;
	this->pArmor.armorSellValue = 0;
}

void Player::sellWeapon()
{
	std::cout << "Selling weapon..." << std::endl;
	this->pGold += this->pWeapon.weaponSellValue;
	this->pWeapon.weaponName = "Stick";
	this->pWeapon.weaponSellValue = 0;
	this->pWeapon.DamageRange.Low  = 0; 
	this->pWeapon.DamageRange.High = 0;
}

void Player::sellItem()
{
	int sel = 0;
	for(std::vector<Item>::iterator item_it = pItemsInventory.begin(); item_it < pItemsInventory.end(); ++item_it)
	{
		std::cout << std::distance(pItemsInventory.begin(), item_it)+1 << ": " << item_it->getName() << " " << item_it->getsellValue() << std::endl;	
	}
	std::cout << "What would you like to sell? " << std::endl;
	std::cin >> sel;
	if (sel > int(pItemsInventory.size()))
	{
		std::cout << "Wrong choice!" << std::endl;
	}
	else
	{
		std::cout << pItemsInventory[sel-1].getName() << " sold" << std::endl;
		pGold += pItemsInventory[sel-1].getsellValue();
		pItemsInventory.erase(pItemsInventory.begin()+ sel-1); 
	}
}

void Player::viewInventory()
{
	for(std::vector<Item>::iterator item_it = pItemsInventory.begin(); item_it < pItemsInventory.end(); ++item_it)
	{
		std::cout << item_it->getName() << " " << item_it->getLabel() << std::endl;	
	}
	std::cout << std::endl;
}