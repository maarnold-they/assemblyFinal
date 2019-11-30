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

string lvl2Start(character& mainChar, void typo()) {
	cout << "you go through the door and find yourself in a fancy looking apartment." << endl;
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
			break;
		}
		if (choice == "3") {
			cout << "The food fills you up and you feel refreshed! HP is restored.";
			mainChar.HP = mainChar.maxHP;
			mainChar.inventory >> 48 && 0;

		}
	
	}
}