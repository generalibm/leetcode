#ifndef SRC_ZHANGHONG_SRC_00008_STRING_TO_INTEGER
#define SRC_ZHANGHONG_SRC_00008_STRING_TO_INTEGER

#include <string>
using namespace std;

class Solution {
public:
	int myAtoi(const string & rhs);

private:
    char head(const string & rhs);
	bool isDigit(char elem);
	bool isNagativeMark(char elem);
	bool isPositiveMark(char elem);
	bool isWhitespace(char elem);
};

#endif
