class Solution {
public:
    int beautySum(string s) {
        std::vector<std::vector<int> > counts(s.size() + 1);
        counts[0].resize(26, 0);
        for (int i = 1; i <= s.size(); ++i) {
            counts[i] = counts[i-1];
            ++counts[i][s[i-1]-'a'];
        }

        function<int(int, int)> beauty = [&](int l, int r) {
            int maxCount = 0, minCount = s.size();
            for (int i = 0; i < 26; ++i) {
                int t = counts[r][i] - counts[l][i];
                if (t == 0) continue;
                maxCount = std::max(maxCount, t);
                minCount = std::min(minCount, t);
            }
            return maxCount - minCount;
        };

        int ans = 0;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 1; j < i; ++j) {
                ans += beauty(j-1, i);
            }
        }
        return ans;
    }
};
