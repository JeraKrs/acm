class Solution {
public:
    // 题目需要限定复杂度为o(logn)
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        int m = nums[r];

        while (r && nums[r-1] == nums[r]) r--;
        while (l < r && nums[r] == nums[l]) l++;

        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] > m) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return min(nums[l], nums[r]);
    }
};
