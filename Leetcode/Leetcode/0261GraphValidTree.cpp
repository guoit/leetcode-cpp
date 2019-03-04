/*
261 Graph Valid Tree

Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

For example:

Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.

Hint:

Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], what should your return? Is this case a valid tree?
According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
*/
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution {
public:
	// union find
	bool validTree(int n, vector<pair<int, int>>& edges) {
		unordered_map<int, vector<int>> graph;
		for (auto &t : edges) {
			graph[t.first].push_back(t.second);
			graph[t.second].push_back(t.first);
		}

		vector<int> root;
		for (int i = 0; i < n; ++i)	root[i] = i;


	}

	int find(vector<int> &root, int i) {
		while (root[i] != i) {
			i = root[i];
		}

		return i;
	}
};

int main() {
	int n = 5;
	vector<pair<int, int>> edges{ {0,1}, {1,2}, {2, 3}, {1,3}, {1,4} };
	Solution obj;
	cout << obj.validTree(n, edges) << endl;

	cin.get();
	return 0;
}