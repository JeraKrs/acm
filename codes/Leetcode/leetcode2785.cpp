class Solution {
public:
    inline bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;
        return false;
    }
    string sortVowels(string s) {
        std::vector<int> positions;
        std::vector<char> vowels;

        for (int i = 0; i < s.size(); ++i) {
            if (isVowel(s[i])) {
                positions.push_back(i);
                vowels.push_back(s[i]);
            }
        }
        std::sort(vowels.begin(), vowels.end());
        for (int i = 0; i < vowels.size(); ++i) {
            s[positions[i]] = vowels[i];
        }
        return s;
    }
};
