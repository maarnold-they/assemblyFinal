//level2.cpp
//contains level 2's code
//William, Millard, Harrison
//Dec. 7, 2019

#include "levelTemplate.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;


/*
Code for starting room of Level 2
character mainchar is player
string choice is getline input from player
bool thugCheck keeps track of if thugs are supposed to be following the character
thugheck = true; thugs are not following player
thugheck = false; thugs are following player
*/
string lvl2Start(character& mainChar, string& choice, bool& thugCheck) {
	cout << "\nYou get a strong feeling that a different person is writing this\n";
	cout << "and that the overall tone of this level doesnt fit with the other two\n";
	cout << "levels...¯\\_(v.v)_/¯";
	cout << "\noh yeah, you also hear thugs closing in behind you...\n";
	bool foodCheck = true; //player can eat food to refill health just once.
	while (true) {
		cout << "What do you do?" << endl;
		cout << "(1) Wait for them to come and fight one               (2) Push on and gain more distance" << endl;
		if (checkUtility(0x0001, mainChar) && foodCheck) { //checks if player has the cheese from level 0
			cout << "(3) Eat food you found" << endl;
		}
		getline(cin, choice);
		cout << endl;
		system("CLS");

		if (choice == "1")
		{
			opponent thuglvl2;
			thuglvl2.maxHP = 20;
			thuglvl2.name = "Thug";
			thuglvl2.money = 5;
			thuglvl2.exp = 10;
			thuglvl2.attack = 3;
			cout << "The gang members shouting grows louder and you see one " << endl;
			cout << "turn around the corner and charge you.\n" << endl;

			if (!(fight(mainChar, thuglvl2)))
				return "game over";

			thugCheck = false;
			return "lvl2bathroom";
			break;
		}
		else if (choice == "2") {
			thugCheck = false;
			system("CLS");
			return "lvl2livingRoom";

		}
		else if (choice == "3") {
			cout << "\nThe food fills you up and you feel refreshed! HP is restored.\n";
			mainChar.HP = mainChar.maxHP;
			mainChar.inventory >> 48 && 0xfff0;
			foodCheck = false;
		}
		else {
			typo();
		}
	}
	return "lvl2Bathroom";
}

/*
Code for bathroom of Level 2
character mainchar is player
string choice is getline input from player
bool thugCheck keeps track of if thugs are supposed to be following the character
thugheck = true; thugs are not following player
thugheck = false; thugs are following player
*/
string lvl2Bathroom(character& mainChar, string& choice, bool& thugCheck) {
	cout << "you hear more thuggos comin and you hide in the bathroom which is right by the entrance.\n";
	int wait = 1; //measures how long you need to wait until thugs leave the room
	while (true) {
		cout << "what do you do?\n";
		cout << "(1) look for something useful              ";
		if (wait < 3) {
			cout << "(2) try to surprise attack the thugs\n(3) wait for the thugs to leave\n";
		}
		else {
			cout << "(2) leave the bathroom.\n";
			thugCheck = true;
		}
		getline(cin, choice);
		system("CLS");
		cout << endl;
		if (choice == "1"){
			cout << "you look around but cant find anything useful.\n";
			if (wait < 3) {
				cout << "you hear the thugs rummaging around the room.\n";
					wait++;
			}
			else {
				cout << "the room is silent and you can go without worry of attack.\n";
				thugCheck = true;
			}
		}
		else if (choice == "2" && wait < 3) {
			cout << "you rush out to surprise attack but they were ready and a thug jump at you.\n";
			opponent gimbert;
			gimbert.maxHP = 20;
			gimbert.name = "gimbert";
			gimbert.money = 5;
			gimbert.exp = 10;
			gimbert.attack = 1;

			if (!(fight(mainChar, gimbert)))
				return "game over";

			system("CLS");

			cout << "before you can catch your breath another thug jumps in for a fight.\n";
			opponent janszercxy;
			janszercxy.maxHP = 20;
			janszercxy.name = "janszercxy";
			janszercxy.money = 5;
			janszercxy.exp = 15;
			janszercxy.attack = 2;

			if (!(fight(mainChar, janszercxy)))
				return "game over";

			system("CLS");

			cout << "youre getting pretty tired but a deep wail rings in your skull.\n";
			cout << "youve never heard this noise before. but youve always known it was haunting your soul.\n";
			cout << "The One Who Weeps With Me shambles miserably across the floor at you in a way that aches your heart.\n";
			opponent thugger;
			thugger.maxHP = 20;
			thugger.name = "The One Who Weeps With Me";
			thugger.money = 5;
			thugger.exp = 80;
			thugger.attack = -15; //only enemy who heals the player, can't heal past max HP

			if (!(fight(mainChar, thugger)))
				return "game over";

			system("CLS");
			cout << "you wipe away the tears that arent there and proceed on.\n";
			system("CLS");
			break;

		}
		else if (wait >= 3 && choice == "2") {
			cout << "you exit the bathroom and find the room empty and you make your\n";
			cout << "way to the living room.\n";
			return "lvl2livingRoom";
		}
		else if (wait < 3 && choice == "3") {
			cout << "you wait...a wise choice...\n";
			cout << "you hear the thugs rummaging around the room.\n";
			wait++;
		}
		else {
			typo();
		}
	}
	return "lvl2livingRoom";
}

/*
Code for living room of Level 2
character mainchar is player
string choice is getline input from player
bool thugCheck keeps track of if thugs are supposed to be following the character
thugheck = true; thugs are not following player
thugheck = false; thugs are following player
*/
string lvl2livingRoom(character& mainChar, string& choice, bool& thugCheck) {
	if (thugCheck) {
		bool swordCheck = false; //checks if player found weapon for choice 1
		cout << "thankfully the thugs are gone and you can proceed on without worry.\n";
		while (true) {
			cout << "(1) inspect room           (2) jump out window (yeah its a choice)\n";
			getline(cin, choice);
			cout << endl;
			system("CLS");
			if (choice == "1" && swordCheck == false) {
				cout << "you find an epic sword for more damage! thats epic dude!!\n";
				cout << "no really!!!!\n";
				cout << "...\ngood job!!!\n";
				int epicSword = 0x0fff;
				newWeapon(epicSword, mainChar);
				ability epicSlash = {"Epic Slash", 15, 7, true, false };
				newAbility(mainChar, epicSlash);
				swordCheck = true;
			}
			else if (choice == "1" && swordCheck) {
				cout << "idk dude, after that epic sword you found there\n";
				cout << "isnt really anything else here that could top that... :/\n";
			}
			else if (choice == "2") {
				cout << "you leap out of the window to a place called...\n";
				cout << "...\n...level3.cpp\n\n";
				break;
			}
		}
	}
	else if (!thugCheck) {
		cout << "you run into the dining room and a thug chases you while the other run away idk...\n";
		cout << "you prepare for a fight but the burly flexxer grabs you and throws you to level3.cpp\n\n";
		cout << endl << endl;
	}
	else {
		thugCheck = true;
	}
	system("PAUSE");
	system("CLS");
	return "lvl3";
}
