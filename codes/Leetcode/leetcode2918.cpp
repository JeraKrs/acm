class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, zero1 = 0;
        for (int i = 0; i < nums1.size(); ++i) {
            if (nums1[i] == 0) {
                zero1 += 1;
            } else {
                sum1 += nums1[i];
            }
        }

        long long sum2 = 0, zero2 = 0;
        for (int i = 0; i < nums2.size(); ++i) {
            if (nums2[i] == 0) {
                zero2 += 1;
            } else {
                sum2 += nums2[i];
            }
        }
        if (zero1 == 0 && zero2 == 0) {
            return sum1 == sum2 ? sum1 : -1;
        } else if (zero1 == 0) {
            return sum1 >= sum2 + zero2 ? sum1 : -1;
        } else if(zero2 == 0) {
            return sum2 >= sum1 + zero1 ? sum2 : -1;
        } else {
            return std::max(sum1 + zero1, sum2 + zero2);
        }
    }
};
