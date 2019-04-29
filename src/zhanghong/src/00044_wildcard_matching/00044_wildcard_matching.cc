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


// Dynamic Programming Approach
// Time     : O(n)
// Space    : O(n^2)
// Result   : AC
bool Solution44::Solution::isMatch(string s, string p)
{
    size_t len_s = s.size();
    size_t len_p = p.size();

    bool dp[len_s+1][len_p+1];

    dp[0][0] = true;

    for (size_t i = 0; i < len_p; i++)
    {
        if (p[i] == '*') dp[0][i+1] = dp[0][i];
        else dp[0][i+1] = false;
    }

    for (size_t j = 0; j < len_s; j++)
    {
        dp[j+1][0] = false;
    }

    for (size_t i = 0; i < len_s; i++)
    {
        for (size_t j = 0; j < len_p; j++)
        {
            if (s[i] == p[j] || p[j] == '?')
            {
                dp[i+1][j+1] = dp[i][j];
            }

            else if (p[j] == '*')
            {
                dp[i+1][j+1] = (dp[i+1][j] || dp[i][j+1]);
            }

            else dp[i+1][j+1] = false;
        }
    }

    return dp[len_s][len_p];
}


// Greedy Approach
// Time     : O(n)
// Space    : O(1)
// Result   : AC
//bool Solution44::Solution::isMatch(string s, string p)
//{
//    size_t i = 0;
//    size_t j = 0;
//
//    int ii = -1;
//    int jj = -1;
//
//    for (; i < s.size();)
//    {
//        if (s[i] == p[j] || p[j] == '?')
//        {
//            i++;j++;
//            continue;
//        }
//
//        if (p[j] == '*')
//        {
//            ii = i;
//            jj = j;
//            j++;
//            continue;
//        }
//
//        if (jj >= 0 && jj < p.size())
//        {
//            i = ++ii;
//            j = jj + 1;
//            continue;
//        }
//        return false;
//    }
//
//    for (; j < p.size();j++)
//        if (p[j] != '*') return false;
//
//    return true;
//}

