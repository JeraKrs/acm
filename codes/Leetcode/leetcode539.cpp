class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        std::vector<int> times;
        for (int i = 0; i < timePoints.size(); ++i) {
            int hour = atoi(timePoints[i].substr(0,2).c_str());
            int minus = atoi(timePoints[i].substr(3,2).c_str());
            times.push_back(hour * 60 + minus);
            times.push_back(hour * 60 + minus + 24 * 60);
        }
        sort(times.begin(), times.end());
        int res = 24 * 60;
        for (int i = 1; i < times.size(); ++i) {
            res = std::min(res, times[i] - times[i-1]);
        }
        return res;
    }
};
