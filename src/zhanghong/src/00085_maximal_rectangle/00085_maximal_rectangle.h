#include <vector>
using namespace std;

namespace Solution85{

class Solution {
public:
    int maximalRectangle(const vector<vector<char>>& matrix);
    int largestRectangleArea(const vector<int>& heights);
private:
    vector<int> m_left;
    vector<int> m_right;
};

}


