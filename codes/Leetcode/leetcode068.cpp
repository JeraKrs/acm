class Solution {
	public:
		string full(vector<string>& words, int start, int end, int maxWidth) {
			string ans = "";
			int n = end - start, c = 0;
			for (int i = start; i <= end; i++) c += words[i].size();
			int space = maxWidth - c;
			int gap = n ? space / n: 0, res = n ? space % n : space;
			if (end + 1 == words.size()) gap = 1, res = 0;

			for (int i = start; i <= end; i++) {
				ans += words[i];
				if (i < end) {
					for (int j = 0; j < gap; j++) ans += " ";
					if (i - start < res) ans += " ";
				}
			}
			while (ans.size() < maxWidth) ans += " ";

			return ans;
		}

		vector<string> fullJustify(vector<string>& words, int maxWidth) {
			vector<string> ans;
			int n = words.size(), p = 0;
			while (p <  n) {
				int t = p + 1, c = words[p].size();
				while (t < n && c + words[t].size() + 1 <= maxWidth) { c += words[t++].size() + 1; }
				string tmp = full(words, p, t - 1, maxWidth);
				ans.push_back(tmp);
				p = t;
			}
			return ans;
		}
};
