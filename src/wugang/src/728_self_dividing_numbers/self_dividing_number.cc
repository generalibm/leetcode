#include "self_dividing_number.h"

vector<int> SelfDividingNumber::selfDividingNumbers(int left, int right) 
{
    vector<int> result;
        
    for(int i = left; i <= right; i++)
	{
        if(isSelfDivideNumber(i))
		{
            result.push_back(i);
        }
    }
        
    return result;
        
}

bool SelfDividingNumber::isSelfDivideNumber(int num)
{
	int tmp = num;
    int remainder = tmp % 10;
        
    while(remainder != 0)
	{
        if((num % remainder) != 0)
		{
            return false;
        }
            
        tmp /= 10;
        remainder = tmp % 10;
    }
        
    if(tmp > 0)
	{
        return false;
    }
        
    return true;
}

