class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxLen = 0, ans = 0;
        for (auto r : rectangles) {
            int f = std::min(r[0], r[1]);
            if (f > maxLen) {
                maxLen = f;
                ans = 0;
            }
            if (f == maxLen) ans++;
        }
        return ans;
    }
};
