#include "gtest/gtest.h"

#include "00008_string_to_integer.h"

class SolutionTest : public ::testing::Test {
protected:
	Solution sol;
};

TEST_F(SolutionTest, TrimWhitespace)
{
    EXPECT_EQ(648, sol.myAtoi("     648"));
    EXPECT_EQ(648, sol.myAtoi("   +648"));
    EXPECT_EQ(-648, sol.myAtoi("   -648"));
}

TEST_F(SolutionTest, StartWithNumber)
{
	EXPECT_EQ(648, sol.myAtoi("648"));
}

TEST_F(SolutionTest, StartWithNagtiveMark)
{
	EXPECT_EQ(-64, sol.myAtoi("-64"));
}

TEST_F(SolutionTest, StartWithPositiveMark)
{
    EXPECT_EQ(64, sol.myAtoi("+64"));
}

TEST_F(SolutionTest, LowerBoundry)
{
	EXPECT_EQ(-2147483648, sol.myAtoi("-91283472332"));
}

TEST_F(SolutionTest, HigherBoundry)
{
	EXPECT_EQ(2147483647, sol.myAtoi("91283472332"));
}

TEST_F(SolutionTest, StartWithNondigist)
{
	EXPECT_EQ(0, sol.myAtoi("words and 987"));
}

TEST_F(SolutionTest, EndWithNondigist)
{
	EXPECT_EQ(4193, sol.myAtoi("4193 with words"));
}

TEST_F(SolutionTest, FirstNumber)
{
	EXPECT_EQ(4193, sol.myAtoi("4193 with words 946"));
}

TEST_F(SolutionTest, ContinusMark)
{
    EXPECT_EQ(0, sol.myAtoi("+-45"));
    EXPECT_EQ(0, sol.myAtoi("-+45"));
}
