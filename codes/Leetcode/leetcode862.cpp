class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int ans = -1;
        std::vector<pair<long long, int> > records;
        long long sum = 0;

        records.emplace_back(make_pair(sum, 0));
        for (int i = 1; i <= nums.size(); ++i) {
            sum += nums[i-1];

            int index = std::upper_bound(records.begin(), records.end(), make_pair(sum - k + 1, 0)) - records.begin();
            index = std::max(index - 1, 0);
            
            if (records[index].first + k <= sum) {
                if (ans == -1 || ans > i - records[index].second) {
                    ans = i - records[index].second;
                }
            }
            
            while (records.size() && records[records.size() - 1].first >= sum) {
                records.pop_back();
            }
            records.emplace_back(make_pair(sum, i));
        }
        return ans == 0 ? -1 : ans;
    }
};
