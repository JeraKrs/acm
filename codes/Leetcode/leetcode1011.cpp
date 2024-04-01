class Solution {
public:
    int judge(int load, std::vector<int>& weights) {
        int sum = 0, cnt = 0;
        for (int i = 0; i < weights.size(); ++i) {
            if (sum + weights[i] > load) {
                ++cnt;
                sum = weights[i];
            } else {
                sum += weights[i];
            }
        }
        return cnt + 1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0, r = 0;
        for (int i = 0; i < weights.size(); ++i) {
            r += weights[i];
            l = std::max(l, weights[i] - 1);
        }

        while(l + 1 < r) {
            int mid = (l + r)/2;
            if (judge(mid, weights) <= days) r = mid;
            else l = mid;
        }
        return r;
    }
};
