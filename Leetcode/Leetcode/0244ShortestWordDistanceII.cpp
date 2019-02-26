/*
244 Shortest Word Distance II

This is a follow up of Shortest Word Distance. The only difference is now you are given the list of words and your method will be called repeatedly many times with different parameters. How would you optimize it?

Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list.

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

// put all indices of a word into map
// use two pointers to find out the minimum distance between the two ordered list
class WordDistance {
public:
	WordDistance(vector<string>& words) {
		for (int i = 0; i < words.size(); ++i) {
			m[words[i]].push_back(i);
		}
	}

	int shortest(string word1, string word2) {
		auto &v1 = m[word1], &v2 = m[word2];
		int i = 0, j = 0, res = INT_MAX;
		while (i < v1.size() && j < v2.size()) {
			if (v1[i] > v2[j]) {
				res = min(res, v1[i] - v2[j]);
				++j;
			}
			else {
				res = min(res, v2[j] - v1[i]);
				++i;
			}
		}

		return res;
	}
private:
	unordered_map<string, vector<int>> m;
};

//int main() {
//	vector<string> words{ "practice", "makes", "perfect", "coding", "makes" };
//	WordDistance obj(words);
//	cout << obj.shortest("coding", "makes");
//	cin.get();
//	return 0;
//}