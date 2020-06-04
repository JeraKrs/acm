// Copyright (c) 2020 Ke Shuai.
// All rights reserved.
//
// @filename: basic_string.h
// @author: jerakrs
// @version: 1.0
// @description: the basic algorithm of string.

#include "basic_string.h"

#include <stdlib.h>
#include <algorithm>

namespace algo {

static const uint32_t MAX_PROCESS_LENGTH = 2048;

static const char MANACHER_START_CHAR = '$';
static const char MANACHER_SPLIT_CHAR = '#';

int manacher(const char* str) {
	std::vector<uint32_t> res;
	return manacher(str, &res);
}

int manacher(const char* str, std::vector<uint32_t>* res) {
	if (!str || !res) {
		fprintf(stderr, "Manacher: str or res is nullptr.\n");
		return -1;
	}

	uint32_t len = strlen(str);
	if (len > MAX_PROCESS_LENGTH) {
		fprintf(stderr, "Manacher: the given string is overlength.\n");
		return -1;
	}

	uint32_t mov = 0;
	char tmpstr[(len<<1) + 3];

	tmpstr[mov] = MANACHER_START_CHAR;
	for (uint32_t i = 0; i <= len; ++i) {
		tmpstr[++mov] = MANACHER_SPLIT_CHAR;
		tmpstr[++mov] = str[i];
	}

	res->clear();
	res->resize(mov);

	uint32_t ret = 0;
	uint32_t mix = 0;
	uint32_t idx = 0;
	for (uint32_t i = 1; i < mov; ++i) {
		uint32_t& rad = res->at(i);

		if (i < mix) {
			rad = std::min(res->at(2 * idx - i), mix - i);
		} else {
			rad = 1;
		}

		while (tmpstr[i - rad] == tmpstr[i + rad]) {
			if (mix < i + rad) {
				mix = i + rad;
				idx = i;
			}
			++rad;
		}
		ret = std::max(ret, rad);
	}

	return ret - 1;
}

} // namespace algo
