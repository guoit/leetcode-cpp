/*
288 Unique Word Abbreviation

An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:

a) it                      --> it    (no abbreviation)

	 1
b) d|o|g                   --> d1g

			  1    1  1
	 1---5----0----5--8
c) i|nternationalizatio|n  --> i18n

			  1
	 1---5----0
d) l|ocalizatio|n          --> l10n
Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.

Example:

Given dictionary = [ "deer", "door", "cake", "card" ]

isUnique("dear") -> false
isUnique("cart") -> true
isUnique("cane") -> false
isUnique("make") -> true
*/
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
class ValidWordAbbr {
public:
	ValidWordAbbr(vector<string> &dictionary) {
		for (string& s : dictionary) {
			string k = s.front() + to_string(s.size() - 2) + s.back();
			if (m.end() != m.find(k) && m[k] != s) {
				m[k] = "";
			}
			else
			{
				m[k] = s;
			}
		}
	}
	bool isUnique(string word) {
		string k = word.front() + to_string(word.size() - 2) + word.back();
		return !m.count(k) || m[k] == word;
	}
private:
	unordered_map<string, string> m;
};

//int main()
//{
//	vector<string> dictionary{"door", "door"};
//	string word = "door";
//	ValidWordAbbr obj(dictionary);
//	cout << obj.isUnique(word) << endl;
//	cin.get();
//	return 0;
//}