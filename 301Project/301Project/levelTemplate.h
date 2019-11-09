//levelTemplate.h
//Header file containing prototypes for levels,
//as well as the character struct
//William, Millard, Harrison

//Project Details
//Make a text-based choose-your-own-adventure game
//featuring turn-based combat and an inventory system
//utilizing bitwise operations.
//So far, there has been good progress on level 0, but the combat system
//and inventory system still need to be implemented
//before it can be finished. Naturally, they are what will
//be worked on next.
//For now, level 0 prompts the user to make some decisions,
//and different responses occur based on what the user
//inputs. There are checks in place for if the user types
//an invalid response.

#ifndef LEVELTEMPLATE_H
#define LEVELTEMPLATE_H
#include<iostream>
#include<string>

struct character
{
	std::string name;
	int aggression = 0;
	//inventory (however we want to make that)
	int HP = 100;
};

//notes on inventory:
//first 32 bits be for keys
//next 16 bits for weapons (1 on person at a time)
//final 16 bits for utility purposes (like a candlestick)
//no weapons = 0xFFFF0000FFFFFFFF
//weapon = 0x000100000000
//inventory = (inventory & no weapons) | weapon

struct enemy
{
	int HP;
	std::string name;
	//moves (not really sure how to implement yet)
	int money;
	int exp;
};

void lvl0(character& mainChar);

#endif
