//combat.cpp
//contains the code for battles
//William, Millard, Harrison
//Dec. 7, 2019

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

//One of the HUD printing functions; prints player stats and enemy stats as well as player options
void printOptions(vector <pair<string, string>> options, character & protag, opponent & enemy, int & weapon) {
	cout << "\nPLAYER: " << protag.name << endl;
	cout << "HEALTH: " << protag.HP << " / " << protag.maxHP << endl;
	cout << "MP: " << protag.MP << " / " << protag.maxMP << endl;
	cout << "ATTACK: " << weapon << endl;
	cout << "\nENEMY: " << enemy.name << endl;
	cout << "HEALTH: " << enemy.HP << endl;
	for (int i = 0; i < options.size(); i++) {
		cout << options[i].first;
	}
	cout << "                         INPUT HERE: ";
}

//function that returns an array of options for the player
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
if bool guard = true, then enemy is guarding against players next attack
*/
void playerMove(vector <pair<string, string>> options, int& weapon, string input,
	character& protag, opponent& enemy, bool& enemyGuard, bool& playerGuard) {
	bool temp = true;
	while (temp) {
		//Standard Attack Code
		if (input == options[0].second) {
			if (enemyGuard) {
				cout << "\nwhat can i say, the mans ready and your fists were\n";
				cout << "a straw too short. no damage.\n";
			}
			else {
				cout << "\nyou give the big slap... oh you know his feelings hurt.\n";
				cout << enemy.name << " received " << weapon << " points of damage!" << endl;
				enemy.HP = enemy.HP - weapon;
			}
			playerGuard = false;
			temp = false;
		}

		//Abilities Code
		else if (input == options[1].second)
		{
			if (protag.abilities.empty()) //If player has no abilities yet
			{
				cout << protag.name << " has no abilities right now." << endl;
				system("PAUSE");
				system("CLS");
				printHUD(options, weapon, input, protag, enemy); //Print out battle HUD again
				getline(cin, input); //Resume turn like nothing happened
			}
			else //if player DOES have abilities
			{
				vector<int> hotKeys;
				cout  << "Abilities:" << endl;
				for (int i = 0; i < protag.abilities.size(); ++i) //for loop that prints the abilities list in battle
				{
					cout << protag.abilities[i].name << " [" << protag.abilities[i].MPcost << " MP] " << " (" << i + 1 << ")" << endl;
					hotKeys.push_back(i + 1);
				}
				string abilityInput;
				bool abilityExist = false;
				cout << endl << "Press enter to go back..." << endl;
				cout << "          INPUT:  ";
				getline(cin, abilityInput);
				if (abilityInput.empty()) //if player decides they don't want to use ability, press enter to return to battle menu
				{
					system("CLS");
					printHUD(options, weapon, input, protag, enemy);
					getline(cin, input);
				}
				else
				{
					for (int ii = 0; ii < hotKeys.size(); ++ii)
					{
						if (abilityInput == std::to_string(hotKeys[ii])) //checks if player input is the same number as an actual ability hot key
						{
							abilityExist = true;
							if (protag.MP - protag.abilities[ii].MPcost >= 0) //check if player has enough MP to use ability
							{
								if (enemyGuard && protag.abilities[ii].attack) //makes attacking abilities capable of being blocked by the enemy
								{
									cout << endl << protag.name << " tried using " << protag.abilities[ii].name << ", but " << enemy.name << " blocked it!" << endl;
								}
								else //if the enemy is not guarding
								{
									if (protag.abilities[ii].attack) //if ability is an attacking ability
									{
										cout << endl << protag.name << " used " << protag.abilities[ii].name << "!" << endl;
										cout << enemy.name << " received " << weapon + protag.abilities[ii].damageBoost << " points of damage!" << endl;
										enemy.HP -= (weapon + protag.abilities[ii].damageBoost); //deal the boosted damage to the enemy
									}
								}
								if (protag.abilities[ii].support) //if ability is a healing ability
								{
									cout << endl << protag.name << " used " << protag.abilities[ii].name << "!" << endl;
									cout << protag.name << " recovered " << protag.abilities[ii].damageBoost << " HP!" << endl;
									protag.HP += protag.abilities[ii].damageBoost; //heal player the specified amount
									if (protag.HP > protag.maxHP)
										protag.HP = protag.maxHP; //ensure that player cannot heal past their max HP when healing themselves

								}
								protag.MP -= protag.abilities[ii].MPcost; //use the required MP for the ability
								playerGuard = false;
								temp = false;
								break;
							}
							else //if player did not have enough MP to use specified ability
							{
								system("CLS");
								cout << endl << protag.name << " tried to use " << protag.abilities[ii].name << ", but didn't have enough MP!" << endl << endl;
								playerGuard = false;
								break;
							}
						}
					}
					if (!abilityExist) //if player typed in something that doesn't correspond to an ability hot key
					{
						system("CLS");
						typo();
						cout << endl;
					}
				}
			}
		}

		//Player Guard Code
		else if (input == options[2].second) {
			cout << "\nyou block\n";
			playerGuard = true;
			temp = false;
		}

		//Focus Code
		else if (input == options[3].second) {
			if (weapon < 15) {
				cout << "\nyou focus your mind and better your stance.\n";
				cout << "\nDamage increased!\n";
				weapon = weapon + 3;
			}
			else {
				cout << "\nyou cannot power up any more than this.";
			}
			temp = false;
		}
		//Player input something in battle menu that doesn't correspond to any hot key
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
			if (enemy.name == "The One Who Weeps With Me") {
				cout << "The One Who Weeps With Me cries and you almost smile...\n";
				cout << protag.name << " receives " << enemy.attack << " points of damage...?" << endl;
				protag.HP = protag.HP - enemy.attack;
			}
			else {
				cout << endl << enemy.name << " slugs you good and bad. YEE-OUCH BABEY!!\n";
				cout << protag.name << " receives " << enemy.attack << " points of damage!" << endl;
				protag.HP = protag.HP - enemy.attack;
			}
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
//Prints message telling how the enemy feels during each turn
void fightHeader(opponent enemy) {
	int hpChecker = 10; //reference for dialogue of enemies status
	if (enemy.HP > hpChecker) {
		if (enemy.name == "The One Who Weeps With Me") {
			cout << "He doesn't want to fight but neither do you...\n";
		}
		else {
			cout << enemy.name << " wants to fight!\nWhat will you do?\n";
		}
	}
	else if (hpChecker / 2 < enemy.HP <= hpChecker) {
		cout << enemy.name << " looks tired!\nWhat will you do?\n";
	}
	else {
		cout << enemy.name << " looks like they might collapse any moment!\n";
		cout << "What will you do ? \n";
	}
}

//function for calculating player's standard damage based off weapon in inventory
int getDamage(character protag, int weapon) {
	//tempInv handles implicit zeros messing with bitshift operations
	unsigned long long tempInv = 0xFFff0000FFffFFff | protag.inventory;
	long weaponDamage = (tempInv >> 32) & 0xFFFF;
	int temp = 0;
	if (weaponDamage != 0) {
		//for loops increments by base 16, every increment adds one value to damage
		// 0xFFFF = 4 extra damage;
		for (int i = 1; i < weaponDamage; i ++) {
			temp++;
			i = i * 16;
		}
	}
	return weapon + temp;
}

//function for printing the HUD in battle (player stats, some enemy stats, etc.)
void printHUD(vector<pair<string, string>> options, int& weapon, string input,
character& protag, opponent& enemy)
{
	fightHeader(enemy);
	printOptions(options, protag, enemy, weapon);
}

/*
main function for combat. uses while loop for each turn
*/
bool fight(character& protag, opponent& enemy) {
	cout << endl;
	system("PAUSE");
	system("CLS");

	enemy.HP = enemy.maxHP;
	bool result; //Result is used to tell whether the player won or lost the fight

	bool enemyGuard = false;
	bool playerGuard = false;
	vector <pair<string, string>> options = setOptions();
	int weapon = 5; //player does base 5 damage, weapons increase damage
	weapon = getDamage(protag, weapon);
	while (protag.HP > 0 && enemy.HP > 0) {
		if (protag.HP > protag.maxHP) {
			protag.HP = protag.maxHP;
		}
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

	if (protag.HP <= 0) {
		//if player loses to Struggles of Everyday Life, they get bad ending, they don't die
		if(enemy.name != "The Struggles of Everyday Life")
			cout << "\nyou died.\n";
		result = false;
	}

	else {
		if (enemy.name == "The One Who Weeps With Me") {
			cout << "The One Who Weeps With Me is defeated.\n";
			cout << "They assume the position as a placeholder for your heart.\n";
			cout << "...\nYou Disapprove.\n";
		}
		else {
			cout << "\nthe bad guy died yay. \n\n";
		}
		protag.exp += enemy.exp;
		enemy.HP = enemy.maxHP;
		while (protag.exp >= 20) {
			cout << "You leveled up!\nMax HP increased by 5!\nMax MP increased by 5!\n";
			protag.exp = protag.exp % 20;
			protag.maxHP += 5;
			protag.maxMP += 5;
			protag.MP = protag.maxMP;
			protag.level++;
		}
		result = true;
		system("pause");
		system("CLS");
	}
	return result;
}