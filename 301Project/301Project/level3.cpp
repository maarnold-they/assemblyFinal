//level3.cpp
//contains level 3's code
//William, Millard, Harrison

#include "levelTemplate.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

string lvl3Start(character& mainChar, string& notableChoice, string& choice)
{
	cout << "At this point, you're just plain tired. But you keep on trucking." << endl;
	cout << "You find yourself in a garage. Yes, a garage. On the fourth floor." << endl;
	cout << "There's a car, naturally, as well as a red toolbox." << endl;
	while (true)
	{
		cout << "What do you do?" << endl;
		cout << "(1) Get in the car           (2) Open tool box" << endl;
		getline(cin, choice);
		system("CLS");

		if (choice == "1")
		{
			int carKey = 0x0111;
			if (checkKey(carKey, mainChar))
			{
				cout << "You use the car key to open the car door, and get inside." << endl;
				//INSERT MORE INSIDE CAR STUFF HERE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			}
			else
			{
				cout << "You grab the door handle and pull, but alas, no cigar." << endl;
				cout << "The door is locked, and you could break the window to get inside," << endl;
				cout << "but only if you could convince yourself to damage such a gorgeous vehicle." << endl;
				cout << "You'll be needing a car key if you're actually gonna get inside." << endl;
			}
		}
		else if (choice == "2")
		{
			cout << "You open the red tool box. Inside are a wrench, a hammer, a chainsaw," << endl;
			cout << "and a first aid kit. You decide that wielding a chainsaw would be" << endl;
			cout << "friggin' awesome." << endl;

			int epicSword = 0x0fff;
			bool byeChainsaw = false;

			if (checkWeapon(epicSword, mainChar))
			{
				cout << "...Or at least that's what you thought until you realized your epic" << endl;
				cout << "sword has better stats. RIP chainsaw." << endl;
				while (true)
				{
					cout << "Equip Chainsaw anyway?" << endl;
					cout << "(1) Nah, it ain't good enough           (2) Heck yeah, it's a CHAINSAW" << endl;
					getline(cin, choice);
					system("CLS");

					if (choice == "1")
					{
						cout << "Yeah, TRULY cool chainsaws inflict instant death. You leave" << endl;
						cout << "this chainsaw behind." << endl;
						byeChainsaw = true;
						break;
					}
					else if (choice == "2")
					{
						break;
					}
					else
						typo();
				}
			}
			if (!byeChainsaw)
			{
				cout << "Acquired CHAINSAW!" << endl;
				int chainsaw = 0x00ff;
				newWeapon(chainsaw, mainChar);
				ability ripNTear = { "Rip and Tear", 12, 5, true, false };
				newAbility(mainChar, ripNTear);
			}
			while (true)
			{
				cout << "Investigate the first aid kit?" << endl;
				cout << "(1) Sounds handy          (2) That's for chumps who actually went to health class" << endl;
				getline(cin, choice);
				system("CLS");

				if (choice == "1")
				{
					cout << "You grab the first aid kit and open it up. Turns out, it has been emptied" << endl;
					cout << "of all surprise. Sounds helpful in a bind. Before you throw it away, you" << endl;
					cout << "notice a sticky note on the inside with archaic runes. Apparently, they're" << endl;
					cout << "for a healing spell of some sort." << endl;
					ability heal = { "Heal", 20, 4, false, true };
					newAbility(mainChar, heal);
					break;
				}
				else if (choice == "2")
				{
					cout << "You throw the first aid kit in the trash, where it belongs. Nobody needs" << endl;
					cout << "the ability to heal after taking damage." << endl;
					break;
				}
				else
				{
					typo();
				}
			}
			cout << "Having removed the chainsaw, you see now that there is a key in the toolbox." << endl;
			cout << "A smile begins to stretch across your face, until you realize it isn't" << endl;
			cout << "a car key and there's a locked door in front of you." << endl;
			while (true)
			{
				cout << "(1) Admire chainsaw            (2) Enter other room" << endl;
				getline(cin, choice);
				system("CLS");

				if (choice == "1")
				{
					if (byeChainsaw)
					{
						cout << "You look at the chainsaw. It's pretty alright, you guess." << endl;
						cout << "You head to the next room." << endl;
					}
					else
					{
						cout << "You pet the chainsaw. Including the blade. You then hold it up in" << endl;
						cout << "the air and let out a 'h-haw, yeah!' before deciding to go to the" << endl;
						cout << "other room." << endl;
					}
					return "breakroom";
				}
				else if (choice == "2")
				{
					cout << "You head to the next room of your quest." << endl;
					return "breakroom";
				}
				else
				{
					typo();
				}
			}
		}
		else
		{
			typo();
		}
	}
}

string lvl3Breakroom(character& mainChar, string& notableChoice, string& choice)
{
	cout << "You get to the breakroom, and it is filled to the BRIM with thugs" << endl;
	cout << "chilling by the water cooler. This is a perfect opportunity to try" << endl;
	cout << "out your brand new weapon!" << endl;

	opponent chillinThugs;
	chillinThugs.name = "Group of Chillin' Thugs";
	chillinThugs.maxHP = 80;
	chillinThugs.attack = 8;
	chillinThugs.money = 20;
	chillinThugs.exp = 20;
	if (!(fight(mainChar, chillinThugs)))
		return "game over";

	cout << "You defeat a group of thugs in one go, but not the entire mass of thugs." << endl;
	cout << "Right as the next group is about to rush you, you hold out your hand and" << endl;
	cout << "say 'just a minute'. You reach for a styrofoam cup and enjoy some cold," << endl;
	cout << "refreshing, tasteless water." << endl;
	cout << "HP Fully Restored!" << endl << endl;
	mainChar.HP = mainChar.maxHP;
	cout << "You throw your empty cup on the floor and stomp on it, and then let out" << endl;
	cout << "a war cry. The next group of thugs draws near!" << endl;

	opponent moreChillinThugs;
	moreChillinThugs.name = "Slightly Tougher Group of Chillin' Thugs";
	moreChillinThugs.maxHP = 120;
	moreChillinThugs.attack = 10;
	moreChillinThugs.money = 30;
	moreChillinThugs.exp = 30;
	if (!(fight(mainChar, moreChillinThugs)))
		return "game over";

	return "dummy";
}
