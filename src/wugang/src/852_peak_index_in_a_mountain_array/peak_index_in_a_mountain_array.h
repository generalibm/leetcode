#ifndef WG_PEAK_INDEX_IN_A_MOUNTAIN_ARRAY_H_
#define WG_PEAK_INDEX_IN_A_MOUNTAIN_ARRAY_H_

#include <vector>

using namespace std;

class PeakIndexInAMountainArray
{
public:
    int peakIndexInMountainArray(vector<int>& A);

private:
    int peakIndexInMountainArray(vector<int>& A, int left, int right);
};

#endif
