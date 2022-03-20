class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<int, int> g;
        vector<string> ans;
        for (int i = 0; i + 10 <= s.size(); ++i) {
            int v = 0;
            for (int j = 0; j < 10; ++j) {
                int t = 0;
                if (s[i+j] == 'C') {
                    t = 1;
                } else if (s[i+j] == 'G') {
                    t = 2;
                } else if (s[i+j] == 'T') {
                    t = 3;
                }
                v = (v << 2) + t;
            }
            if (g.find(v) != g.end()) {
                if (g[v] == 1) {
                    ans.push_back(s.substr(i,10));
                }
                ++g[v];
            } else {
                g[v] = 1;
            }
            
        }
        return ans;
    }
};
