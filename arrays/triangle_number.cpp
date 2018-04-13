
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
	The first solution is basically brute-force, plus some improvement, like sorting and binary search.
	Time complexity is O(n^2Logn), space complexity is O(1).
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
				int sum = nums[i] + nums[j], left = j + 1, right = size;

				while (left < right) {
					int m = (right - left) / 2 + left;
					if (nums[m] < sum) left = m + 1;
					else right = m;
				}

				res += right - j - 1;
			}
		}

		return res;
	}

	// Second solution:
	// Let's say we have a left position which starts from 0, a right position which starts from the second last position.
	// The last position is moving from last number backforward, once at a time.
	// So if we find that nums[left] + nums[right] bigger than nums[last], then we can safely say that every number between left(inclusive) 
	// and right(exclusive) can form a triangle with right number and last number.
	// Time complexity is O(n^2), space complexity is O(1).

	int triangleNumber2(vector<int>& nums) {
		int size = nums.size();
		if (size < 3) return 0;

		int res = 0;
		sort(nums.begin(), nums.end());

		for (int i = size - 1; i >= 2; --i) {
			int left = 0, right = i - 1;

			while (left < right) {
				if (nums[left] + nums[right] > nums[i]) {
					res += right - left;
					right--;
				}
				else left++;
			}
		}

		return res;
	}
};