class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int mv_first = 0, mv_second = 0;
        std::vector<std::vector<int> > ans;
        while (mv_first < firstList.size() && mv_second < secondList.size()) {
            int l = std::max(firstList[mv_first][0], secondList[mv_second][0]);
            int r = std::min(firstList[mv_first][1], secondList[mv_second][1]);
            if (l <= r) {
                std::vector tmp = {l, r};
                ans.emplace_back(tmp);
            }

            if (firstList[mv_first][1] < secondList[mv_second][1]) mv_first++;
            else mv_second++;
        }
        return ans;
    }
};
