class Solution {
	public:
		vector<string> generateParenthesis(int n) {
			vector<string> ret;
			if (n == 0) return ret;
			queue<string> qs;
			queue<int> qi;
			qs.push("");
			qi.push(0);

			for (int i = 0; i < 2*n; i++) {
				int t = qs.size();
				for (int j = 0; j < t; j++) {
					string s = qs.front(); qs.pop();
					int c = qi.front(); qi.pop();

					if (c < n) {
						qs.push(s + '(');
						qi.push(c + 1);
					}
					if (2 * c > i) {
						qs.push(s + ')');
						qi.push(c);
					}
				}
			}
			while (!qs.empty()) ret.push_back(qs.front()), qs.pop();
			return ret;
		}
};
