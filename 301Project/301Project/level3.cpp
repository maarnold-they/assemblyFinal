//level3.cpp
//contains level 3's code
//William, Millard, Harrison
//Dec. 7, 2019

#include "levelTemplate.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

//Code for starting room of Level 3
string lvl3Start(character& mainChar, string& notableChoice, string& choice)
{
	int carKey = 0x0100;
	if (checkKey(carKey, mainChar)) //once player has the car key, alternative text occurs
	{
		cout << "You look around the third floor garage. There's still" << endl;
		cout << "a car. There's still a toolbox." << endl;
	}
	else
	{
		cout << "At this point, you're just plain tired. But you keep on trucking." << endl;
		cout << "You find yourself in a garage. Yes, a garage. On the third floor of" << endl;
		cout << "another building. There's a car, naturally, as well as a red toolbox." << endl;
	}
	while (true)
	{
		cout << "What do you do?" << endl;
		cout << "(1) Get in the car           (2) Open tool box" << endl;
		getline(cin, choice);
		system("CLS");

		if (choice == "1")
		{
			if (checkKey(carKey, mainChar)) //once player has the car key, ending options occur
			{
				cout << "You use the car key to open the car door, and get inside." << endl;
				cout << "You pop that car key into the ignition, and the engine" << endl;
				cout << "starts with a roar. Then it starts spewing ignition everywhere" << endl;
				cout << "and you realize you're gonna get carbon monoxide poisoning" << endl;
				cout << "if you just do nothing." << endl;
				while (true)
				{
					cout << "What do you do?" << endl;
					cout << "(1) Drive out the window           (2) Sit still and die slowly" << endl;
					getline(cin, choice);
					system("CLS");

					if (choice == "1") //Get ready for final battle
					{
						cout << "You drive that new vehicle of yours straight out the third floor" << endl;
						cout << "window. It looks like you're some action hero straight out of an" << endl;
						cout << "action movie. And, just like an action movie, your car is perfectly" << endl;
						cout << "fine once you land on the street below." << endl;
						cout << "You drive off into the sunset and live happily ever after." << endl << endl;
						system("PAUSE");
						system("CLS");

						cout << "OR SO YOU THOUGHT." << endl;
						system("PAUSE");
						system("CLS");

						cout << "Having returned to a normal life, you realize that normal life" << endl;
						cout << "isn't as easy as you thought it would be!" << endl;

						opponent everydayLife;
						everydayLife.name = "The Struggles of Everyday Life";
						everydayLife.maxHP = 130;
						everydayLife.attack = 10;
						everydayLife.money = 0;
						everydayLife.exp = 0;

						if (fight(mainChar, everydayLife)) //Good Ending
						{
							cout << "Having conquered the struggles of everyday life, you have" << endl;
							cout << "become a true hero. Your name shall be carried down for" << endl;
							cout << "generations to come... or be forgotten in, like, five" << endl;
							cout << "minutes. There's not really any way you can tell." << endl << endl;
							cout << "Anyway, after all you've been through, you decide to retire" << endl;
							cout << "at a young age and enjoy yourself." << endl;
							return "end";
						}
						else //Bad Ending
						{
							cout << "The struggles of everyday life have bested you. They are" << endl;
							cout << "simply too irritating and mundane to be conquered by anyone." << endl;
							cout << "You live out the rest of your days working a retail job." << endl;
							return "end";
						}
					}
					else if (choice == "2") //Still Pretty Bad Ending
					{
						cout << "You decide to not drive out the window, as realistically you'd" << endl;
						cout << "probably die from the fall. Instead, you'd rather go out in a" << endl;
						cout << "a beautiful, mint condition ride. With your final breath, you" << endl;
						cout << "notice a stain on the passenger seat." << endl;
						return "game over";
					}
					else
					{
						typo();
					}
				}
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
			if (checkKey(carKey, mainChar))
			{
				cout << "Upon reopening the toolbox, you find that the applesauce looks" << endl;
				cout << "incredibly appetizing when you're nearly dead and you know it'll" << endl;
				cout << "somehow manage to heal you right up. You wolf it down." << endl;
				cout << "HP fully recovered!" << endl << endl;
				mainChar.HP = mainChar.maxHP;
				system("PAUSE");
				system("CLS");
				return "lvl3";
			}
			else
			{
				cout << "You open the red tool box. Inside are a wrench, a hammer, a chainsaw," << endl;
				cout << "and a first aid kit. You decide that wielding a chainsaw would be" << endl;
				cout << "friggin' awesome." << endl;

				int epicSword = 0x0fff;
				bool byeChainsaw = false; //bool to check if player grabbed the chainsaw or not

				if (checkWeapon(epicSword, mainChar)) //if player has the epic sword, they get to choose whether or not to get the chainsaw
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
				if (!byeChainsaw) //if player says yes to chainsaw
				{
					cout << "Acquired CHAINSAW!" << endl;
					int chainsaw = 0x00ff;
					newWeapon(chainsaw, mainChar);
					ability ripNTear = { "Rip and Tear", 12, 5, true, false };
					newAbility(mainChar, ripNTear); //player learns Rip and Tear ability if they grab the chainsaw
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
						cout << "of all supplies. Sounds helpful in a bind. Before you throw it away, you" << endl;
						cout << "notice a sticky note on the inside with archaic runes. Apparently, they're" << endl;
						cout << "for a healing spell of some sort." << endl;
						ability heal = { "Heal", 20, 4, false, true };
						newAbility(mainChar, heal); //player learns heal ability if they investigate the first aid kit
						break;
					}
					else if (choice == "2")
					{
						cout << "You throw the first aid kit in the trash, where it belongs. Nobody needs" << endl;
						cout << "the ability to heal in the middle of battle." << endl;
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
		}
		else
		{
			typo();
		}
	}
}

//Code for breakroom of Level 3
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
	moreChillinThugs.name = "Notably Tougher Group of Chillin' Thugs";
	moreChillinThugs.maxHP = 120;
	moreChillinThugs.attack = 10;
	moreChillinThugs.money = 30;
	moreChillinThugs.exp = 30;
	if (!(fight(mainChar, moreChillinThugs)))
		return "game over";

	cout << "You did it. You beat your way through EVERY SINGLE THUG in the room." << endl;
	cout << "You search their bodies, only to find nothing of interest. As you turn" << endl;
	cout << "around to head back where you came from, you find some car keys right" << endl;
	cout << "by the door, sitting in a basket. Go figure." << endl;
	cout << "Acquired CAR KEYS!" << endl;
	newKey(0x0100, mainChar); //add car keys to player's inventory

	return "lvl3";
}
