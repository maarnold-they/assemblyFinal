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
	while (move != "lvl1")
	{
		if (move == "hall")
			move = lvl0Hall(mainChar, notableChoice);

		if (move == "Gangster's Lair")
			move = lvl0Lair(mainChar, notableChoice);

		if (move == "game over")
		{
			std::cout << "GAME OVER" << std::endl;
			exit;
		}
	}

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
			exit;
		}
	}

	//INSERT LEVEL 2 LOOP HERE!!!!!!!!!!!!!!!!!!!!!!!!

	while (move != "end")
	{
		if (move == "lvl3")
			move = lvl3Start(mainChar, notableChoice);
	}
}