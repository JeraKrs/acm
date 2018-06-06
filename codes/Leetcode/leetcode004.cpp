class Solution {
	public:
		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
			int s1 = 0, s2 = 0, e1 = nums1.size() - 1, e2 = nums2.size() - 1; 
			int n1 = nums1.size(), n2 = nums2.size();

			while (n1 != 0 && n2 != 0 && n1 + n2 > 2) {
				int d = ceil(min(n1, n2) / 3.0);
				int l1 = s1 + ceil(n1 / 3.0) - 1;
				int r1 = e1 - ceil(n1 / 3.0) + 1;
				int l2 = s2 + ceil(n2 / 3.0) - 1;
				int r2 = e2 - ceil(n2 / 3.0) + 1;

				if (nums1[l1] < nums2[l2]) {
					n1 -= d;
					s1 += d;
				} else {
					n2 -= d;
					s2 += d;
				}

				if (nums1[r1] < nums2[r2]) {
					n2 -= d;
					e2 -= d;
				} else {
					n1 -= d;
					e1 -= d;
				}
			}

			double ans = 0;
			if (n1 == 0) {
				int d = ceil(n2 / 2.0);
				ans = (nums2[s2 + d - 1] + nums2[e2 - d + 1]) / 2.0;
			} else if (n2 == 0) {
				int d = ceil(n1 / 2.0);
				ans = (nums1[s1 + d - 1] + nums1[e1 - d + 1]) / 2.0;
			} else {
				ans = (nums1[s1] + nums2[s2]) / 2.0;
			}

			return ans;
		}
};
