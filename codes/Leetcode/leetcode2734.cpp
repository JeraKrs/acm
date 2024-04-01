class Solution {
public:
    string smallestString(string s) {
        bool start = false;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'a') {
                if (start) break;
                else continue;
            }
            s[i]--;
            start = true;
        }
        if (start == false) {
            s[s.size()-1] = 'z';
        }
        return s;
    }
};
