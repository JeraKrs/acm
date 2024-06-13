class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        std::vector<int> ans;
        int start = rounds[0];
        int end = rounds[rounds.size() -1];
        if (start > end) {
            for (int i = 1; i <= end; ++i) ans.push_back(i);
            for (int i = start; i <= n; ++i) ans.push_back(i);
        } else if (start == end) {
            ans.push_back(start);
        } else {
            for (int i = start; i <= end; ++i) ans.push_back(i);
        }
        return ans;

    }
};
