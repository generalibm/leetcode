#include "flipping_an_image.h"

vector<vector<int> > FlippingAnImage::flipAndInvertImage(vector<vector<int> >& matrix) 
{
    vector<vector<int> > resultMatrix = matrix;
        
        flipImage(resultMatrix);
        invertImage(resultMatrix);
        
        return resultMatrix;
    }
    
void FlippingAnImage::flipImage(vector<vector<int> >& matrix)
{
        for(int i = 0; i < matrix.size(); i++)
		{
            reverse(matrix[i]);
        }
}
    
void FlippingAnImage::invertImage(vector<vector<int> >& matrix)
{
    for(int i = 0; i < matrix.size(); i++)
    {
        invert(matrix[i]);
    }
}
    
void FlippingAnImage::reverse(vector<int>& row)
{
    int i = 0;
    int j = row.size() - 1;

    while(i < j)
	{
        swap(row[i], row[j]);
        i++;
        j--;
    }
}
    
void FlippingAnImage::invert(vector<int>& row)
{
    for(int i = 0; i < row.size(); i++)
	{
        row[i] ^= 1;   // 0->1; 1->0
    }
}