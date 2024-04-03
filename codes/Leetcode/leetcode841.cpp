class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int flags[n];
        memset(flags, 0, sizeof(flags));

        int cnt = 1;
        std::queue<int> que;
        que.push(0);
        flags[0] = 1;
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            
            for (int i = 0; i < rooms[u].size(); ++i) {
                int v = rooms[u][i];
                if (flags[v]) continue;
                flags[v] = 1;
                que.push(v);
                ++cnt;
            }
        }
        return cnt == n;
    }
};
