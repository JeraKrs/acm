/*
 * special case: "a "  
 */

class Solution {
	public:
		int lengthOfLastWord(string s) {
			int n = s.size(), c = 0;
			while (n && s[n-1] == ' ') n--;

			for (int i = 0; i < n; i++) {
				if (s[i] == ' ') c = 0;
				else c++;
			}
			return c;
		}
};
