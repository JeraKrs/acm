class Solution {
public:
    void dfs(int num, vector<string>& ans) {
        int billion = 1e9;
        int billion_num = num / billion;
        num %= billion;
        if (billion_num) {
            dfs(billion_num, ans);
            ans.push_back("Billion");
        }

        int million = 1e6;
        int million_num = num / million;
        num %= million;
        if (million_num) {
            dfs(million_num, ans);
            ans.push_back("Million");
        }

        int thousand = 1e3;
        int thousand_num = num / thousand;
        num %= thousand;
        if (thousand_num) {
            dfs(thousand_num, ans);
            ans.push_back("Thousand");
        }

        int hundred = 1e2;
        int hundred_num = num / hundred;
        num %= hundred;
        if (hundred_num) {
            dfs(hundred_num, ans);
            ans.push_back("Hundred");
        }

        static map<int, string> m;
        if (m.size() == 0) {
            m[20] = "Twenty";
            m[30] = "Thirty";
            m[40] = "Forty";
            m[50] = "Fifty";
            m[60] = "Sixty";
            m[70] = "Seventy";
            m[80] = "Eighty";
            m[90] = "Ninety";
            m[19] = "Nineteen";
            m[18] = "Eighteen";
            m[17] = "Seventeen";
            m[16] = "Sixteen";
            m[15] = "Fifteen";
            m[14] = "Fourteen";
            m[13] = "Thirteen";
            m[12] = "Twelve";
            m[11] = "Eleven";
            m[10] = "Ten";
            m[9] = "Nine";
            m[8] = "Eight";
            m[7] = "Seven";
            m[6] = "Six";
            m[5] = "Five";
            m[4] = "Four";
            m[3] = "Three";
            m[2] = "Two";
            m[1] = "One";
        }

        if (num >= 20) {
            int n = num / 10 * 10;
            ans.push_back(m[n]);         
            num %= 10;
        }

        if (num) {
            ans.push_back(m[num]);
        }
    }
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        vector<string> ans;
        dfs(num, ans);

        string res;
        for (int i = 0; i < ans.size(); ++i) {
            if (i) {
                res += " ";
            }
            res += ans[i];
        }
        return res;
    }
};
