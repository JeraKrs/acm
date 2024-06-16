class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        int add = 0;
        for (int i = s.size() - 1; i > 0; --i) {
            if ((add && s[i] == '1') || (add == 0 && s[i] == '0')) {
                ans += 1;
            } else { 
                add = 1;
                ans += 2;
            }
        }
        if (add) ans++;
        return ans;
    }
};
