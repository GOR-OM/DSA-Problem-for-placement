
#include<bits/stdc++.h>
using namespace std;

bool solve(int i, int k , vector<int>&arr,vector<vector<int>>&dp){
    if(k==0)return   true;
    if(i==0)return  false;
    if(dp[i][k]!=-1)return dp[i][k];
    if(arr[i-1]<=k){
        return dp[i][k] = solve(i-1,k-arr[i-1],arr,dp) || solve(i-1,k,arr,dp);
    }else{
        return dp[i][k] = solve(i-1,k,arr,dp);
    }

}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    return solve(n,k,arr,dp);
}




bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (arr[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][k];
}