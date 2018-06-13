/*********************************************************************************
  * Copyright (c) 2018 Shuai Ke. All rights reserved.
  *
  * FileName: merge_sort.hpp
  * Author: jerakrs
  * Version: 1.0
  * Date: 12/06/2018
  * Description: The implementation of merge sort algorithm in a recursive method.
  *
  * Function List: 
     1.merge_sort
  		- Params: the unordered array (array) and its length (n).
		- Return: a sorted array.
		- Time complexity: o(n logn).
		- Space complexity: o(n).
	  If the sorted element is class, the class needs to overload the '<' operator.
	 2.merge_sort_recursive
		- Params: the unordered array (array), an array to assist (reg) and the
			block start and end positions (start, end).
		- Return: a sorted block in the array.
  *
**********************************************************************************/

#ifndef _merge_sort_h_
#define _merge_sort_h_

template<typename T>
void merge_sort_recursive(T array[], T reg[], int start, int end)
{
	if (start >= end)
		return;

	int mid = (end + start) >> 1;
	merge_sort_recursive(array, reg, start, mid);
	merge_sort_recursive(array, reg, mid + 1, end);

	int p1 = start, p2 = mid + 1;
	for (int i = start; i <= end; i++) {
		if (p2 > end || (p1 <= mid && array[p1] <= array[p2])) {
			reg[i] = array[p1++];
		} else {
			reg[i] = array[p2++];
		}
	}

	for (int i = start; i <= end; i++)
		array[i] = reg[i];
}


template<typename T>
void merge_sort(T array[], const int n)
{
	if (n < 0) {
		fprintf(stderr, "merge_sort: the "
				"length (%d) of array is illegal.\n", n);
		exit(1);
	}

	T* reg = new T[n];
	if (reg == NULL) {
		fprintf(stderr, "merge_sort: failed "
			"to apply for memory space.\n");
		exit(1);
	}

	merge_sort_recursive(array, reg, 0, n - 1);

	delete[] reg;
}

#endif
