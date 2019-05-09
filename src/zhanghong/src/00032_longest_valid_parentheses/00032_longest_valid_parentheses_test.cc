#include "00032_longest_valid_parentheses.h"

#include "gtest/gtest.h"

using namespace Solution32;

class SolutionTest32 : public ::testing::Test {
protected:
    Solution sol;
};

TEST_F(SolutionTest32, Example1)
{
   EXPECT_EQ(2, sol.longestValidParentheses("(()"));
}

TEST_F(SolutionTest32, Example2)
{
   EXPECT_EQ(4, sol.longestValidParentheses(")()())"));
}

TEST_F(SolutionTest32, WrongAnswer1)
{
   EXPECT_EQ(2, sol.longestValidParentheses("()(()"));
}

TEST_F(SolutionTest32, WrongAnswer2)
{
   EXPECT_EQ(6, sol.longestValidParentheses("()(())"));
}

TEST_F(SolutionTest32, WrongAnswer3)
{
   EXPECT_EQ(4, sol.longestValidParentheses("(()()"));
}

TEST_F(SolutionTest32, BoundTest)
{
    EXPECT_EQ(310,
            sol.longestValidParentheses(
                    "())()()(())((()(()()(((()))((((())((()(())()())(()((((()))()(()))(())()(())(()(((((())((((((()())())(()(()((())()))(()))))))()(()))((((())()()()))()()()(((()(()())(()()(()(()()(((()))))))()()))())())((()()))))))((()))(((()((())()(()()))((())))()()())))))))()))))(()))))()))()))()((())))((()))(()))))))(((()))))))))()(()()()(())((())()))()()(())))()()))(()())()))(((()())()))((())((((()))(()(()(()()()(((())()(((((()))((()(((((())(()()))((((((((()(()(()(()(())))(())(()())())(()((((()(())((()(())))(())))()(((((()(()()(())))))))())(())(())(()()(((())))((()))(((((()))))())))()((()))()))))())))))((())(((((()()))((((())))(((()(()(())())(((()(()(()()()())))())()))((()((())())()()()(((())(((((()((((((()((()())))((((())((()(((((((()(()((()()()(()(()())(()(()()((((())))()(((()())))(()()))()(()()()()(((((())(()))))((()))())))()((((((()))())))()(()))(())))((((()())(((((()()())(((((())(()())(()))))()(()()))()))))))())))(((())(()(()()))(()))()(((())))())((((()(((()))))))()(()(()))()()(()()))))))))((()))))))(())((()((()))()))((((((()())))))(()((())((((()))))(()(()()()()(()))()()(()(()))(()()(((((((()())(())(()())((())())()(()())((())()())())(()())))())))(())())())(())((()())(((()()))()))()()))()(()(())((((((((())))()((())((()((((((((((()))))(()(((((())(()(()())())))((())())))))()))(()((()()))((()((())()()()((()(())())((())())(()()(((())))))())()()(()))()())(()(()((())))((((()()(())))())(())(()(()(())())())(()()())()(())())))(()()(((())))((()()(((())()()(()())((((()()(()())(()((((()(()()(()(()(((()((()())(()()))(()((((()(((((()))))()()))(((()((((((()(()()()()())()))(()(())))))((()(((()())())))(((()()))(()(()(((((((()()))(()(())))())()(())())(())(()))(())(()))()()(()()())))))()))()((())(((()((((((((())()()))())))((()())("));
}