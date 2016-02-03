//Store.cpp

#include "Store.h"
#include "Player.h"
#include <iostream> 


Store::Store()
{
	Weapon w1, w2, w3, w4, w5, w6, w7, w8, w9, w10;
	w1.weaponName = "bastard sword";
	w1.mDamageRange.mLow = 4;
	w1.mDamageRange.mHigh = 12;
	w1.weaponValue = 1100;
	w2.weaponName = "two handed sword";
	w2.mDamageRange.mLow = 8;
	w2.mDamageRange.mHigh = 18;
	w2.weaponValue = 2700;
	w3.weaponName = "war bow";
	w3.mDamageRange.mLow = 4;
	w3.mDamageRange.mHigh = 9;
	w3.weaponValue = 900;
	w4.weaponName = "spear";
	w4.mDamageRange.mLow = 5;
	w4.mDamageRange.mHigh = 11;
	w4.weaponValue = 1200;
	w5.weaponName = "lighter staff of power";
	w5.mDamageRange.mLow = 3;
	w5.mDamageRange.mHigh = 6;
	w5.weaponValue = 600;
	w6.weaponName = "staff of power";
	w6.mDamageRange.mLow = 5;
	w6.mDamageRange.mHigh = 9;
	w6.weaponValue = 900;
	w7.weaponName = "lighter flail";
	w7.mDamageRange.mLow = 3;
	w7.mDamageRange.mHigh = 8;
	w7.weaponValue = 550;
	w8.weaponName = "heavy flail";
	w8.mDamageRange.mHigh = 7;
	w8.mDamageRange.mLow = 11;
	w8.weaponValue = 
}

void Store::enter(Player &player)
{
	//int dec
	std::cout << "enter method";
}