#include <vector>
#include <string>

void get_next(const std::string& pattern, std::vector<int>& next) {
	int len = pattern.size();
	int j = 0;
	next[0] = next[1] = 0;
	for (int i = 1; i < len; ++i) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = next[j];
		}

		if (pattern[i] == pattern[j]) {
			++j;
		}

		next[i+1] = j;
	}
}

std::vector<int> kmp_search(const std::string& text, const std::string& pattern) {
	int n = text.size(), m = pattern.size();
	std::vector<int> next(m+1);
	get_next(pattern, next);

	int j = 0;
	std::vector<int> res;
	for (int i = 0; i < n; ++i) {
		while (j > 0 && text[i] != pattern[j]) {
			j = next[j];
		}

		if (text[i] == pattern[j]) {
			++j;
		}

		if (j == m) {
			res.push_back(i-m+1);
			j = next[j];
		}
	}

	return res;
}
