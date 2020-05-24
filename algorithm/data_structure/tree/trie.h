// Copyright (c) 2020 Ke Shuai.
// All rights reserved.
//
// @filename: trie.h
// @author: jerakrs
// @version: 1.0
// @description: the declaration of trie.

#ifndef ALGORITHM_DATA_STRUCTURE_TREE_TRIE_H
#define ALGORITHM_DATA_STRUCTURE_TREE_TRIE_H

#include <stdlib.h>

namespace algo {

const uint32_t TRIE_MAX_NODES = 1e6;
const uint32_t TRIE_ALPHABET_SIZE = 52;

class Trie {
public:
	// Constructs a Trie.
	Trie() : _size(0), _node_size(0) {
		_root = new_node();
	}

	// Gets the number of items in the Trie.
	uint32_t size() const;

	// Gets the value of a given key.
	// @param: key, the given key for searching value.
	// @return: a pointer of the value if the item exist, else return nullptr.
	void* search(const char* key) const;

	// Inserts a new item to Trie.
	// @param: key, the key of the inserted item.
	// @param: val, the value of the inserted item.
	// @return: true if the insertion is successful.
	bool insert(const char* key, void* value);

	// Removes a existing item.
	// @param: key, the key of the existing item.
	// @return: true if the remove is successful.
	bool remove(const char* key);

	// Empties the Trie.
	void clear();

private:
	struct TrieNode {
		void* _val;
		int _next[TRIE_ALPHABET_SIZE];
	};

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

} // namespace algo

#endif // ALGORITHM_DATA_STRUCTURE_TREE_TRIE_H
