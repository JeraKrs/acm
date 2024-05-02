class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        std::map<int, int> counts;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                counts[nums[i] * nums[j]]++;
            }
        }

        int ans = 0;
        for (auto i : counts) {
            int t = i.second;
            ans += (t * (t-1));
        }
        return ans * 4;
    }
};
