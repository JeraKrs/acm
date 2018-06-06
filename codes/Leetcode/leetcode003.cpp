class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			int begin = 0, ans = 0;
			map<char, int> g;

			for (int i = 0; i < s.size(); i++) {
				while (g.count(s[i])) {
					g.erase(s[begin++]);
				}
				g[s[i]] = i;
				ans = max(ans, i - begin + 1);
			}
			return ans;
		}
};
