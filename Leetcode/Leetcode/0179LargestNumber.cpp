/*
179 Largest Number

Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:

Input: [10,2]
Output: "210"
Example 2:

Input: [3,30,34,5,9]
Output: "9534330"
Note: The result may be very large, so you need to return a string instead of an integer.
*/
# include <vector>
# include <string>
# include <algorithm>
# include <numeric>
# include <iostream>

using namespace std;

class Solution {
public:
	static bool compare(int a, int b) {
		string a_str = to_string(a);
		string b_str = to_string(b);

		return a_str + b_str > b_str + a_str;
	}

	string largestNumber(vector<int>& nums) {
		if (all_of(nums.begin(), nums.end(), [](int i) {return i == 0; })) {
			return "0";
		}// bug fixed: forget the cases when nums's elements are all 0

		sort(nums.begin(), nums.end(), compare);
		
		string res;
		// use for loop to concatenate numbers
		/*
		for (int a : nums) {
			res += to_string(a);
		}
		*/
		// example of using std::accumulate function in numeric library
		auto func_concatenate = [](string& accumulator, int a)->string& {
			accumulator += to_string(a);
			return accumulator;
		};
		
		res = accumulate(nums.begin(), nums.end(), res, func_concatenate);

		return res;
	}
};

int main() {
	Solution obj;
	//vector<int> nums = { 3,30,34,5,9 };
	vector<int> nums(10, 0);
	cout << obj.largestNumber(nums) << endl;
	cin.get();

	return 0;
}
