class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        std::vector<std::set<int> > languages_set;
        for (auto i : languages) {
            languages_set.emplace_back(i.begin(), i.end());
        }
        std::set<int> p;
        for (auto f : friendships) {
            int u = f[0] - 1, v = f[1] - 1;
            bool can = false;
            for (int i = 1; i <= n; ++i) {
                if (languages_set[u].find(i) != languages_set[u].end()
                    && languages_set[v].find(i) != languages_set[v].end()) {
                    can = true;
                    break;
                }
            }
            if (!can) {
                p.insert(u);
                p.insert(v);
            }
        }
        int ans = p.size();
        for (int i = 1; i <= n; ++i) {
            int cnt = 0;
            for (auto u : p) {
                if (languages_set[u].find(i) == languages_set[u].end()) cnt++;
            }
            ans = std::min(ans, cnt);
        }
        return ans;
    }
};
