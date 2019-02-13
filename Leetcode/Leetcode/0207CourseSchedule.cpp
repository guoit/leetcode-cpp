/*
207 Course Schedule

There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:

Input: 2, [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
			 To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: 2, [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
			 To take course 1 you should have finished course 0, and to take course 0 you should
			 also have finished course 1. So it is impossible.
Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
*/

#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<int> in(numCourses, 0);	// in degrees of nodes
		vector<vector<int>> graph(numCourses, vector<int>());	// graph[i] contains all courses which i points to

		for (auto& p : prerequisites) {
			in[p.first]++;
			graph[p.second].push_back(p.first);
		}

		deque<int> q;
		for (int i = 0; i < numCourses; ++i) {
			if (0 == in[i])	q.push_back(i);
		}

		while (!q.empty()) {
			int a = q.front();
			q.pop_front();
			for (int b : graph[a]) {
				if (0 == --in[b])	q.push_back(b);
			}
		}

		return all_of(in.begin(), in.end(), [](int x)->bool {return 0 == x; });
	}
};

//int main() {
//	int numCourses = 2;
//	vector<pair<int, int>> pre = {};
//
//	Solution obj;
//	cout << obj.canFinish(numCourses, pre)<<endl;
//
//	cin.get();
//	return 0;
//}