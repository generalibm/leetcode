#ifndef __SRC_00098_VALIDATE_BINARY_SEARCH_TREE_H
#define __SRC_00098_VALIDATE_BINARY_SEARCH_TREE_H


#include "../headers/tree_node.h"

#include <climits>

class Solution
{
public:
    bool isValidBST(TreeNode<int> * root)
    {
        int min = INT_MIN, max = INT_MAX;
        bool flag = bottomUp(root, min, max);
        return (min < max) && flag;
    }

    bool bottomUp(TreeNode<int> * x, int & min, int & max)
    {
        if (x == nullptr) 
        {
            return true;
        }

        int minL = INT_MIN;
        int maxL = INT_MAX;
        int minR = INT_MIN;
        int maxR = INT_MAX;

        if (x->left == nullptr && x->right == nullptr)
        {
            min = max = x->val;
            return true;
        }
        else if (x->left == nullptr)
        {
            bool flagR = bottomUp(x->right, minR, maxR);

            max = maxR;
            min = x->val;

            bool (x->val < minR) && flagR;
        }
        else if (x->right == nullptr)
        {
            bool flagL = bottomUp(x->left, minL, maxL);

            min = minL;
            max = x->val;

            return (maxL < x->val) && flagL;
        }
        else
        { 
            bool flagL = bottomUp(x->left, minL, maxL);
            bool flagR = bottomUp(x->right, minR, maxR);

            min = minL;
            max = maxR;

            return (maxL < x->val) && (minR > x->val) && flagL && flagR; 
        }               
    }
};


#endif