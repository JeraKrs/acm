class Solution {
public:
    static const int mod = 1e9 + 7;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.emplace_back(0);
        horizontalCuts.emplace_back(h);
        verticalCuts.emplace_back(0);
        verticalCuts.emplace_back(w);
        std::sort(horizontalCuts.begin(), horizontalCuts.end());
        std::sort(verticalCuts.begin(), verticalCuts.end());

        int max_h = 0, max_w = 0;
        for (int i = 1; i < horizontalCuts.size(); ++i) {
            max_h = std::max(max_h, horizontalCuts[i] - horizontalCuts[i-1]);
        }
        for (int i = 1 ; i < verticalCuts.size(); ++i) {
            max_w = std::max(max_w, verticalCuts[i] - verticalCuts[i-1]);
        }
        return 1LL * max_h * max_w % mod;
    }
};
