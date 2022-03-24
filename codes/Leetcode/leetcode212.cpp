class Solution {
public:
    struct Node {
        int v;
        int next[26];
        Node() {
            v = 0;
            memset(next, -1, sizeof(next));
        }
    };
    void dfs(int x, int y, const vector<vector<char>>& board,
                int mov, const vector<Node>& nodes,
                vector<vector<int>>& flags,  set<int>& finds) {
        if (nodes[mov].v) {
            finds.insert(nodes[mov].v);
        }
        static int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int m = board.size();
        int n = board[0].size();

        for (int d = 0; d < 4; ++d) {
            int xx = x + dir[d][0];
            int yy = y + dir[d][1];
            if (xx < 0 || xx >= m || yy < 0 || yy >= n || flags[xx][yy]) {
                continue;
            }
            
            int e = board[xx][yy] - 'a';
            if (nodes[mov].next[e] == -1) {
                continue;
            }
            flags[xx][yy] = 1;
            dfs(xx, yy, board, nodes[mov].next[e], nodes, flags, finds);
            flags[xx][yy] = 0;
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<Node> nodes;
        nodes.emplace_back(Node());

        for (int i = 0; i < words.size(); ++i) {
            int mov = 0;
            for (int j = 0; j < words[i].size(); ++j) {
                int e = words[i][j] - 'a';
                if (nodes[mov].next[e] == -1) {
                    nodes[mov].next[e] = nodes.size();
                    nodes.emplace_back(Node());
                }
                mov = nodes[mov].next[e];
            }
            nodes[mov].v = i + 1;
        }

        set<int> finds;
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> flags;
        flags.resize(m);
        for (int i = 0; i < m; ++i) {
            flags[i].resize(n);
            for (int j = 0; j < n; ++j) {
                flags[i][j] = 0;
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int e = board[i][j] - 'a';
                if (nodes[0].next[e] != -1) {
                    flags[i][j] = 1;
                    dfs(i, j, board, nodes[0].next[e], nodes, flags, finds);
                    flags[i][j] = 0;
                }
            }
        }

        vector<string> ans;
        for (int i = 0; i < words.size(); ++i) {
            if (finds.find(i+1) != finds.end()) {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};
