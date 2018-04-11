
/*
https://leetcode.com/problems/valid-triangle-number/description/

Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
Example 1:
Input: [2,2,3,4]
Output: 3
Explanation:
Valid combinations are:
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
Note:
The length of the given array won't exceed 1000.
The integers in the given array are in the range of [0, 1000].

*/

#include "stdafx.h"

using namespace std;

/*
	The first solution is basically brute-force, plus some improvement, like sorting.
	Time complexity is O(n^3), space complexity is O(1).
*/

class Solution {
public:
	int triangleNumber(vector<int>& nums) {
		int size = nums.size();
		if (size < 3) return 0;

		int res = 0;
		sort(nums.begin(), nums.end());

		for (int i = 0; i < size; ++i) {
			for (int j = i + 1; j < size; ++j) {
				for (int k = j + 1; k < size; ++k) {
					if (canMakeTriangle(nums[i], nums[j], nums[k])) res++;
					else break;
				}
			}
		}

		return res;
	}

	bool canMakeTriangle(int a, int b, int c) {
		return a && b && c && (a + b > c) && (a + c > b) && (b + c > a);
	}
};