class Solution {
public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        int num = parent.size();

        // build graph;
        std::vector<std::vector<int>> childs;
        childs.resize(num);
        for (int i = 1; i < num; ++i) {
            childs[parent[i]].push_back(i);
        }

        std::map<int, int> counts;
        std::vector<int> marks;
        marks.resize(num, 0);
        std::queue<int> que;
        que.push(0);
        counts[0] = 1;

        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (int i = 0; i < childs[u].size(); ++i) {
                int v = childs[u][i];
                int m = marks[u] ^ (1<< (s[v] - 'a'));
                if (counts.find(m) != counts.end()) {
                    counts[m]++;
                } else {
                    counts[m] = 1;
                }
                marks[v] = m;
                que.push(v);
            }
        }
        long ans = 0;
        for (std::map<int,int>::iterator iter = counts.begin(); iter != counts.end(); iter++) {
            int key = iter->first;
            int val = iter->second;
            ans += 1LL * val * (val - 1) / 2;
            for (int i = 0; i < 26; ++i) {
                int new_key = key^(1<<i);
                if (new_key <= key) continue;
                if (counts.find(new_key) != counts.end()) {
                    int new_val = counts[new_key];
                    ans += 1LL * val * new_val;
                }
            }
        }

        return ans;
    }
};
