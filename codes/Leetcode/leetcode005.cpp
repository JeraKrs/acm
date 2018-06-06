class Solution {
	public:
		string longestPalindrome(string s) {
			const int maxn = 2 * 1e3 + 5;
			int pos, rad[maxn];
			char str[maxn];  

			int len = s.length(), cnt = 0;  
			str[cnt++] = '$'; 
			for (int i = 0; i <= len; i++) {  
				str[cnt++] = '#';  
				str[cnt++] = s[i];  
			} 
			int ans = 0, mix = 0, id = 0;
			for (int i = 1; i <= cnt; i++) {  
				if (mix > i)  
					rad[i] = min(rad[2 * id - i], mix - i);  
				else  
					rad[i] = 1;  

				for ( ; str[i - rad[i]] == str[i + rad[i]]; rad[i]++) {  
					if (mix < i + rad[i]) {  
						mix = i + rad[i];  
						id = i;  
					}  
				}  

				if (rad[i] > ans) {
					pos = i - rad[i];
					ans = rad[i];
				}
			}

			string ret = "";
			int mv = pos / 2;
			for (int i = 1; i < ans; i++)
				ret += s[mv++];
			return ret;
		}
};
