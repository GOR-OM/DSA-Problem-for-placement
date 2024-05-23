#include<bits/stdc++.h>
using namespace std;



int solve(int i, vector<int>&nums,vector<int>&dp){
    if(i==0)return dp[i]= nums[i];
    if(i<0)return 0;
    if(dp[i]!=-1)return dp[i];
    int pick = nums[i] + solve(i-2,nums,dp);
    int notPick  = 0  + solve(i-1,nums,dp);

    return dp[i] =  max(pick,notPick);
}



int maximumNonAdjacentSum(vector<int> &nums) {
    int n= nums.size();
   
    vector<int>dp(n,-1);
    solve(n-1,nums,dp);
    return dp[n-1];
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<maximumNonAdjacentSum(nums)<<endl;
    }
}


// more optimized 

int maximumNonAdjacentSum(vector<int> &nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    vector<int> dp(n + 1,0);
    dp[0] = nums[0];
    for(int i=0;i<n;i++){
    int nota = dp[i - 1];
    int take = 0;
    if(i>1){
    take = nums[i] + dp[i - 2];
    }
    dp[i] = max(nota, take);
    
    }
    return dp[n-1];
}