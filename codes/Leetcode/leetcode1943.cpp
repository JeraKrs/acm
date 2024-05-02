class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        std::vector<pair<int,int> > positions;
        for (int i = 0; i < segments.size(); ++i) {
            positions.emplace_back(make_pair(segments[i][0], segments[i][2]));
            positions.emplace_back(make_pair(segments[i][1], -segments[i][2]));
        }

        std::sort(positions.begin(), positions.end());
        std::vector<std::vector<long long> > ans;
        long long color = positions[0].second;
        int pre = positions[0].first;
        for (int i = 1; i < positions.size(); ++i) {
            if (positions[i].first == pre) {
                color += positions[i].second;
                continue;
            }
            if (color) {
                std::vector<long long> temp = {positions[i-1].first, positions[i].first, color};
                ans.emplace_back(temp);
            }
            color += positions[i].second;
            pre = positions[i].first;
        }
        return ans;
    }
};
