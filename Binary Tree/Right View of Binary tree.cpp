#include<bits/stdc++.h>
using namespace std ;


template <typename T>

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

void solve(BinaryTreeNode<int>*root, int l, vector<int>&ans){
    if(root==NULL)return ;
    if(l==ans.size())ans.push_back(root->data);
    solve(root->right,l+1,ans);
    solve(root->left,l+1,ans);
    }


vector<int> printRightView(BinaryTreeNode<int>* root) {
    vector<int>ans;
    if(root==NULL)return ans;
    solve(root,0,ans);
    return ans;
}