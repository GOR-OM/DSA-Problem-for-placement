#include<bits/stdc++.h>
using namespace std ;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data= val;
        left =NULL;
        right = NULL;
    }
};

vector <int> bottomView(Node *root) {
        vector<int>ans;
        if(root==NULL)return ans;
        queue<pair<Node*,int>>q;
        map<int,int>mp;
        q.push({root,0});
        while(!q.empty()){
            Node* cur = q.front().first;
            int l = q.front().second;
            q.pop();
            mp[l]=cur->data;
            if(cur->left)q.push({cur->left,l-1});
            if(cur->right)q.push({cur->right,l+1});
        }
        for(auto i : mp){
            ans.push_back(i.second);
        }
        return ans;
    }