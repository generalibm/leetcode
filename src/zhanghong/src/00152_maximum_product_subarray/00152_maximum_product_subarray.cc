#include "00152_maximum_product_subarray.h"

#include <iostream>

// Divide Conquer
//- Time: O(n^2)
//- Space: O(n)
//int Solution::maxProduct(const vector<int>& nums)
//{
//    if (nums.empty())
//        return 0;
//    if (nums.size() == 1)
//        return nums.front();
//
//    int low = 0;
//    int high = nums.size() - 1;
//    int mid = (low + high) / 2;
//
//    int max = nums[mid];
//    if (max != 0)
//    {
//        int product;
//        for (int i = mid; i <= high; i++)
//        {
//            product = 1;
//            for (int j = i; j >= low; j--)
//            {
//                product *= nums[j];
//                if (max < product)
//                    max = product;
//            }
//        }
//    }
//
//    vector<int> left(mid - low);
//    for (int i = 0; i <= mid -1; i++)
//    {
//        left[i] = nums[i];
//    }
//    vector<int> right(high - mid);
//    for (int i = 0, j = mid + 1; j <= high; i++, j++)
//    {
//        right[i] = nums[j];
//    }
//
//    return std::max(std::max(maxProduct(left), maxProduct(right)), max);
//}


int Solution::maxProduct(const vector<int>& nums)
{
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums.front();

    int max = nums.front();
    int min = nums.front();
    int prefix = max;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] < 0)
            swap(max, min);

        max = std::max(nums[i], max*nums[i]);
        min = std::min(nums[i], min*nums[i]);

        prefix = std::max(prefix, max);
    }

    return prefix;
}
