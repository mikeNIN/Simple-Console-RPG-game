
#include "Items.h"
#include <vector>
#include <sstream>

//Constructors

Item::Item(const std::string& name, int sellValue, int BuyValue, int effect, char type)
{
	
	std::stringstream ss;

	this->iName = name;
	this->iSellValue = sellValue;
	this->iBuyValue = BuyValue;
	this->iType = type;
	
	switch(type)
	{
		case 'S':
			this->iDamage = effect;
			ss << iDamage;
			this->label = " damages for " + ss.str();
			break;
		case 'M':
			this->iMana = effect;
			ss << iMana;
			this->label = " restores " + ss.str() + " mana";
			break;
		case 'H':
			this->iHealth = effect;
			ss << iHealth;
			this->label = " restores " + ss.str() + " HP";
			break;
		default:
			break;
	}

}

//Methods

std::string Item::getName() const
{
	return iName;
}

int Item::getsellValue() const
{
	return iSellValue;
}

int Item::getBuyValue() const
{
	return iBuyValue;
}

int Item::getDamage() const
{
	return iDamage;
}

int Item::getHealth() const
{
	return iHealth;
}

int Item::getMana() const
{
	return iMana;
}

std::string Item::getLabel() const
{
	return label;
}