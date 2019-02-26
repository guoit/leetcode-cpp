/*
243 Shortest Word Distance

Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
	// 1st try, using a map, not efficient
	int shortestDistance(vector<string>& words, string word1, string word2) {
		int res = INT_MAX;
		unordered_map<string, int> index;
		for (int i = 0; i < words.size(); ++i) {
			auto word = words[i];
			if (word == word1) {
				if (index.count(word2)) {
					res = min(res, i - index[word2]);
				}
			}
			else if (word == word2) {
				if (index.count(word1)) {
					res = min(res, i - index[word1]);
				}
			}
			index[word] = i;
		}

		return res;
	}

	// 2nd try, use only two variables to save word1 and word2 positions because we only care of them
	int shortestDistance2(vector<string>& words, string word1, string word2) {
		int res = INT_MAX;
		int p1 = -1, p2 = -1;
		for (int i = 0; i < words.size(); ++i) {
			if (word1 == words[i]) {
				if (p2 != -1)	res = min(res, i - p2);
				p1 = i;
			}
			else if (word2 == words[i]) {
				if (p1 != -1)	res = min(res, i - p1);
				p2 = i;
			}
		}

		return res;
	}

	// best solution using one variable to record word1 or word2's position
	int shortestDistance3(vector<string>& words, string word1, string word2) {
		int idx = -1, res = INT_MAX;
		for (int i = 0; i < words.size(); ++i) {
			if (words[i] == word1 || words[i] == word2) {
				if (idx != -1 && words[i] != words[idx])
					res = min(res, i - idx);
				idx = i;
			}
		}

		return res;
	}
};

//int main() {
//	vector<string> words{ "practice", "makes", "perfect", "coding", "makes" };
//	Solution obj;
//	cout << obj.shortestDistance3(words, "coding", "makes");
//	cin.get();
//	return 0;
//}