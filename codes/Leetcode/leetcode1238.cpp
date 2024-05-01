class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        std::vector<int> ans(1<<n);
        for (int i = 0; i < ans.size(); ++i) {
            ans[i] = i ^ (i>>1) ^ start;
        }
        return ans;
    }
};
