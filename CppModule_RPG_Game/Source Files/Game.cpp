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
 cout << "1) Move, 2) Rest, 3) View Stats, 4) Quit: "; 
 cin >> selection; 
 
 Monster* monster = 0; 
  switch( selection ) 
 {
	 case 1: 
      // Move the player. 
 gameMap.movePlayer(); 
 
 if( gameMap.getPlayerXPos() == 1 &&  
    gameMap.getPlayerYPos() == 1 ) 
{ 
 Store store; 
 store.enter(mainPlayer); 
}

  // Check for a random encounter.  This function 
  // returns a null pointer if no monsters are 
  // encountered. 
 monster = gameMap.checkRandomEncounter(); 
 
  // 'monster' not null, run combat simulation. 
  
      if( monster != 0 ) 
 { 
	 // Loop until a 'b
	 //keep armor in case player choose shield 
	   int playerArmor = mainPlayer.getArmor(); 
    while( true ) 
   {
    // Display hitpoints
   mainPlayer.displayHitPoints(); 
   monster->displayHitPoints(); 
   cout << endl; 
   bool runAway = mainPlayer.attack(*monster); 
	if( runAway )
	{
		//it's fucked up idea at that moment, must create 
		//another method to zero armor
		mainPlayer.levelUp(playerArmor); 
		break;
	}
 
    if( monster->isDead() ) 
   {
   mainPlayer.victory(monster->getXPReward(), gameMap.generateGold(*monster));
   mainPlayer.levelUp(playerArmor); 
   break; 
   } 
 
	monster->attack(mainPlayer); 
 
    if( mainPlayer.isDead() ) 
   { 
	   mainPlayer.gameover(); 
	   done = true; 
	   break; 
   } 
	} 
 
   // The pointer to a monster returned from 
   // checkRandomEncounter was allocated with 
   // 'new', so we must delete it to avoid 
   // memory leaks. 
   delete monster; 
  monster = 0; 
	  }
 
break;
case 2:
	if ((Random(1, 4) == 1))
	{
		while(true)
		{
			if ((monster = gameMap.checkRandomEncounter())!= 0)
				break;
		}
		// :/duplicated code
		int playerArmor = mainPlayer.getArmor(); 
		while( true ) 
		{
			mainPlayer.displayHitPoints(); 
			monster->displayHitPoints();
			cout << endl;
			monster->attack(mainPlayer); 
			if( mainPlayer.isDead() ) 
			{ 
				mainPlayer.gameover(); 
				done = true; 
				break; 
			}
			bool runAway = mainPlayer.attack(*monster); 
			if( runAway )
			{
				//it's fucked up idea at that moment, must create 
				//another method to zero armor
				mainPlayer.levelUp(playerArmor); 
				break;
			}
			if( monster->isDead() ) 
			{
				mainPlayer.victory(monster->getXPReward(), gameMap.generateGold(*monster));
				mainPlayer.levelUp(playerArmor); 
				break; 
			}

		}
	}
   mainPlayer.rest(); 
   break; 
     case 3: 
   mainPlayer.viewStats(); 
   break; 
     case 4: 
   done = true; 
   break;
   }// End Switch Statement 
   }// End While Statement 
}// End main function. 
