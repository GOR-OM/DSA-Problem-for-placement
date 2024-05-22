#include <bits/stdc++.h> 
using namespace std;

int solve(int i, int n, vector<int>&heights , vector<int>&dp){
    if(i==0)return 0;
    if(dp[i]!=-1)return dp[i];
    int jump1 = abs(heights[i]-heights[i-1])+solve(i-1,n,heights, dp);
    int jump2 = INT_MAX;
    if(i>1){
        jump2 = abs(heights[i]-heights[i-2])+solve(i-2,n,heights,dp);
    }
    return dp[i]= min(jump1,jump2);
}


int frogJump(int n, vector<int> &heights)
{   
    vector<int>dp(n,-1);
    return solve(n-1,n,heights,dp);
}



// tabular dp


int frogJump(int n, vector<int> &heights)
{   
    vector<int>dp(n,-1);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int jump1 = abs(heights[i]-heights[i-1])+dp[i-1];
        int jump2 = INT_MAX;
        if(i>1){
            jump2 = abs(heights[i]-heights[i-2])+dp[i-2];
        }
        dp[i]=min(jump1,jump2);
    }
    return dp[n-1];
}