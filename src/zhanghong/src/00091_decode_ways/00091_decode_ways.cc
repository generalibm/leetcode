#include "00091_decode_ways.h"

using namespace Solution91;
#include <iostream>
#include <vector>


/// Intuitive Enumerative Recursion
/// Time    : O(2^n)
/// Space   : O(1)
/// Result  : TLE if n > 45
#if 0
int numDecodings(int i, string s)
{
    int n = s.size();
    if (i == n) return 1;
    if (s.at(i) == '0') return 0;

    int res = numDecodings(i+1, s);

    if ((i < n -1) && (s.at(i) == '1' || (s.at(i) == '2' && s.at(i+1) < '7')))
    {
        res += numDecodings(i+2, s);
    }
    return res;
}

int Solution91::Solution::numDecodings(string s)
{
    if (s.empty()) return 0;

    return ::numDecodings(0, s);
}
#endif
/// Memoization
/// Time    : O(n)
/// Space   : O(n)
/// Result  : AC
int numDecodings(int i, string s, vector<int> & mem)
{
    if (-1 != mem.at(i)) return mem.at(i);
    if ('0' == s.at(i)) return mem.at(i) = 0;

    int res = numDecodings(i+1, s, mem);

    if ((i < s.size() - 1) && (s.at(i) == '1' || (s.at(i) == '2' && s.at(i+1) < '7')))
    {
        res += numDecodings(i+2, s ,mem);
    }
    return mem.at(i) = res;
}

int Solution91::Solution::numDecodings(string s)
{
    if (s.empty()) return 0;

    vector<int> mem(s.size()+1, -1);
    mem.at(s.size()) = 1;

    return ::numDecodings(0, s, mem);
}

