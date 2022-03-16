class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s;
        while (columnNumber) {
            int c = (columnNumber - 1) % 26;
            columnNumber = (columnNumber - 1) / 26;
            s += ('A' + c);
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
