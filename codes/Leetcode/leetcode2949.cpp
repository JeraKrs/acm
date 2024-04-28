class Solution {
public:
    long long beautifulSubstrings(string s, int k) {
        auto is_vowels = [&](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        std::vector<int> w;
        for (int i = 0; i < k; ++i) {
            if (i * i % k == 0) w.emplace_back(i);
        }

        std::map<int, std::map<int, int> > record;
        record[0][0] = 1;
        int vowels = 0, consonants = 0;
        long long ans = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (is_vowels(s[i])) vowels++;
            else consonants++;
            int det = vowels - consonants;
            for (int j = 0; j < w.size(); ++j) {
                int t = (vowels - w[j] + k) % k;
                ans += record[det][t];
            }
            record[det][vowels % k]++;
        }
        return ans;
    }
};
