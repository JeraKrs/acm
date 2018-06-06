class Solution {
	public:
		int maxArea(vector<int>& height) {
			int ans = 0, n = height.size();
			vector<int> sta;
			vector<int> pos;

			sta.push_back(height[0]);
			pos.push_back(0);
			for (int i = 1; i < n; i++) {
				int t = lower_bound(sta.begin(), sta.end(), height[i]) - sta.begin();
				if (t < sta.size()) {
					ans = max(ans, height[i] * (i - pos[t]));
				}

				if (sta[sta.size()-1] < height[i]) {
					sta.push_back(height[i]);
					pos.push_back(i);
				}
			}

			sta.clear(), pos.clear();
			sta.push_back(height[n-1]);
			pos.push_back(n-1);

			for (int i = n-1; i >= 0; i--) {
				int t = lower_bound(sta.begin(), sta.end(), height[i]) - sta.begin();
				if (t < sta.size()) {
					ans = max(ans, height[i] * (pos[t] - i));
				}

				if (sta[sta.size()-1] < height[i]) {
					sta.push_back(height[i]);
					pos.push_back(i);
				}
			}

			return ans;
		}
};
