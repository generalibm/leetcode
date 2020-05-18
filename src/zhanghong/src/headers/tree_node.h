#ifndef __HEADERS_TREE_NODE_H
#define __HEADERS_TREE_NODE_H

template<typename T>
struct TreeNode {
    T val;
    TreeNode<T> * left;
    TreeNode<T> * right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(T x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(T x, TreeNode<T> * l, TreeNode<T> * r) : val(x), left(l), right(r) {}
};

#endif
