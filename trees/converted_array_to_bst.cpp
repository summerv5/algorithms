
/*
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/

#include "stdafx.h"
#include "tree.h"

using namespace std;

/*
	Because we want a BST and the array is ordered already, we can find the root by finding the mid number easily.
	Recursively, we can build a balance BST using the same method.

	Time complexity is O(n), space complexity is O(1).
*/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

class ConvertedToBST{
public:
	TreeNode * sortedArrayToBST(vector<int>& nums) {
		int size = nums.size();
		if (size < 1) return nullptr;

		return helper(nums, 0, size - 1);
	}

	TreeNode* helper(vector<int>& nums, int l, int r) {
		if (l > r) return nullptr;

		int m = (r - l) / 2 + l;
		TreeNode* root = new TreeNode(nums[m]);
		root->left = helper(nums, l, m - 1);
		root->right = helper(nums, m + 1, r);

		return root;
	}
};