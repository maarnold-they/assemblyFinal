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
	std::string typo = "Hey, are you sure you meant to type that? I don't think you did.";

	std::string move = lvl0Start(mainChar, typo);
	while (move != "lvl1")
	{
		if (move == "hall")
			move = lvl0Hall(mainChar, typo);

		if (move == "Gangster's Lair")
			move = lvl0Lair(mainChar, typo);

		if (move == "game over")
		{
			std::cout << "GAME OVER" << std::endl;
			break;
		}
	}

	if (move == "lvl1")
		move = lvl1Start(mainChar, typo);

	while (move != "lvl2")
	{
		
	}
}