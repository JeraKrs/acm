class Solution {
public:
    double distance(double x, double y) {
        return std::sqrt(x*x+y*y);
    }
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        std::vector<int> ans;
        for (auto query : queries) {
            int cnt = 0;
            for (auto point : points) {
                double dis = distance(point[0] - query[0], point[1] - query[1]);
                if (dis <= query[2]) ++cnt;
            }
            ans.emplace_back(cnt);
        }
        return ans;
    }
};
