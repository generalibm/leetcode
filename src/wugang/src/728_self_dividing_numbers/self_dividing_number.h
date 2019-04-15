#ifndef WG_SELF_DIVIDING_NUMBER_H_
#define WG_SELF_DIVIDING_NUMBER_H_

#include <vector>

using namespace std;

class SelfDividingNumber
{
public:
    vector<int> selfDividingNumbers(int left, int right);

private:
    bool isSelfDividingNumber(int num);
};

#endif
