class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        std::priority_queue<int> que;
        for (int i = 0; i < piles.size(); ++i) {
            que.push(piles[i]);
        }

        while (k--) {
            int x = que.top();
            que.pop();
            x -= (x>>1);
            que.push(x);
        }

        int ans = 0;
        while (!que.empty()) {
            ans += que.top();
            que.pop();
        }
        return ans;

    }
};
