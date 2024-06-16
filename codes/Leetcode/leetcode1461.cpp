class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < k) return false;

        std::set<int> records;
        int mov = 0;
        for (int i = 0; i < k; ++i) {
            mov = (mov<<1) | (s[i] - '0');
        }

        int n = 1<<k;
        int mask = n - 1;
        records.insert(mov);
        for (int i = k; i < s.size(); ++i) {
            mov = (mov<<1) | (s[i] - '0');
            mov &= mask;
            records.insert(mov);
        }
        return records.size() == n;
    }
};
