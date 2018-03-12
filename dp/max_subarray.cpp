
/*
https://leetcode.com/problems/maximum-subarray/description/

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/

#include "stdafx.h"
#include "algorithm"

using namespace std;

/*
	A typical DP solution is to have 2 variables, one represents the max sum that we have so far, 
	the other represents the max current sum.

	Time complexity is O(n), space complexity is O(1).
*/

class MaxSubarray{
public:
	// dp solution
	int maxSubArray(vector<int>& nums) {
		if (nums.size() < 1) return 0;

		int maxv = nums[0], curv = maxv;

		for (int i = 1; i < nums.size(); ++i) {
			curv = max(nums[i], curv + nums[i]);
			maxv = max(maxv, curv);
		}

		return maxv;
	}

	// Divide and conquer solution.
	int maxSubArray(vector<int>& nums) {
		if (nums.size() < 1) return 0;

		int mx = 0, lmx = 0, rmx = 0, sum = 0;
		helper(nums, 0, nums.size() - 1, mx, lmx, rmx, sum);

		return mx;
	}

	/*
	mx : the max sum of current subarray.
	lmx: the sum of current subarray that starts with the left most number.
	rmx: the sum of current subarray that ends with the right most number.
	sum: the sum of the current array.
	*/
	void helper(vector<int>& nums, int l, int r, int& mx, int& lmx, int& rmx, int& sum) {
		if (l == r) {
			lmx = nums[l];
			rmx = nums[l];
			sum = nums[l];
			mx = nums[l];
			return;
		}

		int m = (r - l) / 2 + l;
		int mx1, lmx1, rmx1, sum1, mx2, lmx2, rmx2, sum2;

		helper(nums, l, m, mx1, lmx1, rmx1, sum1);
		helper(nums, m + 1, r, mx2, lmx2, rmx2, sum2);

		lmx = max(lmx1, sum1 + lmx2);
		rmx = max(rmx2, rmx1 + sum2);
		mx = max(max(mx1, mx2), rmx1 + lmx2);
		sum = sum1 + sum2;
	}
};