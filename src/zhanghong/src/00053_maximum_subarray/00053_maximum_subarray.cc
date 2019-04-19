#include "00053_maximum_subarray.h"

// brute-force Approach
// Time:  O(n^2)
// Space: O(1)
//int Solution::maxSubArray(const vector<int>& nums)
//{
//    if (nums.empty())
//        return 0;
//    if (nums.size() == 1)
//        return nums.front();
//
//    int max = nums.front();
//    int sum;
//    for (size_t i = 0; i < nums.size(); i++)
//    {
//        sum = 0;
//        for (size_t j = i; j < nums.size(); j++)
//        {
//            sum += nums[j];
//            if (max < sum)
//                max = sum;
//        }
//    }
//
//    return max;
//}

// dived-conquer Approach
// Time:  O(n*log(n))
// Space: O(1) + recursive stack consume
//int Solution::maxSubArray(const vector<int>& nums)
//{
//    if (nums.empty())
//        return 0;
//    if (nums.size() == 1)
//        return nums.front();
//
//    size_t low = 0;
//    size_t high = nums.size() - 1;
//    size_t mid = (low + high) / 2;
//
//    int sum_left = 0, max_left = nums[mid];
//    for (int i = mid; i >= 0; i--)
//    {
//        sum_left += nums[i];
//        if (max_left < sum_left)
//            max_left = sum_left;
//    }
//
//    int sum_right = 0, max_right = nums[mid];
//    for (size_t j = mid; j <= high; j++)
//    {
//        sum_right += nums[j];
//        if (max_right < sum_right)
//            max_right = sum_right;
//    }
//
//    int sum = max_left + max_right - nums[mid];
//
//    vector<int> left(mid - low + 1);
//    for (size_t i = 0; i <= mid; i++)
//    {
//        left[i] = nums[i];
//    }
//
//    vector<int> right(high - mid);
//    for (size_t i = 0, j = mid + 1; j <= high; i++, j++)
//    {
//        right[i] = nums[j];
//    }
//
//    std::initializer_list<int> res = { maxSubArray(left), maxSubArray(right),
//            sum };
//
//    return std::max(res);
//}

// Dynamic programming Approach
// Time:  O(n)
// Space: O(n)
int Solution::maxSubArray(const vector<int>& nums)
{
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums.front();

    vector<int> dp(nums.size());
    int res = dp[0] = nums[0];

    for (size_t i = 1; i < nums.size(); i++)
    {
        dp[i] = nums[i] + (dp[i-1] > 0 ? dp[i-1] : 0);

        res = std::max(dp[i], res);
    }

    return res;
}

// Prefix array Approach
// Time:  O(n)
// Space: O(1)
//int Solution::maxSubArray(const vector<int>& nums)
//{
//    if (nums.empty()) return 0;
//    if (nums.size() == 1) return nums.front();
//
//    int prefix  = nums.front();
//    int res     = prefix;
//
//    for (size_t i = 1; i < nums.size(); i++)
//    {
//        prefix  = std::max(prefix + nums[i], nums[i]);
//        res     = std::max(res, prefix);
//    }
//
//    return res;
//}

