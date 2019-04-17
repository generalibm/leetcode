#ifndef SRC_ZHANGHONG_SRC_00005_LONGEST_PALINDROMIC_SUBSTRING
#define SRC_ZHANGHONG_SRC_00005_LONGEST_PALINDROMIC_SUBSTRING

#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(const string & s) {
        if (s.empty() || s.size() < 1) return "";
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = std::max(len1, len2);
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }

    int expandAroundCenter(const string & s, int left, int right) {
        int L = left, R = right;
        while (L >= 0 && R < s.size() && s.at(L) == s.at(R)) {
            L--;
            R++;
        }
        return R - L - 1;
    }

///   Time:   O(n^3)
///   Space:  O(1)
//    string longestPalindrome(const string & rhs)
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
//      bool isPalindromic(const string & rhs)
//      {
//          for (int i = 0, j = rhs.size() - 1; i <= j; i++, j--)
//          {
//              if (rhs[i] != rhs[j]) return false;
//          }
//          return true;
//      }
};


#endif
