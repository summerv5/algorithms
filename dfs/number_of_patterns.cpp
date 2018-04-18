
/*
http://lintcode.com/en/problem/android-unlock-patterns/

Given an Android 3x3 key lock screen and two integers m and n, where 1 ≤ m ≤ n ≤ 9, count the total number of unlock patterns of the Android lock screen, which consist of minimum of m keys and maximum n keys.

Rules for a valid pattern:
1. Each pattern must connect at least m keys and at most n keys.
2. All the keys must be distinct.
3. If the line connecting two consecutive keys in the pattern passes through any other keys, the other keys must have previously selected in the pattern. No jumps through non selected key is allowed.
4. The order of keys used matters.

*/

#include "stdafx.h"

using namespace std;

/*
	This problem has a couple of tricky parts:
		1. since the solution is symmetric on starting position, so the numbers for 0,2,6,8 are the same, numbers for 1,3,5,7 are the same. 
		2. we need a 2-d array j[i][j] to know that if there's any number between i and j. So only when you can jump directly from i to j or you have visited the number between i and j,
		we can continue this pattern.

		Time complexity is O(n) and space complextiy is O(1).
*/

class Solution {
public:
	/**
	* @param m: an integer
	* @param n: an integer
	* @return: the total number of unlock patterns of the Android lock screen
	*/
	int numberOfPatterns(int m, int n) {
		// Write your code here
		vector<bool> visited(9, false);
		vector<vector<int>> jumps(9, vector<int>(9, 0));
		jumps[0][8] = jumps[8][0] = jumps[2][6] = jumps[6][2] = 4;
		jumps[0][2] = jumps[2][0] = 1;
		jumps[0][6] = jumps[6][0] = 3;
		jumps[1][7] = jumps[7][1] = 4;
		jumps[2][8] = jumps[8][2] = 5;
		jumps[3][5] = jumps[5][3] = 4;
		jumps[6][8] = jumps[8][6] = 7;

		int corner = 0, border = 0, center = 0;

		dfs(m, n, jumps, visited, 0, 1, corner);
		center += corner * 4;

		dfs(m, n, jumps, visited, 1, 1, border);
		center += border * 4;

		dfs(m, n, jumps, visited, 4, 1, center);

		return center;
	}

	void dfs(int m, int n, vector<vector<int>>& jumps, vector<bool>& visited, int pos, int cur, int& total) {
		if (cur >= m) {
			total++;
		}

		cur++;
		if (cur > n) {
			return;
		}

		visited[pos] = true;

		for (int i = 0; i < 9; ++i) {
			int jump = jumps[pos][i];
			if (!visited[i] && (!jump || visited[jump])) {
				dfs(m, n, jumps, visited, i, cur, total);
			}
		}

		visited[pos] = false;
	}
};