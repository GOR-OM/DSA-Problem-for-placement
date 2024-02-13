#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        queue<TreeNode*>q;
        q.push(root);
        bool t = true;
        while(!q.empty()){
            int n = q.size();
            vector<int>row(n);
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();
                int index = t ? i : n-i-1 ;
                row[index] = node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                
            }
            t = !t;
            ans.push_back(row);
        }
        return ans;

    }
};