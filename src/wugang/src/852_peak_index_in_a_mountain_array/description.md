**Websit:**  
https://leetcode.com/problems/peak-index-in-a-mountain-array/  

**Description:**    
Let's call an array A a mountain if the following properties hold:  
A.length >= 3  
There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]  
Given an array that is definitely a mountain, return any i such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].  

**Example 1:**  
**Input:** [0,1,0]  
**Output:** 1  

**Example 2:**  
**Input:** [0,2,1,0]  
**Output:** 1  

**Notes:**  
3 <= A.length <= 10000  
0 <= A[i] <= 10^6  
A is a mountain, as defined above.  

**Solution:**  
**Time:** 2019-4-16 13:58:00  
**Runtime:** 16 ms, faster than 97.57% of C++ online submissions for Peak Index in a Mountain Array.  
**Memory Usage:** 9.7 MB, less than 5.69% of C++ online submissions for Peak Index in a Mountain Array.   
