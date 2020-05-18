#include<gtest/gtest.h>

#include "linear-list/skiplist.hpp"

namespace unittest {

TEST(test_skiplist, search) {
	::algo::Skiplist<uint32_t, uint32_t> sk;

	uint32_t val = 0;
	ASSERT_EQ(sk.search(1, &val), false);
	ASSERT_EQ(val, 0);

	ASSERT_EQ(sk.insert(1, 1), true);
	ASSERT_EQ(sk.search(1, &val), true);
	ASSERT_EQ(val, 1);
}

TEST(test_skiplist, insert) {
	static const uint32_t MAX_SIZE = 10;
	::algo::Skiplist<uint32_t, uint32_t> sk(
			::algo::SKIPLIST_LEVEL_PROB,
			::algo::SKIPLIST_MAX_LEVEL, MAX_SIZE);

	ASSERT_EQ(sk.size(), 0);

	for (uint32_t i = 0; i < MAX_SIZE; ++i) {
		ASSERT_EQ(sk.insert(i, i), true);
		ASSERT_EQ(sk.size(), i + 1);
		ASSERT_EQ(sk.insert(i, 0), false);
	}

	ASSERT_EQ(sk.insert(MAX_SIZE + 1, 0), false);
	ASSERT_EQ(sk.size(), MAX_SIZE);
}

TEST(test_skiplist, update) {
	::algo::Skiplist<uint32_t, uint32_t> sk;

	uint32_t val = 0;
	ASSERT_EQ(sk.update(1, 1), false);
	ASSERT_EQ(sk.search(1, &val), false);
	ASSERT_EQ(val, 0);

	ASSERT_EQ(sk.insert(1, 2), true);
	ASSERT_EQ(sk.search(1, &val), true);
	ASSERT_EQ(val, 2);
	ASSERT_EQ(sk.update(1, 1), true);
	ASSERT_EQ(sk.search(1, &val), true);
	ASSERT_EQ(val, 1);
	ASSERT_EQ(sk.size(), 1);
}

TEST(test_skiplist, upsert) {
	::algo::Skiplist<uint32_t, uint32_t> sk;

	uint32_t val = 0;
	ASSERT_EQ(sk.upsert(1, 1), true);
	ASSERT_EQ(sk.search(1, &val), true);
	ASSERT_EQ(val, 1);
	ASSERT_EQ(sk.size(), 1);

	ASSERT_EQ(sk.upsert(1, 2), true);
	ASSERT_EQ(sk.search(1, &val), true);
	ASSERT_EQ(val, 2);
	ASSERT_EQ(sk.size(), 1);
}

TEST(test_skiplist, remove) {
	::algo::Skiplist<uint32_t, uint32_t> sk;

	uint32_t val = 0;
	ASSERT_EQ(sk.remove(1), false);

	ASSERT_EQ(sk.insert(1, 1), true);
	ASSERT_EQ(sk.search(1, &val), true);
	ASSERT_EQ(val, 1);
	ASSERT_EQ(sk.size(), 1);

	ASSERT_EQ(sk.remove(1), true);
	ASSERT_EQ(sk.search(1, &val), false);
	ASSERT_EQ(sk.size(), 0);
}

TEST(test_skiplist, assignment) {
	static const uint32_t MAX_SIZE = 10;
	::algo::Skiplist<uint32_t, uint32_t> sk(
			::algo::SKIPLIST_LEVEL_PROB,
			::algo::SKIPLIST_MAX_LEVEL, MAX_SIZE);

	for (uint32_t i = 0; i < MAX_SIZE; ++i) {
		ASSERT_EQ(sk.insert(i, i + 1), true);
		ASSERT_EQ(sk.size(), i + 1);
	}

	::algo::Skiplist<uint32_t, uint32_t> rhs;
	rhs = sk;
	for (uint32_t i = 0; i < MAX_SIZE; ++i) {
		uint32_t val = 0;
		ASSERT_EQ(sk.search(i, &val), true);
		ASSERT_EQ(val, i + 1);
	}
}

} // namespace unittest

int main (int argc,char *argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
