#include "di_string_match.h"

vector<int> DIStringMatch::diStringMatch(string s) 
{
    int minNum = 0;
    int maxNum = s.size();
    vector<int> result;
        
    for(int i = 0; i < s.size(); i++)
	{
        if('I' == s[i])
		{
            result.push_back(minNum);
            minNum++;
        }
        else if('D' == s[i])
		{
            result.push_back(maxNum);
            maxNum--;
        }
    }
    
	result.push_back(minNum);
        
    return result;
        
}
