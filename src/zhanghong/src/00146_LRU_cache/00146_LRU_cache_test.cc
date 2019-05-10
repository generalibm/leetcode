#include "00146_LRU_cache.h"

#include "gtest/gtest.h"

class LRUCacheTest : public ::testing::Test {
protected:

};
#if 1
TEST_F(LRUCacheTest, Example1)
{
    LRUCache sol(2);
    sol.put(1, 1);
    sol.put(2, 2);
    EXPECT_EQ(1, sol.get(1));

    sol.put(3, 3);
    EXPECT_EQ(-1,sol.get(2));

    sol.put(4, 4);

    EXPECT_EQ(-1,sol.get(1));
    EXPECT_EQ(3,sol.get(3));
    EXPECT_EQ(4,sol.get(4));
}

TEST_F(LRUCacheTest, Example2)
{
    LRUCache sol(1);
    EXPECT_EQ(-1, sol.get(0));
}

TEST_F(LRUCacheTest, Example3)
{
    LRUCache sol(2);
    sol.put(2, 1);
    sol.put(2, 2);
    EXPECT_EQ(2, sol.get(2));

    sol.put(1, 1);
    sol.put(4, 1);
    EXPECT_EQ(-1,sol.get(2));
}

TEST_F(LRUCacheTest, WrongAnswer1)
{
    LRUCache sol(2);
    EXPECT_EQ(-1, sol.get(2));

    sol.put(2, 6);
    EXPECT_EQ(-1, sol.get(1));

    sol.put(1, 5);
    sol.put(1, 2);
    EXPECT_EQ(2, sol.get(1));

    EXPECT_EQ(6,sol.get(2));
}

TEST_F(LRUCacheTest, WrongAnswer2)
{
    LRUCache sol(2);

    sol.put(2, 1);
    sol.put(3, 2);

    EXPECT_EQ(2, sol.get(3));

    EXPECT_EQ(1, sol.get(2));

    sol.put(4, 3);

    EXPECT_EQ(1, sol.get(2));
    EXPECT_EQ(-1, sol.get(3));
    EXPECT_EQ(3, sol.get(4));

}

TEST_F(LRUCacheTest, WrongAnswer3)
{
    LRUCache sol(1);

    sol.put(2, 1);
    EXPECT_EQ(1, sol.get(2));

    sol.put(3, 2);

    EXPECT_EQ(-1, sol.get(2));
    EXPECT_EQ(2, sol.get(3));
}
#endif
TEST_F(LRUCacheTest, WrongAnswer4)
{
    LRUCache sol(3);

    sol.put(1, 1);
    sol.put(2, 2);
    sol.put(3, 3);
    sol.put(4, 4);
    EXPECT_EQ(4, sol.get(4));
    EXPECT_EQ(3, sol.get(3));
    EXPECT_EQ(2, sol.get(2));
    EXPECT_EQ(-1, sol.get(1));

    sol.put(5, 5);
    EXPECT_EQ(-1, sol.get(1));
    EXPECT_EQ(2, sol.get(2));
    EXPECT_EQ(3, sol.get(3));
    EXPECT_EQ(-1, sol.get(4));
    EXPECT_EQ(5, sol.get(5));
}






