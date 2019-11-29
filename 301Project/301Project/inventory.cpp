#include "levelTemplate.h"
unsigned long long noWeapons = 0xFFff0000FFffFFff;
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
bool checkWeapon(int weapon, character& protag)
{
	return weapon == (int)((protag.inventory >> 32) & 0xFFff);
}
bool checkUtility(int utility, character& protag)
{
	return utility == (int)(protag.inventory >> 48);
}
bool checkKey(int key, character& protag)
{
	return key == (int)(protag.inventory & 0xFFffFFff);
}