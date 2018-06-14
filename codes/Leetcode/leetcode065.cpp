class Solution {
	public:
		bool isNumber(string s) {
			int n = s.size();
			cout << s << endl;

			// Extra space
			int start = 0, end = n - 1;
			while (start < n && s[start] == ' ') start++;
			while (end >= start && s[end] == ' ') end--;
			if (start > end) return false;
			s = s.substr(start, end - start + 1);

			// Signale
			if (s[0] == '-' || s[0] == '+') s = s.substr(1);
			if (s.size() == 0) return false;

			bool is_science = false, is_float = false;
			int p_science, p_float;
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == '.') {
					if (is_float) return false;
					else { is_float = true, p_float = i; }
				} else if (s[i] == 'e') {
					if (is_science) return false;
					else { is_science = true, p_science = i; }
				} else if (s[i] >= '0' && s[i] <= '9') {
					continue;
				} else if (s[i] == '-' || s[i] == '+') {
					if (is_science == false) return false;
				} else {
					return false;
				}
			}

			// (float e float) is invalid.
			if (is_science && is_float && p_science < p_float) return false;

			if (is_science) {
				// ( e float) and (float e) are invalid.
				if (p_science == 0 || p_science + 1 == s.size()) return false;
				return isNumber(s.substr(0, p_science)) && isNumber(s.substr(p_science+1));
			}

			// (.) is invalid.
			if (is_float && s.size() == 1) { return false; }

			return true;
		}
};
