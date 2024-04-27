class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        int ans = 0;
        std::sort(processorTime.begin(), processorTime.end());
        std::sort(tasks.begin(), tasks.end());

        int n = processorTime.size();
        for (int i = 0; i < n; ++i) {
            int t = i * 4 + 3;
            ans = std::max(ans, processorTime[n-i-1] + tasks[t]);
        }
        return ans;
    }
};
