class Solution {
public:

    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>> que;
        que.push(1);

        int ans = 0;
        while (n--) {
            while(ans && ans >= que.top()) que.pop();

            ans = que.top();
            que.pop();

            que.push(2LL * ans);
            que.push(3LL * ans);
            que.push(5LL * ans);
        }
        return ans;
    }
};
