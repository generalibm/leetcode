#include "self_dividing_number.h"

int DeleteColumnsToMakeSorted::minDeletionSize(vector<string>& A) 
{
    if(A.empty())
	{
        return 0;
    }
        
    int num = 0;
    int size = A[0].size();
        
    for(int i = 0; i < size; i++)
	{
        for(int j = 0; j < A.size() - 1; j++)
		{
            if(A[j][i] > A[j+1][i])
			{
                num++;
                break;
            }
        }
    }
	
    return num;
}


