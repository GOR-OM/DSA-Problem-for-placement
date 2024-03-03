#include <bits/stdc++.h>
using namespace std;

bool isvalid(int i, int j, int n, int m)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}
vector<pair<int, int>> moves = {
    {1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int, int>> &ar, int x, int y)
{

    int n = grid.size();
    int m = grid[0].size();

    vis[i][j] = 1;
    ar.push_back({i - x, j - y});
    for (auto child : moves)
    {
        int p = i + child.first;
        int q = j + child.second;
        if (!isvalid(p, q, n, m))
            continue;
        if (grid[p][q] == 0)
            continue;
        if (!vis[p][q])
        {

            dfs(p, q, grid, vis, ar, x, y);
        }
    }
}

int countDistinctIslands(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> s;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == 1)
            {
                vector<pair<int, int>> ar;
                dfs(i, j, grid, vis, ar, i, j);
                s.insert(ar);
            }
        }
    }
    return s.size();
}