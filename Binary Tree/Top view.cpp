#include<bits/stdc++.h>
using namespace std ;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

void topView(Node * root) {
        if(root==NULL)return ;
        queue<pair<Node*, int>>q;
        map<int,int>mp;
        q.push({root,0});
        while(!q.empty()){
            Node* cur = q.front().first;
            int l = q.front().second;
            q.pop();
            if (mp.find(l) == mp.end())mp[l]=cur->data;
            if(cur->left)q.push({cur->left,l-1});
            if(cur->right)q.push({cur->right,l+1});
        }
        for(auto i : mp){
            cout<<i.second<<" ";
        }
}