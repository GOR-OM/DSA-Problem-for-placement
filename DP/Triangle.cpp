#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, vector<vector<int>> &arr, vector<vector<int>> &dp,int n)
{
    if (i == n - 1)
        return arr[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];

    int down = arr[i][j] + solve(i + 1, j, arr, dp,n);
    int right = arr[i][j] + solve(i + 1, j + 1, arr, dp,n);

    return dp[i][j] = min(down, right);
}

int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(0, 0,triangle,dp,n);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> arr(n, vector<int>(n,0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cin >> arr[i][j];
            }
        }
        cout << minimumPathSum(arr, n) << endl;
    }
}