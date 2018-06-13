/*********************************************************************************
  * Copyright (c) 2018 Shuai Ke. All rights reserved.
  *
  * FileName: heap_sort.hpp
  * Author: jerakrs
  * Version: 1.0
  * Date: 13/06/2018
  * Description: The implementation of heap sort algorithm. Heap sort is an 
	  unstable sorting algorithm.
  *
  * Function List: 
     1.heap_sort
  		- Params: a unordered array (array) and its length (n).
		- Return: a sorted array.
		- Time complexity: o(n log n).
  		- Space complexity: o(1).
	  If the sorted element is class, the class needs to overload the '<' operator.
	 2.max_heapify
		- Params: the unordered array (array) and the block start and end positions
			(start, end).
		- Return: a sorted array in the heap structure.
  *
**********************************************************************************/

#ifndef _heap_sort_h_
#define _heap_sort_h_

template<typename T>
void max_heapify(T array[], int start, int end)
{
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end) {
		if (son + 1 <= end && array[son] < array[son+1])
			son++;

		if (array[dad] > array[son]) {
			return;
		} else {
			std::swap(array[dad], array[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}


template<typename T>
void heap_sort(T array[], const int n)
{
	if (n < 0) {
		fprintf(stderr, "heap_sort: the "
				"length (%d) of array is illegal.\n", n);
		exit(1);
	}

	for (int i = n / 2 - 1; i >= 0; i--)
		max_heapify(array, i, n - 1);

	for (int i = n - 1; i > 0; i--) {
		std::swap(array[i], array[0]);
		max_heapify(array, 0, i - 1);
	}
}

#endif
