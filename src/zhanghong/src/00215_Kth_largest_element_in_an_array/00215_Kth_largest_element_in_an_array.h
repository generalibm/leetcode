#ifndef SRC_ZHANGHONG_SRC_00215_KTH_LARGEST_ELEMENT_IN_AN_ARRAY_00215_KTH_LARGEST_ELEMENT_IN_AN_ARRAY_H_
#define SRC_ZHANGHONG_SRC_00215_KTH_LARGEST_ELEMENT_IN_AN_ARRAY_00215_KTH_LARGEST_ELEMENT_IN_AN_ARRAY_H_

#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>&& nums, int k) {
        /// assume k is always valid.

//         make_heap(begin(nums), end(nums));
//         while (--k)
//         {
//             pop_heap(begin(nums), end(nums));
//             nums.pop_back();
//             make_heap(begin(nums), end(nums));
//         }
//         return nums.front();

//         priority_queue<int> q;
//         for (auto e : nums) q.push(e);
//         while (--k) q.pop();
//         return q.top();

        // sort(begin(nums), end(nums));
        // return nums.at(nums.size()-k);

        return quickSelect(nums.size() - k, nums, 0, nums.size() - 1);
    }

private:
    ///
    int quickSelect(int kSmall, vector<int>& nums, int left, int right)
    {
        if (left == right) return nums[left];

        int pivot = guess(nums, left, right);

        if (pivot == kSmall)
        {
            return nums[pivot];
        }
        else if (pivot < kSmall)
        {
            return quickSelect(kSmall, nums, pivot + 1, right);
        }
        else
        {
            return quickSelect(kSmall, nums, left, pivot - 1);
        }
    }

    /// guess the candidate(random) is the Kth largest
    /// return the index of candidate
    int guess(vector<int>& nums, int left, int right)
    {
        int i = left;
        int j = right;

        int pivot = left + rand() % (right - left);
        swap(nums[i], nums[pivot]);
        while (i < j)
        {
            while (i < j && nums[j] >= nums[left])
                j--;
            while (i < j && nums[i] <= nums[left])
                i++;
            swap(nums[i], nums[j]);
        }
        swap(nums[left], nums[i]);
        return i;
    }
};




#endif /* SRC_ZHANGHONG_SRC_00215_KTH_LARGEST_ELEMENT_IN_AN_ARRAY_00215_KTH_LARGEST_ELEMENT_IN_AN_ARRAY_H_ */
