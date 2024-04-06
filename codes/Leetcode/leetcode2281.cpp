class Solution {
public:
    const int mod = 1e9 + 7;
    int range_left(int l, int r, int cnt, const std::vector<long>& sum, const std::vector<long>& sum_s) {
        long s = (sum_s[r] - sum_s[l] + mod) % mod;
        s = (s - (r - l) * sum[l] % mod + mod) % mod;
        return s * cnt % mod;
    }
    int range_right(int l, int r, int cnt, const std::vector<long> & sum, const std::vector<long>& sum_s) {
        long s = (sum_s[l] - sum_s[r] + mod) % mod;
        s = (s - (r - l) * sum[r] % mod + mod) % mod;
        return s * cnt % mod;
    }

    int totalStrength(vector<int>& strength) {
        int n = strength.size();
        std::vector<int> left, right;
        left.resize(n);
        right.resize(n);
        std::stack<pair<int, int> > position;
        position.push(make_pair(0, 0));
        for (int i = 1; i <= n; ++i) {
            int v = strength[i-1];
            while (position.top().first >= v) position.pop();
            left[i-1] = i - position.top().second;
            position.push(make_pair(v, i));
        }
        while (!position.empty()) position.pop();
        position.push(make_pair(0, n+1));
        for (int i = n; i > 0; --i) {
            int v = strength[i-1];
            while (position.top().first > v) position.pop();
            right[i-1] = position.top().second - i;
            position.push(make_pair(v, i));
        }

        std::vector<long> sum_l, sum_ll;
        sum_l.resize(n+1, 0);
        sum_ll.resize(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            sum_l[i] = (sum_l[i-1] + strength[i-1]) % mod;
        }
        for (int i = 1; i <= n; ++i) {
            sum_ll[i] = (sum_l[i] + sum_ll[i-1]) % mod;
        }

        std::vector<long> sum_r, sum_rr;
        sum_r.resize(n+1, 0);
        sum_rr.resize(n+1, 0);
        for (int i = n-1; i >= 0; --i) {
            sum_r[i] = (sum_r[i+1] + strength[i]) % mod;
        }
        for (int i = n-1; i >= 0; --i) {
            sum_rr[i] = (sum_r[i] + sum_rr[i+1]) % mod;
        }
        
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int l = i - left[i-1];
            int r = i + right[i-1] - 1;
            int left_val = range_left(i, r, left[i-1], sum_l, sum_ll);
            int right_val = range_right(l, i-1, right[i-1], sum_r, sum_rr);
            long s = 1LL * strength[i-1] * left[i-1] * right[i-1] % mod;
            s = (s + left_val + right_val) % mod;
            ans = (ans + 1LL * s * strength[i-1]) % mod;
        }
        
        return ans;
    }
};
