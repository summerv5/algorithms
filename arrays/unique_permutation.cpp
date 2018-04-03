
/*
https://leetcode.com/problems/permutations-ii/description/

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:

[
[1,1,2],
[1,2,1],
[2,1,1]
]

*/

#include "stdafx.h"
#include "set"
#include "algorithm"

using namespace std;

/*
	In order to know when to skip the duplicates, we can sort the array first then compare if the current element is equal to 
	its previous one and only when the previous one hasn't been visited, we can then skip such case.

	Time complexity is O(n), space complexity is O(n).
*/

class Solution{
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		if (nums.size() < 1) return { {} };

		vector<vector<int>> res;
		vector<int> temp;
		vector<bool> visited(nums.size(), false);

		sort(nums.begin(), nums.end());

		helper(nums, res, temp, visited, 0);

		return res;
	}

	void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& temp, vector<bool>& visited, int pos) {
		if (pos == nums.size()) {
			res.push_back(temp);
			return;
		}

		for (int i = 0; i < nums.size(); ++i) {
			if (!visited[i]) {
				if (i && nums[i] == nums[i - 1] && !visited[i - 1]) continue;
				visited[i] = true;
				temp.push_back(nums[i]);

				helper(nums, res, temp, visited, pos + 1);

				temp.pop_back();
				visited[i] = false;
			}
		}
	}

	// Second solution is to utilize the feature that only unique elements stored in a set.
	// Note that we skip the case when current element is the same with the start element but not itself.

	vector<vector<int>> permuteUnique2(vector<int>& nums) {
		if (nums.size() < 1) return { {} };

		set<vector<int>> s;
		helper2(nums, s, 0);

		return vector<vector<int>>(s.begin(), s.end());
	}

	void helper2(vector<int>& nums, set<vector<int>>& s, int start) {
		if (start == nums.size()) {
			s.insert(nums);
			return;
		}

		for (int i = start; i < nums.size(); ++i) {
			if (i != start && nums[i] == nums[start]) continue;

			swap(nums[i], nums[start]);
			helper2(nums, s, start + 1);
			swap(nums[i], nums[start]);
		}
	}
};