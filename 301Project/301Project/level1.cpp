//level1.cpp
//contains level 1's code
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
			cout << "You decide to head to the room to the right." << endl << endl;
			return "wardrobe";
		}

		if (checkKey(key2, mainChar))
		{
			cout << "You decide to head to the room to the left." << endl << endl;
			return "kitchen";
		}
	}

	//Third Visit, once you have both keys
	int bothKeys = 0x0011;
	if (checkKey(bothKeys, mainChar))
	{
		cout << "You unlock the second locked door. Wow, that was stupid, but" << endl;
		cout << "but you've made it through now. You enter the next room." << endl << endl;
		return "staircase";
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
			notableChoice = "good";
			break;
		}
		else if (choice == "2")
		{
			cout << "You lock the door. That should stop them for a long" << endl;
			cout << "time. It's not like gangsters know how to pick locks" << endl;
			cout << "or shoot locks to open them. You'll be fine." << endl;
			notableChoice = "okay";
			break;
		}
		else if (choice == "3")
		{
			cout << "You leave the door unlocked. You seriously hope the" << endl;
			cout << "gangsters overthink opening this door by trying to bash it open" << endl;
			cout << "before trying the lock." << endl;
			notableChoice = "bad";
			break;
		}
		else if (choice == "4")
		{
			cout << "You throw the chair in front of the door. That should slow" << endl;
			cout << "the gangsters down for a bit. It's a pretty heavy chair," << endl;
			cout << "albeit not as heavy as a bookshelf." << endl;
			notableChoice = "okay";
			break;
		}
		else
		{
			typo();
		}
	}

	cout << "Now that you're done with your first decision of the floor, you" << endl;
	cout << "look around the room. There's not much of interest in this room," << endl;
	cout << "but there are options as to where to go. There is a room to your left," << endl;
	cout << "a room to your right, and a locked door straight ahead." << endl;

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
			if (!blockCheese) //Checks if block of cheese has not been obtained
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
			if (!cheeseGrater) //Checks if cheese grater has not been obtained
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
			cout << "HP fully recovered!" << endl;
			cout << "Acquired KEY!" << endl;
			mainChar.HP = mainChar.maxHP;
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
			cout << "You decide to leave the kitchen. Good call." << endl << endl;
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
	int key2 = 0x0010;

	cout << "You find yourself in a walk-in closet of sorts." << endl;
	cout << "There are enough clothes hanging to obstruct the view of the walls." << endl;
	cout << "That key might be around here somewhere." << endl;
	while (true)
	{
		cout << "What do you do?" << endl;
		cout << "(1) Look at the ceiling        (2) Rummage through pockets" << endl;
		getline(cin, choice);
		cout << endl;

		if (choice == "1")
		{
			cout << "You see cracks in the ceiling, as well as spiderwebs. You feel" << endl;
			cout << "glad that the floor isn't like that until you look down and realize" << endl;
			cout << "that that is exactly what it is like." << endl;
		}
		else if (choice == "2")
		{
			cout << "You rummage through the pockets of one of the jackets that are" << endl;
			cout << "hanging around and all of a sudden a rat jumps out!" << endl;
			int cheese = 0x0001;
			if (checkUtility(cheese, mainChar))
			{
				if (mainChar.aggression < 2)
				{
					while (true)
					{
						cout << "The rat is the same rat from earlier! That is, the one you stole the" << endl;
						cout << "cheese from. Give it back?" << endl;
						cout << "(1) Return the cheese               (2) Never!" << endl;
						getline(cin, choice);
						cout << endl;

						if (choice == "1")
						{
							cout << "You return the cheese to the rat. It seems to appreciate it, as it" << endl;
							cout << "gives you a key in exchange." << endl;
							cout << "Acquired KEY!" << endl;
							newKey(key2, mainChar);
							cout << endl << "All's well that ends well, so you head back to the previous room." << endl << endl;
							return "lvl1";
						}
						else if (choice == "2")
						{
							mainChar.aggression++;
							break;
						}
						else
						{
							typo();
						}
					}
				}
				if (mainChar.aggression >= 2)
				{
					cout << "The rat recognizes you as the jerk who stole its cheese. You" << endl;
					cout << "recognize the rat as the nerd who didn't deserve it in the first" << endl;
					cout << "place. There's only one way this can be settled!" << endl << endl;

					opponent rat;
					rat.HP = 20;
					rat.name = "Hangry Rat";
					rat.money = 10;
					rat.exp = 10;

					fight(mainChar, rat);

					cout << "You manage to fell the rat, and find it was holding onto a key. Nice!" << endl;
					cout << "Acquired KEY!" << endl;
					newKey(key2, mainChar);
					cout << "You decide to leave the room before any more rats show up." << endl;
					return "lvl1";
				}
			}
			cout << "When the rat lands on the floor, you hear a 'clank!' noise." << endl;
			cout << "A key fell onto the floor, so you pick it up. Wow, that was easy." << endl;
			cout << "Acquired KEY!" << endl;
			newKey(key2, mainChar);
			cout << "With that done, you decide to head back to the previous room." << endl;
			return "lvl1";
		}
		else
		{
			typo();
		}
	}
}

string lvl1Staircase(character& mainChar, string& notableChoice)
{
	string choice;
	cout << "The next room turns out to be a staircase! You head up a few steps, and then" << endl;
	cout << "hear footsteps. Loud, fast footsteps." << endl;
	cout << "You've never seen a gangster run so fast. There's no way you'll" << endl;
	cout << "outrun him. Prepare for a fight!" << endl << endl;

	opponent gangster;
	gangster.HP = 15;
	gangster.name = "speedy gangsta";
	gangster.exp = 5;
	gangster.money = 10;

	fight(mainChar, gangster);
	if (notableChoice == "good")
	{
		cout << "After besting the gangster, you continue up the stairs to the next floor." << endl;
		return "lvl2";
	}
	else
	{
		cout << "Immediately after defeating the gangster, another gangster enters the fray!" << endl << endl;
		gangster.HP = 15;
		fight(mainChar, gangster);
		if (notableChoice == "okay")
		{
			cout << "You make it through the second gangster as well, and rush up the stairs" << endl;
			cout << "with renewed determination to not die!" << endl;
			return "lvl2";
		}
		else
		{
			cout << "Yet ANOTHER gangster shows up immediately after the second one's defeat." << endl;
			cout << "You really should have at least LOCKED the door." << endl << endl;
			gangster.HP = 15;
			fight(mainChar, gangster);
			cout << "You wipe your mouth and find your hand now partially painted red. Great." << endl;
			cout << "You utilize that adrenaline of yours to get to the next floor as quickly" << endl;
			cout << "as you can." << endl;
			return "lvl2";
		}
	}
}