class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) {
            return 9;
        }
        long max_value = pow(10, n) - 1;
        for (long i = max_value; i; --i) {
            long val = i;
            for (int j = i; j; j /= 10) {
                val = val * 10 + j % 10;
            }
            for (long j = max_value; j * j >= val; --j) {
                if (val % j == 0) {
                    return val % 1337;
                }
            }
        }
        return 0;
    }
};
