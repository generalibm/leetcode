#include "00213_house_robber_2.h"

using namespace Solution00213;

int Solution::rob(const vector<int> &nums)
{
    int len = nums.size();

    if (0 == len)
        return 0;
    if (1 == len)
        return nums.front();
    if (2 == len)
        return max(nums.at(0), nums.at(1));

    vector<int> dp(len);
    vector<bool> isFirst(len, true);

    dp.at(0) = nums.at(0);
    dp.at(1) = max(nums.at(1), nums.at(0));
    isFirst.at(0) = true;
    isFirst.at(1) = nums.at(1) < nums.at(0);

    // [1,2,3,1]
    for (int i = 2; i < len - 1; i++)
    {
        if (dp.at(i - 1) < dp.at(i - 2) + nums.at(i))
        {
            dp.at(i) = dp.at(i - 2) + nums.at(i);
            isFirst.at(i) = isFirst.at(i - 2);
        }
        else
        {
            dp.at(i) = dp.at(i - 1);
            isFirst.at(i) = isFirst.at(i - 1);
        }
    }

    if (isFirst.at(len - 1 - 2))
    {
        dp.at(len - 1) = dp.at(len - 1 - 1);
    }
    else
    {
        dp.at(len - 1) = max(dp.at(len - 1 - 1), dp.at(len - 1 - 2) + nums.at(len - 1));
    }

    return dp.back();
}

