#ifndef SRC_ZHANGHONG_SRC_00004_MEDIAN_OF_TWO_SORTED_ARRAYS
#define SRC_ZHANGHONG_SRC_00004_MEDIAN_OF_TWO_SORTED_ARRAYS

#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2);
private:
    double findMedian(const vector<int>& longArray, const vector<int> & shortArray, bool isEven);
};

#endif
