//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool isVal(int n, int m, int i, int j) {
        if (i < n && j < m && i >= 0 && j >= 0) return true;
        return false;
    }

    void solve(int i, int j, vector<vector<int>>& grid, set<vector<pair<int,int>>>&st) {
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int,int>>arr;
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = 2;  
        int ans = 0;
        


        while (!q.empty()) {
            pair<int, int> pq = q.front();
            arr.push_back({pq.first - i, pq.second - j});
            q.pop();
            ans++;

            for (auto it : directions) {
                int newX = it.first + pq.first;
                int newY = it.second + pq.second;

                
                if (isVal(n, m, newX, newY) && grid[newX][newY] == 1) {
                    grid[newX][newY] = 2;  
                    q.push({newX, newY});
                }
            }
        }
        st.insert(arr);
        return ;
    }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        set<vector<pair<int,int>>>st;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    solve(i, j, grid,st);
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends