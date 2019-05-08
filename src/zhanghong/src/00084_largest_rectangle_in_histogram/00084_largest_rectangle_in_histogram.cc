#include "00084_largest_rectangle_in_histogram.h"

#include <iostream>
#include <algorithm>
#include <stack>


int rangeMax(const int * data, int left, int right)
{
    if (right < left) return 0;

    int min = data[left];
    for (int i = left; i <= right; i++)
    {
        min = std::min(min, data[i]);
    }

    return min * (right-left +1);
}


/// Brute force Approach
/// Time    : O(n^2)
/// Space   : O(1)
/// Result  : TLE
//int Solution84::Solution::largestRectangleArea(const vector<int>& heights)
//{
//    if (heights.empty()) return 0;
//
//    int res = 0;
//
//    for (size_t i = 0; i < heights.size(); i++)
//    {
//        for (size_t j = i; j < heights.size(); j++)
//        {
//            res = std::max(res, rangeMax(heights.data(), i, j));
////            if (res < rangeMax(heights.data(), i, j))
////            {
////                res = std::max(res, rangeMax(heights.data(), i, j));
////                std::cout << "i = " << i << ", j = "<< j << std::endl;
////            }
//
//        }
//    }
//
//    return res;
//}

int largestRectangleArea(const int * data, int left, int right)
{
    if (right < left)
        return 0;

    if (left == right)
        return data[left];

    int mid = (left + right) >> 1;
    int min = data[mid];
    int res = data[mid];

    int global_min = min;
    int i = mid + 1;
    int ii = mid;
    long area = 0;
    for (; i <= right; i++)
    {
        min = std::min(min, data[i]);
        area = static_cast<long>(min) * (i - mid + 1);
        if (res < area)
        {
            res = area;
            ii = i;
            global_min = min;
        }
    }

    int j = mid - 1;
    min = global_min;
    for (; j >= left; j--)
    {
        min = std::min(min, data[j]);
        area = static_cast<long>(min) * (ii - j + 1);
        if (res < area)
        {
            res = area;
        }
    }

    return std::max(res,
            std::max(largestRectangleArea(data, left, mid),
                    largestRectangleArea(data, mid + 1, right)));
}

/// Divide and conquer Approach
/// Time    : O(n*log(n))
/// Space   : O(1)
/// Result  : AC
int Solution84::Solution::largestRectangleArea(const vector<int>& heights)
{
    if (heights.empty()) return 0;

    int res = ::largestRectangleArea(heights.data(), 0, heights.size()-1);

    vector<int> rever_heights(heights);
    std::reverse(rever_heights.begin(), rever_heights.end());
    int reverse_res = ::largestRectangleArea(rever_heights.data(), 0, rever_heights.size()-1);

    return std::max(res, reverse_res);
}

