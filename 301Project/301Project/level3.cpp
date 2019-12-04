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
			cout << "and a cup of applesauce. You decide that wielding a chainsaw would be" << endl;
			cout << "friggin' awesome." << endl;
			cout << "Acquired CHAINSAW!" << endl << endl;
			int chainsaw = 0x0011;
			newWeapon(chainsaw, mainChar);
			cout << "After removing the chainsaw, you realize there is a key in the toolbox." << endl;
			cout << "A smile begins to stretch across your face, until you realize it isn't" << endl;
			cout << "a car key and there's a locked door in front of you." << endl;
			while (true)
			{
				cout << "(1) Admire chainsaw            (2) Enter other room" << endl;
				getline(cin, choice);
				system("CLS");

				if (choice == "1")
				{
					cout << "You pet the chainsaw. Including the blade. You then hold it up in" << endl;
					cout << "the air and let out a 'h-haw, yeah!' before deciding to go to the" << endl;
					cout << "other room." << endl;
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
	//INSERT LEVEL 3 BREAKROOM CODE HERE!!!!!!!!!!!!!!!!!!!!!!!!!!
	return "dummy";
}