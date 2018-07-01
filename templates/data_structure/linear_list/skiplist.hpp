/*********************************************************************************
  * Copyright (c) 2018 Shuai Ke. All rights reserved.
  *
  * FileName: skiplist.hpp
  * Author: jerakrs
  * Version: 1.0
  * Date: 01/07/2018
  * Description: The implementation of skip list.
  *
  * Function List: 
	1. skiplist::skiplist(): construct a skip list.
		- Params: none.
		- Return: none.

	2. skiplist::~skiplist(): release a skip list.
		- Params: none.
		- Return: none.

	3. skiplist::size(): get the number of items in the skip list.
		- Params: none.
		- Return: the number of items in the skip list.

	4. skiplist::random_level(): get a random number.
		- Params: none.
		- Return: a random number.

	5. skiplist::search(Key key, Val ret): get the value of a key.
		- Params: a key and a variate to store the value.
		- Return: true if the key is exist in the skiplist, false otherwise.

	6. skiplist::insert(Key key, Val ret): insert a new item in the skip list.
		- Params: a key and a value of the key.
		- Return: true if succeed, false otherwise.

	7. skiplist::update(Key key, Val ret): update the item in the skip list.
		- Params: a key and a value of the key.
		- Return: true is succeed, false otherwise.
	
	8. skiplist::upsert(Key key, Val ret): insert a new item if the key is not
		in the skip list, otherwise update the value of the key.
		- Params: a key and a value of the key.
		- Return: true is succeed, false otherwise.
	
	9. skiplist::remove(Key key): remove a item in the skip list.
		- Params: a key which needs to remove.
		- Return: true is succeed, false otherwise.

	10. skiplist::operator= (skiplist& sk): overload the copy operator.
		- Params: a valid skip list.
		- Return: a copy of the exist skip list.

	11. skiplist::copy(skiplist& sk): copy a exist skip list.
		- Params: a valid skip list.
		- Return: none.

	12. skiplist::destroy(): destroy the skip list.
		- Params: none.
		- Return: none.
  *
  * The class of Key needs to overload the '<', '==', '=' operators,
  * and the class of Val needs to overload the '=' operator.
**********************************************************************************/


#ifndef _skiplist_h_
#define _skiplist_h_

#include <cstdlib>

#define SKIPLIST_MAX_LEVEL 20
#define SKIPLIST_PROB 0.25
#define SKIPLIST_MAX_ITEMS 1e6


template <typename Key, typename Val>
class skiplist;

template <typename Key, typename Val>
struct skiplist_item {
	friend class skiplist<Key, Val>;

	skiplist_item() { 
		for (int i = 0; i < SKIPLIST_MAX_LEVEL; i++)
			forwards[i] = NULL;
	}

	Key key;
	Val val;
	struct skiplist_item* forwards[SKIPLIST_MAX_LEVEL];
};


template <typename Key, typename Val>
struct skiplist {
	public:
		skiplist();
		~skiplist();

		int size();
		int random_level();
		bool search(const Key& key, Val& ret);
		bool insert(const Key& key, const Val& val);
		bool update(const Key& key, const Val& val);
		bool upsert(const Key& key, const Val& val);
		bool remove(const Key& key);
		skiplist<Key, Val>& operator= (const skiplist<Key, Val> &sk);

	private:
		int sz;
		int level;
		struct skiplist_item<Key, Val>* header;

		void destroy();
		void copy(const skiplist<Key, Val>& sk);
};


	template <typename Key, typename Val>
skiplist<Key, Val>::skiplist()
{
	this->sz = 0;
	this->level = 0;
	this->header = new skiplist_item<Key, Val>;

	if (this->header == NULL) {
		fprintf(stderr, "skiplist: Failed to apply for memory space.\n");
		exit(1);
	}
}

	template <typename Key, typename Val>
skiplist<Key, Val>::~skiplist()
{
	destroy();
	delete this->header;
}

	template <typename Key, typename Val>
int skiplist<Key, Val>::size()
{
	return this->sz;
}

	template <typename Key, typename Val>
int skiplist<Key, Val>::random_level()
{
	int v = 1;
	while (v < SKIPLIST_MAX_LEVEL &&
			(double)rand() / RAND_MAX < SKIPLIST_PROB) {
		v++;
	}
	return v;
}

	template <typename Key, typename Val>
bool skiplist<Key, Val>::search(const Key& key, Val& ret)
{

	struct skiplist_item<Key, Val>* x = this->header;
	for (int i = this->level - 1; i >= 0; i--) {
		while (x->forwards[i] != NULL &&
				x->forwards[i]->key < key) {
			x = x->forwards[i];
		}
	}

	if (x->forwards[0] != NULL) {
		x = x->forwards[0];
		if (x->key == key) {
			ret = x->val;
			return true;
		}
	}
	return false;
}

	template <typename Key, typename Val>
bool skiplist<Key, Val>::insert(const Key& key, const Val& val)
{

	if (this->sz == SKIPLIST_MAX_ITEMS - 1)
		return false;

	struct skiplist_item<Key, Val>* updates[SKIPLIST_MAX_LEVEL];

	struct skiplist_item<Key, Val>* x = this->header;
	for (int i = this->level - 1; i >= 0; i--) {
		while (x->forwards[i] != NULL &&
				x->forwards[i]->key < key) {
			x = x->forwards[i];
		}
		updates[i] = x;
	}

	if (x->forwards[0] != NULL) {
		x = x->forwards[0];
		/* Key is exist */
		if (x->key == key)
			return false;
	}

	int lvl = random_level();
	if (lvl > this->level) {
		for (int i = this->level; i < lvl; i++)
			updates[i] = this->header;
		this->level = lvl;
	}

	struct skiplist_item<Key, Val>* y = new skiplist_item<Key, Val>;
	if (y == NULL) {
		fprintf(stderr, "skiplist: Failed to apply for memory space.\n");
		return false;
	} else {
		y->key = key, y->val = val;
	}

	for (int i = 0; i < this->level; i++) {
		x = updates[i];
		y->forwards[i] = x->forwards[i];
		x->forwards[i] = y;
	}
	this->sz++;
	return true;
}

	template <typename Key, typename Val>
bool skiplist<Key, Val>::update(const Key& key, const Val& val)
{

	if (this->sz == SKIPLIST_MAX_ITEMS - 1)
		return false;

	struct skiplist_item<Key, Val>* updates[SKIPLIST_MAX_LEVEL];

	struct skiplist_item<Key, Val>* x = this->header;
	for (int i = this->level - 1; i >= 0; i--) {
		while (x->forwards[i] != NULL &&
				x->forwards[i]->key < key) {
			x = x->forwards[i];
		}
		updates[i] = x;
	}

	if (x->forwards[0] != NULL) {
		x = x->forwards[0];
		/* Key is exist */
		if (x->key == key) {
			x->val = val;
			return true;
		}
	}

	return false;
}

	template <typename Key, typename Val>
bool skiplist<Key, Val>::upsert(const Key& key, const Val& val)
{

	if (this->sz == SKIPLIST_MAX_ITEMS - 1)
		return false;

	struct skiplist_item<Key, Val>* updates[SKIPLIST_MAX_LEVEL];

	struct skiplist_item<Key, Val>* x = this->header;
	for (int i = this->level - 1; i >= 0; i--) {
		while (x->forwards[i] != NULL &&
				x->forwards[i]->key < key) {
			x = x->forwards[i];
		}
		updates[i] = x;
	}

	if (x->forwards[0] != NULL) {
		x = x->forwards[0];
		/* Key is exist */
		if (x->key == key) {
			x->val = val;
			return true;
		}
	}

	int lvl = random_level();
	if (lvl > this->level) {
		for (int i = this->level; i < lvl; i++)
			updates[i] = this->header;
		this->level = lvl;
	}

	struct skiplist_item<Key, Val>* y = new skiplist_item<Key, Val>;
	if (y == NULL) {
		fprintf(stderr, "skiplist: Failed to apply for memory space.\n");
		return false;
	} else {
		y->key = key, y->val = val;
	}

	for (int i = 0; i < this->level; i++) {
		x = updates[i];
		y->forwards[i] = x->forwards[i];
		x->forwards[i] = y;
	}
	this->sz++;
	return true;
}

	template <typename Key, typename Val>
bool skiplist<Key, Val>::remove(const Key& key)
{
	struct skiplist_item<Key, Val>* updates[SKIPLIST_MAX_LEVEL];

	struct skiplist_item<Key, Val>* x = this->header;
	for (int i = this->level - 1; i >= 0; i--) {
		while (x->forwards[i] != NULL &&
				x->forwards[i]->key < key) {
			x = x->forwards[i];
		}
		updates[i] = x;
	}

	if (x->forwards[0] != NULL) {
		x = x->forwards[0];

		if (x->key == key) {
			for (int i = 0; i < this->level; i++) {
				if (updates[i]->forwards[i] != x)
					break;
				updates[i]->forwards[i] = x->forwards[i];
			}
			free(x);
			this->sz--;

			/* Update maximum level */
			while (this->level &&
					this->header->forwards[this->level-1] == NULL) {
				this->level--;
			}

			return true;
		}
	}
	return false;
}

	template <typename Key, typename Val>
skiplist<Key, Val>& skiplist<Key, Val>::operator= (const skiplist<Key, Val> &sk)
{
	if (&sk == this)
		return *this;

	destroy();
	copy(sk);
	return *this;
}

	template <typename Key, typename Val>
void skiplist<Key, Val>::destroy()
{
	this->sz = 0;
	this->level = 0;
	skiplist_item<Key, Val>* x = this->header->forwards[0];

	while (x != NULL) {
		x = x->forwards[0];
		delete this->header;
		this->header = x;
	}
}

	template <typename Key, typename Val>
void skiplist<Key, Val>::copy(const skiplist<Key, Val>& sk)
{
	skiplist_item<Key, Val>* x = sk.header->forwards[0];

	while (x != NULL) {
		insert(x->key, x->val);
		x = x->forwards[0];
	}
}

#endif
