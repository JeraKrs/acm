class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int flags[k];
        memset(flags, 0, sizeof(flags));
        int ans = 1, cnt = 0;
        for (int i = 0; i < rolls.size(); ++i) {
            if (flags[rolls[i]-1]) continue;

            flags[rolls[i]-1] = 1;
            ++cnt;

            if (cnt == k) {
                ++ans;
                cnt = 0;
                memset(flags, 0, sizeof(flags));
            }
        }
        return ans;
    }
};
