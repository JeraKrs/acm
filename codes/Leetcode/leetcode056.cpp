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
		static bool cmp(const Interval& a, const Interval& b) { return a.start < b.start; }

		vector<Interval> merge(vector<Interval>& intervals) {
			int n = intervals.size(), p = 0;
			sort(intervals.begin(), intervals.end(), cmp);

			for (int i = 0; i < n; i++) {
				if (intervals[i].start <= intervals[p].end) {
					intervals[p].end = max(intervals[i].end, intervals[p].end);
				} else
					intervals[++p] = intervals[i];
			}
			vector<Interval> ans;
			if (n == 0) return ans;
			for (int i = 0; i <= p; i++) ans.push_back(intervals[i]);
			return ans;
		}
};
