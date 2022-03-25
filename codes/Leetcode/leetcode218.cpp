class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        

        vector<pair<int,int>> pos;
        for (int i = 0; i < buildings.size(); ++i) {
            pos.emplace_back(make_pair(buildings[i][0], buildings[i][2]));
            pos.emplace_back(make_pair(buildings[i][1], -buildings[i][2]));
        }
        sort(pos.begin(), pos.end());

        vector<vector<int>> ans;
        multiset<int> heights;
        int pre_h = 0;
        for (int i = 0; i < pos.size(); ++i) {
            if (pos[i].second < 0) {
                auto iter = heights.find(-pos[i].second);
                heights.erase(iter);
            } else {
                heights.insert(pos[i].second);
            }
            if (i + 1 < pos.size() && pos[i].first == pos[i+1].first) {
                continue;
            }
            int h = heights.empty() ? 0 : *heights.rbegin();
            if (h == pre_h) {
                continue;
            }
            pre_h = h;
            ans.push_back({pos[i].first, h});
        }
        return ans;
    }
};
