//level0.cpp
//contains level 0's code
//William, Millard, Harrison

#include "levelTemplate.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

string lvl1Start(character& mainChar, string & notableChoice)
{
	string choice;

	//Second visit, when you only have one key
	int key = 0x0001;
	int key2 = 0x0010;
	if (checkKey(key, mainChar) || checkKey(key2, mainChar))
	{
		cout << "You take your key and unlock the locked door, only to" << endl;
		cout << "find that there is ANOTHER locked door which takes a completely" << endl;
		cout << "different key right behind it. WOW." << endl;

		if (checkKey(key, mainChar))
		{
			cout << "You decide to head to the room to the right." << endl;
			return "wardrobe";
		}

		if (checkKey(key2, mainChar))
		{
			cout << "You decide to head to the room to the left." << endl;
			return "kitchen";
		}
	}

	//Third Visit, once you have both keys
	int bothKeys = 0x0011;
	if (checkKey(bothKeys, mainChar))
	{
		cout << "You unlock the second locked door. Wow, that was stupid, but" << endl;
		cout << "but you've made it through now. You enter the next room." << endl;
		return "whatever next room is called";
	}
	
	//First Visit, when you have no keys
	cout << "You reach the top of the stairs and find a door." << endl;
	cout << "You open the door and close it behind you. You realize" << endl;
	cout << "you're going to need a way to put some distance on the gangsters." << endl;
	while (true)
	{
		cout << "What do you do?" << endl;
		cout << "(1) Throw bookcase in front of door       (2) Lock door" << endl;
		cout << "(3) Keep door unlocked                    (4) Throw chair in front of door" << endl;
		getline(cin, choice);
		cout << endl;
		
		if (choice == "1")
		{
			cout << "You throw the bookcase in front of the door." << endl;
			cout << "That should keep them for a while." << endl;
			break;
		}
		else if (choice == "2")
		{
			cout << "You lock the door. That should stop them for a long" << endl;
			cout << "time. It's not like gangsters know how to pick locks" << endl;
			cout << "or shoot locks to open them. You'll be fine." << endl;
			notableChoice = "1";
			break;
		}
		else if (choice == "3")
		{
			cout << "You leave the door unlocked. You seriously hope the" << endl;
			cout << "gangsters overthink opening this door by trying to bash it open" << endl;
			cout << "before trying the lock." << endl;
			notableChoice = "2";
			break;
		}
		else if (choice == "4")
		{
			cout << "You throw the chair in front of the door. That should slow" << endl;
			cout << "the gangsters down for a bit. It's a pretty heavy chair," << endl;
			cout << "albeit not as heavy as a bookshelf." << endl;
			notableChoice = "1";
			break;
		}
		else
		{
			typo();
		}
	}

	cout << "Now that you're done with your first decision of the floor, you" << endl;
	cout << "look around the room. There's not much of interest in this room," << endl;
	cout << "but there are options as to where to go." << endl;

	while (true)
	{
		cout << "Where do you go?" << endl;
		cout << "(1) Left        (2) Right" << endl;
		getline(cin, choice);
		cout << endl;

		if (choice == "1")
		{
			cout << "You head to the room to your left" << endl;
			return "kitchen";
		}
		else if (choice == "2")
		{
			cout << "You head to the room to your right" << endl;
			return "wardrobe";
		}
		else
		{
			typo();
		}
	}
}

string lvl1Kitchen(character& mainChar, string& notableChoice)
{
	string choice;
	cout << "You find yourself in a kitchen." << endl;
	cout << "There are pots and pans everywhere. It seems no one has bothered" << endl;
	cout << "to clean up after themselves in quite a while. You notice a fridge" << endl;
	cout << "as well as many drawers throughout the kitchen." << endl;

	bool blockCheese = false;
	bool cheeseGrater = false;
	while (true)
	{
		cout << "(1) Investigate the fridge             (2) Investigate the drawers" << endl;
		getline(cin, choice);
		cout << endl;

		if (choice == "1")
		{
			if (!blockCheese) //CHECK IF BLOCK OF CHEESE IS IN INVENTORY
			{
				cout << "You open up the fridge and realize that you are STARVING." << endl;
				cout << "It sure is a good thing that all that's in there is a block" << endl;
				cout << "of pepper jack cheese. It's inedible as it is, since you" << endl;
				cout << "don't feel like eating cheese by the block, so you stuff it" << endl;
				cout << "into your black hole of a pocket." << endl;
				cout << "Acquired BLOCK OF CHEESE!" << endl;
				blockCheese = true;
			}
			else
			{
				cout << "You open the fridge again. There really is nothing else in there." << endl;
				cout << "You catch yourself mumbling 'friggin gangsters, selfish pigs'." << endl;
				cout << "You close the refrigerator." << endl;
			}
		}
		else if (choice == "2")
		{
			if (!cheeseGrater)
			{
				cout << "You open up a drawer and find absolutely nothing. You then open" << endl;
				cout << "up a second drawer and find spoons and butterknives. There are" << endl;
				cout << "no forks anywhere. You swear that you will find nothing of use" << endl;
				cout << "when all of a sudden you open the tenth drawer and find a cheese" << endl;
				cout << "grater. This might be useful." << endl;
				cout << "Acquired CHEESE GRATER!" << endl;
				cheeseGrater = true;
			}
			else
			{
				cout << "You rummage through the drawers again. Man, everything in" << endl;
				cout << "them is useless." << endl;
			}
		}
		else
		{
			typo();
		}

		if (blockCheese && cheeseGrater)
		{
			cout << endl << "With a block of cheese and a cheese grater both in your possession," << endl;
			cout << "you can finally eat cheese the way God intended. You hold the grater" << endl;
			cout << "and cheese over your head with your mouth open and grate to your heart's" << endl;
			cout << "content. Amidst all of the shredded cheese falling into your mouth is a" << endl;
			cout << "solid metal object! You choke for a bit before hacking out a key onto the floor!" << endl;
			cout << "Acquired KEY!" << endl;
			int key = 0x0001;
			newKey(key, mainChar);
			break;
		}
	}
	cout << "Now that you've got a key, you have a feeling there is nothing" << endl;
	cout << "else left in the kitchen that'll be of use to you." << endl;
	while (true)
	{
		cout << "(1) Stay, just 'cause               (2) Leave the kitchen" << endl;
		getline(cin, choice);
		cout << endl;

		if (choice == "1")
		{
			cout << "You stay in the kitchen simply because you can." << endl;
			cout << "That'll show the game developers for trying to move you along." << endl;
		}
		else if (choice == "2")
		{
			cout << "You decide to leave the kitchen. Good call." << endl;
			return "lvl1";
		}
		else
		{
			typo();
		}
	}
}

string lvl1Wardrobe(character& mainChar, string& notableChoice)
{
	string choice;
	cout << "You find yourself in a walk-in closet of sorts." << endl;
	cout << "You instantly get a key. Convenient." << endl;
	int key2 = 0x0010;
	newKey(key2, mainChar);
	return "lvl1";
}