class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());

        int n = citations.size();
        int p = 0;
        for (int h = 1; h <= n; ++h) {
            while (p < n && citations[p] < h) ++p;
            if (n - p < h) {
                return h - 1;
            }
        }
        return n;
    }
};
