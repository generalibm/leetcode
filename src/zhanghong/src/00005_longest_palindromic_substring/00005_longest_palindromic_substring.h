#ifndef SRC_ZHANGHONG_SRC_00005_LONGEST_PALINDROMIC_SUBSTRING
#define SRC_ZHANGHONG_SRC_00005_LONGEST_PALINDROMIC_SUBSTRING

#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(const string & rhs)
    {
        /// "babad"
        int idx = 0, idy = 0;
        int len = 0;

        for (int i = 0; i < rhs.size(); i++)
        {
            for (int j = 0; j < rhs.size(); j++)
            {
                if (isPalindromic(rhs.substr(i, j - i + 1)))
                {
                    if (len < (j - i + 1))
                    {
                        len = j - i + 1;
                        idx = i;
                        idy = j;
                    }

                }
            }
        }

        return rhs.substr(idx, idy-idx+1);
    }

    bool isPalindromic(const string & rhs)
    {
        for (int i = 0, j = rhs.size() - 1; i <= j; i++, j--)
        {
            if (rhs[i] != rhs[j]) return false;
        }
        return true;
    }
};


#endif
