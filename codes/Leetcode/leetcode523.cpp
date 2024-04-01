class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        long sum = 0;
        std::map<int, int> records;
        records[0] = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            int idx = sum % k;
            if (records.find(idx) != records.end()) {
                if (i - records[idx] >= 1) {
                    return true;
                }
            } else {
                records[idx] = i + 1;
            }
        }
        return false;
    }
};
