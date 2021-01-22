#include "calculate_money_in_leetcode_bank.h"

#if 0
/// approach 1
/// Reslut: TLE
int Solution::totalMoney(int n)
{
    vector<int> rcd(10001, 0);
    const int weekdays = 7;
    int cnt = 0;
    while (cnt * (weekdays + 1) < rcd.size())
    {
        for (int i = 1; i <= weekdays; i++)
        {
            rcd[cnt * weekdays + i] = cnt + i;
        }
        cnt++;
    }
    return accumulate(rcd.begin() + 1, rcd.begin() + n + 1, 0);
}
#endif

/// approach 2
/// Resutl: AC
int Solution::totalMoney(int n)
{
    int ans = 0;
    int mon = 0;
    int now = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 7 == 0) {
            ++mon;
            now = mon;
        }else
        {
            ++now;
        }

        ans += now;
    }

    return ans;
}
