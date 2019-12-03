//main.cpp
//contains the main
//William, Millard, Harrison

#include "levelTemplate.h"

int main()
{
	//Starting stats
	character mainChar;
	mainChar.aggression = 0;
	mainChar.HP = 40;
	//String that is the output text when the player makes a typo
	std::string notableChoice = "0";
	std::string move = lvl0Start(mainChar, notableChoice);

	//Level 0 Loop
	while (move != "lvl1")
	{
		if (move == "hall")
			move = lvl0Hall(mainChar, notableChoice);

		if (move == "Gangster's Lair")
			move = lvl0Lair(mainChar, notableChoice);

		if (move == "game over")
		{
			std::cout << "GAME OVER" << std::endl;
			exit(0);
		}
	}

	//Level 1 Loop
	while (move != "lvl2")
	{
		if (move == "lvl1")
			move = lvl1Start(mainChar, notableChoice);

		if (move == "kitchen")
			move = lvl1Kitchen(mainChar, notableChoice);

		if (move == "wardrobe")
			move = lvl1Wardrobe(mainChar, notableChoice);

		if (move == "staircase")
			move = lvl1Staircase(mainChar, notableChoice);

		if (move == "game over")
		{
			std::cout << "GAME OVER" << std::endl;
			exit(0);
		}
	}

	//INSERT LEVEL 2 LOOP HERE!!!!!!!!!!!!!!!!!!!!!!!!

	//Level 3 Loop
	while (move != "end")
	{
		if (move == "lvl3")
			move = lvl3Start(mainChar, notableChoice);

		if(move == "breakroom")
			move = lvl3Breakroom(mainChar, notableChoice);

		if (move == "game over")
		{
			std::cout << "GAME OVER" << std::endl;
			exit(0);
		}
	}
}

//TODO:
//Add ability to move to other rooms at any time
//Add screen clears in combat
//Implement level ups
//Add pauses until player hits enter when necessary
//Add HUD displaying where you are, your name, your health, (perhaps even inventory)