class Solution {
	public:
		string countAndSay(int n) {
			string s = "1";
			for (int i = 1; i < n; i++) {
				int num = 1;
				char c = s[0], tmp_c;
				string t = "", tmp_s;

				for (int j = 1; j < s.size(); j++) {
					if (s[j] != c) {
						tmp_s = "";
						while (num) {
							tmp_c = '0' + num % 10;
							tmp_s = tmp_s + tmp_c;
							num /= 10;
						}
						t += tmp_s + c;

						num = 1;
						c = s[j];
					} else
						num++;
				}

				tmp_s = "";
				while (num) {
					tmp_c = '0' + num % 10;
					tmp_s = tmp_s + tmp_c;
					num /= 10;
				}
				t += tmp_s + c;
				s = t;
			}
			return s;
		}
};
