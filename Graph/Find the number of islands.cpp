#include<bits/stdc++.h>
using namespace std ;

int numIslands(vector<vector<char>>& grid) {
    int n= grid.size();
    int m = grid[0].size();
    // n * m matrix 
    vector<vector<bool>>vis(n,vector<bool>(m,0));
    int ans= 0;
    queue<pair<int,int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]!='0' && vis[i][j]==false){
                vis[i][j]=true;
                q.push({i,j});
                ans++;
                while(!q.empty()){
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();
                    for(int deltarow = -1 ; deltarow<=1;deltarow++){
                        for(int deltacol =-1; deltacol<=1;deltacol++ ){
                            int newR = r+deltarow;
                            int newC = c+deltacol;
                            if(newR>=0 && newC>=0 && newR<n && newC<m && grid[newR][newC]=='1' && vis[newR][newC]!=true ){
                                vis[newR][newC]=true;
                                q.push({newR, newC});
                            }
                        }
                    }
                }
            }
        }
    }
    return ans;
}