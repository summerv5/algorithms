
/*
https://leetcode.com/contest/weekly-contest-75/problems/champagne-tower/

We stack glasses in a pyramid, where the first row has 1 glass, the second row has 2 glasses, and so on until the 100th row.  Each glass holds one cup (250ml) of champagne.

Then, some champagne is poured in the first glass at the top.  When the top most glass is full, any excess liquid poured will fall equally to the glass immediately to the left and right of it.
When those glasses become full, any excess champagne will fall equally to the left and right of those glasses, and so on.  
(A glass at the bottom row has it's excess champagne fall on the floor.)

For example, after one cup of champagne is poured, the top most glass is full.  After two cups of champagne are poured, the two glasses on the second row are half full.  
After three cups of champagne are poured, those two cups become full - there are 3 full glasses total now.  
After four cups of champagne are poured, the third row has the middle glass half full, and the two outside glasses are a quarter full, as pictured below.

Now after pouring some non-negative integer cups of champagne, return how full the j-th glass in the i-th row is (both i and j are 0 indexed.)
*/

#include "stdafx.h"
#include "unordered_map"
#include "algorithm"

using namespace std;

/*
	The idea is to have an array that represents the total glasses from top down. Then we store the total poured value in the first glass.
	Going forward, any remaining champagne that poured into the first one will fill into the two glasses on the next row.
	
	Time complexity is O(n^2), space complexity is O(n).
*/

class ChampagneTower{
public:
	static double champagneTower(int poured, int query_row, int query_glass) {
		int size = (query_row + 1) * (query_row + 2) / 2;
		vector<double> glasses(size, 0.0);

		double left = (double)poured;
		glasses[0] = left;
		int index = 0;

		for (int i = 1; i <= query_row + 1; ++i) {
			for (int j = 1; j <= i; ++j, ++index) {
				double cur = glasses[index];

				glasses[index] = (cur >= 1.0) ? 1.0 : cur;

				left = (cur >= 1.0) ? (cur - 1.0) : 0.0;

				if (i < query_row + 1) {
					glasses[index + i] += left / 2;
					glasses[index + i + 1] += left / 2;
				}
			}
		}

		return glasses[query_row * (query_row + 1) / 2 + query_glass];
	}
};

int main() {
	ChampagneTower::champagneTower(15, 4, 0);

}