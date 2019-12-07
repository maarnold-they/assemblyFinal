//levelTemplate.h
//Header file containing prototypes for levels,
//as well as the structs for character, opponent, and ability
//A sort-of hub file that links it all together
//William, Millard, Harrison
//Dec. 7, 2019

//Project Details
//Make a text-based adventure game
//featuring many choices, turn-based combat, and an inventory system
//utilizing bitwise operations.

#ifndef LEVELTEMPLATE_H
#define LEVELTEMPLATE_H
#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<vector>

//struct for abilities
struct ability
{
	std::string name; //name of ability
	int damageBoost; //how much damage does it deal (or heal)
	int MPcost; //how much MP it costs to use
	bool attack; //is it an attacking ability?
	bool support; //is it a healing ability?
};

//struct for main character object
struct character
{
	std::string name; //Player's name
	int aggression = 0; //Aggression level; increases when aggressive choices are chosen
	unsigned long long inventory = 0; //needed it to be 64 bits of unsigned.
	int maxHP = 40; //Maximum HP
	int HP = maxHP; //Current HP
	int maxMP = 5; //Maximum MP
	int MP = maxMP; //Current MP
	std::vector<ability> abilities; //vector of abilities, contains all abilities the player has learned
	int exp = 0; //how many experience points the player has
	int level = 1; //the current level of the player
};

//struct for enemy object
struct opponent
{
	int maxHP; //Maximum HP
	int HP; //Current HP
	std::string name; //Enemy's name
	int attack; //How much damage enemy deals
	int money; //How much money enemy drops
	int exp; //How many experience points enemy drops
};

/*
	weapon, utility, and key are all integers so that you only have
	to know them relative to their own parts of the inventory and
	then it's not such a ridiculously complicated inventory.
*/
void newWeapon(int weapon, character& protag);
void newUtility(int utility, character& protag);
void newKey(int key, character& protag);
bool checkWeapon(int weapon, character& protag);
bool checkUtility(int utility, character& protag);
bool checkKey(int key, character& protag);

//notes on inventory:
//first 32 bits be for keys
//next 16 bits for weapons (1 on person at a time)
//final 16 bits for utility purposes (like a candlestick)

//unsigned long long noWeapons = 0xFFff0000FFffFFff; //removes all weapons when put through & operation.

//combat.cpp functions
bool fight(character& protag, opponent& enemy);

void fightHeader(opponent enemy);

void printHUD(std::vector<std::pair<std::string, std::string>> options, int& weapon, std::string input,
	character& protag, opponent& enemy);

//All-around functions
void typo(); //located at top of level0.cpp

void newAbility(character& mainChar, ability newMove); //located at top of level0.cpp

//level0.cpp functions
std::string lvl0Start(character& mainChar, std::string& notableChoice, std::string& choice);

std::string lvl0Hall(character& mainChar, std::string& notableChoice, std::string& choice);

std::string lvl0Lair(character& mainChar, std::string& notableChoice, std::string& choice);

//level1.cpp functions
std::string lvl1Start(character& mainChar, std::string& notableChoice, std::string& choice);

std::string lvl1Kitchen(character& mainChar, std::string& notableChoice, std::string& choice);

std::string lvl1Wardrobe(character& mainChar, std::string& notableChoice, std::string& choice);

std::string lvl1Staircase(character& mainChar, std::string& notableChoice, std::string& choice);

//level2.cpp functions
std::string lvl2Start(character& mainChar, std::string& choice, bool& thugCheck);

std::string lvl2Bathroom(character& mainChar, std::string& choice, bool& thugCheck);

std::string lvl2livingRoom(character& mainChar, std::string& choice, bool& thugCheck);

//level3.cpp functions
std::string lvl3Start(character& mainChar, std::string& notableChoice, std::string& choice);

std::string lvl3Breakroom(character& mainChar, std::string& notableChoice, std::string& choice);

#endif