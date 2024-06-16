class Solution {
public:
    struct Item {
        Item() {}
        Item(int value, int position) : value(value), position(position) {}
        bool operator<(const Item& rhs) const {
            if (value == rhs.value) {
                return position > rhs.position;
            }
            return value < rhs.value;
        }
        int value;
        int position;
    };
    int constrainedSubsetSum(vector<int>& nums, int k) {
        std::vector<int> dp;
        dp.resize(nums.size());

        std::priority_queue<Item> que;

        for (int i = 0; i < nums.size(); ++i) {
            dp[i] = nums[i];

            while (!que.empty() && que.top().position + k < i) {
                que.pop();
            }
            if (!que.empty()) {
                dp[i] = std::max(dp[i], que.top().value + nums[i]);
            }
            que.push(Item(dp[i], i));
        }

        int ans = dp[0];
        for (int i = 1; i < dp.size(); ++i) {
            ans = std::max(ans, dp[i]);
        }
        return ans;
    }
};
