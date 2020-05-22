#ifndef __SRC_01452_PEOPLE_WHOES_FAVORITE_COMPANIES_IS_NOT_A_SUBSET_OF_ANOTHER_LIST
#define __SRC_01452_PEOPLE_WHOES_FAVORITE_COMPANIES_IS_NOT_A_SUBSET_OF_ANOTHER_LIST

#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <unordered_map>
#include <bitset>

using namespace std;

class Solution
{
public:
/**
    vector<int> peopleIndexes(vector<vector<string>> &favoriteCompanies)
    {
        vector<set<string>> lists(favoriteCompanies.size());

        for (int i = 0; i < favoriteCompanies.size(); i++)
        {
            for (const auto &comp : favoriteCompanies[i])
            {
                //lists[i].insert(getHash(comp));
                lists[i].insert(comp);
            }
        }

        vector<int> res;
        for (int i = 0; i < lists.size(); i++)
        {
            int j = 0;
            for (; j < lists.size(); j++)
            {
                if (hasContain(lists[j], lists[i])  && j != i)
                    break;
            }
            if (j == lists.size())
                res.push_back(i);
        }

        return res;
    }
    **/

    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        unordered_map<string, bitset<100>> m;
        for(int i = 0; i < favoriteCompanies.size(); i++) {
            bitset<100> t; t.set(i);
            for(auto &c : favoriteCompanies[i]) {
                m[c] |= t; 
            }
        }

        vector<int> ans;
        for(int i = 0; i < favoriteCompanies.size(); i++) {
            bitset<100> t; t.flip();
            for(auto &c : favoriteCompanies[i]) {
                t &= m[c];
            }
            if(t.count() == 1) ans.push_back(i); 
        }
        
        return ans;
    }

private:
    bool hasContain(const set<string> &l, const set<string> &r)
    {
        auto i = l.begin();
        auto j = r.begin();
        int cnt = 0;
        while (i != l.end() && j != r.end())
        {
            if (*i == *j)
            {
                i++;
                j++;
                cnt++;
            }
            else if (*i < *j)
            {
                i++;
            }
            else
            {
                j++;
            }
        }

        return cnt == r.size();
    }
};

#endif
