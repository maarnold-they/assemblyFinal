#include "levelTemplate.h"
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::pair;

void temp(character & protag, character & enemy) {
	while (protag.HP > 0 || enemy.HP > 0) {
		cout << enemy.name << " wants to fight!\n What will you do?\n";
		vector <pair<string, int>> options(3);
		options[0].first = "give big slappy\n";
		options[0].second = 1;
		options[1].first = "protecc urself from hitt\n";
		options[1].second = 2;
		options[2].first = "idk what to type here 1\n";
		options[2].second = 3;
		options[3].first = "idk what to put here 2, electric boogaloo\n";
		options[3].second = 4;
		for (int i = 0; i <= options.size(); i++) {
			cout << options[i].first;
		}
		int input;
		cin >> input;
		
			if (input == options[i].second) {
				cout << "you give the big slappy... oh you know his feelings hurt.\n";
			}
			else {
				cout << "you idle around and he hits you!!! >:(\n";
				if (enemy.HP > 20) {
					cout << "oh boy he looks like hes not hurt, watcha gonna do bud?\n";
					//getline(cin, input);
				}
			}
		
		vector <pair<int, int>> options;
	}

}