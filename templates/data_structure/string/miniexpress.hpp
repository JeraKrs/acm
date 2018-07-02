/*********************************************************************************
  * Copyright (c) 2018 Shuai Ke. All rights reserved.
  *
  * FileName: miniexpress.hpp
  * Author: jerakrs
  * Version: 1.0
  * Date: 02/07/2018
  * Description: The implementation of miniexpress algorithm.
  *
  * Function List: 
	1. miniexpress
		- Params: A pointer to the C string (str).
		- Return: The start position of the string's minimum dictionary order.
		- Time complexity: o(n).
  *
**********************************************************************************/

#ifndef _miniexpress_hpp_
#define _miniexpress_hpp_

#include <algorithm>

int miniexpress(char* str) {
	int n = strlen(str);
	int p = 0, q = 1, i;

	while (p < n && q < n) {

		for (i = 0; i < n; i++) {
			if (str[(p+i)%n] != str[(q+i)%n])
				break;
		}

		if (str[(p+i)%n] > str[(q+i)%n])
			p = p + i + 1;
		else
			q = q + i + 1;

		if (p == q)
			q++;
	}

	return std::min(p, q);
}

#endif
