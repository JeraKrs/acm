// Copyright (c) 2020 Ke Shuai.
// All rights reserved.
//
// @filename: skiplist.hpp
// @author: jerakrs
// @version: 2.1
// @description: the implementation of skiplist.

#ifndef ALGORITHM_DATA_STRUCTURE_LINEAR_LIST_SKIPLIST_HPP
#define ALGORITHM_DATA_STRUCTURE_LINEAR_LIST_SKIPLIST_HPP

#include <stdio.h>
#include <stdlib.h>
#include <new> // std::bad_alloc

namespace algo {

const double SKIPLIST_LEVEL_PROB = 0.25;
const uint32_t SKIPLIST_MAX_LEVEL = 20;
const uint32_t SKIPLIST_MAX_SIZE = 1e6;

template <typename Key, typename Value>
class Skiplist;

template <typename Key, typename Value>
class SkiplistItem
{
private:
	friend class Skiplist<Key, Value>;

	// Constructs a SkiplistItem.
	// @param: max_level, the maximum level of SkiplistItem.
	SkiplistItem(int max_level)
	{ 
		_forwards = new (std::nothrow) SkiplistItem<Key, Value>*[max_level];

		if (!_forwards) {
			fprintf(stderr, "SkiplistItem: failed to apply memory space for SkiplistItem.\n");
			throw std::bad_alloc();
		}

		for (uint32_t i = 0; i < max_level; ++i) {
			_forwards[i] = nullptr;
		}
	}

	// Release a Skiplist.
	~SkiplistItem()
	{
		delete[] _forwards;
	}

	Key _key;
	Value _val;
	SkiplistItem** _forwards;
};

template <typename Key, typename Value>
class Skiplist
{
public:
	// Constructs the Skiplist.
	// @param: lvl_prob, the probability for random function.
	// @param: max_level, the maximum level of SkiplistItem.
	// @param: max_size, the maximum number of tem in Skiplist.
	Skiplist(double lvl_prob = SKIPLIST_LEVEL_PROB,
			uint32_t max_level = SKIPLIST_MAX_LEVEL,
			uint32_t max_size = SKIPLIST_MAX_SIZE) :
		_size(0), _max_size(max_size),
		_level(0), _max_level(max_level),
		_lvl_prob(lvl_prob)
	{
		_header = new (std::nothrow) SkiplistItem<Key, Value>(_max_level);

		if (!_header) {
			fprintf(stderr, "Skiplist: failed to apply memory space for Skiplist.\n");
			throw std::bad_alloc();
		}
	}

	// Release the Skiplist.
	~Skiplist()
	{
		clear();
		delete _header;
	}

	// Gets the number of items in the Skiplist.
	// @return: the number of items.
	uint32_t size();

	// Gets the value of a given key.
	// @param: key, the given key for searching value.
	// @param: res, a pointer for storing value.
	// @return: true if the key exists.
	bool search(const Key& key, Value* res);

	// Inserts a new item to Skiplist.
	// @param: key, the key of the inserted item.
	// @param: val, the value of the inserted item.
	// @return: true if the insertion is successful.
	bool insert(const Key& key, const Value& val);

	// Updates an existing item.
	// @param: key, the key of the updated item.
	// @param: val, the value of the updated item.
	// @return: true if the update is successful.
	bool update(const Key& key, const Value& val);

	// Inserts or Updates a item.
	// @param: key, the key of the inserted or updated item.
	// @param: val, the value of the inserted or updated item.
	// @return: true if the upsert is successful.
	bool upsert(const Key& key, const Value& val);

	// Removes a existing item.
	// @param: key, the key of the existing item.
	// @return: true if the remove is successful.
	bool remove(const Key& key);

	// Copies a Skiplist.
	// @param: rhs, a given Skiplist.
	// @return: a copied Skiplist.
	const Skiplist<Key, Value>& operator=(const Skiplist<Key, Value>& rhs);
	
	// Empties the Skiplist.
	void clear();

private:
	uint32_t  _size;
	uint32_t _max_size;
	uint32_t _level;
	uint32_t _max_level;
	double _lvl_prob;

	SkiplistItem<Key, Value>* _header;

	// Gets a random number.
	// @return: a random number.
	uint32_t random_level();
};

template <typename Key, typename Value>
uint32_t Skiplist<Key, Value>::size()
{
	return _size;
}

template <typename Key, typename Value>
bool Skiplist<Key, Value>::search(const Key& key, Value* res)
{
	SkiplistItem<Key, Value>* x = _header;
	for (int i = _level - 1; i >= 0; --i) {
		while (x->_forwards[i]
				&& x->_forwards[i]->_key < key) {
			x = x->_forwards[i];
		}
	}

	if (x->_forwards[0]) {
		x = x->_forwards[0];
		if (!(x->_key < key) && !(key < x->_key)) {
			*res = x->_val;
			return true;
		}
	}

	return false;
}

template <typename Key, typename Value>
bool Skiplist<Key, Value>::insert(const Key& key, const Value& val)
{
	if (_size >= _max_size) {
		return false;
	}

	SkiplistItem<Key, Value>* updates[_max_level];
	SkiplistItem<Key, Value>* x = _header;

	for (int i = _level - 1; i >= 0; --i) {
		while (x->_forwards[i] && x->_forwards[i]->_key < key) {
			x = x->_forwards[i];
		}
		updates[i] = x;
	}

	if (x->_forwards[0]) {
		x = x->_forwards[0];
		// key is existing.
		if (!(x->_key < key) && !(key < x->_key)) {
			return false;
		}
	}

	uint32_t level = random_level();
	if (level > _level) {
		for (uint32_t i = _level; i < level; ++i) {
			updates[i] = _header;
		}
		_level = level;
	}

	SkiplistItem<Key, Value>* y = new (std::nothrow) SkiplistItem<Key, Value>(_max_level);
	if (y) {
		y->_key = key;
		y->_val = val;
	} else {
		fprintf(stderr, "Skiplist: failed to apply for memory space.\n");
		return false;
	}

	for (uint32_t i = 0; i < _level; ++i) {
		x = updates[i];
		y->_forwards[i] = x->_forwards[i];
		x->_forwards[i] = y;
	}

	++_size;
	return true;
}

template <typename Key, typename Value>
bool Skiplist<Key, Value>::update(const Key& key, const Value& val)
{
	SkiplistItem<Key, Value>* x = _header;
	for (int i = _level - 1; i >= 0; i--) {
		while (x->_forwards[i]
				&& x->_forwards[i]->_key < key) {
			x = x->_forwards[i];
		}
	}

	if (x->_forwards[0]) {
		x = x->_forwards[0];
		/* Key is existing */
		if (!(x->_key < key) && !(key < x->_key)) {
			x->_val = val;
			return true;
		}
	}

	return false;
}

template <typename Key, typename Value>
bool Skiplist<Key, Value>::upsert(const Key& key, const Value& val)
{
	SkiplistItem<Key, Value>* updates[_max_level];

	SkiplistItem<Key, Value>* x = _header;
	for (int i = _level - 1; i >= 0; --i) {
		while (x->_forwards[i]
				&& x->_forwards[i]->_key < key) {
			x = x->_forwards[i];
		}
		updates[i] = x;
	}

	if (x->_forwards[0]) {
		x = x->_forwards[0];
		/* Key is exist */
		if (!(x->_key < key) && !(key < x->_key)) {
			x->_val = val;
			return true;
		}
	}

	if (_size >= _max_size) {
		return false;
	}

	uint32_t lvl = random_level();
	if (lvl > _level) {
		for (uint32_t i = _level; i < lvl; ++i)
			updates[i] = _header;
		_level = lvl;
	}

	SkiplistItem<Key, Value>* y = new (std::nothrow) SkiplistItem<Key, Value>(_max_level);
	if (y) {
		y->_key = key;
		y->_val = val;
	} else {
		fprintf(stderr, "Skiplist: Failed to apply for memory space.\n");
		return false;
	}

	for (uint32_t i = 0; i < _level; ++i) {
		x = updates[i];
		y->_forwards[i] = x->_forwards[i];
		x->_forwards[i] = y;
	}

	++_size;
	return true;
}

template <typename Key, typename Value>
bool Skiplist<Key, Value>::remove(const Key& key)
{
	SkiplistItem<Key, Value>* updates[_max_level];

	SkiplistItem<Key, Value>* x = _header;
	for (int i = _level - 1; i >= 0; --i) {
		while (x->_forwards[i] &&
				x->_forwards[i]->_key < key) {
			x = x->_forwards[i];
		}
		updates[i] = x;
	}

	if (x->_forwards[0]) {
		x = x->_forwards[0];

		if (!(x->_key < key) && !(key < x->_key)) {
			for (uint32_t i = 0; i < _level; ++i) {
				if (updates[i]->_forwards[i] != x) {
					break;
				}
				updates[i]->_forwards[i] = x->_forwards[i];
			}
			delete x;
			_size--;

			/* Update maximum level */
			while (_level && !_header->_forwards[_level-1]) {
				--_level;
			}

			return true;
		}
	}
	return false;
}

template <typename Key, typename Value>
const Skiplist<Key, Value>& Skiplist<Key, Value>::operator= (
		const Skiplist<Key, Value> &sk)
{
	if (&sk == this) {
		return *this;
	}

	clear();

	_max_size = sk._max_size;
	_max_level = sk._max_level;
	_lvl_prob = sk._lvl_prob;

	SkiplistItem<Key, Value>* x = sk._header->_forwards[0];

	while (x) {
		if (!insert(x->_key, x->_val)) {
			clear();
			break;
		}
		x = x->_forwards[0];
	}

	return *this;
}

template <typename Key, typename Value>
void Skiplist<Key, Value>::clear()
{
	_size = 0;
	_level = 0;
	SkiplistItem<Key, Value>* p = nullptr;

	while (_header->_forwards[0]) {
		p = _header->_forwards[0];
		_header->_forwards[0] = p->_forwards[0];
		delete p;
	}

	for (uint32_t i = 0; i < _max_level; ++i) {
		_header->_forwards[i] = nullptr;
	}
}

template <typename Key, typename Value>
uint32_t Skiplist<Key, Value>::random_level()
{
	uint32_t lvl = 1;
	while (lvl < _max_level
			&& (double)rand() / RAND_MAX < _lvl_prob) {
		++lvl;
	}
	return lvl;
}

} // namespace algo

#endif // ALGORITHM_DATA_STRUCTURE_LINEAR_LIST_SKIPLIST_HPP
