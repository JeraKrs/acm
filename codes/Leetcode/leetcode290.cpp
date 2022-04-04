class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<string, char> string_to_pattern;
        map<char, string> pattern_to_string;

        int p = 0, c = 0;
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') {
                if (i != p) {
                    string str = s.substr(p, i-p);
                    if (c >= pattern.size()) {
                        return false;
                    }
                    char ch = pattern[c++];

                    if (string_to_pattern.find(str) == string_to_pattern.end()) {
                        string_to_pattern[str] = ch;
                    }

                    if (pattern_to_string.find(ch) == pattern_to_string.end()) {
                        pattern_to_string[ch] = str;
                    }

                    if (pattern_to_string[ch] != str
                        || string_to_pattern[str] != ch) {
                            return false;
                    }
                }
                p = i + 1;
            }
        }
        return c == pattern.size();
    }
};
