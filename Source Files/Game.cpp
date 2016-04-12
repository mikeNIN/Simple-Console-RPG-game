// game.cpp 

#include "Map.h" 
#include "Player.h" 
#include "Random.h"
#include "Store.h"
#include <cstdlib> 
#include <ctime> 
#include <iostream> 
using namespace std; 
 
int main() 
{ 
 srand(int(time(NULL)));

 Map gameMap;
 Player mainPlayer; 
 mainPlayer.createClass();

 // Begin adventure. 
bool done = false; 
while( !done ) 
{ 
  // Each loop cycly we output the player position and  
  // a selection menu. 
 
 gameMap.printPlayerPos(); 
  
 int selection = 1;

 cout << "1) Move, 2) Rest, 3) View Stats, 4) Inventory, 5) Quit: "; 
 cin >> selection; 
 
 //Monster* monster = 0; 
  switch( selection ) 
 {
	 case 1:
		 {
			 // Move the player. 
			gameMap.movePlayer(); 
 
		if( gameMap.getPlayerXPos() == 1 &&  
			gameMap.getPlayerYPos() == 1 ) 
		{ 
			Store store; 
			store.enter(mainPlayer);
			break;
		}

	  // Check for a random encounter.  This function 
	  // returns a null pointer if no monsters are 
	  // encountered. 
	 std::vector<Monster> monsters = gameMap.checkRandomEncounter(); 
	 
	  // 'monster' not null, run combat simulation. 
	  
		  if( monsters.size() != 0 ) 
		{ 
		 // Loop until a 'break' statement
		 //keep armor in case player choose shield 
		   int playerArmor = mainPlayer.getArmor();
		   for (int idx = 0; idx < int(monsters.size()); idx ++)
		   {	
			   while( true ) 
			   {
				   // Display hitpoints
					mainPlayer.displayHitPoints(); 
					monsters[idx].displayHitPoints(); 
					cout << endl; 
					bool runAway = mainPlayer.attack(monsters[idx]); 
					if( runAway )
					{
						mainPlayer.levelUp(playerArmor);
						idx = int(monsters.size());
						break;
					}
					if( monsters[idx].isDead() ) 
					{
						mainPlayer.victory(monsters[idx].getXPReward(), gameMap.generateGold(monsters[idx]));
						mainPlayer.levelUp(playerArmor); 
						break; 
					} 
					monsters[idx].attack(mainPlayer); 
					cout << endl; 
					if( mainPlayer.isDead() ) 
					{ 
						mainPlayer.gameover(); 
						done = true; 
						break; 
					}
				}
		   }
		  }
		 }
	break;
case 2:
	if ((Random(1, 4) == 1))
	{
		std::vector<Monster> monsters;
		while(true)
		{
			monsters = gameMap.checkRandomEncounter();
			if (monsters.size()!= 0)
				break;
		}
		// :/duplicated code
		int playerArmor = mainPlayer.getArmor();
		for (int idx = 0; idx < int(monsters.size()); idx ++)
		{	
			while( true ) 
			{
				mainPlayer.displayHitPoints(); 
				monsters[idx].displayHitPoints();
				cout << endl;
				monsters[idx].attack(mainPlayer); 
				if( mainPlayer.isDead() ) 
				{ 
					mainPlayer.gameover(); 
					done = true; 
					break; 
				}
				bool runAway = mainPlayer.attack(monsters[idx]);
				if( runAway )
				{
					//it's fucked up idea at that moment, must create 
					//another method to zero armor
					mainPlayer.levelUp(playerArmor);
					idx = int(monsters.size());
					break;
				}
				if( monsters[idx].isDead() ) 
				{
					mainPlayer.victory(monsters[idx].getXPReward(), gameMap.generateGold(monsters[idx]));
					mainPlayer.levelUp(playerArmor); 
					break; 
				}

			}
		}
	}
	else
	{
		mainPlayer.rest();
	}
   break; 
case 3: 
    mainPlayer.viewStats(); 
	break;
case 4:
	mainPlayer.viewInventory();
	break;
case 5: 
   done = true; 
   break;
   }// End Switch Statement 
   }// End While Statement 
}// End main function. 
