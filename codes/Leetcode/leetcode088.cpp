class Solution {
	public:
		void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
			int mov = m + n - 1;
			while (mov >= 0) {
				if (n <= 0 || (m > 0 && nums1[m-1] > nums2[n-1]))
					nums1[mov--] = nums1[--m];
				else
					nums1[mov--] = nums2[--n];
			}
		}
};
