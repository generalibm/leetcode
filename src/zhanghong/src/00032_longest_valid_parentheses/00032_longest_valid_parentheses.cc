#include "00032_longest_valid_parentheses.h"

//#include <stack>
//
//bool isValid(string && s)
//{
//    stack<char> container;
//
//    for (size_t i = 0; i < s.size(); i++)
//    {
//        if (s[i] == '(')
//        {
//            container.push(s[i]);
//        }
//        else if (!container.empty() && container.top() == '(')
//        {
//            container.pop();
//        }
//        else
//            return false;
//    }
//
//    return container.empty();
//}
//
//// Brute-force Approach
//// Time   : O(n^3)
//// Space  : O(n)
//// Result : Time Limit Exceeded
//// n = 833 + 896, time = 3109ms
//int Solution32::Solution::longestValidParentheses(string s)
//{
//    size_t max = 0;
//
//    for (size_t i = 0; i < s.size(); i++)
//    {
//        for (size_t j = i+1; j < s.size(); j++)
//        {
//            if (isValid(s.substr(i, j-i+1)))
//            {
//                max = std::max(max, j - i + 1);
//            }
//        }
//    }
//    return max;
//}

// Brute-force Optimization
// Time     : O(n)
// Space    : O(n)
// Result   : AC
//#include <stack>
//
//int Solution32::Solution::longestValidParentheses(string s)
//{
//    int max = 0;
//    stack<int> container;
//    container.push(-1);
//
//    for (int i = 0; i < s.size(); i++)
//    {
//        if (s[i] == '(')
//        {
//            container.push(i);
//        }
//        else
//        {
//            container.pop();
//            if (container.empty())
//            {
//                container.push(i);
//            }
//            else
//            {
//                max = std::max(max, i - container.top());
//            }
//        }
//    }
//
//    return max;
//}

//#include <vector>
//
//// Dynamic Programming Approach
//// Time     : O(n)
//// Space    : O(n)
//// Result   : AC
//int Solution32::Solution::longestValidParentheses(string s)
//{
//    int max = 0;
//
//    vector<int> dp(s.size());
//    for (size_t i = 1; i < s.size(); i++)
//    {
//        if (s[i] == ')')
//        {
//            if (s[i-1] == '(')
//            {
//                dp[i] = (i >= 2 ? dp[i-2] : 0) + 2;
//            }
//            else if(i-dp[i-1] >0 && s[i-dp[i-1]-1] == '(')
//            {
//                dp[i] = dp[i-1] + ((i-dp[i-1]) >=2 ? dp[i-dp[i-1]-2] : 0) + 2;
//            }
//
//            max = std::max(max, dp[i]);
//        }
//    }
//
//    return max;
//}


// Intuitive Approach
//Time      : O(n)
// Space    : O(1)
// Result   : AC
int Solution32::Solution::longestValidParentheses(string s)
{
    size_t max = 0;
    size_t left = 0;
    size_t right = 0;

    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            left++;
        else
            right++;

        if (left == right)
            max = std::max(max, left + right);

        if (left < right)
            left = right = 0;
    }

    left = right = 0;
    for (int i = s.size() - 1; i >=0; i--)
    {
        if (s[i] == '(')
            left++;
        else
            right++;

        if (left == right)
            max = std::max(max, left + right);

        if (right < left)
            left = right = 0;
    }

    return max;
}


