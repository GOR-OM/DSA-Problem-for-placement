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

int maxPathSumHelper(BinaryTreeNode<int> *root, int &maxSum)
{
    if (root == NULL)
    {
        return 0;
    }

    // Calculate the maximum sum for the left and right subtrees
    int leftSum = max(0, maxPathSumHelper(root->left, maxSum));
    int rightSum = max(0, maxPathSumHelper(root->right, maxSum));

    maxSum = max(maxSum, leftSum + rightSum + root->data);
    return max(leftSum, rightSum) + root->data;
}

int maxPathSum(BinaryTreeNode<int> *root)
{
    int maxSum = INT_MIN;
    maxPathSumHelper(root, maxSum);
    return maxSum;
}