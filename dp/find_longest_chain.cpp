
/*
https://leetcode.com/problems/maximum-length-of-pair-chain/description/

You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.

Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.

Example 1:
Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]
Note:
The number of given pairs will be in the range [1, 1000].

*/

#include "stdafx.h"

using namespace std;

/*
	Sort the pairs first so we can use DP or Greedy solution to solve this problem.
*/

class Solution {
public:
	// DP solution: time complexity is O(n^2), space complextiy is O(n);
	int findLongestChain(vector<vector<int>>& pairs) {
		sort(pairs.begin(), pairs.end(), comp);

		int res = 0, size = pairs.size();
		vector<int> dp(size, 0);
		dp[0] = 1;

		for (int i = 1; i < size; ++i) {
			int cur_max = 0;

			for (int j = i - 1; j >= 0; --j) {
				if (pairs[i][0] > pairs[j][1]) {
					cur_max = max(dp[j] + 1, cur_max);
				}
				else {
					cur_max = max(dp[j], cur_max);
				}
			}

			dp[i] = cur_max;
		}

		return dp[size - 1];
	}

	static bool comp(vector<int>& p1, vector<int>& p2) {
		return p1[0] < p2[0];
	}

	// Greedy solution: time complexity is O(nlogn), space complexity is O(1).
	int findLongestChain2(vector<vector<int>>& pairs) {
		sort(pairs.begin(), pairs.end(), comp2);

		int res = 0, last = INT_MIN;

		for (auto p : pairs) {
			if (p[0] > last) {
				res++;
				last = p[1];
			}
		}

		return res;
	}

	static bool comp2(vector<int>& p1, vector<int>& p2) {
		return p1[1] < p2[1];
	}
};