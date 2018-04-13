
/*
https://leetcode.com/problems/can-place-flowers/description/

Suppose you have a long flowerbed in which some of the plots are planted and some are not. However, flowers cannot be planted in adjacent plots - they would compete for water and both would die.

Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), and a number n, return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.

Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: True
Example 2:
Input: flowerbed = [1,0,0,0,1], n = 2
Output: False
Note:
The input array won't violate no-adjacent-flowers rule.
The input array size is in the range of [1, 20000].
n is a non-negative integer which won't exceed the input array size.

*/

#include "stdafx.h"

using namespace std;

/*
	If we know how many continuous zeros are we can find the number of flowers we can plant.
	But if the left most and right most are zeros instead of ones, the result would be different.

	To resolve this, we can add a zero in the front if the first number is zero and to the back if the last number is zero.

	Time complexity is O(n), space complexity is O(1).
*/

class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		int cnt = 0;
		if (!flowerbed[0]) flowerbed.insert(flowerbed.begin(), 0);
		if (!flowerbed[flowerbed.size() - 1]) flowerbed.push_back(0);

		for (int i = 0; i <= flowerbed.size(); ++i) {
			if (i == flowerbed.size() || flowerbed[i]) {
				n -= (cnt - 1) / 2;
				cnt = 0;
			}
			else {
				cnt++;
			}
		}

		return n <= 0;
	}
};