class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) {
            return 0;
        }
        std::vector<int> f;
        f.resize(n);
        f[0] = f[1] = 1;
        for (int i = 2; 1LL * i * i < n; ++i) {
            if (f[i]) {
                continue;
            }
            for (int j = 2; 1LL * i * j < n; ++j) {
                f[i*j] = 1;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (f[i] == 0) {
                ++ans;
            }
        }
        return ans;
    }
};
