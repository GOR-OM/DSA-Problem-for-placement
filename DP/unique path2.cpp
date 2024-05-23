#include <bits/stdc++.h>
using namespace std;
const long MOD = 1e9+7;
int solve(int i, int j, vector<vector<int>>& dp,vector<vector<int>>&arr) {
    if (i == 0 && j == 0) return 1;
    if (i < 0 || j < 0) return 0;
    if(arr[i][j]==-1)return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int left = solve(i - 1, j, dp,arr);
    int right = solve(i, j - 1, dp,arr);
    return dp[i][j] = left + right;
}

int uniquePaths(int m, int n,vector<vector<int>>&arr) {
    vector<vector<int>> dp(m, vector<int>(n, -1)); 
    return solve(m - 1, n - 1, dp,arr); 
}






int uniquePaths2(int n, int m,vector<vector<int>>&arr)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(arr[i][j]==-1 && i>0 && j>0){
                dp[i][j]=0;
                continue;
            }
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
                continue;
            }

            int up = 0;
            int left = 0;

            if (i > 0)
                up = dp[i - 1][j];

            if (j > 0)
                left = dp[i][j - 1];

            dp[i][j] = (up + left)%MOD;
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
        vector<vector<int>>arr(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        cout << uniquePaths2(n, m,arr) << endl;
    }
}