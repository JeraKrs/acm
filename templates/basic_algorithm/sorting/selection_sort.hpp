/*********************************************************************************
  * Copyright (c) 2018 Shuai Ke. All rights reserved.
  *
  * FileName: selection_sort.hpp
  * Author: jerakrs
  * Version: 1.0
  * Date: 12/06/2018
  * Description: The implementation of selection sort algorithm.
  *
  * Function List: 
     1.selection_sort
  		- Params: a unordered array (array) and its length (n).
		- Return: a sorted array.
  		- Time complexity: o(n^2).
  		- Space complexity: o(1).
	  If the sorted element is class, the class needs to overload the '<' operator.
  *
**********************************************************************************/

#ifndef _selection_sort_hpp_
#define _selection_sort_hpp_

#include <algorithm>

template<typename T>
void selection_sort(T array[], const int n)
{
	if (n < 0) {
		fprintf(stderr, "selection_sort: the "
				"length (%d) of array is illegal.\n", n);
		exit(1);
	}

	for (int i = 0; i < n - 1; i++) {
		int min_idx = i;
		for (int j = i+1; j < n; j++) {
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		std::swap(array[i], array[min_idx]);
	}
}

#endif
