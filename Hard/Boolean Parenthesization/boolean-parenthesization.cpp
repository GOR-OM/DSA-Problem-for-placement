//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long MOD = 1003;
    // map<pair<int,int>,pair<int,int>>dp;
    pair<int,int> dfs(string& s, int low, int high, vector<vector<pair<int,int>>>& dp){        
        if(low==high){
            if(s[low]=='T')return {1,0};
            else return {0,1};
        }
        pair<int,int>default2 = {-1,-1};
        if(dp[low][high] != default2)return dp[low][high];
        long long truth = 0,falsy=0;
        for(int i=low; i<=high-2; i+=2){
            auto left = dfs(s,low,i,dp);
            auto right = dfs(s,i+2,high,dp);
            if(s[i+1] == '|'){
                truth = (truth + left.first * right.first)%MOD;
                truth = (truth + left.first * right.second)%MOD;
                truth = (truth + left.second * right.first)%MOD;
                falsy = (falsy + left.second * right.second)%MOD;
                
            }else if(s[i+1] == '&'){
                truth = (truth + left.first * right.first)%MOD;
                falsy = (falsy + left.first * right.second)%MOD;
                falsy  = (falsy + left.second * right.first)%MOD;
                falsy = (falsy + left.second * right.second)%MOD;
            }else{
                
                truth = (truth + left.first * right.second)%MOD;
                truth = (truth + left.second * right.first)%MOD;
                falsy = (falsy + left.first * right.first)%MOD;
                falsy = (falsy + left.second * right.second)%MOD;
            }
        // cout<<low<<" "<<i<<" "<<truth<<" "<<falsy<<endl;
        }
        return dp[low][high] = {truth,falsy};
    }
    int countWays(int n, string s){
        // code here
        vector<vector<pair<int,int>>>dp(n,vector<pair<int,int>>(n,{-1,-1}));
        return dfs(s,0,n-1,dp).first;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.countWays(n, s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends