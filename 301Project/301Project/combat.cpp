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

void printOptions(vector <pair<string, string>> options, character & protag, opponent & enemy, int & weapon) {
	cout << "\nPLAYER: " << protag.name << endl;
	cout << "HEALTH: " << protag.HP << endl;
	cout << "Attack: " << weapon << endl;
	cout << "\nENEMY: " << enemy.name << endl;
	cout << "HEALTH: " << enemy.HP << endl;
	for (int i = 0; i < options.size(); i++) {
		cout << options[i].first;
	}
	cout << "                         INPUT HERE: ";
}

vector <pair<string, string>> setOptions() {
	vector <pair<string, string>> setOptions(4);
	setOptions[0].first = "\ngive big slap (1)";
	setOptions[0].second = "1";
	setOptions[1].first = "\nAbilities (2)";
	setOptions[1].second = "2";
	setOptions[2].first = "\nprotecc urself from hitt (3)";
	setOptions[2].second = "3";
	setOptions[3].first = "\nfocus (4)\n";
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

		else if (input == options[1].second)
		{
			if (protag.abilities.empty())
			{
				cout << protag.name << " has no abilities right now." << endl;

				cout << endl << "Press enter to return to battle menu..." << endl;
				cin.get();
				system("CLS");
				printHUD(options, weapon, input, protag, enemy);
				getline(cin, input);
			}
			else
			{
				vector<int> hotKeys;
				cout  << "Abilities:" << endl;
				for (int i = 0; i < protag.abilities.size(); ++i)
				{
					cout << protag.abilities[i].first << " (" << i + 1 << ")" << endl;
					hotKeys.push_back(i + 1);
				}
				string abilityInput;
				bool abilityExist = false;
				cout << endl << "Press enter to go back..." << endl;
				cout << "          INPUT:  ";
				getline(cin, abilityInput);
				if (abilityInput.empty())
				{
					system("CLS");
					printHUD(options, weapon, input, protag, enemy);
					getline(cin, input);
				}
				else
				{
					for (int ii = 0; ii < hotKeys.size(); ++ii)
					{
						if (abilityInput == std::to_string(hotKeys[ii]))
						{
							cout << endl << protag.name << " used " << protag.abilities[ii].first << "!" << endl;
							cout << enemy.name << " Received " << weapon + protag.abilities[ii].second << " points of damage!" << endl;
							enemy.HP = enemy.HP - (weapon + protag.abilities[ii].second);
							abilityExist = true;
							playerGuard = false;
							temp = false;
							break;
						}
					}
					if (!abilityExist)
					{
						system("CLS");
						typo();
						cout << endl;
					}
				}
			}
		}

		else if (input == options[2].second) {
			cout << "\nyou block\n";
			playerGuard = true;
			temp = false;
		}

		else if (input == options[3].second) {
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

		else {
			system("CLS");
			typo();
			cout << endl;
			printHUD(options, weapon, input, protag, enemy);
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
			cout << endl << enemy.name << " slugs you good and bad. YEE-OUCH BABEY!!\n";
			cout << protag.name << " receives " << enemy.attack << " points of damage!" << endl;
			protag.HP = protag.HP - enemy.attack;
		}
		enemyGuard = false;
	}

	else {
		cout << endl << enemy.name << " guards himself against the next attack\n";
		enemyGuard = true;
	}
	cout << endl;
	system("PAUSE");
	system("CLS");
}

/*
every turn the enemies condition is displayed
*/
void fightHeader(opponent enemy) {
	int hpChecker = 10; //reference for dialogue of enemies status
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
	//tempInv handles implicit zeros messing with bitshift operations
	unsigned long long tempInv = 0xFFff0000FFffFFff | protag.inventory;
	long weaponDamage = (protag.inventory >> 32) & 0xFFFF;
	int temp = 0;
	if (weaponDamage != 0) {
		//for loops increments by base 16, every increment adds one value to damage
		// 0xFFFF = 4 extra damage;
		for (int i = 0; i < weaponDamage; i ++) {
			temp++;
			cout << "i: " << i << endl;
			i = i * 16;
		}
	}
	return weapon + temp;
}

void printHUD(vector<pair<string, string>> options, int& weapon, string input,
character& protag, opponent& enemy)
{
	fightHeader(enemy);
	printOptions(options, protag, enemy, weapon);
}

/*
main function for combat. uses while loop for each turn
*/
void fight(character& protag, opponent& enemy) {
	system("PAUSE");
	system("CLS");

	enemy.HP = enemy.maxHP;

	bool enemyGuard = false;
	bool playerGuard = false;
	vector <pair<string, string>> options = setOptions();
	int weapon = 5; //player does base 5 damage, weapons increase damage
	weapon = getDamage(protag, weapon);
	while (protag.HP > 0 && enemy.HP > 0) {
		fightHeader(enemy);
		//prints full combat options for player
		printOptions(options, protag, enemy, weapon);
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
		protag.exp += enemy.exp;
		enemy.HP = enemy.maxHP;
		if (protag.exp >= 20) {
			cout << "You leveled up! Max HP increased by 5.\n";
			protag.exp = protag.exp % 20;
			protag.level++;
		}
		system("pause");
		system("CLS");
	}
}