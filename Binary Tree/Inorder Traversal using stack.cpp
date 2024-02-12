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


vector<int> inOrder(Node*root){
    vector<int>ans;
    stack<Node*>st;
    if(root==NULL)return ans;
    Node* node = st.top();
    st.push(root);
    while(true){
        if(node != NULL){
            st.push(node);
            node = node->left;
        }
        else{
            if(st.empty())break;
            node = st.top();
            st.pop();
            ans.push_back(node->data);
            node = node->right ;
        }
        
    }
    return ans;

}
