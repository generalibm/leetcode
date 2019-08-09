## 684. Redundant Connection[Medium]

 In this problem, a tree is an **undirected** graph that is connected and has no cycles. 

 The given input is a graph that started as a tree with N nodes (with  distinct values 1, 2, ..., N), with one additional edge added.  The  added edge has two different vertices chosen from 1 to N, and was not an  edge that already existed. 

 The resulting graph is given as a 2D-array of `edges`.  Each element of `edges` is a pair `[u, v]` with `u < v`, that represents an **undirected** edge connecting nodes `u` and `v`. 

 Return an edge that can be removed so that the resulting graph is a tree  of N nodes.  If there are multiple answers, return the answer that  occurs last in the given 2D-array.  The answer edge `[u, v]` should be in the same format, with `u < v`. 

**Example 1:**


```
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given undirected graph will be like this:
  1
 / \
2 - 3
```

**Example 2:**


```
Input: [[1,2], [2,3], [3,4], [1,4], [1,5]]
Output: [1,4]
Explanation: The given undirected graph will be like this:
5 - 1 - 2
    |   |
    4 - 3
```

**Note:**


The size of the input 2D-array will be between 3 and 1000.

Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.

 **Update (2017-09-26):**
 We have overhauled the problem description + test cases and specified clearly the graph is an **undirected** graph. For the **directed** graph follow up please see **Redundant Connection II**). We apologize for any inconvenience caused. 



### Solution Analysis

**Approach 1**: Union find

>   Union find, also called Disjoint Set Union, is applied in Kruskal Algorithm to solve Minimum Spanning Tree problem. In which it supports effective loop detection by specifying one as leader to represent whole group. 
>
>   Here, the existed edges that has no cycles can be a group, and the additional is alone, which actually is what we want to know.

-   Time: O(N)

-   Space: O(N)

-   Result: AC
-   Code Sample:

```c++
class Dsu {
public:
    virtual ~Dsu() {}
    
    DSU(int size)
    {
        for (int i = 0; i < size; i ++)
            m_parent.at(i) = i;
    }
    int find(int x)
    {
        while (x != m_parent.at(x))
            x = m_parent.at(x);
        return x;
    }
    void merge(int x, int y)
    {
        m_parent.at(find(x)) = find(y);
    }
private:
    vector<int> m_parent;
};

/// path compress to boost find method
class pathCompressDsu : public Dsu {
public:
    int find(int x) override
    {
        if (m_parent.at(x) != x)
        {
            m_parent.at(x) = find(m_parent.at(x));
        }
        return m_parent.at(x);
    }    
};

/// Union by rank to decrease find length
class CallByRankDsu : public Dsu {
public:
    CallByRankDsu(int size) : m_parent(size), m_rank(size) {}
    void merge(int x, int y) override
    {
        int px = find(x);
        int py = find(y);
        
        if (px == py)
            return;
        if (m_rank.at(px) < m_rank.at(py))
        {
            m_parent.at(px) = py;
            m_rank.at(py) ++;
        }
        else
        {
            m_prent.at(py) = px;
            m_rank.at(px) ++;
        }
    }
private:
    vector<int> m_rank;
};
```

