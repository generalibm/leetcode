#include "gtest/gtest.h"

#include "00008_string_to_integer.h"

namespace SolutionTest_00008 {


class SolutionTest00008 : public ::testing::Test {
protected:
	Solution sol;
};

TEST_F(SolutionTest00008, TrimWhitespace)
{
    EXPECT_EQ(648, sol.myAtoi("     648"));
    EXPECT_EQ(648, sol.myAtoi("   +648"));
    EXPECT_EQ(-648, sol.myAtoi("   -648"));
}

TEST_F(SolutionTest00008, StartWithNumber)
{
	EXPECT_EQ(648, sol.myAtoi("648"));
}

TEST_F(SolutionTest00008, StartWithNagtiveMark)
{
	EXPECT_EQ(-64, sol.myAtoi("-64"));
}

TEST_F(SolutionTest00008, StartWithPositiveMark)
{
    EXPECT_EQ(64, sol.myAtoi("+64"));
}

TEST_F(SolutionTest00008, LowerBoundry)
{
	EXPECT_EQ(-2147483648, sol.myAtoi("-91283472332"));
}

TEST_F(SolutionTest00008, HigherBoundry)
{
	EXPECT_EQ(2147483647, sol.myAtoi("91283472332"));
}

TEST_F(SolutionTest00008, StartWithNondigist)
{
	EXPECT_EQ(0, sol.myAtoi("words and 987"));
}

TEST_F(SolutionTest00008, EndWithNondigist)
{
	EXPECT_EQ(4193, sol.myAtoi("4193 with words"));
}

TEST_F(SolutionTest00008, FirstNumber)
{
	EXPECT_EQ(4193, sol.myAtoi("4193 with words 946"));
}

TEST_F(SolutionTest00008, ContinusMark)
{
    EXPECT_EQ(0, sol.myAtoi("+-45"));
    EXPECT_EQ(0, sol.myAtoi("-+45"));
}

};
