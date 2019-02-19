/*
[LintCode] 613 High Five -	Amazon OA2
Description
There are two properties in the node student id and scores, to ensure that each student will have at least 5 points, find the average of 5 highest scores for each person.


Example
Given results = [[1,91],[1,92],[2,93],[2,99],[2,98],[2,97],[1,60],[1,58],[2,100],[1,61]]

Return [[1, 72.4], [2, 97.4]]

// https://yeqiuquan.blogspot.com/2017/03/lintcode-613-high-five.html
*/
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
	unordered_map<int, double> highFive(vector<vector<int>> &records) {
		unordered_map<int, priority_queue<int, vector<int>, greater<int>>> highfive;	// map from id to a minimum heap
		unordered_map<int, double> res;	// result to return
		
		for (const auto &record : records) {
			auto &minHeap = highfive[record[0]];
			minHeap.push(record[1]);
			if (minHeap.size() > 5)	minHeap.pop();
		}

		for (auto &item : highfive) {
			auto &minHeap = item.second;
			unsigned int count = minHeap.size();	// count number of scores in minimum heap, in case that there are less than 5 scores for a id
			double scores = 0;
			while (!minHeap.empty()) {
				scores += (double)minHeap.top();
				minHeap.pop();
			}
			res[item.first] = scores / (double)count;
		}

		return res;
	}
};

//int main() {
//	vector<vector<int>> results{ {1,91},{1,92},{2,93},{2,99},{2,98},{2,97},{1,60},{1,58},{2,100},{1,61} };
//	Solution obj;
//	auto res = obj.highFive(results);
//	cin.get();
//	return 0;
//}