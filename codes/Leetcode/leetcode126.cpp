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

		vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
			vector<vector<string>> ans;
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
			queue< pair<int, vector<string>> > que;
			vector<string> cur;
			cur.push_back(beginWord);
			que.push(make_pair(n-1, cur));

			bool* flag = new bool[n];
			for (int i = 0; i < n; i++) flag[i] = false;
			flag[n-1] = true;

			while (!que.empty()) {
				int n = que.size();
				vector<int> visit;

				while (n--) {
					int start = que.front().first;
					cur = que.front().second;
					que.pop();

					if (wordList[start] == endWord) {
						ans.push_back(cur);
						continue;
					}

					for (int i = 0; i < graph[start].size(); i++) {
						int v = graph[start][i];
						if (flag[v]) continue;

						vector<string> tmp = cur;
						tmp.push_back(wordList[v]);
						que.push(make_pair(v, tmp));
						visit.push_back(v);
					}
				}

				if (ans.size()) break;
				for (int i = 0; i < visit.size(); i++) flag[visit[i]] = true;
			}

			delete[] graph;
			delete[] flag;
			return ans;
		}
};
