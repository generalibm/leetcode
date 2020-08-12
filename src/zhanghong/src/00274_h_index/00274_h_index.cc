#include "00274_h_index.h"
#if 0
/// Approach 1
int Solution::hIndex(vector<int>& citations) {
//     [3,0,6,1,5]
//     [0,1,3,5,6]
//          3 4 5  
    sort(citations.begin(), citations.end());

    int h = 0;
    for (int i = citations.size() - 1; i >= 0; i--)
    {
        if (citations[i] <= h) break;
        h = i;
    }
    return h;
}
#endif
#if 1
/// Approach 2
int Solution::hIndex(vector<int>& citations) {
//     [3,0,6,1,5]
//     [0,1,3,5,6]
    
//     [1,1,0,1,0,2]
//      0 1 2 3 4 5
    int len = citations.size();
    vector<int> recds(len + 1, 0);
    
    for (const int cit : citations)
    {
        if (cit > len) recds[len]++;
        else recds[cit]++;
    }
    
    int total = 0;
    int h = 0;
    for (int i = len; i >= 0; i--)
    {
        total += recds[i];
        if (total >= i) {h = i; break;}
        
    }
    
    return h;
}
#endif