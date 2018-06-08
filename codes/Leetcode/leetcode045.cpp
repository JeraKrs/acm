class Solution {
	public:
		int jump(vector<int>& nums) {
			int n = nums.size();
			if (n == 0) return 0;

			int* dp = new int[n];
			priority_queue<pair<int,int>> que;
			dp[0] = 0;
			que.push(make_pair(0, nums[0]));

			for (int i = 1; i < n; i++) {
				while (!que.empty() && que.top().second < i) que.pop();
				dp[i] =  1 - que.top().first;
				que.push(make_pair(-dp[i], i+nums[i]));
			}

			int ans = dp[n-1];
			delete dp;
			return ans;
		}
};
