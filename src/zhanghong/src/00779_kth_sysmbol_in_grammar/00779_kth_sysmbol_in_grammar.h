#ifndef __SRC_00779
#define __SRC_00779

class Solution {
public:
    int kthGrammar(int N, int K) {
        /// base case
        if (N == 1 and K == 1) return 0;
        
        /// left child
        if (K % 2 == 1) return kthGrammar(N-1, (K+1)/2);
        /// right child
        else return kthGrammar(N-1, (K+1)/2)  xor 1;
    }
};

#endif