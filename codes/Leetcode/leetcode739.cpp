class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> records(105, temperatures.size());
        std::vector<int> ans(temperatures.size());

        for (int i = temperatures.size() - 1; i >= 0; --i) {
            int t = temperatures.size();
            for (int j = temperatures[i] + 1; j <= 100; ++j) {
                t = std::min(t, records[j]);
            }
            ans[i] = t < temperatures.size() ? t - i : 0;
            records[temperatures[i]] = i;
        }
        return ans;
    }
};
