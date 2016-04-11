// Player.h 
 
#ifndef PLAYER_H 
#define PLAYER_H 
 
#include "Structures.h"
#include "Monster.h"
#include "Items.h"
#include <string>
#include <vector>

 
class Player 
{ 
public: 
  // Constructor. 
 Player(); 
 
  // Methods 
  bool isDead(); 
  std::string getName() const;
  int getArmor() const;
  bool buyWeapon(std::string name, int sellValue, int lowDmg, int highDmg, int cost);
  bool buyArmor(std::string name, int sellValue, int effect, int cost);
  bool buyItem(Item& item);
  void sellArmor();
  void sellWeapon();
  void sellItem();
  void takeDamage(int damage); 
  void createClass(); 
  bool attack(Monster& monster); 
  void levelUp(int playerArmor); 
  void rest(); 
  void viewStats(); 
  void victory(int xp, int gold); 
  void gameover(); 
  void displayHitPoints();
  void viewInventory();
  
private: 
  // Data members.
  std::string pName; 
  std::string pClassName;
  std::string pRace;
  int         pAccuracy; 
  int         pHitPoints; 
  int         pMaxHitPoints;
  int		  pMagicPoints;
  int		  pMaxMagPoints;
  int         pExpPoints; 
  int         pNextLevelExp; 
  int         pLevel; 
  int		  pGold;
  std::vector<Spell> pSpellBook;
  Armor       pArmor;
  Weapon      pWeapon;
  Spell		  pSpell;
  std::vector<Item> pItemsInventory;
}; 
 
#endif //PLAYER_H