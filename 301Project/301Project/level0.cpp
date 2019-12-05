//level0.cpp
//contains level 0's code
//William, Millard, Harrison

#include "levelTemplate.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

void typo()
{
	cout << "Hey, are you sure you meant to type that? I don't think you did." << endl;
}

void newAbility(character & mainChar, ability newMove)
{
	cout << "Learned " << newMove.name << "!" << endl << endl;
	mainChar.abilities.push_back(newMove);
}

string lvl0Start(character& mainChar, string& notableChoice, string& choice)
{
	cout << "It's not like I forgot or anything, but, uhh..." << endl;
	cout << "What was your name again?" << endl;
	getline(cin, mainChar.name);
	system("CLS");
	cout << "Yeah, that's right, your name is " << mainChar.name << "!" << endl;
	cout << "Told ya I didn't forget!" << endl << endl;
	cout << "Anyway, you wake up in a straaaaaange place." << endl;
	cout << "You notice an old man in the fetal position rocking back and forth in the corner." << endl;
	while (true)
	{
		cout << "You have a couple options here." << endl;
		cout << "(1) Talk to him                (2) Be anti-social" << endl;
		getline(cin, choice);
		system("CLS");

		if (choice == "1")
		{
			cout << "The old man sounds like he's had a couple hundred too" << endl;
			cout << "many cigarettes in the last hour. You largely can't understand what he's saying." << endl << endl;
			break;
		}
		else if (choice == "2")
		{
			cout << "Your sheer lack of enthusiasm for talking to random people in strange places" << endl;
			cout << "is completely understandable, but it doesn't exactly move the plot forward," << endl;
			cout << "now does it?" << endl << endl;
		}
		else
		{
			typo();
		}
	}
	cout << "In the middle of the old man's incomprehensible babbling, you see a glimmer" << endl;
	cout << "of light in his eyes, reminding you of the light in a child's eyes when" << endl;
	cout << "they're desperate for you to listen. Try to hear him out?" << endl;
	while (true)
	{
		cout << "(1) Fine, I'll try to understand               (2) I hate children" << endl;
		getline(cin, choice);
		system("CLS");

		if (choice == "1")
		{
			cout << "You manage to make out some of what the old man goes on about," << endl;
			cout << "specifically something about there being a thug who has been terrorizing folks" << endl;
			cout << "and that it's dangerous to go alone." << endl << endl;
			cout << "The old man hands you a makeshift-sword constructed out of twigs." << endl;
			cout << "While not particularly outstanding, it'll make for a decent starter weapon." << endl;
			cout << "Equip it?" << endl;
			while (true)
			{
				cout << "(1) Sure, why not                         (2) My fists will more than suffice" << endl;
				getline(cin, choice);
				system("CLS");

				if (choice == "1")
				{
					cout << "You shove the sword into your pocket. What? It's not like" << endl;
					cout << "the old man's gonna give you a sheath for free." << endl << endl;
					int twigSword = 0x000F;
					newWeapon(twigSword, mainChar); //twig sword enters player's inventory

					ability heavySlash = { "Heavy Slash", 5, 1 };
					newAbility(mainChar, heavySlash);

					ability heavierSlash = { "Heavier Slash", 8, 3 };
					newAbility(mainChar, heavierSlash);

					break;
				}
				else if (choice == "2")
				{
					cout << "You're pretty sure your grandma's pinky finger would cut through a monster" << endl;
					cout << "before that sword ever would. All you need are your dukes." << endl << endl;
					break;
				}
				else
				{
					typo();
				}
			}
			break;
		}
		else if (choice == "2")
		{
			cout << "You look at the old man in disgust and then walk away." << endl << endl;
			mainChar.aggression++;
			return "hall";
		}
		else
		{
			typo();
		}
	}

	while (true)
	{
		cout << "There is nothing else of interest in the room." << endl;
		cout << "Leave?" << endl;
		cout << "(1) Blow this popsicle stand                (2) Nah, I like boring rooms" << endl;
		getline(cin, choice);
		system("CLS");

		if (choice == "1")
		{
			cout << "You leave the room." << endl << endl;
			return "hall";
		}
		else if (choice == "2")
		{
			cout << "You stay in the room. It's just as boring as the narrator promised." << endl << endl;
		}
		else
		{
			typo();
		}
	}
}

string lvl0Hall(character& mainChar, string& notableChoice, string& choice)
{
	bool first = true;
	cout << "You hear the old man mumble 'good luck' before shutting" << endl;
	cout << "the door behind you and locking it. You guess there was never" << endl;
	cout << "any point in going back there, anyway." << endl;

	cout << "You find yourself in a long hallway. There are many people" << endl;
	cout << "all lined up, waiting for something. You can't tell what it is" << endl;
	cout << "due to the fact that the line goes all the way down the hall and" << endl;
	cout << "into another room." << endl;
	while (true)
	{
		cout << "What do you do? " << endl;
		cout << "(1) Look around the hall                  (2) Talk to someone in line" << endl;
		getline(cin, choice);
		system("CLS");

		int cheese = 0x0001;

		if (choice == "1")
		{
			if (!first)
			{
				cout << "There's not much of interest in the hallway other than that line." << endl;
			}
			else
			{
				cout << "Some parts of the wallpaper are peeling off throughout the hall." << endl;
				cout << "The floor is just downright dirty, with dust buildup everywhere" << endl;
				cout << "and the occasional rat. You see one rat nibbling on some cheese." << endl;
				while (true)
				{
					first = false;
					cout << "Snatch the cheese?" << endl;
					cout << "(1) Heck yeah! CHEESE!                 (2) Cheese is for the weak" << endl;
					getline(cin, choice);
					system("CLS");

					if (choice == "1")
					{
						cout << "You grab that cheese so fast the rat can't even react." << endl;
						cout << "The rat then looks at you sadly and you hiss at him, scaring him off." << endl;
						cout << "You acquire cheese!" << endl << endl;

						newUtility(cheese, mainChar); //add cheese into player's inventory
						mainChar.aggression++; //increase player's aggression level by 1
						break;
					}
					else if (choice == "2")
					{
						cout << "You decide that you don't need cheese. The rat can keep it his" << endl;
						cout << "'calcium' and his 'strong bones'." << endl;
						choice = "1"; //keep choice from activating next dialogue
						break;
					}
					else
					{
						typo();
					}
				}
			}
		}

		else if (choice == "2")
		{
			cout << "You ask the person in the very back of the line about the point" << endl;
			cout << "of said line. While he is initially surprised by the fact you" << endl;
			cout << "need to ask, he quickly realizes that you must be the adventure" << endl;
			cout << "game protagonist he was told to wait for. He hurriedly pulls out" << endl;
			cout << "his script and begins battering you with exposition." << endl;
			cout << "In the end, you were able to make out that the line leads to the gangsters" << endl;
			cout << "in charge of the local town, and that it was that time of the week again: " << endl;
			cout << "time to pay them taxes." << endl << endl;
			break;
		}
		else
		{
			typo();
		}
	}

	cout << "You decide that there is clearly something wrong with the fact that people" << endl;
	cout << "are giving up their money to some gangsters, and realize you have an important" << endl;
	cout << "decision to make." << endl;

	while (true)
	{
		cout << "(1) Take the fight to the gangsters               (2) Give in to the cycle and pay the gangsters" << endl;
		getline(cin, choice);
		system("CLS");

		if (choice == "1")
		{
			cout << "You won't stand for this. This is criminal. Plus," << endl;
			cout << "you're way too cheap to pay taxes twice over. You cut all the way" << endl;
			cout << "past the line, into the gangsters' lair." << endl << endl;
			break;
		}
		else if (choice == "2")
		{
			cout << "Well, you're not so sure you can take on a WHOLE GANG" << endl;
			cout << "by yourself, so you stay safe and just agree to pay them" << endl;
			cout << "taxes every week in exchange for them not killing you and" << endl;
			cout << "your entire family. You sign your name in a few different" << endl;
			cout << "spaces and the paperwork is done. The gangsters are surprisingly" << endl;
			cout << "tidy when it comes to paperwork." << endl << endl;
			return "game over";
		}
		else
		{
			typo();
		}
	}

	return "Gangster's Lair";
}

string lvl0Lair(character& mainChar, string& notableChoice, string& choice)
{
	cout << "After pushing and shoving dozens upon dozens of people," << endl;
	cout << "you make your way into the gangsters' lair." << endl;
	cout << "A man who clearly stands out as the leader gestures for you" << endl;
	cout << "to wait your turn, but then notices a glint in your eye." << endl << endl;
	cout << "It's not a friendly glint." << endl << endl;
	cout << "The gang leader pulls out a pristine dagger, and you" << endl;
	cout << "prepare for battle!" << endl << endl;

	opponent gangLeader;
	gangLeader.maxHP = 20;
	gangLeader.name = "Gang Leader";
	gangLeader.attack = 5;
	gangLeader.money = 5;
	gangLeader.exp = 10;

	fight(mainChar, gangLeader);
	cout << "You manage to defeat the gang leader, only to realize" << endl;
	cout << "that there's, like, 20 other gang members in this room alone." << endl;
	cout << "You look to your left and notice an upward staircase." << endl;

	while (true)
	{
		cout << "What do you do?" << endl;
		cout << "(1) Say you're sorry                 (2) Bee line for the stairs" << endl;
		getline(cin, choice);
		system("CLS");
		if (choice == "1")
		{
			cout << "You apologize for having killed the gang's leader." << endl;
			cout << "The gang members tell you it happens to everybody" << endl;
			cout << "at one point or another, and generally seem shockingly" << endl;
			cout << "understanding. Then you realize that at some point one of them" << endl;
			cout << "stabbed you in the gut. That makes much more sense." << endl << endl;
			return "game over";
		}
		else if (choice == "2")
		{
			cout << "You dash for those stairs like your life depends on it. Because it does." << endl;
			cout << "You make it successfully, and head up to the next floor." << endl << endl;
			return "lvl1";
		}
		else
		{
			typo();
		}
	}
}