
/*
https://leetcode.com/problems/next-closest-time/description/

Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. 
There is no limit on how many times a digit can be reused.

You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.

*/

#include "stdafx.h"
#include "set"

using namespace std;

/*
	
*/


class Solution {
public:
	 string nextClosestTime(string time) {
		set<int> s{ time[0], time[1], time[3], time[4] };
		string s2(s.begin(), s.end());
		string res = time;

		for (int i = 4; i >= 0; --i) {
			if (time[i] == ':') continue;

			int pos = s2.find(time[i]);
			if (pos == s2.size() - 1) {
				res[i] = s2[0];
			}
			else {
				char next = s2[pos + 1];
				if (i == 4 || (i == 3 && next <= '5')) {
					res[i] = next;
					return res;
				}
				else if (i == 1 && ((res[0] == '2' && next <= '3') || res[0] != '2')) {
					res[i] = next;
					return res;
				}
				else if (i == 0 && next <= '2') {
					res[i] == next;
					return res;
				}

				res[i] = s2[0];
			}
		}

		return res;
	}

	string nextClosestTime(string time) {
		int m = stoi(time.substr(3)), h = stoi(time.substr(0, 2));

		while (1) {
			m++;
			if (m > 59) {
				m = 0;
				(++h) %= 24;
			}

			
		}
	}
};