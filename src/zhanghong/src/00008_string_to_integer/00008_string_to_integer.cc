#include "00008_string_to_integer.h"

int Solution::myAtoi(const string & rhs)
{
    string str = rhs;
    while (isWhitespace(head(str)))
    {
        str.erase(0, 1);
    }

    if (!isPositiveMark(head(str)) && !isNagativeMark(head(str)) && !isDigit(head(str)))
        return 0;

	long res = 0;

	res = std::atol(str.c_str());

	if (res < -2147483648)
	{
		res = -2147483648;
	}
	else if (2147483647 < res)
	{
		res = 2147483647;
	}

	return res;
}

char Solution::head(const string & rhs)
{
	return rhs[0];
}

bool Solution::isDigit(char elem)
{
	if (48 <= elem && elem <= 57)
	{
		return true;
	}
	else
		return false;
}

bool Solution::isNagativeMark(char elem)
{
	return '-' == elem;
}

bool Solution::isPositiveMark(char elem)
{
	return '+' == elem;
}

bool Solution::isWhitespace(char elem)
{
	return ' ' == elem;
}
