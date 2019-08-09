#include "gtest/gtest.h"

#include <vector>

using namespace std;

namespace SolutionTest00684 {

class Solution {
public:
    vector<int> findRedundantConnection(const vector<vector<int>>& edges) {
        vector<int> res;
        DSU dsu(10001);

        for (auto e : edges)
        {
            /// in the same group, return the duplicated
            if (dsu.find(e.front()) == dsu.find(e.back()))
            {
                res.push_back(e.front());
                res.push_back(e.back());
                break;
            }

            /// not in the same group, union them
            dsu.merge(e.front(), e.back());
        }

        return res;
    }

    class DSU {
    public:
        DSU(int size) : m_parent(size) {
            for (int i = 0; i < size; i++)
                m_parent.at(i) = i;
        }

        int find(int x)
        {
            if (m_parent.at(x) != x)
            {
                m_parent.at(x) = find(m_parent.at(x));
            }
            return m_parent.at(x);
        }

        void merge(int x, int y)
        {
            m_parent.at(find(x)) = find(y);
        }

    private:
        vector<int> m_parent;
    };

};

class SolutionTest :  public ::testing::Test {
protected:
    Solution sol;
};

TEST_F(SolutionTest, Example1)
{
    EXPECT_EQ(2, sol.findRedundantConnection({{1, 2},{1, 3},{2, 3}}).front());
    EXPECT_EQ(3, sol.findRedundantConnection({{1, 2},{1, 3},{2, 3}}).back());
}

TEST_F(SolutionTest, Example2)
{
    EXPECT_EQ(1, sol.findRedundantConnection({{1, 2},{2, 3},{3, 4},{1, 4}, {1, 5}}).front());
    EXPECT_EQ(4, sol.findRedundantConnection({{1, 2},{2, 3},{3, 4},{1, 4}, {1, 5}}).back());
}

}






