class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        std::map<std::string, int> counts;
        for (int i = 0; i < paths.size(); ++i) {
            if (counts.find(paths[i][0]) == counts.end()) {
                counts[paths[i][0]] = 1;
            } else {
                counts[paths[i][0]] += 1;
            }
            if (counts.find(paths[i][1]) == counts.end()) {
                counts[paths[i][1]] = 0;
            }
        }

        for (auto i : counts) {
            if (i.second == 0) {
                return i.first;
            }
        }
        return "";

    }
};
