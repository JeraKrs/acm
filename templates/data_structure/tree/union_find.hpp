/*********************************************************************************
  * Copyright (c) 2018 Shuai Ke. All rights reserved.
  *
  * FileName: union_find.hpp
  * Author: jerakrs
  * Version: 1.0
  * Date: 05/07/2018
  * Description: The implementation of union find.
  *
  * Function List: 
	1. union_find::union_find(int sz): construct a union-find data structure.
		- Params: the size of set.
		- Return: none.
		- Time complexity: o(n).

	2. union_find::~union_find(): release a union-find data structure.
		- Params: none.
		- Return: none.

	3. union_find::find(int x): for the given number, find its group. 
		- Params: the given number (x).
		- Return: the group number of the given number.
		- Time complexity: o(1).

	4. union_find::merge(int x, int y): merge two group.
		- Params: merge the (x)'s group and (y)'s group.
		- Return: none.
		- Time complexity: o(1).

	5. union_find::operator= (union_find& uf): overload the copy operator.
		- Params: a valid union-find data structure.
		- Return: a copy of the exist union-find data structure.

	6. union_find::copy(union_find& uf): copy a exist union-find data structure.
		- Params: a valid union-find data structure.
		- Return: none.

	7. union_find::destroy(): destroy the union-find data structure.
		- Params: none.
		- Return: none.
  *
**********************************************************************************/

#ifndef _union_find_hpp_
#define _union_find_hpp_

#include <algorithm>

class union_find {
	public:
		union_find(int sz = 0);
		~union_find();

		int find(int x);
		void merge(int x, int y);
		union_find& operator= (const union_find &uf);

	private:
		int sz;
		int* far;
		int* cnt;

		void destory();
		void copy(const union_find& uf);
};

union_find::union_find(int sz)
{
	this->sz = sz;
	this->far = new int[sz];
	this->cnt = new int[sz];

	for (int i = 0; i < sz; i++) {
		this->far[i] = i;
		this->cnt[i] = 1;
	}
}

union_find::~union_find()
{
	destory();
}

int union_find::find(int x)
{
	return x == far[x] ? x : far[x] = find(far[x]);
}

void union_find::merge(int x, int y)
{
	int fx = find(x);
	int fy = find(y);

	if (cnt[fx] > cnt[fy])
		std::swap(fx, fy);

	if (fx != fy) {
		far[fx] = fy;
		cnt[fy] += cnt[fx];
	}
}

union_find& union_find::operator= (const union_find &uf)
{
	if (&uf == this)
		return *this;

	destory();
	copy(uf);
	return *this;
}

void union_find::destory()
{
	this->sz = 0;
	delete[] this->far;
	delete[] this->cnt;
}

void union_find::copy(const union_find& uf)
{
	this->sz = uf.sz;
	this->far = new int[this->sz];
	this->cnt = new int[this->sz];

	for (int i = 0; i < this->sz; i++) {
		this->far[i] = uf.far[i];
		this->cnt[i] = uf.cnt[i];
	}
}

#endif
