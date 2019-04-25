#include "00010_regular_expression_matching.h"

using namespace Solution10;

bool Solution::isMatch(string s, string p)
{
    int i = 0;

    for (int j = 0; i < s.size() && j < p.size();)
    {
        if (p[j] == '*')
        {
            if ((p[j-1] == s[i] || p[j-1] == '.') && j > 0)
            {
                i++;continue;
            }
            else
            {
                j++;
            }
        }

        if (s[i] == p[j] || p[j] == '.')
        {
            i++;j++;
        }
        else
        {
            j++;
        }
    }

    return i == s.size();
}






