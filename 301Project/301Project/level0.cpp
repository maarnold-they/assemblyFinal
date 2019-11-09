//level0.cpp
//contains level 0's code
//William, Millard, Harrison

#include "levelTemplate.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

void lvl0(character& mainChar)
{
	string typo = "Hey, are you sure you meant to type that? I don't think you did.";
	cout << "It's not like I forgot or anything, but, uhh..." << endl;
	cout << "What was your name again?" << endl;
	getline(cin, mainChar.name);
	cout << "Yeah, that's right, your name is " << mainChar.name << "!" << endl;
	cout << "Told ya I didn't forget!" << endl << endl;

	cout << "Anyway, you wake up in a straaaaaange place." << endl;
	cout << "You notice an old man in the fetal position rocking back and forth in the corner." << endl;
	string choice;
	while (true)
	{
		cout << "You have a couple options here." << endl;
		cout << "(1) Talk to him                (2) Be anti-social" << endl;
		getline(cin, choice);
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
			cout << typo << endl << endl;
		}
	}
	cout << "In the middle of the old man's incomprehensible babbling, you see a glimmer" << endl;
	cout << "of light in his eyes, reminding you of the light in a child's eyes when" << endl;
	cout << "they're desperate for you to listen. Try to hear him out?" << endl;
	while (true)
	{
		cout << "(1) Fine, I'll try to understand               (2) I hate children" << endl;
		getline(cin, choice);
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
				if (choice == "1")
				{
					cout << "You feel a strong desire for the creators of this game to implement" << endl;
					cout << "the inventory system already." << endl;
					break;
				}
				else if (choice == "2")
				{
					cout << "You're pretty sure your grandma's pinky finger would cut through a monster" << endl;
					cout << "before that sword ever would. All you need are your dukes." << endl;
					break;
				}
				else
				{
					cout << typo << endl << endl;
				}
			}
			break;
		}
		else if (choice == "2")
		{
			cout << "You look at the old man in disgust and then walk away." << endl;
			break;
		}
		else
		{
			cout << typo << endl << endl;
		}
	}
}