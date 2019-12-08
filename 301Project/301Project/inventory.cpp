//inventory.cpp
//contains the code for the inventory system
//William, Millard, Harrison
//Dec. 7, 2019

#include "levelTemplate.h"

const unsigned long long noWeapons = 0xFFff0000FFffFFff; //Constant designed to remove all the weapons so that only one weapon is held at a time.

/*
The new weapon function removes all weapons and then adds a new one, but the others just add a new item of the correct type by flipping the bits that correspond with it.
Takes input of the item & character.
*/
void newWeapon(int weapon, character& protag)
{
	protag.inventory = (protag.inventory & noWeapons) | ((unsigned long long)weapon << 32);
}
void newUtility(int utility, character& protag)
{
	protag.inventory = protag.inventory | ((unsigned long long)utility << 48);
}
void newKey(int key, character& protag)
{
	protag.inventory = protag.inventory | (key);
}

/*
The check functions check to see if the correct bits are flipped to correspond to the specific item for each item type.
Takes input of the item & character.
*/
bool checkWeapon(int weapon, character& protag)
{
	return weapon == (int)((protag.inventory >> 32) & weapon);
}
bool checkUtility(int utility, character& protag)
{
	return utility == (int)((protag.inventory >> 48)&utility);
}
bool checkKey(int key, character& protag)
{
	return key == (int)(protag.inventory & key);
}