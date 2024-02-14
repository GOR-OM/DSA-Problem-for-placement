#include<bits/stdc++.h>
using namespace std ;

struct Node {
    int data;
    Node* left ;
    Node* right;

    Node(int val){
        data= val;
        left =NULL;
        right = NULL;
    }
};

bool isLeafNode(Node* root){
    return !root->left && !root->right ;
}

void leftBoundary(Node* root ,vector<int>& ref){
    Node* curr = root->left;
    while(curr){
        if(!isLeafNode(curr)) ref.push_back(curr->data);
        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }
}

void rightBoundary(Node* root, vector<int>& ref){
    Node* curr = root->right; // Change here to start from the right
    vector<int> temp;
    while(curr){
        if(!isLeafNode(curr)) temp.push_back(curr->data);
        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }
    for(int i = temp.size()-1; i >= 0; i--){
        ref.push_back(temp[i]);
    }
}

void addLeafNodes(Node* root, vector<int>& ref){
    if(isLeafNode(root)){
        ref.push_back(root->data);
        return;
    }
    if(root->left) addLeafNodes(root->left, ref);
    if(root->right) addLeafNodes(root->right, ref);
}

vector<int> printBoundary(Node* root){
    vector<int> ref;
    if(root == NULL) return ref;
    ref.push_back(root->data); // Add root to result
    leftBoundary(root, ref);
    addLeafNodes(root, ref);
    rightBoundary(root, ref);
    return ref;
}
