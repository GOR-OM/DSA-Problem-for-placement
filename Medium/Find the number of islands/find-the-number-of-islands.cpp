//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
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
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends