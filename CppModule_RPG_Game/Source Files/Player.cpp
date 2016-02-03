// Player.cpp

#include "Monster.h"
#include "Player.h"
#include "Random.h"
#include "Structures.h"
#include "Map.h"
#include <iostream>
#include <string>
#include <vector>


// constructor
Player::Player() 
{
	mName			= "Default"; 
	mClassName		= "Default";
	mRace			= "Default";
	mAccuracy		= 0; 
	mHitPoints		= 0; 
	mMaxHitPoints	= 0;
	mMagicPoints	= 0;
	mMaxMagPoints	= 0;
	mExpPoints		= 0; 
	mNextLevelExp	= 0; 
	mLevel			= 0; 
	mArmor			= 0;
	mGold			= 0;	
	mWeapon.weaponName = "Default Weapon Name"; 
	mWeapon.mDamageRange.mLow  = 0; 
	mWeapon.mDamageRange.mHigh = 0;

	// creating spellBook
	//fireball
	Spell s1;
	s1.spellName = "Fireball";
	s1.spellDamageRange.mHigh = 18;
	s1.spellDamageRange.mLow = 5;
	s1.spellMagicPointsRequired = 15;
	mSpellBook.push_back(s1);
	Spell s2;
	s2.spellName = "Magic missle";
	s2.spellDamageRange.mHigh = 13;
	s2.spellDamageRange.mLow = 7;
	s2.spellMagicPointsRequired = 15;
	mSpellBook.push_back(s2);
	Spell s3;
	s3.spellName = "Shield";
	s3.spellDamageRange.mHigh = 0;
	s3.spellDamageRange.mLow = 0;
	s3.spellMagicPointsRequired = 40;
	mSpellBook.push_back(s3);
}


// check if players is dead
bool Player::isDead()
{
	return mHitPoints <= 0; 
}


// accessor method
int Player::getArmor()
{
	return mArmor;
}

// This method is called when a monster hits a player
void Player::takeDamage(int damage)
{
	mHitPoints -= damage;
}

// this code performs the character generation process
void Player::createClass()
{
	std::cout << "CHARACTER CLASS GENERATION" << std::endl;
	std::cout << "==========================" << std::endl;
	
	// Input character's name.
	std::cout << "Enter your character's name: "; 
	getline(std::cin, mName);

	//Race selection
	std::cout << "Please select a character race number..." << std::endl;
	std::cout << "1)Human 2)Elf 3)Dwarf : ";
	int raceNum = 1;
	std::cin >> raceNum;
	
	// Character selection.
	std::cout << "Please select a character class number..."<< std::endl;  
	std::cout << "1)Fighter 2)Wizard 3)Cleric 4)Thief : ";  
	int characterNum = 1;  
	std::cin >> characterNum; 

	switch( characterNum ) 
	{
		case 1:  // Fighter
			mClassName		= "Fighter"; 
			mAccuracy		= 10; 
			mHitPoints		= 20; 
			mMaxHitPoints	= 20;
			mMagicPoints	= 30;
			mMaxMagPoints	= 30;
			mExpPoints		= 0;
			mNextLevelExp	= 1000; 
			mLevel			= 1; 
			mArmor			= 4; 
			mWeapon.weaponName	= "Long Sword"; 
			mWeapon.mDamageRange.mLow  = 1; 
			mWeapon.mDamageRange.mHigh = 8; 
			break;
		case 2:  // Wizard
			mClassName    = "Wizard"; 
			mAccuracy     = 5; 
			mHitPoints    = 10; 
			mMaxHitPoints = 10; 
			mMagicPoints	= 80;
			mMaxMagPoints	= 80;
			mExpPoints    = 0; 
			mNextLevelExp = 1000;
			mLevel        = 1; 
			mArmor        = 1; 
			mWeapon.weaponName = "Staff"; 
			mWeapon.mDamageRange.mLow  = 1; 
			mWeapon.mDamageRange.mHigh = 4; 
			break;
		case 3:	// Cleric
			mClassName		= "Cleric";
			mAccuracy		= 8; 
			mHitPoints		= 15;
			mMaxHitPoints	= 15;
			mMagicPoints	= 60;
			mMaxMagPoints	= 60;
			mExpPoints		= 0;
			mNextLevelExp	= 1000;
			mLevel			= 1;
			mArmor			= 3;
			mWeapon.weaponName	= "Flail";
			mWeapon.mDamageRange.mLow  = 1;
			mWeapon.mDamageRange.mHigh = 6;
			break;
		default: // Thief
			mClassName		= "Thief";
			mAccuracy		= 7; 
			mHitPoints		= 12;
			mMaxHitPoints	= 12;
			mMagicPoints	= 50;
			mMaxMagPoints	= 50;
			mExpPoints		= 0;
			mNextLevelExp	= 1000;
			mLevel			= 1;
			mArmor			= 2;
			mWeapon.weaponName	= "Short Sword";
			mWeapon.mDamageRange.mLow  = 1;
			mWeapon.mDamageRange.mHigh = 6;
			break;
	}
	
	switch(raceNum)
	{
	case 1:
			mRace			= "Human";
			mAccuracy		-= 1;
			mHitPoints		+= 2;
			mMaxHitPoints	+= 2;
			mMagicPoints	+= 1;
			mMaxMagPoints	+= 1;
			mArmor			+= 1;
			break;
	case 2:
			mRace			= "Elf";
			mAccuracy		+= 3; 
			mHitPoints		-= 4;
			mMaxHitPoints	-= 4;
			mMagicPoints	+= 4;
			mMaxMagPoints	+= 4;
			mArmor			-= 2;
			break;
	default:
			mRace			= "Dwarf";
			mAccuracy		-= 3; 
			mHitPoints		+= 5; 
			mMaxHitPoints	+= 5;
			mMagicPoints	-= 2;
			mMaxMagPoints	-= 2;
			mArmor			+=3;
			break;
	}
}


bool Player::attack(Monster& monster)
{
	int selection = 1; 
	std::cout << "1) Attack, 2) Cast spell 3) Run: "; 
	std::cin >> selection; 
	std::cout << std::endl;
	switch( selection ) 
	{
		case 1: 
			std::cout << "You attack an " << monster.getName()  
				<< " with a " << mWeapon.weaponName << std::endl; 
			if( Random(0, 20) < mAccuracy ) 
			{ 
				int damage = Random(mWeapon.mDamageRange); 
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
			{int select = 1;
			std::string spellName = " ";
			std::cout << "Choose spell :" << std::endl;
			for (int i = 0; i < (int)mSpellBook.size(); ++i)
			{
				std::cout << i+1 << ") " << mSpellBook[i].spellName << " ";
			}
			std::cout << std::endl;
			std::cin >> select;
			spellName = mSpellBook[select-1].spellName;
			//check if spell chosen by player is shield
			if (spellName == "Shield")
			{
				// check magic points
				if (mMagicPoints < mSpellBook[select-1].spellMagicPointsRequired)
				{
					std::cout << " You don't have enough magica !" << std::endl;
					break;
				}
				else
				{
					std::cout << " Your armor has been doubled! " << std::endl;
					mArmor *= 2;
					mMagicPoints -= mSpellBook[select-1].spellMagicPointsRequired;
				}
				return false;
			}
			else // try to attack monster with this spell
			{
				// check magic points
				if (mMagicPoints < mSpellBook[select-1].spellMagicPointsRequired)
				{
					std::cout << " You don't have enough magica !" << std::endl;
					break;
				}
				// now attack
				else
				{
					std::cout << "You attack an " << monster.getName()  
				<< " with a " << mSpellBook[select-1].spellName << std::endl; 
					if( Random(0, 20) < mAccuracy ) 
					{ 
						int damage = Random(mSpellBook[select-1].spellDamageRange); 
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
							mMagicPoints -= mSpellBook[select-1].spellMagicPointsRequired;
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
			break;}
		case 3: 
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
	if (playerArmor != mArmor)
	{
		mArmor = playerArmor;
	}
	if( mExpPoints >= mNextLevelExp ) 
	{ 
		std::cout << "You gained a level!" << std::endl; 
 
		// Increment level. 
		mLevel++; 
 
		// Set experience points required for next level. 
		mNextLevelExp = mLevel * mLevel * 1000; 
 
		// Increase stats (added - depending of the class) 
		if (mClassName == "Fighter")
		{
			mAccuracy     += 3; 
			mMaxHitPoints += 6; 
			mMaxMagPoints	+= 1;
			mArmor        += 2;
		}
		if (mClassName == "Wizard")
		{
			mAccuracy     += 1; 
			mMaxHitPoints += 3;
			mMaxMagPoints	+= 5;
			mArmor        += 1;
		}
		if (mClassName == "Cleric")
		{
			mAccuracy     += 2; 
			mMaxHitPoints += 5;
			mMaxMagPoints	+= 4;
			mArmor        += 2;
		}
		if (mClassName == "Thief")
		{
			mAccuracy     += 2; 
			mMaxHitPoints += 4;
			mMaxMagPoints	+= 3;
			mArmor        += 1; 
		}
		// Give player full hitpoints when they level up. 
		mHitPoints = mMaxHitPoints; 
		mMagicPoints = mMaxMagPoints;
	}
}

//This method is called when the player chooses to rest.
//trying to modify
void Player::rest()
{
	std::cout << "Resting..." << std::endl; 
	mHitPoints = mMaxHitPoints;
	mMagicPoints = mMaxMagPoints;
}

void Player::viewStats()
{
	std::cout << "PLAYER STATS" << std::endl; 
 std::cout << "============" << std::endl; 
 std::cout << std::endl; 
 
 std::cout << "Name            = " << mName         << std::endl;
 std::cout << "Race            = " << mRace         << std::endl;
 std::cout << "Class           = " << mClassName    << std::endl; 
 std::cout << "Accuracy        = " << mAccuracy     << std::endl;
 std::cout << "Hitpoints       = " << mHitPoints    << std::endl;
 std::cout << "MaxHitpoints    = " << mMaxHitPoints << std::endl;
 std::cout << "MagicPoints     = " << mMagicPoints << std::endl;
 std::cout << "MaxMagPoints    = " << mMaxMagPoints << std::endl;
 std::cout << "Gold            = " << mGold			<< std::endl;
 std::cout << "XP              = " << mExpPoints    << std::endl; 
 std::cout << "XP for Next Lvl = " << mNextLevelExp << std::endl; 
 std::cout << "Level           = " << mLevel        << std::endl; 
 std::cout << "Armor           = " << mArmor        << std::endl; 
 std::cout << "Weapon Name     = " << mWeapon.weaponName << std::endl; 
 std::cout << "Weapon Damage   = " << mWeapon.mDamageRange.mLow  
	 << "-" << mWeapon.mDamageRange.mHigh << std::endl; 
 
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
	mExpPoints += xp;
	std::cout << "You get " << gold << " gold!" << std::endl;
	mGold += gold;
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
	std::cout << mName << "'s hitpoints = " << mHitPoints << std::endl;
}
