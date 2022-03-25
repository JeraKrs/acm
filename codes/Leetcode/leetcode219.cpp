class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    
        vector<pair<int,int>> pairs;
        for (int i = 0; i < nums.size(); ++i) {
            pairs.emplace_back(make_pair(nums[i], i));
        }
        sort(pairs.begin(), pairs.end());
        for (int i = 1; i < pairs.size(); ++i) {
            if (pairs[i].first == pairs[i-1].first
                && pairs[i].second - pairs[i-1].second <= k) {
                return true;
            }
        }
        return false;
    }
};
