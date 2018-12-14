#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//
//struct Interval {
//     int start;
//     int end;
//     Interval() : start(0), end(0) {}
//    Interval(int s, int e) : start(s), end(e) {}
// };

class SortIntervals{
public:
	bool operator()(Interval a,Interval b)
	{
		if (a.start < b.start)
			return true;
		return false;
	}
};


struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> ret;
		if (intervals.empty())
			return ret;
		if (intervals.size() == 1)
			return intervals;
		sort(intervals.begin(), intervals.end(), SortIntervals());
		int i = 0;
		while (i < intervals.size())
		{
			int start = intervals[i].start;
			int end = intervals[i].end;
			int j = i + 1;
			while (j < intervals.size() && intervals[j].start < end)
			{
				if (intervals[j].end>end)
					end = intervals[i].end;
				j++;
			}
			struct  Interval merge = { start, end };
			ret.push_back(merge);
		}
		return ret;
	}
};

//class Solution {
//public:
//	vector<Interval> merge(vector<Interval>& intervals) {
//		vector<Interval> ret;
//		sort(intervals.begin(), intervals.end(), SortIntervals());
//		int index = 0;
//		while (index < intervals.size())
//		{
//			intervals[index].end=FindIndexEnd(intervals, intervals[index].end,index);
//		}
//	}
//	int FindIndexEnd(vector<Interval>& intervals, int end,int index)
//	{
//		for (int i = index; i < intervals.size(); i++)
//		{
//			if (intervals[i].start> end)
//		}
//	}
//};