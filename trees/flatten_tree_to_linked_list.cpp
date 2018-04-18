
/*
http://lintcode.com/en/problem/flatten-binary-tree-to-linked-list/

Flatten a binary tree to a fake "linked list" in pre-order traversal.

Here we use the right pointer in TreeNode as the next pointer in ListNode.

Notice
Don't forget to mark the left child of each node to null. Or you will get Time Limit Exceeded or Memory Limit Exceeded.

*/

#include "stdafx.h"
#include "tree.h"

using namespace std;

/*
	Time complexity is O(n), space complexity is O(1).
*/

/**
* Definition of TreeNode:
* class TreeNode {
* public:
*     int val;
*     TreeNode *left, *right;
*     TreeNode(int val) {
*         this->val = val;
*         this->left = this->right = NULL;
*     }
* }
*/

class Solution {
public:
	/**
	* @param root: a TreeNode, the root of the binary tree
	* @return: nothing
	*/
	void flatten(TreeNode * root) {
		// write your code here

		if (!root) return;

		TreeNode *cur = root;
		
		while (cur)
		{
			if (cur->left) {
				TreeNode* pre = cur->left;

				while (pre->right)
				{
					pre = pre->right;
				}

				pre->right = cur->right;
				cur->right = cur->left;
				cur->left = nullptr;
			}
			
			cur = cur->right;
		}
	}
};