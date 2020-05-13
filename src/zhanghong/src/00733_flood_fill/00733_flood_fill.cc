#include "00733_flood_fill.h"

void Solution::helper(vector<vector<int>> &image, int sr, int sc, int newColor, int oldColor)
{
    if (oldColor == image[sr][sc])
    {
        image[sr][sc] = newColor;

        printf("%d, %d\n", sr, sc);// << "sr = " << sr << ", sc = " << sc << "\n";

        if (sr > 0)
            helper(image, sr - 1, sc, newColor, oldColor);
        if (sc > 0)
            helper(image, sr, sc - 1, newColor, oldColor);
        if (sr < image.size() - 1)
            helper(image, sr + 1, sc, newColor, oldColor);
        if (sc < image.front().size() - 1)
            helper(image, sr, sc + 1, newColor, oldColor);
    }
}

vector<vector<int>> Solution::floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int oldColor = image[sr][sc];
    
    if (oldColor != newColor) helper(image, sr, sc, newColor, oldColor);

    return image;
}

