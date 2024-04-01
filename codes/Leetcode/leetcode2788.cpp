class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        std::vector<std::string> ans;
        for (int i = 0; i < words.size(); ++i) {
            std::string mov;
            for (int j = 0; j < words[i].size(); ++j) {
                if (words[i][j] != separator) mov += words[i][j];
                else if (mov.size()) {
                    ans.push_back(mov);
                    mov = "";
                }
            }
            if (mov.size()) ans.push_back(mov);
        }
        return ans;
    }
};
