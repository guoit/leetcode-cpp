/*
K Nearest Points	-	Amazon OA2

The background is to load goods into a truck. The truck is at the origin and you are given the coordinates of all goods. Find the k nearest goods.

questions:
1. what if K > number of given goods

*/

#include <queue>
#include <vector>
using namespace std;

#define SQUARE(x) (x)*(x)

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	return SQUARE(a.first) + SQUARE(a.second) < SQUARE(b.first) + SQUARE(b.second);
}

vector<pair<int, int>> KNearestGoods(vector<pair<int, int>> &goods, int K) {
	priority_queue< pair<int, int>, vector<pair<int,int>>, decltype(&cmp)> q(cmp);
	for (auto &g : goods)	q.push(g);

	vector<pair<int, int>> res;
	for (int i = 0; i < K; ++i) {
		if (!q.empty()) {
			res.push_back(q.top());
			q.pop();
		}
	}

	return res;	
}