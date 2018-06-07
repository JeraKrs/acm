class Solution {
	public:
		vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
			vector<int> tmp;
			vector<vector<int>> ans;

			queue< pair<int, int> > que_infos;
			queue<vector<int>> que_state;
			que_infos.push(make_pair(target, 0));
			que_state.push(tmp);

			sort(candidates.begin(), candidates.end());

			while (!que_infos.empty()) {
				int res = que_infos.front().first;
				int start = que_infos.front().second;
				vector<int> state = que_state.front();
				que_infos.pop(), que_state.pop();

				if (res == 0) { ans.push_back(state); continue;}

				for (int i = start; i < candidates.size(); i++) {
					if (candidates[i] > res) break;
					tmp = state;
					tmp.push_back(candidates[i]);
					que_infos.push(make_pair(res - candidates[i], i));
					que_state.push(tmp);
				}
			}

			return ans;
		}
};
