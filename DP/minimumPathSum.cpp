
#include <bits/stdc++.h>
using namespace std;
// const int MOD = 1e9+7;

int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return grid[0][0];
    if (i < 0 || j < 0)
        return 1e9;
    if (dp[i][j] != -1)
        return dp[i][j];

    int left = (grid[i][j] + solve(i, j - 1, grid, dp));
    int up = (grid[i][j] + solve(i - 1, j, grid, dp));

    return dp[i][j] = min(left, up);
}

int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(n - 1, m - 1, grid, dp);
}

int minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = grid[i][j];
                continue;
            }

            int up = i > 0 ? dp[i - 1][j] + grid[i][j] : INT_MAX;
            int left = j > 0 ? dp[i][j - 1] + grid[i][j] : INT_MAX;

            dp[i][j] = min(up, left);
        }
    }

    return dp[n - 1][m - 1];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        cout << minSumPath(arr) << endl;
        cout << minPathSum(arr) << " ** " << endl;
    }
}