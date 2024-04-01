class Solution {
public:
    inline int bitcount(long x) {
        int c = 0;
        while (x) {
            c += (x&1);
            x >>= 1;
        }
        return c;
    }
    int makeTheIntegerZero(int num1, int num2) {
        for (int i = 1; ; ++i) {
            long res = num1 - 1LL * i * num2;
            if (res < 0) {
                return -1;
            }
            if (res >= i && bitcount(res) <= i) {
                return i;
            }
        }
        return -1;
    }
};
