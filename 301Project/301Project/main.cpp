//main.cpp
//contains the main
//William, Millard, Harrison

#include "levelTemplate.h"

int main()
{
	//Starting stats
	character mainChar;
	std::string notableChoice = "0";
	std::string choice = "";
	std::string move = lvl0Start(mainChar, notableChoice, choice);
	
	//Level 0 Loop
	while (move != "lvl1")
	{
		if (move == "hall")
			move = lvl0Hall(mainChar, notableChoice, choice);

		if (move == "Gangster's Lair")
			move = lvl0Lair(mainChar, notableChoice, choice);

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
			move = lvl1Start(mainChar, notableChoice, choice);

		if (move == "kitchen")
			move = lvl1Kitchen(mainChar, notableChoice, choice);

		if (move == "wardrobe")
			move = lvl1Wardrobe(mainChar, notableChoice, choice);

		if (move == "staircase")
			move = lvl1Staircase(mainChar, notableChoice, choice);

		if (move == "game over")
		{
			std::cout << "GAME OVER" << std::endl;
			exit(0);
		}
	}

	//Level 2 Loop
	while (move != "lvl3") {
		bool thugCheck = false;
		if (move == "lvl2"){
			move = lvl2Start(mainChar, choice, thugCheck);
		}
		if (move == "lvl2bathroom") {
			move = lvl2Bathroom(mainChar, choice, thugCheck);
		}
		if (move == "lvl2livingRoom") {
			move = lvl2livingRoom(mainChar, choice, thugCheck);
		}
		if (move == "game over")
		{
			std::cout << "GAME OVER" << std::endl;
			exit(0);
		}
	}

	//Level 3 Loop
	while (move != "end")
	{
		if (move == "lvl3")
			move = lvl3Start(mainChar, notableChoice, choice);

		if(move == "breakroom")
			move = lvl3Breakroom(mainChar, notableChoice, choice);

		if (move == "game over")
		{
			std::cout << "GAME OVER" << std::endl;
			exit(0);
		}
	}
}

//TODO:
//Finish level 3
//Adjust abilities code in combat.cpp to add heal spell
//