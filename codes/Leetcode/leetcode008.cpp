class Solution {
	public:
		int myAtoi(string str) {
			long ans = 0;
			int flag = 1;
			for (int i = 0; i < str.length(); i++) {
				if (str[i] == '-' )
					flag = -1;
				else if (str[i] == '+')
					flag = 1;
				else if (str[i] == ' ')
					continue;

				if (str[i] == '-' || str[i] == '+') i++;

				while (str[i] >= '0' && str[i] <= '9' && i < str.length()) {
					ans = ans * 10 + (str[i] - '0') * flag;
					if (ans >= INT_MAX) return INT_MAX;
					if (ans <= INT_MIN) return INT_MIN;
					i++;
				}
				break;
			}
			return ans;
		}
};
