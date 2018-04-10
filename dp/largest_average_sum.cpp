
/*
https://leetcode.com/problems/largest-sum-of-averages/description/

We partition a row of numbers A into at most K adjacent (non-empty) groups, then our score is the sum of the average of each group. What is the largest score we can achieve?

Note that our partition must use every number in A, and that scores are not necessarily integers.

Example:
Input:
A = [9,1,2,3,9]
K = 3
Output: 20
Explanation:
The best choice is to partition A into [9], [1, 2, 3], [9]. The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
We could have also partitioned A into [9, 1], [2], [3, 9], for example.
That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.

Note:

1 <= A.length <= 100.
1 <= A[i] <= 10000.
1 <= K <= A.length.
Answers within 10^-6 of the correct answer will be accepted as correct.

*/

#include "stdafx.h"

using namespace std;

/*
	Let f[i][j] be the maximum sum of the average of j groups in numbers from A[0] to A[i];
	Say the last group has at least one number in it, last group can include numbers from A[0] to A[i - 1] one at a time;
	Let p to be the last number of the second last group, the maximum sum of the average of j - 1 groups in numbers from A[0] to A[p] is f[p][j - 1];
	Then the last group starts from p + 1;
	The total sum of the last groups is A[p + 1] + A[p + 2] + ... + A[i];
	The average of the last group is (A[p + 1] + ... + A[i]) / (i - p);

	So the formula is f[i][j] = max{f[p][j - 1] + (A[p + 1] + ... + A[i]) / (i - p)}, 0 <= p < i. Using bottom-up solution.

	Time complexity is O(Kn^2), space complexity is O(Kn).
*/

class Solution {
public:
	double largestSumOfAverages(vector<int>& A, int K) {
		int size = A.size();
		if (size < 1 || K < 1) return 0.0;

		vector<vector<double>> dp(size, vector<double>(K + 1, 0));
		
		double cur = 0.0;
		for (int i = 0; i < size; ++i) {
			cur += A[i];
			dp[i][1] = cur / (i + 1);
		}

		for (int j = 2; j <= K; ++j) {
			for (int i = 0; i < size; ++i) {
				double mcur = 0.0;
				for (int p = 0; p < i; ++p) {
					double cur = dp[p][j - 1] + (dp[i][1] * (i + 1) - dp[p][1] * (p + 1)) / (i - p);
					mcur = max(mcur, cur);
				}

				dp[i][j] = mcur;
			}
		}

		return dp[size - 1][K];
	}
};