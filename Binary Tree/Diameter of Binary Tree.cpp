#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

int solve(TreeNode<int>*root, int &maxi){
    if(root==NULL)return 0;
    int lh = solve(root->left,maxi);
    int rh = solve(root->right,maxi);
    maxi =  max(maxi,lh+rh);
    return 1 + max(lh,rh);
}


int diameterOfBinaryTree(TreeNode<int> *root)
{
    int maxi =INT_MIN;
    solve(root,maxi);
    return maxi;
}