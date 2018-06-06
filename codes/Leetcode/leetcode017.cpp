class Solution {
	public:
		vector<string> letterCombinations(string digits) {
			vector<string> ans;
			if (digits.size() == 0) return ans;

			ans.push_back("");
			string p[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
			for (int i = 0; i < digits.size(); i++) {
				vector<string> tmp = ans;
				ans.clear();
				int idx = digits[i] - '2';
				for (int j = 0; j < p[idx].size(); j++) {
					for (int k = 0; k < tmp.size(); k++) {
						ans.push_back(tmp[k] + p[idx][j]);
					}
				}
			}
			return ans;
		}
};
