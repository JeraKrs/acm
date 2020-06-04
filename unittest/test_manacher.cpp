#include <gtest/gtest.h>

#include "string/basic_string.h"

#include <stdio.h>
#include <vector>
#include <string>

namespace unittest {

TEST(test_manacher, manacher) {

	ASSERT_EQ(-1, algo::manacher(nullptr));
	ASSERT_EQ(0, algo::manacher(""));
	ASSERT_EQ(1, algo::manacher("abcdef"));
	ASSERT_EQ(8, algo::manacher("abaddaba"));
}

} // unittest

int main (int argc,char *argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
