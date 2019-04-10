#include "robot_return_to_origin.h"

bool RobotReturnToOrigin::judgeCircle(string moves)
{
	int x = 0;
    int y = 0;
        
    for(int i = 0; i < moves.size(); i++)
	{
        if('U' == moves[i])
		{
            y++;
        }
        else if('D' == moves[i])
		{
            y--;
        }
        else if('L' == moves[i])
		{
            x--;
        }
        else if('R' == moves[i])
		{
            x++;
        }
        else{
            // do nothing
        }
    }
        
    
	//if((0 == x) && (0 == y))
	//{
    //    return true;
    //}
    //else
	//{
    //    return false;
    //}

    return ((0 == x) && (0 == y))
}
