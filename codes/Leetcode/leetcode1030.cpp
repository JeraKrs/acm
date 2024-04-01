class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        std::vector<std::vector<int>> g;
        g.resize(rows);
        for (int i = 0 ; i < rows; ++i) g[i].resize(cols, 0);

        g[rCenter][cCenter] = 1;
        std::queue<pair<int,int>> que;
        que.push(make_pair(rCenter, cCenter));

        vector<vector<int>> ans;
        const int dir[] = {1, 0, -1, 0, 1};
        while (!que.empty()) {
            int r = que.front().first;
            int c = que.front().second;
            que.pop();
            ans.push_back({r, c});
            for (int d = 0; d < 4; ++d) {
                int rr = r + dir[d];
                int cc = c + dir[d+1];
                if (rr < 0 || rr >= rows || cc < 0 || cc >= cols || g[rr][cc]) continue;
                que.push(make_pair(rr, cc));
                g[rr][cc] = 1;
            }
        }
        return ans;
    }
};
