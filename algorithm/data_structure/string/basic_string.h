// Copyright (c) 2020 Ke Shuai.
// All rights reserved.
//
// @filename: basic_string.h
// @author: jerakrs
// @version: 1.1
// @description: the basic algorithm of string.

#ifndef ALGORITHM_DATA_STRUCTURE_STRING_BASIC_STRING_H
#define ALGORITHM_DATA_STRUCTURE_STRING_BASIC_STRING_H

#include <vector>

namespace algo {

// Get the length of the longest palindrome subchain.
// @param: str, the given string.
// @return: the length of the longest palindrome subchain, -1 means error.
int manacher(const char* str);

// Get the length of the longest palindrome subchain.
// @param: str, the given string.
// @param: res, the vector for storing results which each position as the middle of palindrome subchain.
// @return: the length of the longest palindrome subchain, -1 means error.
int manacher(const char* str, std::vector<uint32_t>* res);

} // namespace algo

#endif // ALGORITHM_DATA_STRUCTURE_STRING_BASIC_STRING_H
