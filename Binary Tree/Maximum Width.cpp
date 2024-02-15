#include<bits/stdc++.h>
using namespace std ;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};



int getMaxWidth(TreeNode<int> *root)
{
    if(!root)return 0;
    int ans=0;
    queue<pair<TreeNode<int>* , int>>q;
    q.push({root,0});
    while(!q.empty()){
        int mini = q.front().second;
        int size= q.size();
        int first , last;
        for(int i=0;i<size;i++){
            int curr = q.front().second - mini;
            TreeNode<int>* cur = q.front().first;
            q.pop();
            if(i==0)first = curr;
            if(i==size-1)last=curr;
            if(cur->left)q.push({cur->left,2*curr+1});
            if(cur->right)q.push({cur->right,2*curr+2});

        }
        ans = max(ans,last-first+1);
    }
    return ans;

}