class Solution {
public:
    int isPeakElement(vector<int>& nums, int n) {
        bool lhs = false;
        if (n == 0 || nums[n-1] < nums[n]) {
            lhs = true;
        }

        bool rhs = false;
        if (n == nums.size() - 1 || nums[n+1] < nums[n]) {
            rhs = true;
        }

        if (lhs && rhs) {
            return 0;
        } else if (lhs && !rhs) {
            return 1;
        }
        return -1;
    }
    int findPeakElement(vector<int>& nums) {
        if (nums.size() <= 1) {
            return 0;
        }

        int l = -1;
        int r = nums.size();
        while (l < r) {
            int mid = (l + r) >> 1;
            int val = isPeakElement(nums, mid);
            if (val == 0) {
                return mid;
            } else if (val > 0) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return -1;
    }
};
