// Player.h 
 
#ifndef PLAYER_H 
#define PLAYER_H 
 
#include "Structures.h"
#include "Monster.h"
#include <string>
#include <vector>

 
class Player 
{ 
public: 
  // Constructor. 
 Player(); 
 
  // Methods 
  bool isDead(); 
  std::string getName(); 
  int  getArmor(); 
  void takeDamage(int damage); 
  void createClass(); 
  bool attack(Monster& monster); 
  void levelUp(int playerArmor); 
  void rest(); 
  void viewStats(); 
  void victory(int xp, int gold); 
  void gameover(); 
  void displayHitPoints();
  
private: 
  // Data members.
  std::string mName; 
  std::string mClassName;
  std::string mRace;
  int         mAccuracy; 
  int         mHitPoints; 
  int         mMaxHitPoints;
  int		  mMagicPoints;
  int		  mMaxMagPoints;
  int         mExpPoints; 
  int         mNextLevelExp; 
  int         mLevel; 
  int         mArmor; 
  int		  mGold;
  std::vector<Spell> mSpellBook;
  Weapon      mWeapon;
  Spell		  mSpell;
}; 
 
#endif //PLAYER_H