#ifndef ITEMS_H
#define ITEMS_H

#include <string>


class Item{

public:
	//Constructors
	//Item();
	Item(const std::string& name, int sellValue, int BuyValue, int effect, char type);
	
	//Methods:
	std::string getName() const;
	int getsellValue() const;
	int getBuyValue() const;
	int getDamage() const;
	int getHealth() const;
	int getMana() const;
	std::string getLabel() const;

	char iType;

private:
	//Members
	std::string iName;
	int iSellValue;
	int iBuyValue;
	int iDamage;
	int iHealth;
	int iMana;
	std::string label;
};

#endif //ITEMS_H