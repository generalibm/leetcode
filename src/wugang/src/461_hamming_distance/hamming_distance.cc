#include "hammingdistance.h"

bool HammingDistance::hammingDistance(int x, int y)
{
	int hammingDistanceNum = 0;
    int xorNum = x ^ y;
        
    while(xorNum != 0)
	{
        if(1 == (xorNum % 2))
		{
            hammingDistanceNum++;
        }
        
		xorNum /= 2;
    }
        
    return hammingDistanceNum;
}
