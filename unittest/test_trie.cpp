#include <gtest/gtest.h>

#include "tree/trie.h"

namespace unittest {

TEST(test_trie, search) {
	::algo::Trie<uint32_t> trie;

	const char* key1 = "keyword";
	const char* key2 = "key";
	uint32_t value = 0;

	// passed-key don't exist.
	ASSERT_EQ(trie.search(key1, &value), false);
	// invalid passed-key.
	ASSERT_EQ(trie.search("_key", &value), false);

	// normal search.
	ASSERT_EQ(trie.insert(key1, 1), true);
	ASSERT_EQ(trie.insert(key2, 2), true);

	ASSERT_EQ(trie.search(key1, &value), true);
	ASSERT_EQ(value, 1);
	ASSERT_EQ(trie.search(key2, &value), true);
	ASSERT_EQ(value, 2);
	ASSERT_EQ(trie.size(), 2);
}

TEST(test_trie, insert) {
	::algo::Trie<uint32_t> trie;

	const char* key = "keyword";
	uint32_t value;

	// normal insertion.
	ASSERT_EQ(trie.insert(key, 1), true);
	ASSERT_EQ(trie.search(key, &value), true);
	ASSERT_EQ(value, 1);
	ASSERT_EQ(trie.size(), 1);

	// duplicated insertion.
	ASSERT_EQ(trie.insert(key, 1), false);
	ASSERT_EQ(trie.size(), 1);

	// invalid passed-key.
	ASSERT_EQ(trie.insert("_key", 1), false);
	ASSERT_EQ(trie.size(), 1);
}

TEST(test_trie, remove) {
	::algo::Trie<uint32_t> trie;

	const char* key = "keyword";
	uint32_t value;

	// passed-key don't exist.
	ASSERT_EQ(trie.remove(key), false);
	// invalid passed-key.
	ASSERT_EQ(trie.remove("_key"), false);

	// normal remove.
	ASSERT_EQ(trie.insert(key, 1), true);
	ASSERT_EQ(trie.search(key, &value), true);
	ASSERT_EQ(value, 1);
	ASSERT_EQ(trie.size(), 1);

	ASSERT_EQ(trie.remove(key), true);
	ASSERT_EQ(trie.size(), 0);

	ASSERT_EQ(trie.search(key, &value), false);
}

TEST(test_trie, clear) {
	::algo::Trie<uint32_t> trie;

	const char* key = "keyword";
	uint32_t value;

	ASSERT_EQ(trie.insert(key, 1), true);
	ASSERT_EQ(trie.search(key, &value), true);
	ASSERT_EQ(value, 1);
	ASSERT_EQ(trie.size(), 1);

	trie.clear();

	ASSERT_EQ(trie.search(key, &value), false);
}

TEST(tes_trie, initialization) {
	::algo::Trie<uint32_t> rhs;

	const char* key = "keyword";
	uint32_t value;

	ASSERT_EQ(rhs.insert(key, 2), true);
	ASSERT_EQ(rhs.search(key, &value), true);
	ASSERT_EQ(value, 2);

	::algo::Trie<uint32_t> lhs = rhs;

	ASSERT_EQ(lhs.search(key, &value), false);
	ASSERT_EQ(lhs.size(), 0);
	ASSERT_EQ(rhs.search(key, &value), true);
	ASSERT_EQ(value, 2);
}

TEST(tes_trie, assignment) {
	::algo::Trie<uint32_t> lhs;
	::algo::Trie<uint32_t> rhs;

	const char* key = "keyword";
	uint32_t value;

	ASSERT_EQ(lhs.insert(key, 1), true);
	ASSERT_EQ(lhs.search(key, &value), true);
	ASSERT_EQ(value, 1);

	ASSERT_EQ(rhs.insert(key, 2), true);
	ASSERT_EQ(rhs.search(key, &value), true);
	ASSERT_EQ(value, 2);

	lhs = rhs;
	ASSERT_EQ(lhs.search(key, &value), true);
	ASSERT_EQ(value, 1);
	ASSERT_EQ(rhs.search(key, &value), true);
	ASSERT_EQ(value, 2);
}

TEST(test_trie, alphabet) {
	::algo::Trie<uint32_t> trie;

	// normal passed-char.
	ASSERT_EQ(trie.alphabet('a'), 0);
	ASSERT_EQ(trie.alphabet('z'), 25);
	ASSERT_EQ(trie.alphabet('A'), 26);
	ASSERT_EQ(trie.alphabet('Z'), 51);

	// invalid passed-char.
	ASSERT_EQ(trie.alphabet('a' - 1), -1);
	ASSERT_EQ(trie.alphabet('Z' + 1), -1);
	ASSERT_EQ(trie.alphabet(0), -1);
}

} // namespace unittest

int main (int argc,char *argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
