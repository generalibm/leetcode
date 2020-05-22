#ifndef __SRC_00451_SORT_CHARACTERS_BY_FREQUENCE_H
#define __SRC_00451_SORT_CHARACTERS_BY_FREQUENCE_H

#include <map>
#include <set>
#include <string>

using namespace std;

class Solution
{
public:
    string frequencySort(string s) {
        map<char, int> recd;
        for (const char & c : s) recd[c]++;
        
        auto comp = [](const pair<char, int> & l, const pair<char, int> & r) {
            return l.second < r.second;
        };
        
        multiset<pair<char, int>, decltype(comp)> freq(comp);
        for (const auto & e : recd) freq.insert({e.first, e.second});
        
        string res;
        for (const auto & e : freq) res.insert(res.cbegin(), e.second, e.first);
        
        return res;
    }
};

#endif
