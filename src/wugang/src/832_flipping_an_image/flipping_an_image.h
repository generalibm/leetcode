#ifndef WG_FLIPPING_AN_IMAGE_H_
#define WG_FLIPPING_AN_IMAGE_H_

#include <algorithm>
#include <vector>

using namespace std;

class FlippingAnImage
{
public:
    vector<vector<int> > flipAndInvertImage(vector<vector<int> >& matrix);
    
private: 
    void flipImage(vector<vector<int> >& matrix);
    void invertImage(vector<vector<int> >& matrix);
    void reverse(vector<int>& row);
    void invert(vector<int>& row);

};

#endif
