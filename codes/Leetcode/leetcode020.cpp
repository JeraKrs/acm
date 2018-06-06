class Solution {
	public:
		bool isValid(string s) {
			stack<char> g;
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
					g.push(s[i]);
				} else if (g.empty()) {
					return false;
				} else {
					char t = g.top(); g.pop();
					if (t == '(' && s[i] == ')') continue;
					if (t == '[' && s[i] == ']') continue;
					if (t == '{' && s[i] == '}') continue;
					return false;
				}
			}
			return g.empty();
		}
};
