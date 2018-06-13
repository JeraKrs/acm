/*********************************************************************************
  * Copyright (c) 2018 Shuai Ke. All rights reserved.
  *
  * FileName: quick_sort.hpp
  * Author: jerakrs
  * Version: 1.0
  * Date: 13/06/2018
  * Description: The implementation of quick sort algorithm in a recursive method.
	  Quick sort is an unstable sorting algorithm, its average time compleity is
	  o(n log n), but the worest time complexity is o(n^2).
  *
  * Function List: 
     1.quick_sort
  		- Params: a unordered array (array) and its length (n).
		- Return: a sorted array.
		- Time complexity: o(n log n).
  		- Space complexity: o(1).
	  If the sorted element is class, the class needs to overload the '<' operator.
	 2.quick_sort_recursive
		- Params: the unordered array (array) and the block start and end positions
		    (start, end).
		- Return: a sorted block in the array.
  *
**********************************************************************************/

#ifndef _quick_sort_h_
#define _quick_sort_h_

#include <algorithm>

template<typename T>
void quick_sort_recursive(T array[], int start, int end)
{
	if (start >= end)
		return;

	int mov = start + 1, mid = end;
	while (mov <= mid) {
		while (mov <= mid && array[mov] <= array[start])
			mov++;

		if (mov <= mid)
			std::swap(array[mov], array[mid--]);
	}

	std::swap(array[start], array[mid]);

	quick_sort_recursive(array, start, mid - 1);
	quick_sort_recursive(array, mid + 1, end);
}


template<typename T>
void quick_sort(T array[], const int n)
{
	if (n < 0) {
		fprintf(stderr, "quick_sort: the "
				"length (%d) of array is illegal.\n", n);
		exit(1);
	}

	quick_sort_recursive(array, 0, n - 1);
}

#endif
