class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude = 0, ans = 0;
        for (auto g : gain) {
            altitude += g;
            ans = std::max(ans, altitude);
        }
        return ans;
    }
};
