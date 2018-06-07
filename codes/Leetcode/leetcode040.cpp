class Solution {
	public:
		vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
			vector<int> tmp;
			vector<vector<int>> ans;

			int* count = new int[candidates.size()];
			int n = count[0] = 0;
			sort(candidates.begin(), candidates.end());
			for (int i = 0; i < candidates.size(); i++) {
				if (candidates[i] == candidates[n]) count[n]++;
				else { 
					count[++n] = 1;
					candidates[n] = candidates[i];
				}
			}

			queue< pair<int, int> > que_infos;
			queue<vector<int>> que_state;
			que_infos.push(make_pair(target, 0));
			que_state.push(tmp);

			while (!que_infos.empty()) {
				int res = que_infos.front().first;
				int start = que_infos.front().second;
				vector<int> state = que_state.front();
				que_infos.pop(), que_state.pop();

				if (res == 0) { ans.push_back(state); continue;}

				for (int i = start; i <= n; i++) {
					if (candidates[i] > res) break;
					int k = count[i], f = res;
					tmp = state;

					while (k && f >= candidates[i]) {
						k--; tmp.push_back(candidates[i]);
						f -= candidates[i];
						que_infos.push(make_pair(f, i + 1));
						que_state.push(tmp);
					}
				}
			}

			delete count;
			return ans;
		}
};
