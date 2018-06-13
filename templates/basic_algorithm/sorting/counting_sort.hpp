/*********************************************************************************
  * Copyright (c) 2018 Shuai Ke. All rights reserved.
  *
  * FileName: counting_sort.hpp
  * Author: jerakrs
  * Version: 1.0
  * Date: 13/06/2018
  * Description: The implementation of counting sort algorithm. Counting sort is
	  not a comparison sort algorithm, hence it is fast than any comparison sort
	  algorithm. However, it has many limitations, like it cannot sort the array
	  which has a wide range of number and it also cannot sort the array of class.
  *
  * Function List: 
     1.counting_sort
  		- Params: a unordered array (array), its length (n) and the maximum number
		    in array (k).
		- Return: a sorted array.
		- Time complexity: o(n+k).
  		- Space complexity: o(k).
  *
**********************************************************************************/

#ifndef _counting_sort_h_
#define _counting_sort_h_

void counting_sort(int array[], const int n, const int k)
{
	if (n < 0) {
		fprintf(stderr, "countint_sort: the "
				"length (%d) of array is illegal.\n", n);
		exit(1);
	}

	int* count = new int[k+1];
	if (count == NULL) { 
		fprintf(stderr, "counting_sort: failed " 
				"to apply for memory space.\n");
		exit(1);
	}

	for (int i = 0; i <= k; i++)
		count[i] = 0;
	for (int i = 0; i < n; i++)
		count[array[i]]++;

	int mov = 0;
	for (int i = 0; i <= k; i++) {
		while (count[i] > 0) {
			array[mov++] = i;
			count[i]--;
		}
	}

	delete[] count;
}

#endif
