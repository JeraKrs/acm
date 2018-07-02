/*********************************************************************************
  * Copyright (c) 2018 Shuai Ke. All rights reserved.
  *
  * FileName: manacher.hpp
  * Author: jerakrs
  * Version: 1.0
  * Date: 30/06/2018
  * Description: The implementation of manacher algorithm.
  *
  * Function List: 
	1. manacher
		- Params: A pointer to the C string (str).
		- Return: The length of the longest palindromic substring in str.
		- Time complexity: o(n).
  *
**********************************************************************************/

#ifndef _manacher_h_
#define _manacher_h_

#include <algorithm>

int manacher(char* str) {
	int n = strlen(str), m = 0;
	char* tmpstr = new char[(n<<1)+3];

	tmpstr[m++] = '$';
	for (int i = 0; i < n; i++) {
		tmpstr[m++] = '#';
		tmpstr[m++] = str[i];
	}
	tmpstr[m++] = '#';
	tmpstr[m] = '\0';

	int ret = 0, mix = 0, idx = 0;
	int* rad = new int[(n<<1)+3];
	for (int i = 1; i < m; i++) {

		if (mix > i)
			rad[i] = std::min(rad[2 * idx - i], mix - i);
		else
			rad[i] = 1;

		for ( ; tmpstr[i - rad[i]] == tmpstr[i + rad[i]]; rad[i]++) {
			if (mix < i + rad[i]) {
				mix = i + rad[i];
				idx = i;
			}
		}
		ret = std::max(ret, rad[i]);
	}

	delete[] tmpstr;
	delete[] rad;

	return ret - 1;
}

#endif
