class Solution {
	public:
		bool isPalindrome(string s) {
			int n = s.size();
			for (int i = 0; i + i < n; i++)
				if (s[i] != s[n-i-1]) return false;
			return true;
		}

		int minCut(string s) {
			if (s.size() == 0) return 0;

			queue<pair<int, int>> que;
			que.push(make_pair(0, 0));

			int ans, n = s.size();
			bool* flag = new bool[n+1];
			for (int i = 0; i <= n; i++) flag[i] = false;

			while (!que.empty()) {
				int start = que.front().first;
				int step = que.front().second;
				que.pop();

				if (start >= n) {
					ans = step - 1;
					break;
				}

				for (int i = start; i < n; i++) {
					if (flag[i+1]) continue;

					string tmp = s.substr(start, i - start + 1);
					if (isPalindrome(tmp)) {
						flag[i+1] = true;
						que.push(make_pair(i+1, step + 1));
					}
				}
			}

			delete[] flag;
			return ans;
		}
};
