class Solution {
public:

    void get_next(const std::string& pattern, std::vector<int>& next) {
        int len = pattern.size();
        int j = 0;
        next[0] = next[1] = 0;
        for (int i = 1; i < len; ++i) {
            while (j > 0 && pattern[i] != pattern[j]) {
                j = next[j];
            }
    
            if (pattern[i] == pattern[j]) {
                ++j;
            }
    
            next[i+1] = j;
        }
    }
 
    std::vector<int> kmp_search(const std::string& text, const std::string& pattern) {
        int n = text.size(), m = pattern.size();
        std::vector<int> next(m+1);
        get_next(pattern, next);
    
        int j = 0;
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            while (j > 0 && text[i] != pattern[j]) {
                j = next[j];
            }
    
            if (text[i] == pattern[j]) {
                ++j;
            }
    
            if (j == m) {
                res.push_back(i-m+1);
                j = next[j];
            }
        }
    
        return res;
    }

    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.size();
        std::vector<int> position_a = kmp_search(s, a);
        std::vector<int> position_b = kmp_search(s, b);

        std::vector<int> cnt;
        cnt.resize(n + 1, 0);
        for (auto i : position_b) cnt[i+1] = 1;
        for (int i = 1; i <= n; ++i) cnt[i] += cnt[i-1];
        
        std::vector<int> ans;
        for (auto i : position_a) {
            int l = std::max(i - k, 0);
            int r = std::min(i + k + 1, n);
            if (cnt[r] - cnt[l] > 0) ans.emplace_back(i);
        }
        return ans;
    }
};
