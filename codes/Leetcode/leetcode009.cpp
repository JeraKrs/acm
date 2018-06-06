class Solution {
	public:
		bool isPalindrome(int x) {
			if (x < 0) return false;
			int ans = 0, t = x;
			while (t) {
				ans = ans * 10 + t % 10;
				t /= 10;
			}
			return ans == x;
		}
};
