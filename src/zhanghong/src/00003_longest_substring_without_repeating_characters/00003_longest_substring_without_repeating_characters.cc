#include "00003_longest_substring_without_repeating_characters.h"

int Solution::lengthOfLongestSubstring(const string & rhs)
{
    if (rhs.empty())
        return 0;

    string str = rhs;

    int res = 0;
    int i = 0, j = 0;

    while (j < str.size() && i <= j)
    {
        if (res < (j - i + 1))
            res = (j - i + 1);

        if (str.size() <= j + 1)
            break;

        if (isContained(str.data(), i, j, str[j + 1]))
        {
            i++;
            if (j < i)
                j = i;
        }
        else
        {
            j++;
        }
    }

    return res;
}

bool Solution::isContained(const char * base, int begin, int end, char ch)
{
    for (int i = begin; i <= end; i++)
    {
        if (base[i] == ch)
            return true;
    }
    return false;
}
