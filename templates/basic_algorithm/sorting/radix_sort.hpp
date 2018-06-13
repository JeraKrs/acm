/*********************************************************************************
  * Copyright (c) 2018 Shuai Ke. All rights reserved.
  *
  * FileName: radix_sort.hpp
  * Author: jerakrs
  * Version: 1.0
  * Date: 13/06/2018
  * Description: The implementation of radix sort algorithm. Counting sort is
      not a comparison sort algorithm.
  *
  * Function List: 
     1.radix_sort
  		- Params: a unordered array (array) and its length (n).
		- Return: a sorted array.
		- Time complexity: o(kn).
  		- Space complexity: o(n+k).
     2.max_bit
  		- Params: a unordered array (array) and its length (n).
		- Return: the maximum number of bit.
  *
**********************************************************************************/

#ifndef _radix_sort_h_
#define _radix_sort_h_

#include <algorithm>

int max_bit(int array[], const int n)
{
	int maximum = array[0];
	for (int i = 1; i < n; i++)
		maximum = std::max(maximum, array[i]);

	int d = 0;
	while (maximum > 0) {
		d++;
		maximum = maximum / 10;
	}
	return d;
}


void radix_sort(int array[], const int n)
{
	if (n < 0) {
		fprintf(stderr, "radix_sort: the "
				"length (%d) of array is illegal.\n", n);
		exit(1);
	}

	int* tmp = new int[n];
	int* cnt = new int[10];
	if (tmp == NULL || cnt == 0) { 
		fprintf(stderr, "radix_sort: failed " 
				"to apply for memory space.\n");
		exit(1);
	}

	int d = max_bit(array, n);
	int radix = 1;

	for (int k = 0; k < d; k++) {

		for (int i = 0; i < 10; i++)
			cnt[i] = 0;

		for (int i = 0; i < n; i++) {
			int k = (array[i] / radix) % 10;
			cnt[k]++;
		}

		for (int i = 1; i < 10; i++)
			cnt[i] = cnt[i-1] + cnt[i];

		for (int i = n - 1; i >= 0; i--) {
			int k = (array[i] / radix) % 10;
			tmp[cnt[k] - 1] = array[i];
			cnt[k]--;
		}

		for (int i = 0; i < n; i++)
			array[i] = tmp[i];

		radix = radix * 10;
	}

	delete[] cnt;
	delete[] tmp;
}

#endif
