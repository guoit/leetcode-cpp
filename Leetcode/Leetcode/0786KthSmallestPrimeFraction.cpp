/*
786 K-th Smallest Prime Fraction

A sorted list A contains 1, plus some number of primes. Then, for every p < q in the list, we consider the fraction p/q.

What is the K-th smallest fraction considered? Return your answer as an array of ints, where answer[0] = p and answer[1] = q.

Examples:
Input: A = [1, 2, 3, 5], K = 3
Output: [2, 5]
Explanation:
The fractions to be considered in sorted order are:
1/5, 1/3, 2/5, 1/2, 3/5, 2/3.
The third fraction is 2/5.

Input: A = [1, 7], K = 1
Output: [1, 7]
Note:

A will have length between 2 and 2000.
Each A[i] will be between 1 and 30000.
K will be between 1 and A.length * (A.length - 1) / 2.
*/
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
class Solution {
public:
	// http://www.cnblogs.com/grandyang/p/9135156.html
	// min heap solution
	vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
		priority_queue<pair<double, pair<int, int>>> q;
		for (int i = 0; i < A.size(); ++i) {	// push all fractions into priority queue with last int of A as denominator
			q.push({ -1.0*A[i] / A.back(), {i, A.size() - 1} });	// also push index pair into priority queue
		}
		while (--K) {
			auto t = q.top().second; q.pop();
			--t.second;	// everytime we pop a fraction, we push the next bigger fraction into priority queue by taking the next smaller denominator
			q.push({ -1.0*A[t.first] / A[t.second], {t.first, t.second} });
		}

		return { A[q.top().second.first], A[q.top().second.second] };
	}

	// binary search solution
	vector<int> kthSmallestPrimeFraction2(vector<int>& A, int K) {
		double left = 0, right = 1;
		int p = 0, q = 1;	// result's numerator and denominator
		int cnt = 0;
		while (true) {
			double mid = left + (right - left) / 2.0;
			cnt = 0; p = 0;
			for (int i = 0, j = 0; i < A.size(); ++i) {
				while (j < A.size() && A[i] > mid*A[j])	++j;
				cnt += A.size() - j;
				if (j < A.size() && p*A[j] < q*A[i]) {
					p = A[i];
					q = A[j];
				}
			}

			if (cnt == K)	return { p, q };
			else if (cnt < K)	left = mid;
			else right = mid;
		}

	}
};