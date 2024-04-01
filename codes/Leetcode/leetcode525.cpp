class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int N = nums.size();
        vector<int> diffs(N+1);
        diffs[0] = 0;
        for (int i = 1; i <= N; ++i) {
            diffs[i] += diffs[i-1] + (nums[i-1] ? -1 : 1);
        }
        vector<int> records;
        records.resize(N * 2 + 1, -1);
        int ans = 0;
        for (int i = 0; i <= N; ++i) {
            if (records[diffs[i]+N] == -1) {
                records[diffs[i]+N] = i;
            } else {
                ans = std::max(ans, i - records[N+diffs[i]]);
            }
        }
        return ans;
    }
};
