#ifndef SRC_ZHANGHONG_SRC_00003_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS
#define SRC_ZHANGHONG_SRC_00003_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS

#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(const string & rhs);

private:
    bool isContained(const char * base, int begin, int end, char ch);
};

#endif
