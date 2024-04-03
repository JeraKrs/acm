class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        std::vector<pair<int,int> > positions;
        for (int i = 0; i < shifts.size(); ++i) {
            int v = (shifts[i][2] == 0 ? -1 : 1);
            positions.emplace_back(make_pair(shifts[i][0], v));
            positions.emplace_back(make_pair(shifts[i][1] + 1, v * -1));
        }
        std::sort(positions.begin(), positions.end());

        int mv = 0, bias = 0;
        for (int i = 0; i < s.size(); ++i) {
            while (mv < positions.size() && positions[mv].first == i) {
                bias = (bias + positions[mv++].second + 26) % 26;
            }
            int c = (s[i] - 'a' + bias + 26) % 26;
            s[i] = 'a' + c;
        }
        return s;
    }
};
