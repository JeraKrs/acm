/*********************************************************************************
  * Copyright (c) 2018 Shuai Ke. All rights reserved.
  *
  * FileName: shell_sort.hpp
  * Author: jerakrs
  * Version: 1.0
  * Date: 12/06/2018
  * Description: The implementation of shell sort algorithm. Shell sort is an
	  unstable sorting algorithm, the worest time complexity is o(n^2).
  *
  * Function List: 
     1.shell_sort
  		- Params: a unordered array (array) and its length (n).
		- Return: a sorted array.
		- Time complexity: o(n log n) ~ o(n^2).
  		- Space complexity: o(1).
	  If the sorted element is class, the class needs to overload the '<' operator.
  *
**********************************************************************************/

#ifndef _shell_sort_h_
#define _shell_sort_h_

template<typename T>
void shell_sort(T array[], const int n)
{
	if (n < 0) {
		fprintf(stderr, "shell_sort: the "
				"length (%d) of array is illegal.\n", n);
		exit(1);
	}

    int h = 1;
    while (h < n / 3) {
        h = 3 * h + 1;
    }

    while (h >= 1) {
        for (int i = h; i < n; i++) {
            for (int j = i; j >= h && array[j] < array[j - h]; j -= h) {
                std::swap(array[j], array[j - h]);
            }
        }
        h = h / 3;
    }
}

#endif
