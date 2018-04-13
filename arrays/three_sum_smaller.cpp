
/*
Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

For example, given nums = [-2, 0, 1, 3], and target = 2.

Return 2. Because there are two triplets which sums are less than 2:

[-2, 0, 1]
[-2, 0, 3]
Follow up:
Could you solve it in O(n2) runtime?

*/

#include "stdafx.h"

using namespace std;

/*
	This is a variation of triangle_numbers. Basic idea is to sort array first then locate the left 2 numbers and find the max
	last number, then any number between the left number and right number is eligible.

	Time complexity is O(n^2), space complexity is O(1).
*/

class Solution {
public:
	int threeSumSmaller(vector<int>& nums, int target) {
		int res = 0;
		if (nums.size() < 3) return res;

		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size() - 2; ++i) {
			int left = i + 1, right = nums.size() - 1;

			while (left < right) {
				if (nums[left] + nums[right] + nums[i] < target) {
					res += right - left;
					left++;
				}
				else {
					right--;
				}
			}
		}

		return res;
	}
};