#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <Windows.h>
#include "Funct.h"
using namespace std;

vector<string> split(const string& fLine, const char& item)
{
	string result = "";
	vector<string> arr_result;

	for (auto n : fLine) {
		if (n != item)
			result += n;
		else
			if (n == item && result != "") {
				arr_result.push_back(result);
				result = "";
			}
	}
	if (result != "")
		arr_result.push_back(result);

	return arr_result;
}

void delete_needlessly(string &item_group, int i) {
	for (int j = i + 1; j < item_group.size() - 1; ++j) {
		item_group[j] = item_group[j + 1];
	}
	item_group.pop_back();
}

extern const string lat = "abcdefghijklmnopqrstuvwxyz";
extern const string kir = "абвгґдеєжзиіїйклмнопрстуфхцчшщьюя";
extern map<char, char> dict = { {'a','a' },{'b','б' },{'v','в' },{'h','г' },{'d','д' },{'e','е' }
	,{'z','з' },{'g','ґ' },{'y','и' },{'i','i' },{'j','й' },{'k','к' },{'l','л' },{'m','м' },{'n','н' }
	,{'o','о' },{'p','п' },{'r','р' },{'s','с' },{'t','т' },{'u','у' },{'f','ф' },{'x','х' }
	,{'`','ь' },{'c','ц' } };

extern map<string, char> dict1 = { {"ja",'я'},{"je", 'є'},{"ju", 'ю'}, {"ji", 'ї'}, {"zh", 'ж'}, {"ch", 'ч'},{"sh", 'ш'},{"shch", 'щ'} };

void func() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	string line;
	getline(cin, line);
	vector<string> group = { split(line, ' ') };


	int count_lat = 0, count_kir = 0;
	for (auto& item_group : group) {
		for (char& letter : item_group) {
			for (char letter_lat : lat) {
				if (letter == letter_lat)
					count_lat++;
			}
			for (char letter_kir : kir) {
				if (letter == letter_kir)
					count_kir++;
			}

		}
		for (int i = 0; i < item_group.size(); i++) {
			char& letter = item_group[i];
			string res = "";
			res += letter;
			switch (letter) {
			case 's':
				if (i != item_group.size() - 1) {
					res += item_group[i + 1];
					if (res == "sh") {
						string res_SHCH = res;
						if (i != item_group.size() - 5) {
							res_SHCH += item_group[i + 2];
							res_SHCH += item_group[i + 3];
							if (res_SHCH == "shch") {
								letter = dict1[res_SHCH];
								delete_needlessly(item_group, i + 2);
								delete_needlessly(item_group, i + 1);
								delete_needlessly(item_group, i);
							}
							else {
								letter = dict1[res];
								delete_needlessly(item_group, i);
							}

						}
					}
			case 'j':
				if (res == "ja") {
					letter = dict1[res];
					delete_needlessly(item_group, i);
				}
				if (res == "je") {
					letter = dict1[res];
					delete_needlessly(item_group, i);

				}
				if (res == "ju") {
					letter = dict1[res];
					delete_needlessly(item_group, i);

				}
				if (res == "ji") {
					letter = dict1[res];
					delete_needlessly(item_group, i);

				}
			case 'z':
				if (res == "zh") {
					letter = dict1[res];
					delete_needlessly(item_group, i);

				}
			case 'c':
				if (res == "ch") {
					letter = dict1[res];
					delete_needlessly(item_group, i);

				}


				}

			default:
				for (char letter_lat : lat) {
					if (letter == letter_lat)
						letter = dict[letter];

				}
			}
		}
	}



	for (auto n : group) {
		cout << n << " ";
	}




}


