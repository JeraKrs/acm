class Solution {
	public:
		string minWindow(string s, string t) {
			int sMap[128] = {0}, tMap[128] = {0};

			int n = t.size();
			for (int i = 0; i < n; i++) tMap[t[i]]++;

			int mov = 0, count = 0;
			int start = -1, ans = 0;
			for (int i = 0; i < s.size(); i++) {
				if (sMap[s[i]] < tMap[s[i]]) count++;
				sMap[s[i]]++;

				if (count == n) {
					char c = s[mov];
					while (sMap[c] > tMap[c]) {
						sMap[c]--;
						c = s[++mov];
					}

					if (start == -1 || ans > i - mov + 1) {
						start = mov;
						ans = i - mov + 1;
					}
				}
			}

			if (start == -1) return "";
			else return s.substr(start, ans);
		}
};
