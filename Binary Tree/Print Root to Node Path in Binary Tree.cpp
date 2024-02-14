#include<bits/stdc++.h>
using namespace std ;


template <typename T>
class TreeNode {
        public :
        int data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

bool getPath(TreeNode<int>*root,int b, vector<int>& ans ){
    if(!root)return false;
    ans.push_back(root->data);
    if(root->data ==b ){
        return true;
    }
    if(getPath(root->left,b,ans) || getPath(root->right,b,ans))return true;
    ans.pop_back();
    return false;
}

vector <int> pathInATree(TreeNode<int> *root, int b){
    vector<int>ans;
    if(root==NULL)return ans;
    getPath(root,b,ans);
    return ans;
}