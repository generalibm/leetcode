## 540. Single Element in a Sorted Array[Medium]

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

**Example 1:**
```
Input: [1,1,2,3,3,4,4,8,8]
Output: 2
```

**Example 2:**
```
Input: [3,3,7,7,10,11,11]
Output: 10
```
**Note:** Your solution should run in O(log n) time and O(1) space.

## Solution Analysis

### 1. Brute force approach

It is intuitive to use a **map<int, int>** to record all the elements with their appearences in the array. And then traverse the whole array to get the single element whose appearence is equal to `1`;

```c++
int singleNonDuplicate(vector<int>& nums) {
    int res = 0;
    map<int, int> recd;
    for (const int & e : nums) recd[e]++;
    for (const int & e : nums) if (recd[e] == 1) {res = e; break;}
    
    return res;  
}
```

**Time Complexity:** O(N)
**Space Complexity:** O(N)
**Result:** Accept

### 2.Math approach

When we have two same integers, for instance `a` and `b`,we can get `0` by `0 = a ^ a`. So we can get `b = a ^ a ^ b`, and it is what the idea to solve the problem.
```c++
int singleNonDuplicate(vector<int>& nums) {
    int res = 0;
    for (const int & e : nums) res ^= e;
    
    return res;  
}
```

**Time Complexity:** O(N)
**Space Complexity:** O(1)
**Result:** Accept

### 3.Binary search approach

Since it is a sorted array, we can, and the description wants us to, derease the time complexity to **O(logN)** by *binary search*. 

Concerning there is only one single element in the array, it means that the others elements appear exactly twice. So the number of total elements in the array is `N = 2k+1`, which is an odd number. 

When we say the position of  `mid` element in the array, there are two situations. 

At first, Let `X` indicates `nums[mid]` and `O` indicates` nums[i]`where `i = 1, 2, ..., N; except for mid`.

***Situation 1:*** 

The total numbers in the left and the right part are odd, one of  which can be like this:

> O O O X O O O

So `X` can not be the single element we want beacause the array is sorted.  Actually, `X` can be equal to **the previous** or the **next element** of the mid position, which can be one of the following two:

>O O ***O X*** O O O    ------(1)

>O O O ***X O*** O O    ------(2)

If it is like (1), the single element would be in the right part of `X`.

And (2), the left part of `X`.

This way, we have decrease the scale of the problem like binary search.

***Situation 2:***

The total numbers in the left and the right part are even, one of which can be like this:

> O O X O O

So `X` can or can not be the single element we want. If it is is, just return;

when it is not,  if let `X` is equal to the later one, we can jump to **the one after its next**, which is similar but a little different to binary search. Here, we move 2 steps.

> O O ***X O*** O

> O O X O **O**
> ------------|             
>
> ----------- mid would here since we move 2 steps     
```c++
int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1) return nums.front();
        if (nums.size() % 2 == 0) return -1;
        
        int res = 0;
        
        int left = 0;
        int right = nums.size() -1;
        int mid = 0;
        while (left <= right)
        {
            mid = (left + right) >> 1;
                                                
            if ( (mid == 0 || mid == nums.size() - 1) || 
                 (nums[mid-1] != nums[mid] && nums[mid+1] != nums[mid]) )
            {
                res = nums[mid];
                break;
            }
            
            if (mid %2 == 0)
            {
                nums[mid-1] == nums[mid] ? right = mid - 2 : left = mid + 2;
            }
            else
            {
                nums[mid-1] == nums[mid] ? left = mid + 1 : right = mid - 1;
            }
        }
                
        return res;
    }
```

**Time Complexity:** O(logN)
**Space Complexity:** O(1)
**Result:** Accept