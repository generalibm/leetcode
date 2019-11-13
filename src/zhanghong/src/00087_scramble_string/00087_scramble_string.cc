#include "00087_scramble_string.h"

#include <vector>

bool Solution87::Solution::isScramble(string s1, string s2)
{
    if (s1 == s2) return true;

    if (s1.size() != s2.size()) return false;

    vector<int> cnt(26, 0);

    size_t len = s1.size();

    for (size_t i = 0; i < len; i++)
    {
        cnt[s1[i] - 'a']++;
        cnt[s2[i] - 'a']--;
    }

    for (size_t i = 0; i < cnt.size(); i++)
    {
        if (0 != cnt[i]) return false;
    }

    for (size_t i = 1; i <= len-1; i++)
    {
        if (isScramble(s1.substr(0,i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
            return true;

        if (isScramble(s1.substr(0, i), s2.substr(len-i)) && isScramble(s1.substr(i), s2.substr(0, len-i)))
            return true;
    }

    return false;
}
