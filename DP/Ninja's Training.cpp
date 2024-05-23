#include<bits/stdc++.h>
using namespace std;



int solve(int i, int previous , vector<vector<int>> &points, vector<vector<int>>&dp){
    if(i==0){
        int maxi =0;
        for(int j=0;j<=2;j++){
            if(j!=previous){
                maxi=max(maxi,points[i][j]);
            }
        }
        return dp[i][previous] = maxi;
    }
    if(dp[i][previous]!=-1)return dp[i][previous];
    int maxi = 0;
    for(int j=0;j<=2;j++){
        int pointGain=0;
        if(j!=previous){
        pointGain  = points[i][j] + solve(i-1,j,points,dp);
        }
        maxi= max(maxi,pointGain);
    }
    return dp[i][previous] = maxi;
}





int ninjaTraining(int n, vector<vector<int>> &points){
    vector<vector<int>>dp(n,vector<int>(4,-1));
    return solve(n-1,3,points,dp);
}


int main (){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>>arr(n,vector<int>(3));
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                cin>>arr[i][j];
            }
        }
        cout<<ninjaTraining(n,arr)<<endl;
    }
}