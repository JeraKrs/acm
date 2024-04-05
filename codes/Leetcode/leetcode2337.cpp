class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        std::vector<int> start_L, start_R;
        std::string start_str = "";
        for (int i = 0; i < n; ++i) {
            if (start[i] == 'L') {
                start_str += 'L';
                start_L.emplace_back(i);
            } else if (start[i] == 'R') {
                start_str += 'R';
                start_R.emplace_back(i);
            }
        }

        std::string  target_str = "";
        std::vector<int> target_L, target_R;
        for (int i = 0; i < n; ++i) {
            if (target[i] == 'L') {
                target_str += 'L';
                target_L.emplace_back(i);
            } else if (target[i] == 'R') {
                target_str += 'R';
                target_R.emplace_back(i);
            }
        }

        if (start_str != target_str) return false;
        for (int i = 0; i < start_L.size(); ++i) {
            if (start_L[i] < target_L[i]) return false;
        }
        for (int i = 0; i < start_R.size(); ++i) {
            if (start_R[i] > target_R[i]) return false;
        }
        return true;
    }
};
