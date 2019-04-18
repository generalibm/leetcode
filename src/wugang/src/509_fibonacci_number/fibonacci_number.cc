#include "fibnacci_number.h"

int FibonacciNumber::fib(int num) 
{
    if(num == 0 || num == 1)
	{
        return num;
    }
        
    int x = 0;  // F(i-1)
    int y = 1;  // F(i)
    int tmp = y;
        
    for(int i = 2; i < num; i++)
	{
        tmp = y;
        y = x + y;
        x = tmp;
    }
        
    return (x + y);
}
