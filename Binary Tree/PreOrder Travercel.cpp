#include<bits/stdc++.h>
using namespace std ;


struct Node 
{
    int data;
    Node* left;
    Node* right ; 

    Node(int val){
        data = val;
        left= NULL;
        right = NULL;
    }
};


vector<int> preOrder(Node*root){
    vector<int>ans;
    stack<Node*>st;
    if(root==NULL)return ans;
    st.push(root);
    while(!st.empty()){
        Node* node = st.top();
        st.pop();
        ans.push_back(node->data);
        if(node->right)st.push(node->right);
        if(node->left)st.push(node->left);
    }
    return ans;

}
