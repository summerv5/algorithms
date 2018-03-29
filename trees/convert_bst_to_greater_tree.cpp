
/*
https://leetcode.com/problems/convert-bst-to-greater-tree/description/

Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.
*/

#include "stdafx.h"
#include "tree.h"

using namespace std;

/*
	The idea is to traverse the tree using reversed inorder: right -> root -> left.
	In order to record the current sum of all traversed nodes, we use a reference variable to record it.

	Time complexity is O(n), space complexity is O(1).
*/

class Solution{
public:
	TreeNode * convertBST(TreeNode* root) {
		if (!root) return root;

		int cur = 0;
		helper(root, cur);

		return root;
	}

	void helper(TreeNode* root, int& cur) {
		if (!root) return;

		helper(root->right, cur);
		root->val += cur;
		
		cur = root->val;
		helper(root->left, cur);
	}
};