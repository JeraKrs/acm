class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        std::sort(arr.begin(), arr.end());
        int n = arr.size();
        int m = arr[(n-1)>>1];

        int l = 0, r = n-1;
        std::vector<int> ans;
        for (int i = 0; i < k; ++i) {
            int dis_r = abs(arr[r] - m);
            int dis_l = abs(arr[l] - m);
            if (dis_l > dis_r) {
                ans.emplace_back(arr[l++]);
            } else {
                ans.emplace_back(arr[r--]);
            }
        }
        return ans;
    }
};
