
/*
https://leetcode.com/problems/merge-sorted-array/description/

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
*/

#include "stdafx.h"

using namespace std;

/*
	If every single number in nums2 has been moved into nums1, then the rest of nums1 are in the right place, if there's any.
	
	Time complexity is O(n).
*/

class MergeArray{
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = m - 1, j = n - 1, pos = m + n - 1;

		while (i >= 0 && j >= 0) {
			if (nums1[i] > nums2[j]) {
				nums1[pos--] = nums1[i--];
			}
			else {
				nums1[pos--] = nums2[j--];
			}
		}

		while (j >= 0) {
			nums1[pos--] = nums2[j--];
		}
	}
};