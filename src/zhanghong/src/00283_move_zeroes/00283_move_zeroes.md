## 283. Move Zeroes[Easy]

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

**Example:**
**Input:** `[0,1,0,3,12]`
**Output:** `[1,3,12,0,0]`

***Note:***
You must do this in-place without making a copy of the array.
Minimize the total number of operations.

## Solution Analysis

### 1. Brute force - Bubble sort approach

```c++
void moveZeroes(vector<int>& nums) 
{
    for (int i = nums.size()-1; i >=0; i--)
    {
        if (nums[i] != 0) continue;
    
        for (int j = i + 1; j < nums.size(); j++)
        {                
            swap(nums[j-1], nums[j]);                
        }
    }
}
```
**Time Complexity:** O(N^2)
**Space Complexity:** O(1)
**Result:** Accept

### 2. Intuive approach by couting

```c++
void moveZeroes(vector<int>& nums) 
{
    vector<int> res;
    int j = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (0 != nums[i])
        {
            res.push_back(nums[i]);
            j++;
        }
    } 
    for (; j < nums.size(); j++) res.push_back(0);

    nums.swap(res);
}
```

**Time Complexity:** O(N)
**Space Complexity:** O(N)
**Result:** Accept

### 3. optimizing without extra space by two pointers

```c++
void moveZeroes(vector<int>& nums) 
{
    for (int i = 0, j = 0; i < nums.size(); i++)
    {
        if (0 != nums[i]) swap(nums[j++], nums[i]);
    }
}
```
