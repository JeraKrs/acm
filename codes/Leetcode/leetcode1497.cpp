class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        std::vector<int> counts;
        counts.resize(k, 0);
        for (auto i : arr) {
            int mod = (i % k + k) % k;
            counts[mod]++;
        }
        if (counts[0]&1) return false;
        if ((k&1)==0 && counts[k>>1]&1) return false;
        for (int i = 1; i <= (k>>1); ++i) {
            if (counts[i] != counts[k-i]) return false;
        }
        return true;
    }
};
