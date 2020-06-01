// Copyright (c) 2020 Ke Shuai.
// All rights reserved.
//
// @filename: trie.h
// @author: jerakrs
// @version: 1.0
// @description: the implementation of trie.

#ifndef ALGORITHM_DATA_STRUCTURE_TREE_TRIE_H
#define ALGORITHM_DATA_STRUCTURE_TREE_TRIE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

namespace algo {

const uint32_t TRIE_MAX_NODES = 1e3;
const uint32_t TRIE_ALPHABET_SIZE = 52;

template <typename Value>
class Trie
{
public:
	// Constructs a Trie.
	Trie() : _size(0), _node_size(0)
	{
		_root = new_node();
	}

	// Gets the number of items in the Trie.
	uint32_t size() const;

	// Gets the value of a given key.
	// @param: the passed-key for searching value.
	// @param: res, a pointer for storing value.
	// @return: true if the key exists.
	bool search(const char* key, Value* res) const;

	// Inserts a new item to Trie.
	// @param: key, the passed-key for storage.
	// @param: val, the passed-val for storage.
	// @return: true if the insertion is successful.
	bool insert(const char* key, const Value& val);

	// Removes a existing item.
	// @param: key, the passed-key for deletion.
	// @return: true if the remove is successful.
	bool remove(const char* key);

	// Empties the Trie.
	void clear();

private:
	struct TrieNode {
		bool _is_set;
		Value _val;
		int _next[TRIE_ALPHABET_SIZE];
	};

	// No copy constructor.
	Trie(const Trie& rhs);

	// No copy operation.
	Trie& operator=(const Trie& rhs);

	// Converts a character to an index.
	// @param: ch, the given char for conversion.
	// @return: the index of the given char, return -1 means unkown char.
	int alphabet(char ch) const;

	// Applies a new TrieNode.
	// @return: the index of the new TrieNode., return -1 means application failed.
	int new_node();

	uint32_t _root;
	uint32_t _size;

	uint32_t _node_size;
	TrieNode _nodes[TRIE_MAX_NODES];
};

template <typename Value>
uint32_t Trie<Value>::size() const
{
	return _size;
}

template <typename Value>
bool Trie<Value>::search(const char* key, Value* res) const
{
	int ch = 0;
	int p = _root;

	for (uint32_t i = 0; key[i]; ++i) {
		if ((ch = alphabet(key[i])) == -1) {
			return false;
		}

		int nxt = _nodes[p]._next[ch];
		if (!nxt) {
			return false;
		}
		p = nxt;
	}

	if (!_nodes[p]._is_set) {
		return false;
	}

	*res = _nodes[p]._val;
	return true;
}

template <typename Value>
bool Trie<Value>::insert(const char* key, const Value& value)
{
	int ch = 0;
	int p = _root;

	for (uint32_t i = 0; key[i]; ++i) {
		if ((ch = alphabet(key[i])) == -1) {
			return false;
		}

		int& nxt = _nodes[p]._next[ch];
		if (!nxt) {
			nxt = new_node();
			if (nxt == -1) {
				return false;
			}
		}

		p = nxt;
	}

	if (_nodes[p]._is_set) {
		fprintf(stderr, "Trie: duplicated insertion.\n");
		return false;
	}

	++_size;
	_nodes[p]._is_set = true;
	_nodes[p]._val = value;
	return true;
}

template <typename Value>
bool Trie<Value>::remove(const char* key)
{
	int ch = 0;
	int p = _root;

	for (uint32_t i = 0; key[i]; ++i) {
		if ((ch = alphabet(key[i])) == -1) {
			return false;
		}

		int nxt = _nodes[p]._next[ch];
		if (!nxt) {
			return false;
		}
		p = nxt;
	}

	if (_nodes[p]._is_set) {
		_nodes[p]._is_set = false;
		--_size;
	}
	return true;
}

template <typename Value>
void Trie<Value>::clear()
{
	_size = 0;
	_node_size = 0;
	_root = new_node();
}

template <typename Value>
Trie<Value>::Trie(const Trie& rhs)
{
	clear();
}

template <typename Value>
int Trie<Value>::alphabet(char ch) const
{
	if (ch >= 'a' && ch <= 'z') {
		return ch - 'a';
	} else if (ch >= 'A' && ch <= 'Z') {
		return ch - 'A' + 26;
	}
	fprintf(stderr, "Trie: unknown char[%c].\n", ch);
	return -1;
}

template <typename Value>
int Trie<Value>::new_node()
{
	if (_node_size >= TRIE_MAX_NODES) {
		fprintf(stderr, "Trie: failed to apply new TrieNode for Trie.\n");
		return -1;
	}

	_nodes[_node_size]._is_set = false;
	memset(_nodes[_node_size]._next, 0, sizeof(_nodes[_node_size]._next));
	return _node_size++;
}

} // namespace algo

#endif // ALGORITHM_DATA_STRUCTURE_TREE_TRIE_H
