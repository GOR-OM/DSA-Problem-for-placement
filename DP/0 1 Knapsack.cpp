#include<bits/stdc++.h>
using namespace std;


int solve(int i, int maxWeight, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp)
{
    if(i==0){
        if(weight[i]<=maxWeight)return dp[i][maxWeight] = value[i];
        else return dp[i][maxWeight] = 0;
    }
    if (i < 0 || maxWeight <= 0)
        return 0;
    if (dp[i][maxWeight] != -1)
        return dp[i][maxWeight];
    int ans = 0;
    if (weight[i] <= maxWeight)
    {
        ans = max(ans, solve(i - 1, maxWeight - weight[i], weight, value, dp) + value[i]);
    }
    ans = max(ans, solve(i - 1, maxWeight, weight, value, dp));
    return dp[i][maxWeight] = ans;
}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n , vector<int>(maxWeight + 1, -1));
    return solve(n-1,maxWeight,weight,value,dp);
}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n + 1, vector<int>(maxWeight + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= maxWeight; j++) {
            if (weight[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j - weight[i - 1]] + value[i - 1], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][maxWeight];
}


int knapsack(vector<int>& wt, vector<int>& val, int n, int W) {
    // Initialize a vector 'prev' to represent the previous row of the DP table
    vector<int> prev(W + 1, 0);

    // Base condition: Fill in 'prev' for the weight of the first item
    for (int i = wt[0]; i <= W; i++) {
        prev[i] = val[0];
    }

    // Fill in the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++) {
        for (int cap = W; cap >= 0; cap--) {
            // Calculate the maximum value by either excluding the current item or including it
            int notTaken = prev[cap];
            int taken = INT_MIN;

            // Check if the current item can be included without exceeding the knapsack's capacity
            if (wt[ind] <= cap) {
                taken = val[ind] + prev[cap - wt[ind]];
            }

            // Update 'prev' for the current capacity
            prev[cap] = max(notTaken, taken);
        }
    }

    // The final result is in the last cell of the 'prev' vector
    return prev[W];
}