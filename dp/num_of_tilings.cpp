
/*
https://leetcode.com/problems/domino-and-tromino-tiling/description/

We have two types of tiles: a 2x1 domino shape, and an "L" tromino shape. These shapes may be rotated.

XX  <- domino

XX  <- "L" tromino
X
Given N, how many ways are there to tile a 2 x N board? Return your answer modulo 10^9 + 7.

(In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings 
has both squares occupied by a tile.)

Example:
Input: 3
Output: 5
Explanation:
The five different ways are listed below, different letters indicates different tiles:
XYZ XXZ XYY XXY XYY
XYZ YYZ XZZ XYY XXY
Note:

N  will be in range [1, 1000].

*/

#include "stdafx.h"

using namespace std;

/*
	This is a problem that we need to observe and analyze. Using 2 types of tiles are complex. So we break it down to smaller problems. 
	Let's find the solution for using only domino type: (It's better we have a piece of paper and a pen to draw it out)
	when N = 1, f(1) = 1
	N = 2, f(2) = 2
	N = 3, f(3) = 3 = f(2) + f(1)
	...
	so we can observe that the formula for domino tile only is f(n) = f(n - 1) + f(n - 2), just like fibonacci number.

	Now we add a tromino shape. We have following observation.
	dp[n][0] = dp[n - 1][0] + dp[n - 2][0] + dp[n - 1][1] + dp[n - 2][2]. dp[i][1] means that only top row is covered, dp[i][2] means that only bottom row is covered, dp[i][0] means that both rows are covered.

	dp[i][1] = dp[i - 2][0] + dp[i - 1][2]
	dp[i][2] = dp[i - 2][0] + dp[i - 1][1]

	so dp[n][0] = dp[n - 1][0] + dp[n - 2][0] + 2 * dp[n - 1][1]

	Time complexity is O(n), space complexity is O(2n) -> O(n).
*/

class Solution {
public:
	int numTilings(int N) {
		vector<vector<long>> dp(N + 1, vector<long>(2, 0));
		int kMod = 1000000007;
		dp[0][0] = dp[1][0] = 1;

		for (int i = 2; i <= N; ++i) {
			dp[i][0] = (dp[i - 1][0] + dp[i - 2][0] + 2 * dp[i - 1][1]) % kMod;
			dp[i][1] = (dp[i - 2][0] + dp[i - 1][1]) % kMod;
		}

		return dp[N][0];
	}
};