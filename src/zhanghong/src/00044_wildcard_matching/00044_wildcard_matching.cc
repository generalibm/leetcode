#include "00044_wildcard_matching.h"

#include <cstring>

// Modern cpp library support Approach
// Time     :
// Space    :
// Result   : TLE, when input = ("aaaabaaaabbbbaabbbaabbaababbabbaaaababaaabbbbbbaabbbabababbaaabaabaaaaaabbaabbbbaababbababaabbbaababbbba", "*****b*aba***babaa*bbaba***a*aaba*b*aa**a*b**ba***a*a*")

//#include <regex>
//bool Solution44::Solution::isMatch(string s, string p)
//{
//    for (size_t i = 0; i < p.size(); i++)
//    {
//        if (p[i] == '?')
//            p[i] = '.';
//        if (p[i] == '*')
//            p.insert(i++, 1, '.');
//    }
//
//    regex reg(p);
//
//    return regex_match(s, reg);
//}

//bool match(char const *needle, char const *haystack)
//{
//    for (; *needle != '\0'; ++needle)
//    {
//        switch (*needle)
//        {
//            case '?':
//                if (*haystack == '\0')
//                    return false;
//                ++haystack;
//                break;
//            case '*':
//            {
//                if (needle[1] == '\0')
//                    return true;
//                if (haystack[0] == '\0')
//                {
//                    for (size_t i = 0; i < strlen(needle);i++)
//                    {
//                        if (needle[i] != '*') return false;
//                    }
//                    return true;
//                }
//                size_t max = strlen(haystack);
//                for (size_t i = 0; i < max; i++)
//                    if (match(needle + 1, haystack + i))
//                        return true;
//                return false;
//            }
//            default:
//                if (*haystack != *needle)
//                    return false;
//                ++haystack;
//        }
//    }
//    return *haystack == '\0';
//}

// Intuitive Recursive Approach
// Time     : O(n^2)
// Space    : O(1)
// Result   : TLE, when input = ("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b")
//bool Solution44::Solution::isMatch(string s, string p)
//{
//    return match(p.c_str(), s.c_str());
//}


// Greedy Approach
// Time     : O(n)
// Space    : O(1)
// Result   : AC
bool Solution44::Solution::isMatch(string s, string p)
{
    size_t i = 0;
    size_t j = 0;

    int ii = -1;
    int jj = -1;

    for (; i < s.size();)
    {
        if (s[i] == p[j] || p[j] == '?')
        {
            i++;j++;
            continue;
        }

        if (p[j] == '*')
        {
            ii = i;
            jj = j;
            j++;
            continue;
        }

        if (jj >= 0 && jj < p.size())
        {
            i = ++ii;
            j = jj + 1;
            continue;
        }
        return false;
    }

    for (; j < p.size();j++)
        if (p[j] != '*') return false;

    return true;
}

