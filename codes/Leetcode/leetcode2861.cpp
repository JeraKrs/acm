class Solution {
public:
    int maxNumberOfAlloy(const std::vector<int>& composition,
        int budget, int n, const std::vector<int>& stock,
        const std::vector<int>& cost) {

        int l = 0, r = 1e9;
        while (l + 1 < r) {
            int mid = (l + r) >> 1;

            bool can = true;
            int res_money = budget;
            for (int i = 0; i < n; ++i) {
                long long need_item = std::max(0LL, 1LL * mid * composition[i] - stock[i]);
                long long need_money = need_item * cost[i];
                if (need_money > res_money) {
                    can = false;
                    break;
                }
                res_money -= need_money;
            }
            if (can) l = mid;
            else r = mid;
        }
        return l;
    }

    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {

        int ans = 0;
        for (int i = 0; i < k; ++i) {
            ans = std::max(ans, maxNumberOfAlloy(composition[i], budget, n, stock, cost));
        }
        return ans;
    }
};
