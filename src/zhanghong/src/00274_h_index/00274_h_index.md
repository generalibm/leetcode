## 274. H-Index [Medium]

Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

> According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

**Example:**

**Input:** citations = [3,0,6,1,5]
**Output:** 3 

> Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had 
>              received 3, 0, 6, 1, 5 citations respectively. 
>              Since the researcher has 3 papers with at least 3 citations each and the remaining 
>              two with no more than 3 citations each, her h-index is 3.
> Note: If there are several possible values for h, the maximum one is taken as the h-index.

### Approach 1

The problem can be transfered to 

> find the max count in a array in which the sum of the last elements if greater than its index.

so, a intuitive approach is to sort the array, and then count the number from iteratoring.

**cpp code sample:**

```cpp
int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end());
    int h = 0;
    for (int i = citations.size() - 1; i >= 0; i--)
    {
        if (citations[i] <= h) break;
        h++;
    }
    
    return h;
}
```
**Result:** AC
**Time complexity:** O(nlogn)
**Space complexity:** O(1)

### Approach 1 -- from bucket sort
When we say counting the total number from a array, it usually can be viewed as recording the appearence of the elements with an extra recording array, which is a little bit like the way that bucket sort does.

**Cpp code sample**
```cpp
int hIndex(vector<int>& citations) {
    int len = citations.size();
    vector<int> recds(len + 1, 0);
    
    for (const int cit : citations)
    {
        if (cit > len) recds[len]++;
        else recds[cit]++;
    }
    
    int total = 0;
    int h = 0;
    for (int i = len; i >= 0; i--)
    {
        total += recds[i];
        if (total >= i) {h = i; break;}
        
    }
    
    return h;
}
```

**Result:** AC (0ms)
**Time complexity:** O(n)
**Space complexity:** O(n)

