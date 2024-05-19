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

void findPar(unordered_map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> & par, BinaryTreeNode<int>*root){
    if(root==NULL)return ;
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int>* cur = q.front();
        q.pop();
        if(cur->left){
            par[cur->left]= cur;
            q.push(cur->left);
        }
        if(cur->right){
            par[cur->right]= cur;
            q.push(cur->right);
        }
    }
}


vector<BinaryTreeNode<int>*> printNodesAtDistanceK(BinaryTreeNode<int>* root, BinaryTreeNode<int>* target, int K) {
    vector<BinaryTreeNode<int>*>ans;
    if(root==NULL)return ans;
    if(K==0){
        ans.push_back(target);
        return ans;
    }

    unordered_map<BinaryTreeNode<int>*,BinaryTreeNode<int>*>parents;
    findPar(parents,root);

    // BFS 
    queue<BinaryTreeNode<int>*>q;
    unordered_map<BinaryTreeNode<int>*,bool>check;
    q.push(target);
    check[target]=true;
    int level = 0;
    while(!q.empty()){
        int size = q.size();
        if(level++ == K)break;
        for(int i=0;i<size;i++){
        BinaryTreeNode<int>* cur = q.front();
        q.pop();
        if(cur->left && !check[cur->left]){
            check[cur->left]=true;
            q.push(cur->left);
        }
        if(cur->right && !check[cur->right]){
            check[cur->right] = true;
            q.push(cur->right);
        }
        if(parents[cur] && !check[parents[cur]]){
            check[parents[cur]]=true;
            q.push(parents[cur]);
        }

        }

    }
    while(!q.empty()){
        ans.push_back(q.front());
        q.pop();
    }
    return ans;
}