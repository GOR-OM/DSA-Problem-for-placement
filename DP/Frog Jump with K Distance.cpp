#include<bits/stdc++.h>
using namespace std;


int frogJump(int n, vector<int> &heights, int k)
{   
    vector<int>dp(n,-1);
    dp[0]=0;
    for(int i=1;i<n;i++){
        dp[i]=INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                dp[i]=min(dp[i],abs(heights[i]-heights[i-j])+dp[i-j]);
            }
            else break;
        }
    }
    return dp[n-1];
}

int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int>heights(n);
    for(int i=0;i<n;i++){
        cin>>heights[i];
    }
    cout<<frogJump(n,heights,k);
    return 0;
}