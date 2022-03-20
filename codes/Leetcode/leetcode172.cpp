class Solution {
public:
    int trailingZeroes(int n) {
        int count2 = 0;
        int count5 = 0;

        for (int i = 1; i <= n; ++i) {
            int m = i;
            while (m % 2 == 0) {
                ++count2;
                m /= 2;
            }
            while (m % 5 == 0) {
                ++count5;
                m /= 5;
            }
        }
        return min(count2, count5);
    }
};
