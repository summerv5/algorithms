
/*
https://leetcode.com/problems/climbing-stairs/description/

You are climbing a stair case.It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps.In how many distinct ways can you climb to the top ?
Note : Given n will be a positive integer.
*/

#include "stdafx.h"

using namespace std;

/*
	Basic idea is similar to fibonacci numbers. If we need to know the distinct ways to N,
	then we need to know different ways to N-1 and N-2.
	
	Time complexity is O(n), space complexity is O(1).
*/

class Clibing_Stairs{
public:
	int climbStairs(int n) {
		if (n == 1) return 1;
		if (n == 2) return 2;

		int onestepbefore = 2, twostepbefore = 1, res = 0;

		for (int i = 3; i <= n; ++i) {
			res = onestepbefore + twostepbefore;
			twostepbefore = onestepbefore;
			onestepbefore = res;
		}

		return res;
	}
};