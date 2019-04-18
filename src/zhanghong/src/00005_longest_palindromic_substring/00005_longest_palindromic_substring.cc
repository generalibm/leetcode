#include "00005_longest_palindromic_substring.h"

string Solution::longestPalindrome(const string & s)
{
    if (s.empty())
        return "";
    if (s.size() == 1)
        return s;

    const int len = s.size();

    bool dp[len][len] = { false };
    for (int i = 0; i < len; i++)
    {
        dp[i][i] = true;
        if (i != len - 1)
            dp[i][i + 1] = (s[i] == s[i + 1]);

    }

    for (int i = len - 3; i >= 0; i--)
    {
        for (int j = len - 1; j > i+1; j--)
        {

            dp[i][j] = (dp[i + 1][j - 1] && s[i] == s[j]);
        }
    }

    int max = 0;
    string res;
    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            if (dp[i][j])
            {
                if (max < j - i + 1)
                {
                    max = j - i + 1;
                    res = s.substr(i, j - i + 1);
                }

            }
        }
    }
    return res;
}

//    Expand around center Approach
//    Time:  O(n^2)
//    Space: O(1)
//    string Solution::longestPalindrome(const string & s) {
//        if (s.empty() || s.size() < 1) return "";
//        int start = 0, end = 0;
//        for (int i = 0; i < s.size(); i++) {
//            int len1 = expandAroundCenter(s, i, i);
//            int len2 = expandAroundCenter(s, i, i + 1);
//            int len = std::max(len1, len2);
//            if (len > end - start) {
//                start = i - (len - 1) / 2;
//                end = i + len / 2;
//            }
//        }
//        return s.substr(start, end - start + 1);
//    }
//
//    int Solution::expandAroundCenter(const string & s, int left, int right) {
//        int L = left, R = right;
//        while (L >= 0 && R < s.size() && s.at(L) == s.at(R)) {
//            L--;
//            R++;
//        }
//        return R - L - 1;
//    }

//    Brute-force Approach
///   Time:   O(n^3)
///   Space:  O(1)
//    string Solution::longestPalindrome(const string & rhs)
//      {
//          /// "babad"
//          int idx = 0, idy = 0;
//          int len = 0;
//
//          for (int i = 0; i < rhs.size(); i++)
//          {
//              for (int j = 0; j < rhs.size(); j++)
//              {
//                  if (isPalindromic(rhs.substr(i, j - i + 1)))
//                  {
//                      if (len < (j - i + 1))
//                      {
//                          len = j - i + 1;
//                          idx = i;
//                          idy = j;
//                      }
//
//                  }
//              }
//          }
//
//          return rhs.substr(idx, idy-idx+1);
//      }
//
//      bool Solution::isPalindromic(const string & rhs)
//      {
//          for (int i = 0, j = rhs.size() - 1; i <= j; i++, j--)
//          {
//              if (rhs[i] != rhs[j]) return false;
//          }
//          return true;
//      }
