#include <bits/stdc++.h>
using namespace std;

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

void findPar(unordered_map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> &par, BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *cur = q.front();
        q.pop();
        if (cur->left)
        {
            par[cur->left] = cur;
            q.push(cur->left);
        }
        if (cur->right)
        {
            par[cur->right] = cur;
            q.push(cur->right);
        }
    }
}

BinaryTreeNode<int> *find(BinaryTreeNode<int> *root, int start)
{
    if (root == NULL)
        return NULL;
    if (root->data == start)
        return root;
    BinaryTreeNode<int> *left = find(root->left, start);
    if (left)
        return left;
    return find(root->right, start);
}

int timeToBurnTree(BinaryTreeNode<int> *root, int start)
{

    BinaryTreeNode<int> *target = find(root, start);
    if (root == NULL)
        return 0;

    unordered_map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> parents;
    findPar(parents, root);

    // DFS
    queue<BinaryTreeNode<int> *> q;
    unordered_map<BinaryTreeNode<int> *, bool> check;
    q.push(target);
    check[target] = true;
    int time = 0;
    while (!q.empty())
    {
        int size = q.size();
        time++;
        for (int i = 0; i < size; i++)
        {
            BinaryTreeNode<int> *cur = q.front();
            q.pop();
            if (cur->left && !check[cur->left])
            {
                check[cur->left] = true;
                q.push(cur->left);
            }
            if (cur->right && !check[cur->right])
            {
                check[cur->right] = true;
                q.push(cur->right);
            }
            if (parents[cur] && !check[parents[cur]])
            {
                check[parents[cur]] = true;
                q.push(parents[cur]);
            }
        }
    }

    return time;
}