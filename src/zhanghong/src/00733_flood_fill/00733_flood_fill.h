#ifndef __00733_FLOOD_FILL_H
#define __00733_FLOOD_FILL_H

#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor);
private:
    void helper(vector<vector<int>> &image, int sr, int sc, int newColor, int oldColor);
};

#endif
