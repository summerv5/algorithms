
/*
http://lintcode.com/en/problem/meeting-rooms-ii/

Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

Example
Given intervals = [(0,30),(5,10),(15,20)], return 2.

*/

#include "stdafx.h"
#include "interval.h"
#include "queue"
#include "functional"

using namespace std;

/*
	Here we make use of priority_queue container. So sort the intervals by the start time, if we come cross a start time that is bigger the the first number in the queue,
	then we can say that the previous meeting has completed (we store the ending time in the queue), we can remove the first number in the queue. Repeatly through the intervals,
	we can then find the mininal number required by counting the size of the queue.

	Time complexity is O(nLogn), space complexity is O(n).
*/

/**
* Definition of Interval:
* classs Interval {
*     int start, end;
*     Interval(int start, int end) {
*         this->start = start;
*         this->end = end;
*     }
* }
*/

class Solution {
public:
	/**
	* @param intervals: an array of meeting time intervals
	* @return: the minimum number of conference rooms required
	*/
	int minMeetingRooms(vector<Interval> &intervals) {
		// Write your code here

		sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b) { return a.start < b.start; });
		priority_queue<int, vector<int>, greater<int>> q;

		for (auto i : intervals) {
			if (!q.empty() && i.start >= q.top()) q.pop();
			q.push(i.end);
		}

		return q.size();
	}
};