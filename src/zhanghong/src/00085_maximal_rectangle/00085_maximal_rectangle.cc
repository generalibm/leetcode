#include "00085_maximal_rectangle.h"

/// Dynamic programming Approach
///     - based on largest area of histogram(leetcode 84)
/// Time    : O(n^2)
/// Space   : O(n)
/// Result  : AC
int Solution85::Solution::maximalRectangle(const vector<vector<char>>& matrix)
{
    int n = matrix.size();
    int m = n > 0 ? matrix[0].size() : 0;

    if (0 == m || 0 == n) return 0;

    vector<int> histogram(m, 0);

    int res = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ('0' == matrix[i][j])
            {
                histogram[j] = 0;
            }
            else
            {
                histogram[j] += matrix[i][j] - '0';
            }
        }

        res = std::max(res, largestRectangleArea(histogram));
    }

    return res;
}


int Solution85::Solution::largestRectangleArea(const vector<int>& heights)
{
    if (heights.empty()) return 0;

    const int len = heights.size();

    this->m_left.resize(len);
    std::fill(this->m_left.begin(), this->m_left.end(), -1);

    this->m_right.resize(len);
    std::fill(this->m_right.begin(), this->m_right.end(), len);

    int p = 0;
    for (int i = 1; i < len; i++)
    {
        p = i - 1;
        while (0 <= p && heights[i] <= heights[p])
        {
            p = this->m_left[p];
        }
        this->m_left[i] = p;
    }

    for (int i = len - 2; i >= 0; i--)
    {
        p = i + 1;
        while (p < len && heights[i] <= heights[p])
        {
            p = this->m_right[p];
        }
        this->m_right[i] = p;
    }

    int max = heights.front();
    for (int i = 0; i < len; i++)
    {
        max = std::max(max, heights[i] * (m_right[i] - m_left[i] - 1));
    }

    return max;
}


