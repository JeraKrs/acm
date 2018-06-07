class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        
        int l = 0, r = nums.size();
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] <= target) l = mid;
            else r = mid;
        }
        
        int end = (l + r) >> 1;
        if (nums[end] != target) return {-1, -1};
        
        l = 0, r = nums.size();
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] < target) l = mid;
            else r = mid;
        }
        if (nums[l] < target) l = l + 1;
        
        return {l, end};
    }
};
