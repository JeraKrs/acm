class Solution {
public:

    int maxNiceDivisors(int primeFactors) {
        const int mod = 1e9 + 7;
        if (primeFactors == 1) return primeFactors;
        function<int(int, int)> pow = [&](int x, int t) {
            int r = 1;
            while (t) {
                if (t&1) r = (1LL * r * x) % mod;
                x = (1LL * x * x) % mod;
                t >>= 1;
            }
            return r;
        };
        int x = primeFactors - 2;
        return 1LL * pow(3, x / 3) * (x % 3 + 2) % mod;
    }
};
