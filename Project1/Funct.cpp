#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <Windows.h>
#include "Funct.h"
using namespace std;

// Split String
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



// DataBase
extern const string lat = "abcdefghijklmnopqrstuvwxyz";
extern const string kir = "абвгґдеєжзиіїйклмнопрстуфхцчшщьюя";
extern map<wchar_t, wchar_t> dict = { {'a','a' },{'b','б' },{'v','в' },{'h','г' },{'d','д' },{'e','е' }
	,{'z','з' },{'g','ґ' },{'y','и' },{'i','i' },{'j','й' },{'k','к' },{'l','л' },{'m','м' },{'n','н' }
	,{'o','о' },{'p','п' },{'r','р' },{'s','с' },{'t','т' },{'u','у' },{'f','ф' },{'x','х' }
	,{'`','ь' },{'c','ц' } };
extern map<string, wchar_t> dict1 = { {"ja",'я'},{"je", 'є'},{"ju", 'ю'}, {"ji", 'ї'}, {"zh", 'ж'}, {"ch", 'ч'},{"sh", 'ш'},{"shch", 'щ'} };

void func() {
	
	string line;
	cout << "Enter Group" << endl;
	getline(cin, line);
	vector<string> group = { split(line, ' ') };

	// Count Lat And Kir
	int count_lat = 0, count_kir = 0;
	for (auto& item_group : group) {
		count_lat = 0;
		count_kir = 0;
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
		// Check What Bigger
		if (count_lat > count_kir) {
			for (int i = 0; i < item_group.size(); i++) {
				char& letter = item_group[i];
				string res = "";
				res += letter;
				switch (letter) {
				case 's':
					if (i != item_group.size() - 1) {
						string tepmRes = res;
						tepmRes += item_group[i + 1];
						if (tepmRes == "sh") {
							string res_SHCH = tepmRes;
							if (i != item_group.size() - 5) {
								res_SHCH += item_group[i + 2];
								res_SHCH += item_group[i + 3];
								if (res_SHCH == "shch") {
									letter = dict1[res_SHCH];
									item_group.erase(i + 1, i + 3);
								}
								else {
									letter = dict1[tepmRes];
									item_group.erase(item_group.begin() + i + 1);
								}

							}
						}
					}
				case 'j':
					if (i != item_group.size() - 1) {
						string tepmRes = res;
						tepmRes += item_group[i + 1];
						if (tepmRes == "ja") {
							letter = dict1[tepmRes];
							item_group.erase(item_group.begin()+i+1);
						}
					}
					if (i != item_group.size() - 1) {
						string tepmRes = res;
						tepmRes += item_group[i + 1];
						if (tepmRes == "je") {
							letter = dict1[tepmRes];
							item_group.erase(item_group.begin() + i + 1);
						}
					}
					if (i != item_group.size() - 1) {
						string tepmRes = res;
						tepmRes += item_group[i + 1];
						if (tepmRes == "ju") {
							letter = dict1[tepmRes];
							item_group.erase(item_group.begin() + i + 1);
						}
					}
					if (i != item_group.size() - 1) {
						string tepmRes = res;
						tepmRes += item_group[i + 1];
						if (tepmRes == "ji") {
							letter = dict1[tepmRes];
							item_group.erase(item_group.begin() + i + 1);
						}
					}
				case 'z':
					if (i != item_group.size() - 1) {
						string tepmRes = res;
						tepmRes += item_group[i + 1];
						if (tepmRes == "zh") {
							letter = dict1[tepmRes];
							item_group.erase(item_group.begin() + i + 1);
						}
					}
				case 'c':
					if (i != item_group.size() - 1) {
						string tepmRes = res;
						tepmRes += item_group[i + 1];
						if (tepmRes == "ch") {
							letter = dict1[tepmRes];
							item_group.erase(item_group.begin() + i + 1);
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
	}


	// Output Vector
	cout << "Result: " << endl;
	for (auto n : group) {
		cout << n << " ";
	}




}
