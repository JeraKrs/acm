class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l = 0, r = citations.size() + 1;
        int n = citations.size();
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if (mid && citations[n - mid] < mid) {
                r = mid;
            } else {
                l = mid;
            }            
        }
        return l;
    }
};
