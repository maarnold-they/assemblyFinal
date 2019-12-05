//levelTemplate.h
//Header file containing prototypes for levels,
//as well as the character struct
//William, Millard, Harrison

//Project Details
//Make a text-based choose-your-own-adventure game
//featuring turn-based combat and an inventory system
//utilizing bitwise operations.

#ifndef LEVELTEMPLATE_H
#define LEVELTEMPLATE_H
#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<vector>

//struct for main character object
struct character
{
	std::string name;
	int aggression = 0;
	unsigned long long inventory = 0; //needed it to be 64 bits of unsigned.
	int maxHP = 40;
	int HP = maxHP;
	std::vector<std::pair<std::string, int>> abilities;
	int exp = 0;
	int level = 1;
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

//struct for enemy object
struct opponent
{
	int maxHP;
	int HP;
	std::string name;
	//moves has a list of moves along with their damage values
	//use rand through the list of moves to determine what the enemy does
	std::vector<std::pair<std::string, int>> moves;
	int attack;
	int money;
	int exp;
};

//combat.cpp functions
void fight(character& protag, opponent& enemy);

void fightHeader(opponent enemy);

void printHUD(std::vector<std::pair<std::string, std::string>> options, int& weapon, std::string input,
	character& protag, opponent& enemy);

//All-around functions
void typo();

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