#include<bits/stdc++.h>
using namespace std ; 

template <typename T>
class TreeNode
    {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val)
        {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

bool isBalancedBT(TreeNode<int>* root){
    return dfHight(root) != -1 ;
}

int dfHight(TreeNode<int>* root){
    if(root==NULL)return 0;

    int lh = dfHight(root->left);
    if(lh==-1)return -1;
    int rh = dfHight(root->right);
    if(rh == -1)return -1;

    if(abs(lh-rh)>1)return -1;
    return 1 + max(lh,rh);
}