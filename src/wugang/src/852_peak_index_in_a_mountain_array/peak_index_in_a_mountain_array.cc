#include "peak_index_a_mountain_array.h"

int PeakIndexInAMountainArray::peakIndexInMountainArray(vector<int>& A)
{
        
    return peakIndexInMountainArray(A, 0, A.size() - 1);
}

int PeakIndexInAMountainArray::peakIndexInMountainArray(vector<int>& A, int left, int right)
{
    if(left == right)
	{
        return left;
    }
        
    int mid = (left+right) / 2;
    if(left == mid)
	{
        return A[left] > A[right] ? left : right;
    }
        
    if(A[mid-1] < A[mid] && A[mid] > A[mid+1])
	{
        return mid;
    }
        
    if(A[mid-1] < A[mid] && A[mid] < A[mid+1])
	{
        return peakIndexInMountainArray(A, mid+1, right);
    }
        
    if(A[mid-1] > A[mid] && A[mid] > A[mid+1])
	{
        return peakIndexInMountainArray(A, left, mid-1);
    }
        
    return -1;
}

