class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long s = 0;
        for (auto& num : nums) s ^= num;
        int c = s & (-s);
        int a = 0, b = 0;
        for (auto& num : nums) {
            if (num&c) a ^= num;
            else b ^= num;
        }
        return {a, b};
    }
};
