/*********************************************************************************
  * Copyright (c) 2018 Shuai Ke. All rights reserved.
  *
  * FileName: bubble_sort.hpp
  * Author: jerakrs
  * Version: 1.0
  * Date: 10/06/2018
  * Description: The implementation of bubble sort algorithm. Its best time 
      complexity is o(n), which is occupied when the input is a sorted array.
  *
  * Function List: 
     1.bubble_sort
  		- Params: the unordered array (array) and its length (n).
		- Return: a sorted array.
  		- Time complexity: o(n^2).
  		- Space complexity: o(1).
	  If the sorted element is class, the class needs to overload the '<' operator.
  *
**********************************************************************************/

#ifndef _bubble_sort_hpp_
#define _bubble_sort_hpp_

#include <algorithm>

template<typename T>
void bubble_sort(T array[], const int n)
{
	if (n < 0) {
		fprintf(stderr, "bubble_sort: the "
				"length (%d) of array is illegal.\n", n);
		exit(1);
	}

	for (int i = 1; i < n; i++) {
		bool change = false;

		for (int j = 0; j < n - i; j++) {
			if (array[j] > array[j+1]) {
				std::swap(array[j], array[j+1]);
				change = true;
			}
		}

		if (change == false) return;
	}
}

#endif
