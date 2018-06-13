/*********************************************************************************
  * Copyright (c) 2018 Shuai Ke. All rights reserved.
  *
  * FileName: insertion_sort.hpp
  * Author: jerakrs
  * Version: 1.0
  * Date: 10/06/2018
  * Description: The implementation of insertion sort algorithm.
  *
  * Function List: 
     1.insertion_sort
  		- Params: a unordered array (array) and its length (n).
		- Return: a sorted array.
  		- Time complexity: o(n^2).
  		- Space complexity: o(1).
	  If the sorted element is class, the class needs to overload the '<' operator.
  *
**********************************************************************************/

#ifndef _insertion_sort_hpp_
#define _insertion_sort_hpp_

template<typename T>
void insertion_sort(T array[], const int n)
{
	if (n < 0) {
		fprintf(stderr, "insertion_sort: the "
				"length (%d) of array is illegal.\n", n);
		exit(1);
	}

	for(int i = 1; i < n; i++) {

		int p = i - 1, key = array[i];
		while (p >= 0 && key < array[p]) {
			array[p+1]=array[p];
			p = p - 1;
		}
		array[p+1]=key;
	}
}

#endif
