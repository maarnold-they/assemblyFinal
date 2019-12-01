#include "levelTemplate.h"
#include <vector>
#include <stdlib.h>     /* srand, rand */
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::pair;

/*
PUT IN HEADER FILE:
	void fight(character& protag, opponent& enemy);

TEST DUMMIES (just slap them into main):
	character protag;
	protag.name = "bobby";
	protag.HP = 40;
	opponent enemy;
	enemy.name = "joey";
	enemy.HP = 20;
	fight(mainChar, enemy);
*/

void printOptions(vector <pair<string, string>> options) {
	for (int i = 0; i < options.size(); i++) {
		cout << options[i].first;
	}
	cout << "                         INPUT HERE: ";
}

vector <pair<string, string>> setOptions() {
	vector <pair<string, string>> setOptions(4);
	setOptions[0].first = "\ngive big slap (1)";
	setOptions[0].second = "1";
	setOptions[1].first = "\nprotecc urself from hitt (2)";
	setOptions[1].second = "2";
	setOptions[2].first = "\nfocus (3)";
	setOptions[2].second = "3";
	setOptions[3].first = "\nprint stats (4)\n\n";
	setOptions[3].second = "4";
	return setOptions;
}

/*/
player input is compared with vector options in IF statements
if bool guard = true, then character is guarding against players next attack
*/
void playerMove(vector <pair<string, string>> options, int& weapon, string input,
	character& protag, opponent& enemy, bool& enemyGuard, bool& playerGuard) {
	bool temp = true;
	while (temp) {
		if (input == options[0].second) {
			if (enemyGuard) {
				cout << "\nwhat can i say, the mans ready and your fists were\n";
				cout << "a straw too short. no damage.\n";
			}
			else {
				cout << "\nyou give the big slap... oh you know his feelings hurt.\n";
				enemy.HP = enemy.HP - weapon;
			}
			playerGuard = false;
			temp = false;
		}

		else if (input == options[1].second) {
			cout << "\nyou block\n";
			playerGuard = true;
			temp = false;
		}

		else if (input == options[2].second) {
			if (weapon < 10) {
				cout << "\nyou focus your mind and better your stance.\n";
				cout << "\nDamage increased!\n";
				weapon = weapon + 3;
			}
			else {
				cout << "\nyou cannot power up any more than this.";
			}
			temp = false;
		}

		else if (input == options[3].second) {
			cout << "\nPLAYER: " << protag.name << endl;
			cout << "HEALTH: " << protag.HP << endl;
			cout << "WEAPON DAMAGE: " << weapon << endl;
			cout << "\nNPC: " << enemy.name << endl;
			cout << "HEALTH: " << enemy.HP << endl;
			printOptions(options);
			getline(cin, input);
		}
		else {
			cout << "\nERROR\n";
			printOptions(options);
			getline(cin, input);
		}
	}
}

/*
enemy can do two things, attack or guard
enemy is more likely to attack
rand is called to determine which it does
*/
void enemyMove(vector <pair<string, string>> options,
	character& protag, opponent& enemy, bool& enemyGuard, bool& playerGuard) {
	int enemyMove = rand() % 3; //chooses a move between 0 and 2
	if (enemyMove != 0) {
		if (playerGuard) {
			cout << "\nhe tried to hit! wow! nothing happened to you!\n";
		}
		else {
			cout << "\nthe enemy slugs you good and bad. YEE-OUCH BABEY!!\n";
			protag.HP = protag.HP - 5;
		}
		enemyGuard = false;
	}

	else {
		cout << "\nthe man guards himself against the next attack\n";
		enemyGuard = true;
	}
}

/*
every turn the enemies condition is displayed
*/
void fightHeader(opponent enemy) {
	int hpChecker = 10; //reference for dialouge of enemies status
	if (enemy.HP > hpChecker) {
		cout << enemy.name << " wants to fight!\nWhat will you do?\n";
	}
	else if (hpChecker / 2 < enemy.HP <= hpChecker) {
		cout << enemy.name << " looks tired!\nWhat will you do?\n";

	}
	else {
		cout << enemy.name << " looks like they might collapse any moment!\n";
		cout << "What will you do ? \n";
	}
}

int getDamage(character protag, int weapon) {
	long weaponDamage = (protag.inventory << 32) && 0xFFFF;
	int temp = 0;
	if (weaponDamage != 0) {
		for (int i = 0; i <= weaponDamage; i += 15) {
			temp++;
		}
	}
	return weapon + temp;
}

/*
main function for combat. uses while loop for each turn
*/
void fight(character& protag, opponent& enemy) {
	bool enemyGuard = false;
	bool playerGuard = false;
	vector <pair<string, string>> options = setOptions();
	//newWeapon(5, protag);
	int weapon = 5;
	weapon = getDamage(protag, weapon);
	while (protag.HP > 0 && enemy.HP > 0) {
		fightHeader(enemy);
		//prints full combat options for player
		printOptions(options);
		string input;
		getline(cin, input);
		playerMove(options, weapon, input, protag, enemy, enemyGuard, playerGuard);

		//checks enemies health in case they died before while loop checks HP
		if (enemy.HP > 0) {
			enemyMove(options, protag, enemy, enemyGuard, playerGuard);
		}
		//helps break each turn into sections
		cout << "-------------------------------------------\n";
	}

	if (protag.HP == 0) {
		cout << "\nyou died.\n";
	}

	else {
		cout << "\nthe bad guy died yay. \n\n";
		//protag.exp += enemy.exp;
		if (protag.exp >= 20) {
			cout << "You leveled up! Max HP increased by 5.\n";
			// protag.exp = protag.exp % 20;
		}
	}
}