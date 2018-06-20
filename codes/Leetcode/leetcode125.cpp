class Solution {
	public:
		bool isPalindrome(string s) {
			int n = 0;
			for (int i = 0; i < s.size(); i++) {
				if ((s[i] >= 'a' && s[i] <= 'z')
						|| (s[i] >= '0' && s[i] <= '9')
				   )
					s[n++] = s[i];
				else if (s[i] >= 'A' && s[i] <= 'Z')
					s[n++] = s[i] - 'A' + 'a';
			}
			for (int i = 0; i + i < n; i++) {
				if (s[i] != s[n-i-1]) return false;
			}
			return true;
		}
};
