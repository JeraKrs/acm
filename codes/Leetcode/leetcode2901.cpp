class Solution {
public:
    bool judge(const std::string& lhs, const std::string& rhs) {
        if (lhs.size() != rhs.size()) return false;
        int cnt = 0;
        for (int i = 0; i < lhs.size(); ++i) {
            if (lhs[i] != rhs[i]) cnt++;
        }
        return cnt == 1;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        std::vector<int> dp;
        std::vector<int> re;
        dp.resize(n, 1);
        re.resize(n, 0);

        int max_length = 1, max_position = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] && judge(words[i], words[j])) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        re[i] = j;
                    }
                }
            }
            if (dp[i] > max_length) {
                max_length = dp[i];
                max_position = i;
            }
        }

        std::vector<int> review;
        int mov = max_position;
        while (max_length--) {
            review.emplace_back(mov);
            mov = re[mov];
        }

        std::vector<std::string> ans;
        for (int i = review.size() - 1; i >= 0; --i) {
            ans.emplace_back(words[review[i]]);
        }
        return ans;
    }
};
