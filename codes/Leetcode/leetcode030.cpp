class Solution {
	public:
		vector<int> findSubstring(string s, vector<string>& words) {
			vector<int> ans;
			if (words.size() == 0) return ans;

			// Init
			int sn = s.size(), l = words[0].size();

			int wn = 0;
			int* max_count = new int[words.size()];
			sort(words.begin(), words.end());
			for (int i = 0; i < words.size(); i++) {
				if (i == 0 || words[i-1] != words[i]) {
					max_count[wn] = 1;
					words[wn++] = words[i];
				} else
					max_count[wn-1]++;
			}

			int* p = new int[sn];
			for (int i = 0; i < sn; i++) p[i] = -1;

			// Tag matching sub_str
			for (int i = 0; i < wn; i++) {
				int t = s.find(words[i]);
				while (t != -1) {
					p[t] = i;
					int tmp = s.substr(t+1).find(words[i]);
					if (tmp != -1) t += tmp + 1;
					else t = -1;
				}
			}

			int *c = new int[wn];
			for (int i = 0; i < sn; i++) {
				if (p[i] == -1) continue;

				int count = 0;
				for (int j = 0; j < wn; j++) c[j] = 0;
				for (int j = i; j < sn; j += l) {
					if (p[j] == -1 || count == words.size()) break;
					if (c[p[j]] >= max_count[p[j]]) break;
					c[p[j]]++;
					count++;
				}
				if (count == words.size())
					ans.push_back(i);
			}

			delete p;
			delete c;
			delete max_count;
			return ans;
		}
};
