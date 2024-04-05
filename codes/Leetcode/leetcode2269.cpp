class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int cnt = 0;
        long maximum = 1;
        for (int i = 0 ; i < k; ++i) maximum *= 10;

        std::string num_str = std::to_string(num);
        long val = 0;
        for (int i = 0; i < num_str.size(); ++i) {
            val = (val * 10 + num_str[i] - '0') % maximum;
            if (i + 1 >= k && val && num % val == 0) {
                ++cnt;
            }
        }
        return cnt;
    }
};
