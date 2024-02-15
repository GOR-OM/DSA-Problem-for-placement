#include<bits/stdc++.h>
using namespace std ;

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

void changeTree(BinaryTreeNode < int > * root) {
    if(!root)return ;
    int child=0;
    if(root->left)child += root->left->data;
    if(root->right)child+= root->right->data;
    if(child<root->data){
        if(root->left)root->left->data = child;
        else if(root->right)root->right->data = child;
    }
    changeTree(root->left);
    changeTree(root->right);
    int change = 0 ;
    if(root->left)change += root->left->data;
    if(root->right)change+= root->right->data;
    if(root->left || root->right)root->data= change;
}  