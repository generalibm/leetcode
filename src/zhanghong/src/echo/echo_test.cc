#include <gtest/gtest.h>

#include <string>

#include "echo.h"

TEST(echo_test, test_integer)
{
	Solution solution;
    EXPECT_EQ(100, solution.echo(100));
}

TEST(echo_test, test_string)
{
	Solution solution;
	EXPECT_EQ(std::string("hello world"), solution.echo(std::string("hello world")));
}
