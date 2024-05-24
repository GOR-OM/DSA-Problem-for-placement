#include<bits/stdc++.h>
using namespace std;


int solve(int i, int j1 ,int j2 , int r ,int c , vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
    if(i==r-1){
        if(j1==j2)return dp[i][j1][j2] = grid[i][j1];
        else {
            return dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
        }
    }
    if(i>=r || j1>=c || j2>=c || j1<0 || j2<0)return -1e5;
    if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
    int ans=-1e5;
    for(int d1 = -1 ; d1<=1 ; d1++){
        for(int d2 = -1 ; d2<=1 ; d2++){
            
            if(j1+d1>=0 && j2+d2>=0 && j1+d1<c && j2+d2<c){
                ans = max(ans,solve(i+1,j1+d1,j2+d2,r,c,grid,dp) + grid[i][j1] + (j1!=j2)*grid[i][j2]);
            }
        }
    }
    return dp[i][j1][j2] = ans;
}







int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    return solve(0,0,c-1,r,c,grid,dp);
}


int maximumChocolates2(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,0)));
    for(int i=r-1;i>=0;i--){
        for(int j1=0;j1<c;j1++){
            for(int j2=0;j2<c;j2++){
                if(i==r-1){
                    if(j1==j2)dp[i][j1][j2] = grid[i][j1];
                    else dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
                    continue;
                }
                int ans=-1e5;
                for(int d1 = -1 ; d1<=1 ; d1++){
                    for(int d2 = -1 ; d2<=1 ; d2++){
                        if(j1+d1>=0 && j2+d2>=0 && j1+d1<c && j2+d2<c){
                            ans = max(ans,dp[i+1][j1+d1][j2+d2] + grid[i][j1] + (j1!=j2)*grid[i][j2]);
                        }
                    }
                }
                dp[i][j1][j2] = ans;
            }
        }
    }return dp[0][0][c-1];
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int r,c;
        cin>>r>>c;
        vector<vector<int>>grid(r,vector<int>(c));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>grid[i][j];
            }
        }
        cout<<maximumChocolates2(r,c,grid)<<endl;
}
}

//tabulation
