class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        const int maxn = 1e6;
        bool prime_array[maxn+1];
        memset(prime_array, false, sizeof(prime_array));
        std::vector<int> prime_num;
        for (int i = 2; i <= 1000; ++i) {
            if (prime_array[i]) continue;
            for (int j = i * i; j <= maxn; j *= i) {
                prime_array[j] = true;
            }
            prime_num.emplace_back(i);
        }
        int max_prime_size = prime_num.size();
        for (int i = 1000; i <= maxn; ++i) {
            if (prime_array[i] == false) prime_num.emplace_back(i);
        }

        std::vector<int> sum, mov;
        sum.resize(prime_num.size(), 0);
        mov.resize(prime_num.size(), 0);

        std::vector<std::vector<int> > factors;
        factors.resize(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            int t = nums[i];
            for (int j = 0; j < max_prime_size && t > 1; ++j) {
                while (t % prime_num[j] == 0) {
                    t /= prime_num[j];
                    factors[i].emplace_back(j);
                    ++sum[j];
                }
            }
            if (t != 1) {
                int index = std::lower_bound(prime_num.begin(), prime_num.end(), t) - prime_num.begin();
                factors[i].emplace_back(index);
                ++sum[index];
            }
        }

        int err = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = 0; j < factors[i].size(); ++j) {
                if (mov[factors[i][j]] == 0) err++;
                ++mov[factors[i][j]];
                if (mov[factors[i][j]] == sum[factors[i][j]]) err--;
            }
            if (err == 0) return i;
        }

        return -1;
    }
};
