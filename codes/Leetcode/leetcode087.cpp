class Solution {
	public:
		bool isScramble(string s1, string s2) {
			if (s1.size() != s2.size()) return false;
			if (s1 == s2) return true;

			int n = s1.size();

			int s1Map[128] = {0}, s2Map[128] = {0};
			for (int i = 0; i < n; i++) {
				s1Map[s1[i]]++;
				s2Map[s2[i]]++;
			}
			for (int i = 0; i < 128; i++) if(s1Map[i] != s2Map[i])
				return false;

			for (int i = 1; i < n; i++) {
				if (isScramble(s1.substr(0, i), s2.substr(0, i))
						&& isScramble(s1.substr(i), s2.substr(i)) )
					return true;

				if (isScramble(s1.substr(0, i), s2.substr(n-i))
						&& isScramble(s1.substr(i), s2.substr(0, n-i)) )
					return true;
			}
			return false;
		}
};
