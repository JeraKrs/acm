class Solution {
public:
    int secondHighest(string s) {
        bool cnt[10] = {0};
        for (auto i : s) {
            if (i >= '0' && i <= '9') {
                cnt[i-'0'] = true;
            }
        }
        int flag = false;
        for (int i = 9; i >= 0; --i) {
            if (cnt[i] && flag) return i;
            if (cnt[i]) flag = true;
        }
        return -1;
    }
};
