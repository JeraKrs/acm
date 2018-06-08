/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
	public:
		vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
			int n = intervals.size(), p = 0;
			while (p < n && intervals[p].start <= newInterval.start) p++;

			intervals.push_back(newInterval);
			for (int i = n; i > p; i--) intervals[i] = intervals[i-1];
			intervals[p] = newInterval;

			p = 0;
			for (int i = 0; i <= n; i++) {
				if (intervals[i].start <= intervals[p].end)
					intervals[p].end = max(intervals[i].end, intervals[p].end);
				else intervals[++p] = intervals[i];
			}

			vector<Interval> ans;
			for (int i = 0; i <= p; i++) ans.push_back(intervals[i]);
			return ans;
		}
};
