#ifndef __REMOVE_K_DIGITS_H
#define __REMOVE_K_DIGITS_H

#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k >= num.size()) return "0";

        string res{""};
        for (const char & c : num)
        {
            while (k > 0 && !res.empty() && res.back() > c)
            {
                res.pop_back();
                k--;
            }
            res.push_back(c);
        }

        while (k--) res.pop_back();

        int idx = 0;
        while (idx < res.size())
        {
            if (res[idx] == '0') idx++;
            else break;
        }

        return idx == res.size() ? "0" : res.substr(idx);


         /** 
        stack<char> save;
        for (const char & c : num)
        {
            while (k > 0 && !save.empty() && save.top() > c)
            {
                save.pop();
                k--;
            }
            save.push(c);
        }
        
        while (k--) save.pop();
        
        string res;
        for (; !save.empty(); save.pop()) res.push_back(save.top());
        
        reverse(res.begin(), res.end());
        
        int idx = 0;
        while (idx < res.size())
            if (res[idx] == '0') idx++;
            else break;
        
        return idx == res.size() ? "0" : res.substr(idx);
        **/
    }
};

#endif