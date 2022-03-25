class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            set<int>::iterator iter = mp.lower_bound(max(nums[i], INT_MIN+t) - t);
            if (iter != mp.end() && *iter <= min(nums[i], INT_MAX-t)+t) {
                return true;
            }
            mp.insert(nums[i]);
            if (i >= k) {
                mp.erase(nums[i-k]);
            }
        }
        return false;
    }
};
