#include "gtest/gtest.h"

#include <vector>

using namespace std;

namespace SolutionTest00685 {

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>&& edges) {
        int n = edges.size();
        vector<int> parent(n+1, 0), candA, candB;
        // step 1, check whether there is a node with two parents
        for (auto &edge:edges) {
            if (parent[edge[1]] == 0)
                parent[edge[1]] = edge[0];
            else {
                candA = {parent[edge[1]], edge[1]};
                candB = edge;
                edge[1] = 0;
            }
        }
        // step 2, union find
        for (int i = 1; i <= n; i++) parent[i] = i;
        for (auto &edge:edges) {
            if (edge[1] == 0) continue;
            int u = edge[0], v = edge[1], pu = root(parent, u);
            // Now every node only has 1 parent, so root of v is implicitly v
            if (pu == v) {
                if (candA.empty()) return edge;
                return candA;
            }
            parent[v] = pu;
        }
        return candB;
    }
private:
    int root(vector<int>& parent, int k) {
        if (parent[k] != k)
            parent[k] = root(parent, parent[k]);
        return parent[k];
    }
};

class SolutionTest : public ::testing::Test {
protected:
    Solution sol;
};

TEST_F(SolutionTest, Example1)
{
    EXPECT_EQ(2, sol.findRedundantDirectedConnection({{1, 2},{1, 3},{2, 3}}).front());
    EXPECT_EQ(3, sol.findRedundantDirectedConnection({{1, 2},{1, 3},{2, 3}}).back());
}

TEST_F(SolutionTest, Example2)
{
    EXPECT_EQ(1, sol.findRedundantDirectedConnection({{1, 2},{2, 3},{3, 4},{1, 4}, {1, 5}}).front());
    EXPECT_EQ(4, sol.findRedundantDirectedConnection({{1, 2},{2, 3},{3, 4},{1, 4}, {1, 5}}).back());
}

TEST_F(SolutionTest, WrongAnswer1)
{
    EXPECT_EQ(2, sol.findRedundantDirectedConnection({{2,1}, {3,1}, {4,2}, {1,4}}).front());
    EXPECT_EQ(1, sol.findRedundantDirectedConnection({{2,1}, {3,1}, {4,2}, {1,4}}).back());

}

}




