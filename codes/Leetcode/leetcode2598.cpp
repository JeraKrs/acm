class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        std::vector<int> counts;
        counts.resize(n, 0);
        
        for (int i = 0; i < nums.size(); ++i) {
            int t = (nums[i] % value + value) % value;
            if (t >= n) continue;
            ++counts[t];
        }

        for (int i = 0; i < n; ++i) {
            if (counts[i]) {
                if (i + value < n) {
                    counts[i+value] += (counts[i] - 1);
                }
            } else {
                return i;
            }
        }
        return nums.size();
    }
};
