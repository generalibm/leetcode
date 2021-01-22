#ifndef SRC_01673_FIND_THE_MOST_COMPETITIVE_SUBSEQUENCE_H__
#define SRC_01673_FIND_THE_MOST_COMPETITIVE_SUBSEQUENCE_H__

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> mostCompetitive(vector<int>&& A, int k) {
        if (A.size() <= k) return A;
        
        vector<int> stack;
        for (int i = 0; i < A.size(); ++i) {
            while (!stack.empty() && stack.back() > A[i] && stack.size() - 1 + A.size() - i >= k)
                stack.pop_back();
            if (stack.size() < k)
                stack.push_back(A[i]);
        }
        return stack;
    }
};

#endif