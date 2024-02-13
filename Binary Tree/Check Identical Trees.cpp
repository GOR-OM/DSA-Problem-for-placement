#include <bits/stdc++.h>
using namespace std;

template <typename T>

class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

bool identicalTrees(BinaryTreeNode<int> *root1, BinaryTreeNode<int> *root2)
{
    // If both trees are empty, they are identical
    if (!root1 && !root2)
    {
        return true;
    }

    // If one of the trees is empty and the other is not, they are not identical
    if (!root1 || !root2)
    {
        return false;
    }

    // Check if the data of the roots is the same
    if (root1->data != root2->data)
    {
        return false;
    }

    // Recursively check the left and right subtrees
    return identicalTrees(root1->left, root2->left) && identicalTrees(root1->right, root2->right);
}