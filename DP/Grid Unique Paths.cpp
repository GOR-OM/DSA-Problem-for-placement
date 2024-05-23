#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, vector<vector<int>>& dp) {
    if (i == 0 && j == 0) return 1;
    if (i < 0 || j < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int left = solve(i - 1, j, dp);
    int right = solve(i, j - 1, dp);
    return dp[i][j] = left + right;
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1)); // Initialize dp with m rows and n columns
    return solve(m - 1, n - 1, dp); // Pass m-1 and n-1 as the starting indices
}

//

int uniquePaths2(int n, int m)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // Base condition: If we are at the top-left cell (0, 0), there is one way.
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
                continue; // Skip the rest of the loop and continue with the next iteration.
            }

            // Initialize variables to store the number of ways from the cell above (up) and left (left).
            int up = 0;
            int left = 0;

            // If we are not at the first row (i > 0), update 'up' with the value from the cell above.
            if (i > 0)
                up = dp[i - 1][j];

            // If we are not at the first column (j > 0), update 'left' with the value from the cell to the left.
            if (j > 0)
                left = dp[i][j - 1];

            // Calculate the number of ways to reach the current cell by adding 'up' and 'left'.
            dp[i][j] = up + left;
        }
    }

    // The result is stored in the bottom-right cell (m-1, n-1).
    return dp[n - 1][m - 1];
    
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        
        cout<<uniquePaths2(n,m)<<endl;
    }
}