class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        std::vector<pair<int,int>> windows;
        for (int i = 0; i < nums.size(); ++i) {
            windows.push_back(make_pair(nums[i] - k, 1));
            windows.push_back(make_pair(nums[i] + k + 1, -1));
        }
        sort(windows.begin(), windows.end());
        int ans = 0, mov = 0;
        for (int i = 0; i < windows.size(); ++i) {
            if (i && windows[i].first != windows[i-1].first) {
                ans = std::max(ans, mov);
            }
            mov += windows[i].second;
        }
        return std::max(ans, mov);
    }
};
