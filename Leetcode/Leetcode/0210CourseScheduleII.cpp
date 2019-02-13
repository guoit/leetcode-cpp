/*
210. Course Schedule II
Medium

726

52

Favorite

Share
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Example 1:

Input: 2, [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished
			 course 0. So the correct course order is [0,1] .
Example 2:

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both
			 courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
			 So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
*/

#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<int> in(numCourses, 0);	// in degrees of nodes
		vector<vector<int>> graph(numCourses, vector<int>());	// graph[i] contains all courses which i points to
		vector<int> res;

		for (auto& p : prerequisites) {
			in[p.first]++;
			graph[p.second].push_back(p.first);
		}

		deque<int> q;
		for (int i = 0; i < numCourses; ++i) {
			if (0 == in[i]) {
				q.push_back(i);
				res.push_back(i);
			}
		}

		while (!q.empty()) {
			int a = q.front();
			q.pop_front();
			for (int b : graph[a]) {
				if (0 == --in[b]) {
					q.push_back(b);
					res.push_back(b);
				}
			}
		}

		return any_of(in.begin(), in.end(), [](int x)->bool {return x != 0; }) ? vector<int>() : res;
	}
};