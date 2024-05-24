#include <bits/stdc++.h>
using namespace std;

int solve(int i, int sum, int n, vector<int> &arr, vector<vector<int>> &dp)
{
    if (sum == 0)
        return 1;
    if (i == n - 1)
    {
        return arr[i] == sum;
    }
    long long MOD = 1e9 + 7;
    if (dp[i][sum] != -1)
        return dp[i][sum];

    int nat = solve(i + 1, sum, n, arr, dp);
    int kat = 0;
    if (arr[i] <= sum)
    {
        kat = solve(i + 1, sum - arr[i], n, arr, dp);
    }
    return dp[i][sum] = (nat + kat) % MOD;
}

int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return solve(0, k, n, arr, dp);
}


const long long MOD = 1e9 + 7;

int findWays2(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    if(arr[0]<=k){
        dp[1][arr[0]]=1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - arr[i - 1]]) % MOD;
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][k];
}


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << findWays2(arr, k) << endl;
    }
    return 0;
}