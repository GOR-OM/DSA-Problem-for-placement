#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> moves = {
    {1, 0}, {0, 1}, {-1, 0}, {0, -1}
};

vector<vector<int>> nearest(vector<vector<int>> grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> ans(n, vector<int>(m, -1)); // Initialize ans with appropriate dimensions and initial values
    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                q.push({{i, j}, 0});
                ans[i][j] = 0; // Set the initial distance for the starting points
            }
        }
    }

    while (!q.empty()) {
        int i = q.front().first.first;
        int j = q.front().first.second;
        int dis = q.front().second;
        q.pop();
        vis[i][j] = 1;

        for (auto move : moves) {
            int new_i = i + move.first;
            int new_j = j + move.second;

            if (new_i < 0 || new_i >= n || new_j < 0 || new_j >= m || vis[new_i][new_j] == 1 || ans[new_i][new_j] != -1) {
                continue;
            }

            ans[new_i][new_j] = dis + 1;
            q.push({{new_i, new_j}, dis + 1});
        }
    }

    return ans;
}