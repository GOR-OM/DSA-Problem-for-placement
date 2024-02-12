
#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void PriOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    PriOrder(root->left);
    PriOrder(root->right);
}

void InOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

void PostOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    
    return 0;
}
