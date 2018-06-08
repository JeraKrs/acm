class Solution {
	public:
		int firstMissingPositive(vector<int>& nums) {
			nums.push_back(0);
			int n = nums.size();

			for (int i = 0; i < n; i++) {
				while (nums[i] >= 0 && nums[i] < n) {
					if (nums[i] == i || nums[i] == nums[nums[i]]) break;

					int tmp = nums[i];
					nums[i] = nums[tmp];
					nums[tmp] = tmp;
				}
			}
			int ans = 1;
			while (ans < n && nums[ans] == ans) ans++;
			return ans;
		}
};
