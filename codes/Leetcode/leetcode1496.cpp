class Solution {
public:
    static const int bias = 2 * 1e4;
    int hash(int x, int y) {
        x += 1e4;
        y += 1e4;
        return x * bias + y;
    }
    bool isPathCrossing(string path) {
        std::set<int> records;
        int x = 0, y = 0;
        records.insert(hash(x, y));
        for (int i = 0; i < path.size(); ++i) {
            if (path[i] == 'N') {
                --y;
            } else if (path[i] == 'S') {
                ++y;
            } else if (path[i] == 'W') {
                --x;
            } else {
                ++x;
            }
            int h = hash(x, y);
            if (records.find(h) != records.end()) {
                return true;
            }
            records.insert(h);
        }
        return false;
    }
};
