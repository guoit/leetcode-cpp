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
#include <unordered_set>
#include <queue>
#include <iostream>
using namespace std;
class Solution {
public:
	// best solution: union find method
	bool validTree(int n, vector<pair<int, int>>& edges) {
		vector<int> root(n, -1);

		for (auto &edge : edges) {
			int p = find(root, edge.first);
			int q = find(root, edge.second);
			if (p == q)	return false;
			root[p] = q;
		}

		return edges.size() == n - 1;
	}

	int find(vector<int> &root, int i) {
		while (root[i] != -1) i = root[i];
		return i;
	}

	// BFS solution
	bool validTree2(int n, vector<pair<int, int>>& edges) {
		vector<unordered_set<int>> g(n, unordered_set<int>());

		for (auto &e : edges) {
			g[e.first].insert(e.second);
			g[e.second].insert(e.first);
		}

		unordered_set<int> visited{ { 0 } };
		queue<int> q{ { 0 } };

		while (!q.empty()) {
			int src = q.front(); q.pop();
			for (int dst : g[src]) {
				if (visited.count(dst))	return false;
				q.push(dst);
				visited.insert(dst);
				g[dst].erase(src);	// remove the edge from dst to src, so there is no way to reach src again if there is no loop
				// we can't remove edge from src to dst because this will cause exception in the next for loop
			}
		}

		return visited.size() == n;
	}

	// DFS solution
	bool validTree3(int n, vector<pair<int, int>>& edges) {
		vector<vector<int>> g(n, vector<int>());
		unordered_set<int> visited;

		for (auto &e : edges) {
			g[e.first].push_back(e.second);
			g[e.second].push_back(e.first);
		}

		if (!dfs(g, visited, -1, 0))	return false;

		return visited.size() == n;
	}

	bool dfs(vector<vector<int>> &g, unordered_set<int> &visited, int pre, int cur) {
		if (visited.count(cur))	return false;
		visited.insert(cur);
		for (int next : g[cur]) {
			if (next != pre) {
				if (!dfs(g, visited, cur, next)) return false;
			}
		}

		return true;
	}
};

int main() {
	int n = 5;
	//vector<pair<int, int>> edges{ {0,1}, {0,2}, {0,3}, {1,4} };
	vector<pair<int, int>> edges{ {0,1}, {0,2}, {0,3}, {2,3}, {1,4} };
	Solution obj;
	cout << obj.validTree3(n, edges) << endl;

	cin.get();
	return 0;
}