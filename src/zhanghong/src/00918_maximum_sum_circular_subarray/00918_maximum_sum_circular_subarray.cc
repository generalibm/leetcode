#include "00918_maximum_sum_circular_subarray.h"

int Solution::maxSubarraySumCircular(vector<int> &A)
{
    if (A.empty())
        return 0;

    int N = A.size();

    int ans = A[0];
    int cur = A[0];
    for (int i = 1; i < N; i++)
    {
        cur = A[i] + max(cur, 0);
        ans = max(ans, cur);
    }

    vector<int> rightsums(N, 0);
    rightsums[N - 1] = A[N - 1];
    for (int i = N - 2; i >= 0; i--)
        rightsums[i] = rightsums[i + 1] + A[i];

    vector<int> maxright(N, 0);
    maxright[N - 1] = A[N - 1];
    for (int i = N - 2; i >= 0; i--)
        maxright[i] = max(rightsums[i], maxright[i + 1]);

    int leftsum = 0;

    for (int i = 0; i < N - 2; i++)
    {
        leftsum += A[i];
        ans = max(ans, leftsum + maxright[i + 2]);
    }

    return ans;
}

/**
    int Solution::maxSubarraySumCircular(vector<int>& A)
    {
        vector<int> B(A);
        for (auto it = A.begin(); it != A.end(); it++)
        {
            B.push_back(*it);
        }
        
        long long maxA = maxSubArray2(A, 0, A.size() -1);
        
        //cout << "maxA = " << maxA << "\n";
        
        long long maxB = LLONG_MIN;
        
        for (int i = 1; i < A.size(); i++)
        {
            maxB = maxSubArray2(B, i, i+A.size()-1);
            //cout << "maxB[" << i << "-" << i+A.size()-1 << "] = " << maxB << "\n";
            maxA = max(maxA, maxB);
        }
        
        return maxA;
    }
**/
long long maxSubArray2(vector<int> &arr, int l, int r)
{

    long long prefix = arr[l];
    long long res = prefix;
    for (int i = l + 1; i <= r; i++)
    {
        prefix = max(prefix + arr[i], (long long)arr[i]);
        res = max(res, prefix);
    }

    return res;
}

long long maxSubArray(vector<int> &arr, int l, int r)
{
    if (l == r)
        return arr[l];

    int mid = (l + r) >> 1;
    long long maxL = maxSubArray(arr, l, mid);
    long long maxR = maxSubArray(arr, mid + 1, r);

    long long maxAll = LLONG_MIN;

    long long sum = 0;
    for (int i = mid; i >= l; i--)
    {
        sum += arr[i];
        maxAll = max(maxAll, sum);
    }
    //sum = 0;
    for (int i = mid + 1; i <= r; i++)
    {
        sum += arr[i];
        maxAll = max(maxAll, sum);
    }

    return max(max(maxL, maxR), maxAll);
}