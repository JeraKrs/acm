class Solution {
public:
    int countBinarySubstrings(string s) {
        std::vector<int> count;
        count.emplace_back(0);
        
        int ans = 0;
        int pre = -1;
        int cnt = 0;
        for (int i = 0; i <= s.size(); ++i) {
            if (s[i] != pre) {
                ans += std::min(count[count.size() - 1], cnt);
                count.emplace_back(cnt);
                cnt = 0;
                pre = s[i];
            }
            ++cnt;
        }
        return ans;
    }
};
