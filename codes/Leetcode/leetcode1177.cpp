class Solution {
public:
    bool judge(int* count, int k) {
        int c = 0;
        for (int i = 0; i < 26; ++i) {
            if (count[i]&1) c++;
        }
        return c/2 <= k;
    }

    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        std::vector<bool> ans(queries.size());

        std::vector<std::vector<int> > count(s.size() + 1);
        count[0].resize(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            count[i+1] = count[i];
            count[i+1][s[i]-'a']++;
        }

        for (int i = 0; i < queries.size(); ++i) {
            int l = queries[i][0];
            int r = queries[i][1] + 1;
            int c = 0;
            for (int j = 0; j < 26; ++j) {
                if ((count[r][j] - count[l][j])&1) ++c;
            }
            ans[i] = c/2 <= queries[i][2];
        }
        return ans;
    }
};
