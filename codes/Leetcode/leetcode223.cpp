class Solution {
public:
    bool isin(int x, int y, int x1, int y1, int x2, int y2) {
        return x1 <= x && x <= x2 && y1 <= y && y <= y2;
    }
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        vector<pair<int,int>> points;
        points.emplace_back(make_pair(ax1, ay1));
        points.emplace_back(make_pair(ax1, ay2));
        points.emplace_back(make_pair(ax1, by1));
        points.emplace_back(make_pair(ax1, by2));
        points.emplace_back(make_pair(ax2, ay1));
        points.emplace_back(make_pair(ax2, ay2));
        points.emplace_back(make_pair(ax2, by1));
        points.emplace_back(make_pair(ax2, by2));
        points.emplace_back(make_pair(bx1, ay1));
        points.emplace_back(make_pair(bx1, ay2));
        points.emplace_back(make_pair(bx1, by1));
        points.emplace_back(make_pair(bx1, by2));
        points.emplace_back(make_pair(bx2, ay1));
        points.emplace_back(make_pair(bx2, ay2));
        points.emplace_back(make_pair(bx2, by1));
        points.emplace_back(make_pair(bx2, by2));

        vector<pair<int,int>> inners;
        for (int i = 0; i < points.size(); ++i) {
            if (isin(points[i].first, points[i].second, ax1, ay1, ax2, ay2)
                && isin(points[i].first, points[i].second, bx1, by1, bx2, by2)) {
                    inners.push_back(points[i]);
                }
        }
        int commonArea = 0;
        if (inners.size()) {
            int x1 = inners[0].first;
            int x2 = inners[0].first;
            int y1 = inners[0].second;
            int y2 = inners[0].second;
            for (int i = 0; i < inners.size(); ++i) {
                x1 = min(x1, inners[i].first);
                x2 = max(x2, inners[i].first);
                y1 = min(y1, inners[i].second);
                y2 = max(y2, inners[i].second);
            }
            commonArea = (x2 - x1) * (y2 - y1);
        }
        int sumArea = (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);
        return sumArea - commonArea;
    }
};
