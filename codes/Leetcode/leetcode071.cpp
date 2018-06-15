class Solution {
	public:
		string simplifyPath(string path) {
			stack<string> sta;
			for (int i = 1; i <= path.size(); i++) {
				string tmp = "";
				while (i < path.size() && path[i] != '/') { tmp += path[i++]; }
				if (tmp.size() == 0 || tmp == ".")  {
					continue;
				} else if (tmp == "..") {
					if (!sta.empty()) sta.pop();
				} else sta.push(tmp);
			}

			string ans = "";
			while (!sta.empty()) {
				string tmp = sta.top();
				sta.pop();
				ans = "/" + tmp + ans;
			}
			if (ans.size() == 0) ans = "/";
			return ans;
		}
};
