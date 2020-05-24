#include "trie.h"

#include <stdio.h>
#include <string.h>

namespace algo {

uint32_t Trie::size() const {
	return _size;
}

void* Trie::search(const char* key) const {
	int ch = 0;
	int p = _root;

	for (uint32_t i = 0; key[i]; ++i) {
		if ((ch = alphabet(key[i])) == -1) {
			return nullptr;
		}

		int nxt = _nodes[p]._next[ch];
		if (!nxt) {
			return nullptr;
		}
		p = nxt;
	}

	return _nodes[p]._val;
}

bool Trie::insert(const char* key, void* value) {

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

	if (_nodes[p]._val) {
		fprintf(stderr, "Trie: duplicated insertion.\n");
		return false;
	}

	++_size;
	_nodes[p]._val = value;
	return true;
}

bool Trie::remove(const char* key) {
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

	_nodes[p]._val = nullptr;
	return true;
}

void Trie::clear() {
	_size = 0;
	_node_size = 0;
	_root = new_node();
}

int Trie::alphabet(char ch) const {
	if (ch >= 'a' && ch <= 'z') {
		return ch - 'a';
	} else if (ch >= 'A' && ch <= 'Z') {
		return ch - 'A' + 26;
	}
	fprintf(stderr, "Trie: unknown char[%c].\n", ch);
	return -1;
}

int Trie::new_node() {
	if (_node_size >= TRIE_MAX_NODES) {
		fprintf(stderr, "Trie: failed to apply new TrieNode for Trie.\n");
		return -1;
	}

	_nodes[_node_size]._val = nullptr;
	memset(_nodes[_node_size]._next, 0, sizeof(_nodes[_node_size]._next));
	return _node_size++;
}

} // namespace algo
