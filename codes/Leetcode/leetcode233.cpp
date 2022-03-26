class Solution {
public:
    int countDigitOne(int n) {
        long long k = 1;
        int ans = 0;
        while (n >= k) {
            ans += n / (k * 10) * k + min(max(n % (k * 10) - k + 1, 0LL), k);
            k *= 10;
        }
        return ans;
    }
};
