//constructor

#include <iostream>
#include "Map.h"
#include "Random.h"

Map::Map() 
{ 
  // Player starts at origin (0, 0) 
 mPlayerXPos = 0; 
 mPlayerYPos = 0; 
} 

//accessor function x-position
int  Map::getPlayerXPos() 
{ 
  return mPlayerXPos; 
} 

//accessor function y-position
int  Map::getPlayerYPos() 
{ 
  return mPlayerYPos; 
} 

//keep track of the player�s position
void Map::movePlayer() 
{ 
 int selection = 1; 
 std::cout << "1) North, 2) East, 3) South, 4) West: "; 
 std::cin >> selection;
 while(std::cin.fail())
	{
		std::cout << "Wrong input!" << std::endl;
		std::cin.clear();
        std::cin.ignore(256,'\n');
		std::cin >> selection;
	}
 
  // Update coordinates based on selection. 
  switch( selection ) 
 { 
  case 1: // North 
  mPlayerYPos++; 
   break; 
  case 2: // East 
  mPlayerXPos++; 
   break; 
  case 3: // South 
  mPlayerYPos--; 
   break; 
  default: // West 
  mPlayerXPos--; 
   break; 
 } 
 std::cout << std::endl; 
} 

//
std::vector<Monster> Map::checkRandomEncounter() 
{ 
	int howMany = Random(1, 5);
	int count = 0;
	

	std::vector<Monster> monsters_vec;

	Monster* monster = 0;
	while (count < howMany)
	{
		int roll = Random(0, 20);	 
		
		if( roll <= 5 ) 
		{ 
			count ++;
			continue;
		} 
		else if(roll >= 6 && roll <= 10) 
		{ 
			monster = new Monster("Orc", 10, 8, 200, 1,  
			"Short Sword", 2, 7); 
			std::cout << "You encountered an Orc!" << std::endl; 
			std::cout << "Prepare for battle!" << std::endl; 
			std::cout << std::endl; 
		} 
		else if(roll >= 11 && roll <= 15) 
		{ 
		monster = new Monster("Goblin", 6, 6, 100, 0,  
		"Dagger", 1, 5); 
		std::cout << "You encountered a Goblin!" << std::endl; 
		std::cout << "Prepare for battle!" << std::endl; 
		std::cout << std::endl; 
		} 
		else if(roll >= 16 && roll <= 19) 
		{ 
		monster = new Monster("Ogre", 20, 12, 500, 2, 
		"Club", 3, 8); 
		std::cout << "You encountered an Ogre!" << std::endl; 
		std::cout << "Prepare for battle!" << std::endl; 
		std::cout << std::endl; 
		}   
		else if(roll == 20) 
		{ 
		monster = new Monster("Orc Lord", 25, 15, 2000, 5, 
		"Two Handed Sword", 5, 20); 
	 
		std::cout << "You encountered an Orc Lord!!!" << std::endl; 
		std::cout << "Prepare for battle!" << std::endl; 
		std::cout << std::endl; 
		}
		monsters_vec.push_back(* monster);
		count++;
	}

	return monsters_vec;
} 

//printing player's current coordinates in main menu
void Map::printPlayerPos() 
{ 
 std::cout << "Player Position = (" << mPlayerXPos << ", "  
  << mPlayerYPos << ")" << std::endl << std::endl; 
} 

//added code for gold generator
int Map::generateGold(Monster& monster)
{
	if (monster.getName() == "Ogre")
	{
		return (Random(11, 20))*10;
	}
	if (monster.getName() == "Orc Lord")
	{
		return (Random(11, 20))*20;
	}
	else
		return (Random(1, 10))*10;
}
 