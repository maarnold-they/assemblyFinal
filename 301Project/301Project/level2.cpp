//level2.cpp
//contains level 2's code
//William, Millard, Harrison

#include "levelTemplate.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
/* 

cout << "" << endl;

*/

string lvl2Start(character& mainChar, string notableChoice) {
	cout << "you go through the door and find yourself in a fancy looking apartment." << endl;
	cout << "you see a bathroom to your left and what looks to be a dining room ahead of you." << endl;
	cout << "You hear the gang members shouting growing closer."<< endl;
	string choice;
	while (true) {
		cout << "What do you do?" << endl;
		cout << "(1) Wait for them to come and fight one               (2) Push on and gain more distance" << endl;
		if (checkUtility(mainChar.inventory >> 48, mainChar)) {
			cout << "(3) Eat food you found" << endl;
		}
		getline(cin, choice);
		cout << endl;

		if (choice == "1")
		{
			opponent thug;
			thug.HP = 20;
			thug.name = "Gang Leader";
			thug.money = 5;
			thug.exp = 10;
			cout << "The gang members shouting grows louder and you see one " << endl;
			cout << "turn around the corner and charge you." << endl;
			fight(mainChar, thug);
			cout << "You manage to defeat the thug, only to realize" << endl;
			cout << "that there's, like, 15 other gang members making their way towards you." << endl;
			cout << "You look to your left and notice a bathroom and run in." << endl;
			//lvl2Bathroom(mainChar, typo());
			break;
		}
		if (choice == "3") {
			cout << "The food fills you up and you feel refreshed! HP is restored.";
			mainChar.HP = mainChar.maxHP;
			mainChar.inventory >> 48 && 0;
		}
		return "dummy";
	}
}

string lvl2Bathroom(character& mainChar, string notableChoice) {
	int wait = 0; //tracks how long use has been in the bathroom. at wait=3 thugs leave the room
	cout << "you quickly shut the bathroom door and lock it.\n";
	cout << "it isnt until you hear the thugs walk past the bathroom that you take the time inspect the bathroom.\n";
	string choice;
	while (true) {
		cout << "what do you do?\n";
		cout << "(1) look for something useful                 ";
		if (wait < 3) {
			cout << "(2) try to surprise attack the thugs             (3) wait for the thugs to leave\n";
		}
		else {
			cout << "leave the bathroom.\n";
		}
		getline(cin, choice);
		cout << endl;
		if (choice == "1")
		{
			cout << "you look around but cant find anything useful.\n";
			if (wait < 3) {
				cout << "you hear the thugs rummaging around the room.\n";
					wait++;
			}
			else {
				cout << "the room is silent and you can go without worry of attack.\n";
			}
		}
	}

}