#include "gtest/gtest.h"

#include "00004_median_of_two_sorted_arrays.h"

double Solution::findMedianSortedArrays(const vector<int> & nums1, const vector<int> & nums2)
{
    // assert nums1 and nums2 are not empty
    int m = nums1.size();
    int n = nums2.size();
    bool isEven = ((m+n)%2 == 0);
    if(m > n)
        return findMedian(nums1,nums2,isEven);
    else
        return findMedian(nums2,nums1,isEven);
}

double Solution::findMedian(const vector<int>& longArray,
        const vector<int> & shortArray, bool isEven)
{
    // shortArray is A, A's length is m
    // longArray is B , B's length is n
    int m = shortArray.size();
    int n = longArray.size();
    int imin = 0;
    int imax = m;
    double left_max;
    double right_min;
    while (imin <= imax)
    {
        int i = (imin + imax) / 2;
        int j = (m + n) / 2 - i;
        // if i<m and m < n, then we can calculate j>0
        // if i>0 and m < n, then we can calculate j<n
        if (i < m && longArray[j - 1] > shortArray[i])
            imin = i + 1;
        else if (i > 0 && shortArray[i - 1] > longArray[j])
            imax = i - 1;
        else
        {
            //here, if isEven : median = (max(A[i-1],B[j-1]) + min(A[i],B[i])) / 2
            //      else      : median = min(A[i],B[j])
            //however, i,j maybe equal 0,0 or m,n
            //so, we need to classify them
            if (i == m)
                right_min = longArray[j];
            else if (j == n)
                right_min = shortArray[i];
            else
                right_min = std::min(shortArray[i], longArray[j]);       //c++14

            if (!isEven)
                return right_min;

            if (i == 0)
                left_max = longArray[j - 1];
            else if (j == 0)
                left_max = shortArray[i - 1];
            else
                left_max = std::max(shortArray[i - 1], longArray[j - 1]); //c++14

            return (right_min + left_max) / 2.0;
        }
    }
    return 0.0;
}

