
/*
http://www.lintcode.com/en/problem/origami/

Origami, each time the paper is folded from right to left, the dent is 0, the bump is 1. After the n number of folds, find the 01 sequence of the creases formed with the paper unrolling.

Notice
1 <= n <= 20
Example
Given n = 1, return "0".

Explanation:
the 01 sequence of the creases is "0".
Given n = 2, return "001".

Explanation:
the 01 sequence of the creases is "001".

*/

#include "stdafx.h"

using namespace std;

/*
	i = 1, f(1) = "0"
	i = 2, f(2) = "001"
	i = 3, f(3) = "0010011"
	...
	i = k, f(k) = f(k - 1) + "0" + f(k - 1).reverse().flip().

	Note we use bit manipulation to push back the value instead of hard copy, which can save a lot of time
	when the string is big.

	Time complextiy is O(n * 2^n), space complexity is O(1).
*/

class Solution {
public:
	/**
	* @param n: The folding times
	* @return: the 01 string
	*/
	string getString(int n) {
		// Write your code here

		string res = "0";

		for (int i = 2; i <= n; ++i) {
			int count = 0, len = res.size();
			res.push_back('0');

			while (count < len)
			{
				res.push_back((1 ^ (res[len - count - 1] - '0')) + '0');
				count++;
			}
		}

		return res;
	}
};