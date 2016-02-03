//Monster.cpp

#include <iostream>
#include <string>
#include "Monster.h"
#include "Random.h"
#include "Player.h"

//constructor
Monster::Monster(const std::string& name, int hp, int acc, 
   int xpReward, int armor, const std::string& weaponName, 
   int lowDamage, int highDamage, Player &player) 
{ 
 mName      = name; 
 mHitPoints = hp + player.; 
 mAccuracy  = acc; 
 mExpReward = xpReward; 
 mArmor     = armor; 
 mWeapon.weaponName = weaponName; 
 mWeapon.mDamageRange.mLow  = lowDamage; 
 mWeapon.mDamageRange.mHigh = highDamage; 
}
//check if monster is dead
bool Monster::isDead() 
{ 
  return mHitPoints <= 0; 
} 

//accessor method
int Monster::getXPReward() 
{ 
  return mExpReward; 
}

//accessor method
std::string Monster::getName() 
{ 
  return mName; 
} 

//accessor method
int Monster::getArmor() 
{ 
  return mArmor; 
} 

//computes monster attack
void Monster::attack(Player& player) 
{ 
 std::cout << "A " << mName << " attacks you "  
  << "with a " << mWeapon.weaponName << std::endl; 
 
  if( Random(0, 20) < mAccuracy ) 
 { 
   int damage = Random(mWeapon.mDamageRange); 
 
   int totalDamage = damage - player.getArmor(); 
 
   if( totalDamage <= 0 ) 
  { 
   std::cout << "The monster's attack failed to " 
    << "penetrate your armor." << std::endl; 
  } 
   else 
  { 
   std::cout << "You are hit for " << totalDamage  
    << " damage!" << std::endl; 
 
   player.takeDamage(totalDamage); 
  } 
 } 
  else 
 { 
  std::cout << "The " << mName << " missed!" << std::endl; 
 } 
  std::cout << std::endl; 
} 

//This method is called when a player hits a monster
void Monster::takeDamage(int damage) 
{ 
 mHitPoints -= damage; 
} 

//outputs the monster’s hit points during battle
void Monster::displayHitPoints() 
{ 
 std::cout << mName << "'s hitpoints = " << mHitPoints << std::endl; 
}  

