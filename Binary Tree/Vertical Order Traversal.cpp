#include <bits/stdc++.h>
using namespace std;

template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode<int> *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto p = q.front();
        TreeNode<int> *cur = p.first;
        int x = p.second.first;
        int y = p.second.second;
        nodes[x][y].insert(cur->data);
        if (cur->left)
            q.push({cur->left, {x - 1, y + 1}});
        if (cur->right)
            q.push({cur->right, {x + 1, y + 1}});
    }
    vector<int> result;
    for (auto &col : nodes)
    {
        for (auto &row : col.second)
        {
            for (int val : row.second)
            {
                result.push_back(val);
            }
        }
    }

    return result;
}



//

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    if (!root)
        return {};

    map<int, vector<int>> nodes;
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto p = q.front();
        TreeNode<int> *cur = p.first;
        int x = p.second;
        q.pop();

        nodes[x].push_back(cur->data);

        if (cur->left)
            q.push({cur->left, x - 1});
        if (cur->right)
            q.push({cur->right, x + 1});
    }

    vector<int> result;
    for (const auto &column : nodes)
    {
        for (int val : column.second)
        {
            result.push_back(val);
        }
    }

    return result;
}