class Solution {
	public:
		bool trans(string a, string b) {
			bool diff = false;
			for (int i = 0; i < a.size(); i++) {
				if (a[i] != b[i] && diff) return false;
				if (a[i] != b[i]) diff = true;
			}
			return true;
		}

		int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
			wordList.push_back(beginWord);

			int n = wordList.size();
			vector<int>* graph = new vector<int>[n];
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if (trans(wordList[i], wordList[j])) {
						graph[i].push_back(j);
						graph[j].push_back(i);
					}
				}
			}

			int ans = 0;
			queue<int> que;
			que.push(n-1);

			int* dp = new int[n];
			for (int i = 0; i < n; i++) dp[i] = 0;
			dp[n-1] = 1;

			while (!que.empty()) {
				int start = que.front();
				que.pop(); 

				if (wordList[start] == endWord) {
					ans = dp[start];
					break;
				}

				for (int i = 0; i < graph[start].size(); i++) {
					int v = graph[start][i];
					if (dp[v] != 0) continue;
					dp[v] = dp[start] + 1;
					que.push(v);
				}
			}

			delete[] graph;
			delete[] dp;
			return ans;
		}
};
