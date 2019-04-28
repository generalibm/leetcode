#include "00010_regular_expression_matching.h"

using namespace Solution10;

//bool Solution::isMatch(string s, string p)
//{
//    int i = 0;
//
//    for (int j = 0; i < s.size() && j < p.size();)
//    {
//        if (s[i] == p[j] || p[j] == '.')
//        {
//            i++;j++;
//        }
//        else
//        {
//            j++;
//        }
//
//        if (p[j] == '*')
//        {
//            if ((p[j - 1] == s[i] || p[j - 1] == '.') && j > 0)
//            {
//                i++;
//            }
//            else
//            {
//                j++;
//            }
//        }
//    }
//
//    return i == s.size();
//}

// Modern cpp library support Approach
// Time     :
// Space    :
// Result   : AC
#include <regex>
bool Solution::isMatch(string s, string p)
{
    regex reg(p);

    return regex_match(s, reg);
}




