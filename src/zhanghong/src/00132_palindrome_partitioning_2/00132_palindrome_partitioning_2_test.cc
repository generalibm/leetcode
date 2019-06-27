#include "gtest/gtest.h"

#include "string"
using namespace std;

namespace SolutionTest00132 {

class Solution {
public:
    int minCut(string s) {
        const int N = s.size();
        if (N <= 1)
            return 0;

        bool isPalin[N][N];
        fill_n(&isPalin[0][0], N * N, false);

        int minCuts[N + 1];
        for (int i = 0; i <= N; ++i)
            minCuts[i] = i - 1;

        for (int j = 1; j < N; ++j)
        {
            for (int i = j; i >= 0; --i)
            {
                if ((s[i] == s[j]) && ((j - i < 2) || isPalin[i + 1][j - 1]))
                {
                    isPalin[i][j] = true;
                    minCuts[j + 1] = min(minCuts[j + 1], 1 + minCuts[i]);
                }
            }
        }
        return minCuts[N];
    }
};

class SolutionTest00132 : public ::testing::Test {
protected:
    Solution sol;
};

TEST_F(SolutionTest00132, Example1)
{
    EXPECT_EQ(1, sol.minCut("aab"));
}

TEST_F(SolutionTest00132, EmptyString)
{
    EXPECT_EQ(0, sol.minCut(""));
}

TEST_F(SolutionTest00132, SimgleChar)
{
    EXPECT_EQ(0, sol.minCut("a"));
}

}// namespace SolutionTest00132




