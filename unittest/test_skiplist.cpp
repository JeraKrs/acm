#include<gtest/gtest.h>

#include "skiplist.hpp"

namespace unittest {

TEST(test_skiplist, normal) {
	::algo::Skiplist<int,int> g;
}

} // namespace unittest

int main (int argc,char *argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
