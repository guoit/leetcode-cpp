/*
187 Repeated DNA Sequences

All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

Example:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"

Output: ["AAAAACCCCC", "CCCCCAAAAA"]
*/
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> res;
		unordered_map<int, int> visited;
		int encode = 0;	// encode value with lowest 20 bits represent the 10-character substring
		for (int i = 0; i < s.size(); ++i) {
			encode <<= 2; // shift two bits to give space for new character s[i]

			// get the encode value for s[i]: A-0, T-1, G-2, C-3
			int code = 0;
			switch (s[i]) {
			case 'T':
				code = 1;
				break;
			case 'G':
				code = 2;
				break;
			case 'C':
				code = 3;
				break;
			default:
				code = 0;
				break;
			}

			// update encode
			encode |= code;

			// runs only when s[:i] length >= 10
			if (i >= 9) {
				encode &= 0xFFFFF;	// remove code value of s[i-10] from encode to ensure encode always has 20 bits
				if (visited.count(encode)) {
					visited[encode] += 1;
					if (2 == visited[encode]) {
						res.push_back(s.substr(i - 9, 10));
					}
				}
				else{
					visited[encode] = 1;
				}
			}
		}

		return res;
	}
};