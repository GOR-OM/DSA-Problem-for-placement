
#include<bits/stdc++.h>
using namespace std ;

template <typename T>
class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

bool help(BinaryTreeNode<int>* left, BinaryTreeNode<int>* right){
    if(left==NULL || right==NULL){
        return left==right;
    }
    if(left->data != right->data)return false;
    return help(left->left,right->right) && help(left->right,right->left);
}


bool isSymmetric(BinaryTreeNode<int>* root)
{
    return root==NULL || help(root->left, root->right);
}