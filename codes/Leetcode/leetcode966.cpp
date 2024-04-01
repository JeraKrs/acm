class Trie {
    void add(const std::string& s) {
    }
};


class Solution {
public:
    inline std::string case_insensitive(std::string str) {
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] >= 'A' && str[i] <= 'Z') str[i] = str[i] - 'A' + 'a';
        }
        return str;
    }

    inline std::string vowel_insensitive(std::string str) {
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] >= 'A' && str[i] <= 'Z') str[i] = str[i] - 'A' + 'a';
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') str[i] = '*';
        }
        return str;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        std::map<std::string, int> words;
        std::map<std::string, int> case_insensitive_words;
        std::map<std::string, int> vowel_insensitive_words;

        for (int i = 0; i < wordlist.size(); ++i) {
            if (words.find(wordlist[i]) == words.end()) {
                words[wordlist[i]] = i;
            }
            std::string case_str = case_insensitive(wordlist[i]);
            if (case_insensitive_words.find(case_str) == case_insensitive_words.end()) {
                case_insensitive_words[case_str] = i;
            }
            std::string vowel_str = vowel_insensitive(wordlist[i]);
            if (vowel_insensitive_words.find(vowel_str) == vowel_insensitive_words.end()) {
                vowel_insensitive_words[vowel_str] = i;
            }
        }
        std::vector<std::string> ans;
        for (int i = 0; i < queries.size(); ++i) {
            if (words.find(queries[i]) != words.end()) {
                ans.emplace_back(queries[i]);
                continue;
            }
            
            std::string case_str = case_insensitive(queries[i]);
            if (case_insensitive_words.find(case_str) != case_insensitive_words.end()) {
                ans.emplace_back(wordlist[case_insensitive_words[case_str]]);
                continue;
            }
            std::string vowel_str = vowel_insensitive(queries[i]);
            if (vowel_insensitive_words.find(vowel_str) != vowel_insensitive_words.end()) {
                ans.emplace_back(wordlist[vowel_insensitive_words[vowel_str]]);
                continue;
            }
            ans.emplace_back("");
        }
        return ans;
    }
};
