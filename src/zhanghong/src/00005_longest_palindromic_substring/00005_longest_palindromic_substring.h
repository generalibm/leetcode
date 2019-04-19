#ifndef SRC_ZHANGHONG_SRC_00005_LONGEST_PALINDROMIC_SUBSTRING
#define SRC_ZHANGHONG_SRC_00005_LONGEST_PALINDROMIC_SUBSTRING

#include <string>
using namespace std;

class Solution {
public:
//    Dynamic Programming Approach
//    Time:  O(n^2)
//    Space: O(n^2)
    string longestPalindrome(const string & s);

//    Expand around center Approach
//    Time:  O(n^2)
//    Space: O(1)
//
//    string longestPalindrome(const string & s);
//    int expandAroundCenter(const string & s, int left, int right);


//    Brute-force Approach
///   Time:   O(n^3)
///   Space:  O(1)
//
//    string longestPalindrome(const string & rhs);
//    bool isPalindromic(const string & rhs);

};


#endif
