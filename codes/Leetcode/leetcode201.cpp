class Solution {
public:
    int count(uint32_t v, uint32_t k) {
        v = v + 1;
        uint32_t d = 1UL << (k + 1);
        return v / d * (d / 2) + max(0, (int)(v % d - d / 2));
    }
    int rangeBitwiseAnd(int left, int right) {
        if (left == 0) {
            return 0;
        }
        int ans = 0;
        int d = right - left + 1;
        for (int i = 0; i < 31; ++i) {
            int lc = count(left - 1, i);
            int rc = count(right, i);
            if (rc - lc == d) {
                ans |= (1<<i);
            }
        }
        return ans;
    }
};
