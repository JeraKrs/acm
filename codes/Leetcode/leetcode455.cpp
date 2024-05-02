class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        int mov = 0;
        int ans = 0;

        for (auto i : g) {
            while (mov < s.size() && s[mov] < i) mov++;
            if (mov >= s.size()) break;
            ans++;
            mov++;
        }
        return ans;
    }
};
